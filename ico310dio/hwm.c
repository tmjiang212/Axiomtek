#include <stdio.h>
#include <unistd.h>
#include "libaxio.h"

int main()
{
        unsigned char xch;
    int xData;
    int   read_v;

    xData=EApiBoardGetValue(EAPI_ID_HWMON_VOLTAGE_VBAT ,&read_v);
    if (xData ==0 ) printf("Read VBAT volatage is %2.3f V\n",(float)read_v/1000);
    else            printf("This Board not support vcore monitor function\n");

    xData=EApiBoardGetValue(EAPI_ID_HWMON_VOLTAGE_3V3 ,&read_v);
    if (xData ==0 ) printf("Read 3.3V volatage is %2.3f V\n",(float)read_v/1000);
    else            printf("This Board not support 3.3V monitor function\n");

    xData=EApiBoardGetValue(EAPI_ID_HWMON_VOLTAGE_3V3SB ,&read_v);
    if (xData ==0 ) printf("Read 3.3VSB volatage is %2.3f V\n",(float)read_v/1000);
    else            printf("This Board not support 3.3VSB monitor function\n");

    xData=EApiBoardGetValue(EAPI_ID_HWMON_VOLTAGE_5V ,&read_v);
    if (xData ==0 ) printf("Read 5V volatage is %2.3f V\n",(float)read_v/1000);
    else            printf("This Board not support 5V monitor function\n");

    xData=EApiBoardGetValue(EAPI_ID_HWMON_VOLTAGE_5VSB ,&read_v);
    if (xData ==0 ) printf("Read 5VSB volatage is %2.3f V\n",(float)read_v/1000);
    else            printf("This Board not support 5VSB monitor function\n");

    xData=EApiBoardGetValue(EAPI_ID_HWMON_CPU_TEMP ,&read_v);
    if (xData ==0 ) printf("Read CPU Temp. is %d degree C\n",read_v);
    else            printf("This Board not support CPU Temp. monitor function\n");

     xData=EApiBoardGetValue(EAPI_ID_HWMON_SYSTEM_TEMP ,&read_v);
    if (xData ==0 ) printf("Read SYS Temp. is %d degree C\n",read_v);
    else            printf("This Board not support System Temp. monitor function\n");


    return 0;

}

