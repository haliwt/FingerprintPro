#ifndef __HEADLAMP_H
#define __HEADLAMP_H

#include "mcc.h"

//#define LAMP_BLUE_OFF() 				    do { LATAbits.LATA3 = 0; } while(0)
//#define LAMP_BLUE_ON()  			        do { LATAbits.LATA3 = 1; } while(0) //EDIT WHITE->BLUE
#define LAMP_WHITE_OFF() 				    do { LATAbits.LATA3 = 0; } while(0)
#define LAMP_WHITE_ON()  			        do { LATAbits.LATA3 = 1; } while(0) //EDIT WHITE->BLUE


#define LAMP_BLUE_OFF() 				  do { LATAbits.LATA4 = 0; } while(0)   //
#define LAMP_BLUE_ON()  				  do { LATAbits.LATA4 = 1; } while(0)  //EDIT RED->WHITE

#define LAMP_RED_OFF() 				         do { LATAbits.LATA6 = 0; } while(0)
#define LAMP_RED_ON()  			            do { LATAbits.LATA6 = 1; } while(0)      //EDIT GREEN->RED

#define LAMP_GREEN_OFF() 				  do { LATAbits.LATA7 = 0; } while(0)
#define LAMP_GREEN_ON()  				  do { LATAbits.LATA7 = 1; } while(0) //EDIT BLUE->GREEN



#define RED_DUTY_MAX_LEVEL                159  //50KHz //79  //80%
#define RED_DUTY_MIN_LEVEL                0     //160*30% =48




#define GREEN_DUTY_MAX_LEVEL               159  //50KHz //70%
#define GREEN_DUTY_MIN_LEVEL               0       //160*20%


#define WHITE_DUTY_MAX_LEVEL               159  //50KHz //60%
#define WHITE_DUTY_MIN_LEVEL              0       //160*40%

#define BLUE_DUTY_MAX_LEVEL               159//50KHz //70%
#define BLUE_DUTY_MIN_LEVEL               0       //160*50%

#define DUTY_STEP_LEVEL                   20

#define LEVEL_DEFAULT	  14
#define LEVEL_MIN		   2//
#define LEVEL_MAX        10
#define LEVEL_ZERO        0
#define LEVEL_STEP		  3 ////WT.EDIT 2021.05.31
#define LEVEL_PWM_STEP   10
#define LEVEL_PWM_MAX	  90//


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
   uint16_t red_pwmDuty;
   uint16_t green_pwmDuty;
   uint16_t blue_pwmDuty;
   uint16_t white_pwmDuty;
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
void FAN_ON_FUN(void);
void FAN_OFF_FUN(void);

#endif 