#include "headlamp.h"
#include "tmr2.h"


static uint8_t currLamp;
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
        lamp_t.pwmDuty =399;
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_OFF();
		FAN_OFF_FUN();
		ICXL6006_DISABLE() ;
        TMR2_Stop();//TMR2_StartTimer();
		PWM3_LoadDutyValue(0x0);
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

    static uint8_t inputKey_red=0xff,inputKey_green=0xff,inputKey_blue=0xff,inputKey_white=0xff;
	uint8_t lock=0,lock_k=0;
	switch(keyvalue){
       case 0:

	     if(!keyvalue)
		  	return ;
		  
		
	   break;
   
	   case 0x1: //KEY_RED
         
		  if(inputKey_red !=lamp_t.lampColor && lock_k!=2){
			   lamp_t.lampColor = 0x01;
			   inputKey_red = lamp_t.lampColor;
		       lock =1;
			}
			else if(lock !=1) {
				TX1REG = 0x01;
				lamp_t.lampColor=0;
				lamp_t.zeroflag=0;
				lock_k=2;
			}
   
	   break;
   
	   case 0x02: //KEY_GREEN
	     
		  if(inputKey_green !=lamp_t.lampColor && lock_k!=2){
			  lamp_t.lampColor = 0x02;
			  inputKey_green = lamp_t.lampColor;
		          lock =1;
		   }
		 else if(lock !=1) {
			    TX1REG = 0x02;
		  	    lamp_t.lampColor=0;
				lamp_t.zeroflag=0;
				lock_k=2;
		  	}
   
	   break;
   
	   case 0x04://KEY_BLUE
	     
		  if(inputKey_blue != lamp_t.lampColor && lock_k!=2){
		  	lamp_t.lampColor = 0x04;
			inputKey_blue = lamp_t.lampColor;
			   lock =1;
		  }
		  else if(lock !=1) {
			  TX1REG = 0x04;
		  	  lamp_t.lampColor=0;
			  lamp_t.zeroflag=0;
			  lock_k=2;
			
		  	}
   
	   break;
   
	   case 0x08://KEY_WHITE
		   if(inputKey_white !=lamp_t.lampColor && lock_k!=2 ){
                 lamp_t.lampColor = 0x08;
				inputKey_white = lamp_t.lampColor;
			 	   lock =1;
		   }
		   else if(lock !=1) {
			   TX1REG = 0x08;
		   	   lamp_t.lampColor=0;
			   lamp_t.zeroflag=0;
			   lock_k=2;
		   	}
   
	   break;
   
   
	   case 0x10: //KEY_ADD "+"
          TX1REG = 0x10;
	      lamp_t.lampColor = 0x10;
   
	   break;
   
	   case 0x20: //KEY_SUB "-"
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
	            FAN_OFF_FUN();
				ICXL6006_DISABLE() ;
				TMR2_Stop();//TMR2_StartTimer();
				LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
				TX1REG = 0xff;
				lamp_t.zeroflag=1;
				lamp_t.lampColor=0;
				
	break;

    case 0x01: //KEY_RED
        lamp_t.lampWhichColor_ON_flag = Red;
		lamp_t.zeroflag=2;
		TMR2_Stop();//TMR2_StartTimer();
        LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_ON();
		FAN_ON_FUN();

		
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		ICXL6006_ENABLE() ;
	//	TX1REG = 0xa1;
		
	break;

	case 0x02: //KEY_GREEN
	    lamp_t.lampWhichColor_ON_flag = Green;
		lamp_t.zeroflag=2;
		PWM3_LoadDutyValue(0x0);
        LAMP_RED_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		 LAMP_GREEN_ON();
		 FAN_ON_FUN();
		 TMR2_StartTimer();
         PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		 ICXL6006_ENABLE() ;
		// TX1REG = 0xa2;

	break;

	case 0x04://KEY_BLUE
	    lamp_t.lampWhichColor_ON_flag = Blue;
		lamp_t.zeroflag=2;
		PWM3_LoadDutyValue(0x0);
	    LAMP_GREEN_OFF();
		LAMP_RED_OFF();
	    LAMP_WHITE_OFF();

		LAMP_BLUE_ON();
			FAN_ON_FUN();
		
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		ICXL6006_ENABLE() ;
		//TX1REG = 0xa4;

	break;

	case 0x08://KEY_WHITE
	    lamp_t.lampWhichColor_ON_flag = White;
		lamp_t.zeroflag=2;
		PWM3_LoadDutyValue(0x0);
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
    	LAMP_RED_OFF();
		
		LAMP_WHITE_ON();
		FAN_ON_FUN();
		
		TMR2_StartTimer();
        PWM3_LoadDutyValue(lamp_t.pwmDuty); //PWM cycle duty =50%
		ICXL6006_ENABLE() ;
       // TX1REG = 0xa8;

	break;


	case 0x10: //KEY_ADD "+"
	       if(lamp_t.zeroflag==2){
			FAN_OFF_FUN();

				if(lamp_t.pwmDuty >DUTY_MAX_LEVE) 
					lamp_t.pwmDuty= DUTY_MAX_LEVE;
				else lamp_t.pwmDuty =lamp_t.pwmDuty + STEPNUMBERS;

			PWM3_LoadDutyValue(lamp_t.pwmDuty);
		   
		   TX1REG = 0x1a;
		   }

	break;

	case 0x20: //KEY_SUB "-"
         
		 if(lamp_t.zeroflag==2){
	      FAN_OFF_FUN();
		  if(lamp_t.pwmDuty < DUTY_MIN_LEVEL ) 
		   		lamp_t.pwmDuty= DUTY_MIN_LEVEL ;
		  else lamp_t.pwmDuty = lamp_t.pwmDuty - STEPNUMBERS;

		  PWM3_LoadDutyValue(lamp_t.pwmDuty);
		 TX1REG = 0x2a;
		 }

	break;

	default:
    

	break;

   }

}





