/*
 * Axiomtek ICO310 API Library
 * User-Mode Driver
 * Wrote by ryan.hsu@axiomtek.com.tw
 */

/* Library ==> /usr/lib/libaxio.so.1.0.0 */
/**********************EApi header file********************/
typedef int __int32;
typedef unsigned int uint32_t;

typedef unsigned int EApiStatus_t;
typedef unsigned int EApiId_t;

#ifndef EAPI_UINT32_C
#  define EAPI_UINT8_C(x)  ((uint8_t)(x))
#  define EAPI_UINT16_C(x) ((uint16_t)(x))
#  define EAPI_UINT32_C(x) ((uint32_t)(x))
#endif

#define EAPI_STATUS_INVALID_PARAMETER EAPI_UINT32_C(0xFFFFFEFF)

/* Description
 *   The Block Alignment is incorrect.
 * Actions
 *   Use pInputs and pOutputs to correctly select input and outputs.
 */
#define EAPI_STATUS_INVALID_BLOCK_ALIGNMENT EAPI_UINT32_C(0xFFFFFEFE)

/* Description
 *   This means that the Block length is too long.
 * Actions
 *   Use Alignment Capabilities information to correctly align write access.
 */
#define EAPI_STATUS_INVALID_BLOCK_LENGTH    EAPI_UINT32_C(0xFFFFFEFD)

/* Description
 *   The current Direction Argument attempts to set GPIOs to a unsupported
 *   directions. I.E. Setting GPI to Output.
 * Actions
 *   Use pInputs and pOutputs to correctly select input and outputs.
 */
#define EAPI_STATUS_INVALID_DIRECTION       EAPI_UINT32_C(0xFFFFFEFC)

/* Description
 *   The Bitmask Selects bits/GPIOs which are not supported for the current ID.
 * Actions
 *   Use pInputs and pOutputs to probe supported bits..
 */
#define EAPI_STATUS_INVALID_BITMASK         EAPI_UINT32_C(0xFFFFFEFB)

/* Description
 *   Watchdog timer already started.
 * Actions
 *   Call EApiWDogStop, before retrying.
 */
#define EAPI_STATUS_RUNNING                 EAPI_UINT32_C(0xFFFFFEFA)

/* Description
 *   This function or ID is not supported at the actual hardware environment.
 * Actions
 *   none.
 */
#define EAPI_STATUS_UNSUPPORTED       EAPI_UINT32_C(0xFFFFFCFF)

/* Description
 *   I2C Device Error
 *   No Acknowledge For Device Address, 7Bit Address Only
 *   10Bit Address may cause Write error if 2 10Bit addressed devices
 *   present on the bus.
 * Actions
 *   none.
 */
#define EAPI_STATUS_NOT_FOUND         EAPI_UINT32_C(0xFFFFFBFF)

/* Description
 *   I2C Time-out
 *   Device Clock stretching time-out, Clock pulled low by device
 *   for too long
 * Actions
 *   none.
 */
#define EAPI_STATUS_TIMEOUT           EAPI_UINT32_C(0xFFFFFBFE)

/* Description
 *   EApi  I2C functions specific. The addressed I2C bus is busy or there
 *   is a bus collision.
 *   The I2C bus is in use. Either CLK or DAT are low.
 *   Arbitration loss or bus Collision, data remains low when writing a 1
 * Actions
 *   Retry.
 */
#define EAPI_STATUS_BUSY_COLLISION    EAPI_UINT32_C(0xFFFFFBFD)

/* Description
 *   I2C Read Error
 *    Not Possible to detect.
 *   Storage Read Error
 *    ....
 * Actions
 *   Retry.
 */
#define EAPI_STATUS_READ_ERROR        EAPI_UINT32_C(0xFFFFFAFf)

/* Description
 *   I2C Write Error
 *     No Acknowledge received after writing any Byte after the First Address
 *     Byte.
 *     Can be caused by
 *     unsupported Device Command/Index
 *     Ext Command/Index used on Standard Command/Index Device
 *     10Bit Address Device Not Present
 *   Storage Write Error
 *    ...
 * Actions
 *   Retry.
 */
#define EAPI_STATUS_WRITE_ERROR       EAPI_UINT32_C(0xFFFFFAFE)


/* Description
 *   The amount of available data exceeds the buffer size.
 *   Storage buffer overflow was prevented. Read count was larger then
 *   the defined buffer length.
 *   Read Count > Buffer Length
 * Actions
 *   Either increase the buffer size or reduce the block length.
 */
#define EAPI_STATUS_MORE_DATA         EAPI_UINT32_C(0xFFFFF9FF)

/* Description
 *   Generic error message. No further error details are available.
 * Actions
 *   none.
 */
#define EAPI_STATUS_ERROR             EAPI_UINT32_C(0xFFFFF0FF)

/* Description
 *   The operation was successful.
 * Actions
 *   none.
 */
#define EAPI_STATUS_SUCCESS           EAPI_UINT32_C(0)


EApiStatus_t EApiBoardGetValue( EApiId_t  Id,uint32_t *pValue);

/*****************************************************/


/*****************************************************/
/* Hardware Monitor                         */

EApiStatus_t AXBoardSetValue(
		EApiId_t  Id,		/* Value Id */

		uint32_t pValue    /* Value */
    );
EApiStatus_t EApiBoardGetValue(
    EApiId_t  Id      , /* Value Id */
    uint32_t *pValue    /* Return Value */
);
#define EAPI_ID_HWMON_CPU_TEMP            EAPI_UINT32_C(0x20000) /* 0.1 */
#define EAPI_ID_HWMON_SYSTEM_TEMP         EAPI_UINT32_C(0x20002) /* 0.1 */

#define EAPI_ID_HWMON_VOLTAGE_VBAT       EAPI_UINT32_C(0x21004) /* millivolts */
#define EAPI_ID_HWMON_VOLTAGE_3V3         EAPI_UINT32_C(0x2100C) /* millivolts */
#define EAPI_ID_HWMON_VOLTAGE_3V3SB         EAPI_UINT32_C(0x2100D) /* millivolts */
#define EAPI_ID_HWMON_VOLTAGE_5V         EAPI_UINT32_C(0x2101C) /* millivolts */
#define EAPI_ID_HWMON_VOLTAGE_5VSB         EAPI_UINT32_C(0x2101D) /* millivolts */

#define EAPI_AX_HWMON_DI0				  EAPI_UINT32_C(0x31100) /* GPIO10*/
#define EAPI_AX_HWMON_DI1				  EAPI_UINT32_C(0x31101) /* GPIO11*/
#define EAPI_AX_HWMON_DI2				  EAPI_UINT32_C(0x31102) /* GPIO12*/
#define EAPI_AX_HWMON_DI3				  EAPI_UINT32_C(0x31103) /* GPIO13*/
#define EAPI_AX_HWMON_DI4				  EAPI_UINT32_C(0x31104) /* GPIO30*/
#define EAPI_AX_HWMON_DI5				  EAPI_UINT32_C(0x31105) /* GPIO31*/
#define EAPI_AX_HWMON_DI6				  EAPI_UINT32_C(0x31106) /* GPIO32*/
#define EAPI_AX_HWMON_DI7				  EAPI_UINT32_C(0x31107) /* GPIO33*/


#define EAPI_AX_HWMON_DO0				  EAPI_UINT32_C(0x31200) /* GPIO10*/
#define EAPI_AX_HWMON_DO1				  EAPI_UINT32_C(0x31201) /* GPIO11*/
#define EAPI_AX_HWMON_DO2				  EAPI_UINT32_C(0x31202) /* GPIO12*/
#define EAPI_AX_HWMON_DO3				  EAPI_UINT32_C(0x31203) /* GPIO13*/
#define EAPI_AX_HWMON_DO4				  EAPI_UINT32_C(0x31204) /* GPIO30*/
#define EAPI_AX_HWMON_DO5				  EAPI_UINT32_C(0x31205) /* GPIO31*/
#define EAPI_AX_HWMON_DO6				  EAPI_UINT32_C(0x31206) /* GPIO32*/
#define EAPI_AX_HWMON_DO7				  EAPI_UINT32_C(0x31207) /* GPIO33*/

/* Set DIO mode */
EApiStatus_t EApiSetDIOmode(unsigned char mode);

/* Watch dog */
/****************************************************/
/* TimerMode : 0:sec 1:min  			    */
/* Timer: range 0~255	                            */
EApiStatus_t EApiWDogStart(unsigned char TimerMode,unsigned char Timer);
/****************************************************/
/* disable the WDT timer                            */
EApiStatus_t EApiWDogStop();
/****************************************************/
/* reset the WDT timer                              */
EApiStatus_t EApiWDogReset();





