#ifndef __KEY_H
#define __KEY_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"
#include "../c99/bits/alltypes.h"

//#define IO_RA0_GetValue()           PORTAbits.RA0
#define KEY_RED()    				PORTAbits.RA3//PORTAbits.RA0
#define KEY_GREEN()					PORTAbits.RA2//PORTAbits.RA1
#define KEY_BLUE()					PORTAbits.RA1//PORTAbits.RA2
#define KEY_WHITE()					PORTAbits.RA0//PORTAbits.RA3
#define KEY_ADD()					PORTAbits.RA4

#define KEY_SUB()					PORTAbits.RA5
#define KEY_POWER()                 PORTCbits.RC6  //POWER -KEY INPUT-new PCB



//#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
//#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define FAN_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define FAN_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)


uint8_t   KEY_Scan(void);
void FAN_ON_FUN(void);
void FAN_OFF_FUN(void);
#endif 