#include "headlamp.h"

//LAMP_T lamp_t;

static void KEY_ADDandSUB_Function(void);
static void WhichColor_ON(void);

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

    static uint8_t inputKey_red,inputKey_green,inputKey_blue,inputKey_white;
	switch(keyvalue){

     
      case 0:
	  	   lamp_t.lampColor=0;
	       lamp_t.lampWhichColor_ON_flag=noColor;
		 
		 
	   break;
   
	   case 0x1: //KEY_RED
	        inputKey_red = inputKey_red ^ 0x01;
			if(inputKey_red ==1){
		        lamp_t.lampColor = 0x01;
				inputKey_blue =0;
			    inputKey_green=0;
				inputKey_white=0;
			}
			else 
				lamp_t.lampColor=0;
   
	   break;
   
	   case 0x02: //KEY_GREEN
	      inputKey_green = inputKey_green ^ 0x01;
		  if(inputKey_green ==1){
		       lamp_t.lampColor = 0x02;
			  inputKey_red=0;
	          inputKey_blue =0;
			  inputKey_white=0;
		  }
		  else
		  	 lamp_t.lampColor=0;
   
	   break;
   
	   case 0x04://KEY_BLUE
	      inputKey_blue = inputKey_blue ^ 0X01;
		  if(inputKey_blue ==1){
		  	lamp_t.lampColor = 0x04;
			 inputKey_red=0;
	         inputKey_green =0;
			 inputKey_white=0;
		  }
		  else
		  	 lamp_t.lampColor=0;
   
	   break;
   
	   case 0x08://KEY_WHITE
	       inputKey_white = inputKey_white ^ 0x01;
		   if(inputKey_white==1){
		        lamp_t.lampColor = 0x08;
			 	inputKey_red=0;
             	inputKey_blue =0;
		  		inputKey_green=0;
		   }
		   else
		   	 lamp_t.lampColor=0;
   
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
		
		lamp_t.lampWhichColor_ON_flag = noColor;
    break;

    case 0x01: //KEY_RED
        lamp_t.lampWhichColor_ON_flag = Red;
        LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_ON();
		
	break;

	case 0x02: //KEY_GREEN
	    lamp_t.lampWhichColor_ON_flag = Green;
        LAMP_RED_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		 LAMP_GREEN_ON();
		

	break;

	case 0x04://KEY_BLUE
	    lamp_t.lampWhichColor_ON_flag = Blue;
	    LAMP_GREEN_OFF();
		LAMP_RED_OFF();
	    LAMP_WHITE_OFF();

		LAMP_BLUE_ON();
		

	break;

	case 0x08://KEY_WHITE
	    lamp_t.lampWhichColor_ON_flag = White;
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
    	LAMP_RED_OFF();
		
		LAMP_WHITE_ON();
		
        

	break;


	case 0x10: //KEY_ADD "+"
	     
	     
		   KEY_ADDandSUB_Function();
		   WhichColor_ON();
		  

	break;

	case 0x20: //KEY_SUB "-"
         
		  KEY_ADDandSUB_Function();
		  WhichColor_ON();

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
	 if(lamp_t.lampColor == 0x10 ){//"+"
	 	
	 	 tempDuty += DUTY_STEP_LEVEL;
		 if(tempDuty >=DUTY_MAX_LEVE)tempDuty = DUTY_MAX_LEVE;
		 
         PWM3_LoadDutyValue(tempDuty);


    }

	if(lamp_t.lampColor == 0x20){  //"-"

		 if(tempDuty < DUTY_MIN_LEVEL){
		 	
		 	  tempDuty = DUTY_MIN_LEVEL;
		 }
		 else{
			  tempDuty -=DUTY_STEP_LEVEL;
		 }

        PWM3_LoadDutyValue(tempDuty);
    }
	
}

/***************************************************************************************
	*
	*Function Name:static void WhichColor_ON(void)
	*
	*
	*
	*
***************************************************************************************/
static void WhichColor_ON(void)
{
	switch(lamp_t.lampWhichColor_ON_flag){

	case noColor:
        LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_OFF();


	break;

	case Red:

			LAMP_RED_ON();
    break;

	case Green:
			 LAMP_GREEN_ON();
	break;

	case Blue:
			LAMP_BLUE_ON();

	break;


	case White:
		   LAMP_WHITE_ON();

	break;

	default:

	break;

    }


}


