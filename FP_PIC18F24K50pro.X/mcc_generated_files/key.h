#ifndef __KEY_H
#define __KEY_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"
#include "../c99/bits/alltypes.h"

//#define IO_RA0_GetValue()           PORTAbits.RA0
#define KEY_RED()    				PORTAbits.RA0
#define KEY_GREEN()					PORTAbits.RA1
#define KEY_BLUE()					PORTAbits.RA2
#define KEY_WHITE()					PORTAbits.RA3
#define KEY_ADD()					PORTAbits.RA4
#define KEY_SUB()					PORTAbits.RA5





uint8_t   KEY_Scan(void);

#endif 