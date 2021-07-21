#ifndef __LED_H
#define __LED_H
#include "key.h"
#include "adcc.h"
#include "../mcc_generated_files/pin_manager.h"


#define LED1   PORTCbits.RC0
#define LED2   PORTCbits.RC2
#define LED3   PORTCbits.RC4

#define LED_100_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_100_SetLow()             do { LATCbits.LATC0 = 0; } while(0)

#define LED_80_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_80_SetLow()             do { LATCbits.LATC5 = 0; } while(0)

#define LED_60_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_60_SetLow()             do { LATCbits.LATC4 = 0; } while(0)

#define LED_40_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED_40_SetLow()             do { LATBbits.LATB1 = 0; } while(0)

typedef enum{

    battery_20,
	battery_40,
	battery_60,
	battery_80,
	battery_100

}battery_id;
	
void DisplayBattery_Power_Estimate(void);


#endif 