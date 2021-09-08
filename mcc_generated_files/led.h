#ifndef __LED_H
#define __LED_H
#include "key.h"
#include "adcc.h"
#include "../mcc_generated_files/pin_manager.h"


#define BATT_DetectedGetValue() 		   PORTCbits.RC0

#define LED_40_SetHigh()            do { LATBbits.LATB0 = 1; } while(0) //LED1 
#define LED_40_SetLow()             do { LATBbits.LATB0 = 0; } while(0)


#define LED_60_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)  //LED2
#define LED_60_SetLow()             do { LATCbits.LATC5 = 0; } while(0)

#define LED_80_SetHigh()            do { LATCbits.LATC4 = 1; } while(0) //LED3
#define LED_80_SetLow()             do { LATCbits.LATC4 = 0; } while(0)

#define LED_100_SetHigh()            do { LATCbits.LATC2 = 1; } while(0) //LED4
#define LED_100_SetLow()             do { LATCbits.LATC2 = 0; } while(0)



//#define MSP_EN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
//#define MSP_EN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)

typedef enum{

    battery_20,
	battery_40,  //
	battery_60,
	battery_80,
	battery_100,
	battery_full

}battery_id;
	
void DisplayBattery_Power_Estimate(void);
void LowVoltageAlarm(void);


#endif 