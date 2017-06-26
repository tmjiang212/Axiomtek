#include <stdio.h>
#include "libaxio.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
int kbhit(void);
int main()
{
	int i;
	unsigned int WDT_timeout;
	printf("Enable the Watch Dog Timer\n\n");
	EApiWDogStart(0,9);
	for(i=1; i<7; i++) {
	    printf("%d sec.....\n",i);
	    usleep(1000000); //delay 1 sec
	}
	EApiWDogReset();
	printf("Reload WDT timer .....  quit:q+enter ==>stop WDT Timer \n");
	 for(i=1; i<10; i++) 
	{
		 printf("%d sec.....\n",i);
		 usleep(1000000); //delay 1 sec
		if (kbhit())
		{
			if (getchar()=='q')
			{
				printf("Disable the Watch Dog Timer\n\n");
				EApiWDogStop();
				return 1;
			}
		}

	}
    return 0;
}


int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}
