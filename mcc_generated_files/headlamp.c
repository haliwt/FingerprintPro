#include "headlamp.h"
#include "tmr2.h"
#include "delay.h"
#include "tmr0.h"
#include "led.h"

static uint8_t currLamp;
static void PWM_DUTY_ADJ(void);
/***************************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: The first input LED ON,the second input key LED OFF
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
****************************************************************************/
void LAMP_Init_Value(void)
{
        lamp_t.pwmDuty =29;
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_OFF();
		FAN_OFF_FUN();
		ICXL6006_DISABLE() ;
        TMR2_Stop();//TMR2_StartTimer();
		PWM3_LoadDutyValue(0x0);
        lamp_t.Power_On=1;
}
/***************************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: The first input LED ON,the second input key LED OFF
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
****************************************************************************/
void checkMode(uint8_t keyvalue)
{
	static uint16_t i=0;
    static uint8_t inputKey_red=0xff,inputKey_green=0xff,inputKey_blue=0xff,inputKey_white=0xff,powerflag=0;
	uint8_t lock=0,lock_k=0,lock2=0,lock3=0,lock4=0,lock5=0,lock6=0;
	switch(keyvalue){
       case 0:

	     if(!keyvalue)
		  	return ;
		  
		
	   break;
	   
	   case 0x40: //POWER ON and off
	       powerflag = powerflag ^ 0x01;
	       if(powerflag ==1){
			   
	            lamp_t.Power_On=1;
				lock6=1;
				MSP_EN_SetLow() ;
				i++;
			   
		   }
		   else if(lock6 !=1 ){
		            lamp_t.lampColor = 0x80;
					lamp_t.Power_On=0;
					lamp_t.switch_dev=0;
					MSP_EN_SetHigh() ;
					
			}
		   
				
			 
		break;
   
	   case 0x1: //KEY_WHITE
         
		  if(inputKey_white !=lamp_t.lampColor && lock_k!=2 && lamp_t.lampPWM_ON !=Red){
			   lamp_t.lampColor = 0x01;
			   inputKey_white = lamp_t.lampColor;
		       lock =1;
			    ICXL6006_DISABLE() ;
			    LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
				TMR2_Stop();//TMR2_StartTimer();
				FAN_OFF_FUN();
				tim0_t.tim0_FunStart_flag=0;
				tim0_t.tim0_fun_30s=0;
				DELAY_microseconds(500) ;
			    
				
			}
			else if(lock !=1) {
				TX1REG = 0x01;
				 lamp_t.lampColor=0;
				lamp_t.zeroflag=0;
				lock_k=2;
				lamp_t.lampPWM_ON=0;
				
			}
   
	   break;
   
	   case 0x02: //KEY_GREEN
	     
		  if(inputKey_blue !=lamp_t.lampColor && lock_k!=2 && lamp_t.lampPWM_ON !=Green){
			  lamp_t.lampColor = 0x02;
			  inputKey_blue = lamp_t.lampColor;
		        lock2 =1;
				ICXL6006_DISABLE() ;
				LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
				TMR2_Stop();//TMR2_StartTimer();
				FAN_OFF_FUN();
				tim0_t.tim0_FunStart_flag=0;
				tim0_t.tim0_fun_30s=0;
				DELAY_microseconds(500) ;
			 
		 }
		 else if(lock2 !=1) {
			    TX1REG = 0x02;
		  	   lamp_t.lampColor=0;
				lamp_t.zeroflag=0;
				lock_k=2;
				lamp_t.lampPWM_ON=0;
		  	}
   
	   break;
   
	   case 0x04://KEY_BLUE
	     
		  if(inputKey_green != lamp_t.lampColor && lock_k!=2 && lamp_t.lampPWM_ON !=Blue){
		  	lamp_t.lampColor = 0x04;
			inputKey_green = lamp_t.lampColor;
			   lock3 =1;
                ICXL6006_DISABLE() ;
			   	LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
				TMR2_Stop();//TMR2_StartTimer();
				FAN_OFF_FUN();
				tim0_t.tim0_FunStart_flag=0;
				tim0_t.tim0_fun_30s=0;
				DELAY_microseconds(500) ;
			}
		  else if(lock3 !=1) {
			  TX1REG = 0x04;
		  	  lamp_t.lampColor=0;
			  lamp_t.zeroflag=0;
			  lock_k=2;
			  lamp_t.lampPWM_ON=0;
			
		  	}
   
	   break;
   
	   case 0x08://KEY_RED
		   if(inputKey_red !=lamp_t.lampColor && lock_k!=2 && lamp_t.lampPWM_ON !=White){
                 lamp_t.lampColor = 0x08;
				inputKey_red = lamp_t.lampColor;
			 	   lock4 =1;
				ICXL6006_DISABLE() ;
				LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
				TMR2_Stop();//TMR2_StartTimer();
				FAN_OFF_FUN();
				tim0_t.tim0_FunStart_flag=0;
				tim0_t.tim0_fun_30s=0;
				DELAY_microseconds(500) ;
		   }
		   else if(lock4 !=1) {
			   TX1REG = 0x08;
		   	  lamp_t.lampColor=0;
			   lamp_t.zeroflag=0;
			   lock_k=2;
			   lamp_t.lampPWM_ON=0;
		   	}
   
	   break;
   
   
	   case 0x10: //KEY_ADD "-"
          TX1REG = 0x10;
	      lamp_t.lampColor = 0x10;
   
	   break;
   
	   case 0x20: //KEY_SUB "+"
	      TX1REG = 0x20;
          lamp_t.lampColor = 0x20;
   
	   break;
   
	   default:
   
   				
	   break;
   }
}
/**************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
void checkRun(void)
{

	switch(lamp_t.lampColor){
	case 0: //turn off lamp 
		ICXL6006_DISABLE() ;
		TMR2_Stop();//TMR2_StartTimer();
		lamp_t.lampWhichColor_ON_flag=noColor;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();

		TX1REG = 0xff;
		lamp_t.zeroflag=1;
		lamp_t.lampColor=0;
		lamp_t.lampPWM_ON=0;
		lamp_t.lampPWM_adj=0;
		DELAY_microseconds(500) ;
		tim0_t.tim0_FunStart_flag=1;
	    if(tim0_t.tim0_fun_30s>29 && tim0_t.tim0_fun_30s <31 ){
               FAN_OFF_FUN();
		}
			
	break;

    case 0x01: //KEY_WHITE
        
	
	//	TX1REG = 0xa1;
	
	     lamp_t.lampWhichColor_ON_flag = White;
		lamp_t.zeroflag=2;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_RED_OFF();

		LAMP_WHITE_ON();
		FAN_ON_FUN();
		ICXL6006_ENABLE() ;
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
       // TX1REG = 0xa8;
		
	break;

	case 0x02: //KEY_GREEN
	    lamp_t.lampWhichColor_ON_flag = Green;
		lamp_t.zeroflag=2;
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();
	

		 LAMP_GREEN_ON();
		 FAN_ON_FUN();

		 ICXL6006_ENABLE() ;
		 TMR2_StartTimer();
         PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		// TX1REG = 0xa2;

	break;

	case 0x04://KEY_BLUE
	    lamp_t.lampWhichColor_ON_flag = Blue;
		lamp_t.zeroflag=2;
		LAMP_GREEN_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();

		LAMP_BLUE_ON();
		FAN_ON_FUN();
		ICXL6006_ENABLE() ;
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		//TX1REG = 0xa4;

	break;

	case 0x08://KEY_RED
	   
       // TX1REG = 0xa8;
	    lamp_t.lampWhichColor_ON_flag = Red;
		lamp_t.zeroflag=2;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		
		
		LAMP_RED_ON();
		FAN_ON_FUN();

		ICXL6006_ENABLE() ;
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%

	break;


	case 0x20: //KEY_ADD "+"
	       if(lamp_t.zeroflag==2){
			FAN_OFF_FUN();

				if(lamp_t.pwmDuty >DUTY_MAX_LEVE) 
					lamp_t.pwmDuty= DUTY_MAX_LEVE;
				else lamp_t.pwmDuty =lamp_t.pwmDuty + DUTY_STEP_LEVEL ;

			 PWM3_LoadDutyValue(lamp_t.pwmDuty);
			 
			 lamp_t.lampColor= 0x40;
			 lamp_t.lampPWM_adj = lamp_t.lampWhichColor_ON_flag;
		
		   TX1REG = 0x1a;
		   }

	break;

	case 0x10: //KEY_SUB "-"
         
		 if(lamp_t.zeroflag==2){
	      FAN_OFF_FUN();
		  if(lamp_t.pwmDuty < DUTY_MIN_LEVEL ) 
		   		lamp_t.pwmDuty= DUTY_MIN_LEVEL ;
		  else lamp_t.pwmDuty = lamp_t.pwmDuty - DUTY_STEP_LEVEL ;
   
		  PWM3_LoadDutyValue(lamp_t.pwmDuty);
		  lamp_t.lampColor= 0x40;
		   lamp_t.lampPWM_adj = lamp_t.lampWhichColor_ON_flag;
		  
		 TX1REG = 0x2a;
		 }
	break;
	
	case 0x40:
	     PWM_DUTY_ADJ();
	break;
	
	case 0x80:
			 MSP_EN_SetHigh() ;
	break;
	
    default:
    

	break;

   }

}
/**************************************************************
	*
	*Function Name:void LAMP_ShutOff(void)
	*Function: 
	*Input Ref:NO
	*Return Ref:NO
	*
**************************************************************/
void LAMP_ShutOff(void)
{
		ICXL6006_DISABLE() ;
		TMR2_Stop();//TMR2_StartTimer();
		lamp_t.lampWhichColor_ON_flag=noColor;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();

		lamp_t.zeroflag=0;
		lamp_t.lampColor= 0xfe;
		lamp_t.lampPWM_ON=0;
		lamp_t.lampPWM_adj=0;
		DELAY_microseconds(500) ;
		FAN_OFF_FUN();	
}
/**************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
static void PWM_DUTY_ADJ(void)
{
	
        switch(lamp_t.lampPWM_adj){
			
			case White:
			     lamp_t.lampPWM_ON=White;
				LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_RED_OFF();
				
				LAMP_WHITE_ON();
				FAN_ON_FUN();
				//TMR2_StartTimer();
				PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
				//ICXL6006_ENABLE() ;
			
			break;
			
			case Blue:
			     lamp_t.lampPWM_ON=Blue;
				LAMP_RED_OFF();
				LAMP_WHITE_OFF();
				LAMP_GREEN_OFF();
				
				 LAMP_BLUE_ON();
				FAN_ON_FUN();
				//TMR2_StartTimer();
				PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
				//ICXL6006_ENABLE() ;
			
			break;
			
			case Green:
				lamp_t.lampPWM_ON=Green;
				LAMP_RED_OFF();
				LAMP_WHITE_OFF();
				LAMP_BLUE_OFF();

				LAMP_GREEN_ON();
				FAN_ON_FUN();
				//TMR2_StartTimer();
				PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
				//ICXL6006_ENABLE() ;
			
			break;
			
			case Red:
			lamp_t.lampPWM_ON=Red;
			LAMP_GREEN_OFF();
			LAMP_BLUE_OFF();
			LAMP_WHITE_OFF();

			LAMP_RED_ON();
			FAN_ON_FUN();
			
			//TMR2_StartTimer();
			PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
			//ICXL6006_ENABLE() ;
			
			break;
			
	
}
}



void PowerOff_Fun(void)
{
	LAMP_Init_Value();
	LAMP_ShutOff();
	LED_40_SetHigh() ;
	LED_60_SetHigh();
	LED_80_SetHigh() ;
	LED_100_SetHigh();
}

