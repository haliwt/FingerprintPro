#ifndef __HEADLAMP_H
#define __HEADLAMP_H

#include "pin_manager.h"
#include "key.h"
#include "pwm3.h"

//#define IO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
//#define IO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)

#define LAMP_RED_ON() 				  do { LATAbits.LATA6 = 0; } while(0)
#define LAMP_RED_OFF()  				  do { LATAbits.LATA6 = 1; } while(0)   

#define LAMP_GREEN_ON() 				  do { LATAbits.LATA7 = 0; } while(0)
#define LAMP_GREEN_OFF()  			  do { LATAbits.LATA7 = 1; } while(0)

#define LAMP_BLUE_ON() 				  do { LATBbits.LATB3 = 0; } while(0)
#define LAMP_BLUE_OFF()  				  do { LATBbits.LATB3 = 1; } while(0) 

#define LAMP_WHITE_ON() 				  do { LATBbits.LATB4 = 0; } while(0)
#define LAMP_WHITE_OFF()  			  do { LATBbits.LATB4 = 1; } while(0) 

#define DUTY_MAX_LEVE                 799
#define DUTY_MIN_LEVEL                199
#define DUTY_STEP_LEVEL               20

typedef struct {

   uint8_t lampColor;
   uint8_t lampRed_flag;
   uint8_t lampGreen_flag;
   uint8_t lampBlue_flag;
   uint8_t lampWhite_flag;
   uint8_t lampLight_flag; //0x01 add sub is 0x20;
   
   
}LAMP_T;

LAMP_T lamp_t;

void checkMode(uint8_t value);
void checkRun(void);




#endif 