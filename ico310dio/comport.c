#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/time.h>
#define COM1	1
#define COM2	2


int init_port(int fd)
{
	struct termios newtio,result;
	
    tcgetattr(fd, &newtio);	//save current port settings
    cfsetispeed(&newtio, B9600);
    cfsetospeed(&newtio, B9600);
    newtio.c_cflag &= (~(CLOCAL | CREAD | CSIZE | CSTOPB) );
    newtio.c_cflag |= ((CLOCAL | CREAD | CS8 | CSTOPB) & (~PARENB));
    newtio.c_iflag |= IGNPAR;
    newtio.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON | IXOFF | IXANY | INPCK );
    newtio.c_lflag &= ~( ECHO | ECHONL | ICANON | ISIG |IEXTEN);
	newtio.c_cc[VMIN] = 1; // minimum number of chars to read in noncanonical (raw mode)
 	newtio.c_cc[VTIME] = 5; // time in deciseconds to wait for data in noncanonical mode (raw mode)

	if (tcsetattr(fd, TCSANOW, &newtio) ==  0) {
   		 tcgetattr(fd, &result);
    	if ( (result.c_cflag != newtio.c_cflag) ||
         	(result.c_oflag != newtio.c_oflag) ||
         	(result.c_iflag != newtio.c_iflag) ||
         	(result.c_cc[VMIN] != newtio.c_cc[VMIN]) ||
         	(result.c_cc[VTIME] != newtio.c_cc[VTIME]) ) 
			{
        	perror("While configuring port1");
        	close(fd);
        	return 1;
    		}
 		} 
		else 
		{
    		perror("While configuring port2");
    		close(fd);
    		return 1;
	 	};
	return 1;	
}

int write_port(int fd, char *chars)
{
    int len = strlen(chars);
    chars[len] = 0x0d;
    chars[len+1] = 0x00;

    int n = write(fd, chars, strlen(chars));
    if(n < 0) {
	fputs("write failed!! \n", stderr);
	return 0;
    }
    return 1;
}

int read_port(int fd, char *chars)
{
    int len = read(fd, chars, 254);
    if(len < 0) {
	if(errno == EAGAIN) {
	    printf("SERIAL EAGAIN ERROR");
	    return 0;
	} else {
	    printf("SERIAL read error %d %s \n", errno, strerror(errno));
	    return 0;
	}
    }
    return 1;
}

int main(int argc, char **argv)
{
    char c;
    char model[32];
    int num, type, fd1, fd2, xData;
    char sSent[254], sReceive[254];
    sSent[0] = 0x41;
    sSent[1] = 0x42;
    sSent[2] = 0x43;
    sSent[3] = 0x00;
	
	if (argc!=3)
	{
	printf("\nExample : ./comport -n(num) 1\n");
	printf("-n (num): 1=RS232,2=RS422,3=RS485(default=1,RS232)\n\n");
	return -1;
	}
	for(;;)
	{
		c = getopt(argc,argv,"n:");
		if(c == EOF) break;
		switch(c)
		{
			case 'n':
				memset(model,0x00,sizeof(model));
				sprintf(model,"%s",optarg);
				break;
			default:
				printf("Example : ./comport -n(num) 1");
			exit(1);
				
		}
	}
/****************************set path************************************/
	FILE *fp;
	char tmp[100];
	char path[100];
	system("rm path");
	system("pwd > path");
	fp = fopen("path","r");
	fread(tmp,100,1,fp);
	fclose(fp);
	sprintf(path,"cd %s",tmp);
	system(path);	
/****************************************************************/
	num = atoi(model);
	if (num == 1)
	{
	printf("Set COM1 & COM2 to RS232 \n");
	//com1
	system("./memtool mw -l 0xFED9CC08 0x00118102");
	system("./memtool mw -l 0xFED9CC20 0x00118100");
	//com2
	system("./memtool mw -l 0xFED9CC28 0x00118102");
	system("./memtool mw -l 0xFED9CC00 0x00118100");
	}
	if (num == 2)
	{
	printf("Set COM1 & COM2 to RS422 \n");
	//com1
	system("./memtool mw -l 0xFED9CC08 0x00118102");
	system("./memtool mw -l 0xFED9CC20 0x00118102");
	//com2
	system("./memtool mw -l 0xFED9CC28 0x00118102");
	system("./memtool mw -l 0xFED9CC00 0x00118102");
	}	
	if (num == 3)
	{
	printf("Set COM1 & COM2 to RS485 \n");
	//com1
	system("./memtool mw -l 0xFED9CC08 0x00118100");
	system("./memtool mw -l 0xFED9CC20 0x00118102");
	//com2
	system("./memtool mw -l 0xFED9CC28 0x00118100");
	system("./memtool mw -l 0xFED9CC00 0x00118102");
	}

    usleep(1000000);

    fd1 = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd1 == -1) {
		perror("open_port: Unable to open /dev/ttyS0 -");
		return 1;
    } else {
		fcntl(fd1, F_SETFL, 0);
    }
	fd2 = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd2 == -1) {
		perror("open_port: Unable to open /dev/ttyS1 -");
		return 1;
    } else {
		fcntl(fd2, F_SETFL, 0);
    }

    
    	init_port(fd1);
	init_port(fd2);

/*****test com 1/com 2*******************************/
    if(!write_port(fd1, sSent)) {
		printf("write failed!\n");
		close(fd1);
		

    }
    printf("COM1 sent: %s\n", sSent);
    usleep(100000);
    memset(sReceive,0x00,sizeof(sReceive));
    if(!read_port(fd2, sReceive)) {
		printf("read failed!\n");
		close(fd1);

    }
    printf("COM2 receive: %s\n", sReceive);
	
	if(!write_port(fd2, sSent)) {
		printf("write failed!\n");
		close(fd1);
		

    }
    printf("COM2 sent: %s\n", sSent);
    usleep(100000);
    memset(sReceive,0x00,sizeof(sReceive));
    if(!read_port(fd1, sReceive)) {
		printf("read failed!\n");
		close(fd1);
		close(fd2);
    }
    printf("COM1 receive: %s\n", sReceive);
	close(fd1);
	close(fd2);
/****************************************************/	

    
    return 0;
}
