#include "headlamp.h"

//LAMP_T lamp_t;

static void KEY_ADDandSUB_Function(void);


/**************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
void checkMode(uint8_t keyvalue)
{
    switch(keyvalue){

     
      case 0:
	  	   lamp_t.lampColor=0;
		   lamp_t.lampBlue_flag =0;
	       lamp_t.lampRed_flag=0;
   		   lamp_t.lampGreen_flag=0;
		   lamp_t.lampWhite_flag=0;
		   lamp_t.lampLight_flag=0;
		 
	   break;
   
	   case 0x1: //KEY_RED
		     
   		   lamp_t.lampColor = 0x01;
   
	   break;
   
	   case 0x02: //KEY_GREEN
		  lamp_t.lampColor = 0x02;
   
	   break;
   
	   case 0x04://KEY_BLUE
		  lamp_t.lampColor = 0x04;
   
	   break;
   
	   case 0x08://KEY_WHITE
		   lamp_t.lampColor = 0x08;
   
	   break;
   
   
	   case 0x10: //KEY_ADD "+"

	      lamp_t.lampColor = 0x10;
   
	   break;
   
	   case 0x20: //KEY_SUB "-"
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


	case 0:
		
	    LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_OFF();
		
    break;

    case 0x01: //KEY_RED
        LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_ON();
		lamp_t.lampRed_flag =1;


	break;

	case 0x02: //KEY_GREEN
        LAMP_RED_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		 LAMP_GREEN_ON();
		 lamp_t.lampGreen_flag=1;

	break;

	case 0x04://KEY_BLUE
	    LAMP_GREEN_OFF();
		LAMP_RED_OFF();
	    LAMP_WHITE_OFF();

		LAMP_BLUE_ON();
		lamp_t.lampBlue_flag=1;

	break;

	case 0x08://KEY_WHITE
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
    	LAMP_RED_OFF();
		
		LAMP_WHITE_ON();
		lamp_t.lampWhite_flag=1;

	break;


	case 0x10: //KEY_ADD "+"
	       lamp_t.lampLight_flag=0x01;
		   KEY_ADDandSUB_Function();
		  

	break;

	case 0x20: //KEY_SUB "-"
          lamp_t.lampLight_flag=0x10;
		  KEY_ADDandSUB_Function();
		

	break;

	default:
       lamp_t.lampColor =0;

	break;

   }

}

/**************************************************************
	*
	*Function Name:static void KEY_ADDandSUB_Function(void)
	*Function: 
	*Input Ref:
	*Return Ref:NO
	*
**************************************************************/
static void KEY_ADDandSUB_Function(void)
{
     static uint16_t tempDuty;
	 if(lamp_t.lampLight_flag==0x01){//"+"
	 	
	 	 tempDuty += DUTY_STEP_LEVEL;
		 if(tempDuty >=DUTY_MAX_LEVE)tempDuty = DUTY_MAX_LEVE;
		 
         PWM3_LoadDutyValue(tempDuty);


    }

	if(lamp_t.lampLight_flag = 0x10){  //"-"

		 if(tempDuty < DUTY_MIN_LEVEL){
		 	
		 	  tempDuty = DUTY_MIN_LEVEL;
		 }
		 else{
			  tempDuty -=DUTY_STEP_LEVEL;
		 }

        PWM3_LoadDutyValue(tempDuty);
    }
	




}

