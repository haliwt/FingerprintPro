#ifndef __HEADLAMP_H
#define __HEADLAMP_H

#include "mcc.h"

#define LAMP_BLUE_OFF() 				    do { LATAbits.LATA3 = 0; } while(0)
#define LAMP_BLUE_ON()  			        do { LATAbits.LATA3 = 1; } while(0) //EDIT WHITE->BLUE


#define LAMP_WHITE_OFF() 				  do { LATAbits.LATA4 = 0; } while(0)   //
#define LAMP_WHITE_ON()  				  do { LATAbits.LATA4 = 1; } while(0)  //EDIT RED->WHITE

#define LAMP_RED_OFF() 				         do { LATAbits.LATA6 = 0; } while(0)
#define LAMP_RED_ON()  			            do { LATAbits.LATA6 = 1; } while(0)      //EDIT GREEN->RED

#define LAMP_GREEN_OFF() 				  do { LATAbits.LATA7 = 0; } while(0)
#define LAMP_GREEN_ON()  				  do { LATAbits.LATA7 = 1; } while(0) //EDIT BLUE->GREEN



    

#define DUTY_MAX_LEVE                (128-1)  //50KHz //79  //50%
#define DUTY_MIN_LEVEL                10
#define DUTY_STEP_LEVEL               10



typedef struct {

   uint8_t lampColor;
   uint8_t lampWhichColor_ON_flag;
   uint8_t zeroflag;
   uint8_t lampPWM_adj;
   uint8_t lampPWM_ON;
   uint8_t getMinutes15_flag;
   uint8_t gbatteryLifePercent;
   uint8_t Power_On;
   uint8_t switch_dev;
   uint16_t pwmDuty;
   
   
   
}LAMP_T;

LAMP_T lamp_t;

typedef enum{

    noColor,
	Red,
	Green,
	Blue,
	White

}Color;

void checkMode(uint8_t value);
void checkRun(void);

void LAMP_Init_Value(void);
void LAMP_ShutOff(void);
void PowerOff_Fun(void);
void LowVotalge_Detected(void);
void FAN_ON_FUN(void);
void FAN_OFF_FUN(void);
void BatteryCharing_Power_Estimate(void);
void BatteryWorks_Power_Estimate(void);
#endif 