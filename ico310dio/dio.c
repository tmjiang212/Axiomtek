#include <stdio.h>
#include <unistd.h>
#include "libaxio.h"

int main()
{
	int rtn;
        int readv;
	int i;

	EApiSetDIOmode(0xf0);// config DIO as 4 input(DI0-DI3) 4 output(DO4-DO7)
	/**************************************************************/
	/********************set DO0~3 to high******************/

	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO4,1); // set do4 to high
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO0 Success\n");
	else
		printf("Set DO0 failed\n");

	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO5,1); // set do5 to high
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO1 Success\n");
	else
		printf("Set DO1 failed\n");

	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO6,1); // set do6 to high
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO2 Success\n");
	else
		printf("Set DO2 failed\n");

	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO7,1); // set do7 to high
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO3 Success\n");
	else
		printf("Set DO3 failed\n");
	/**************************************************************/

	/**************************************************************/
	/********************read DI0~3******************/
	
	printf("Read DI(0~3) will be 1 if you link with DO4~7\n");
	//DI default value is high
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI0,&readv); //get di0 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI0 status is %d\n",readv);
	else
		printf("Get DI0 status failed\n");

	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI1,&readv); //get di1 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI1 status is %d\n",readv);
	else
		printf("Get DI1 status failed\n");
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI2,&readv); //get di2 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI2 status is %d\n",readv);
	else
		printf("Get DI2 status failed\n");
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI3,&readv); //get di3 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI3 status is %d\n",readv);
	else
		printf("Get DI3 status failed\n");

	/**************************************************************/
	/********************set DO0~3 to low******************/
	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO4,0); // set do4 to low
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO0 Success\n");
	else
		printf("Set DO0 failed\n");
	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO5,0); // set do5 to low
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO1 Success\n");
	else
		printf("Set DO1 failed\n");
	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO6,0); // set do6 to low
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO2 Success\n");
	else
		printf("Set DO2 failed\n");
	rtn = AXBoardSetValue(EAPI_AX_HWMON_DO7,0); // set do7 to low
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("Set DO3 Success\n");
	else
		printf("Set DO3 failed\n");
	/**************************************************************/
	/********************read DO0~3******************/
	printf("Read DI(0~3) will be 0 if you link with DO4~7\n");
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI0,&readv); //get di0 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI0 status is %d\n",readv);
	else
		printf("Get DI0 status failed\n");

	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI1,&readv); //get di1 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI1 status is %d\n",readv);
	else
		printf("Get DI1 status failed\n");
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI2,&readv); //get di2 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI2 status is %d\n",readv);
	else
		printf("Get DI2 status failed\n");
	rtn = EApiBoardGetValue(EAPI_AX_HWMON_DI3,&readv); //get di3 value
	if(rtn == EAPI_STATUS_SUCCESS)
		printf("DI3 status is %d\n",readv);
	else
		printf("Get DI3 status failed\n");

	return 0;

}

