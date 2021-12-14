#include "headlamp.h"
#include "tmr2.h"
#include "delay.h"
#include "tmr0.h"
#include "../mcc_generated_files/mcc.h"
LAMP_T lamp_t;
uint8_t pwmDutyArray[4];


static void ADJ_LampBrightnessADD(void);
static void ADJ_LampBrightnessSUB(void);
static void setLevel_RED_PWM(uint8_t level);
static void setLevel_BLUE_PWM(uint8_t level);

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
        lamp_t.pwmDuty =95;  //50%
		lamp_t.red_pwmDuty=47;
		lamp_t.green_pwmDuty=95;
		lamp_t.blue_pwmDuty=95;
		lamp_t.white_pwmDuty=95;
		LAMP_GREEN_OFF();
	    LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();

		LAMP_RED_OFF();
		FAN_OFF_FUN();
        TMR2_StartTimer();
		PWM3_LoadDutyValue(0); //100% ->NPN ->0
        lamp_t.Power_On=1;
		TMR0_StartTimer();
      //  TMR2_StopTimer();
}
/**************************************************************
	*
	*Function Name:void CheckMode(uint8_t value)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
void CheckRun(void)
{
    
	switch(lamp_t.lampColor){

	  if(lamp_t.lampColor ==0)return;
	  
	case 0x3f: //turn off lamp 

		lamp_t.lampWhichColor_ON_flag=noColor;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();

		// TMR2_StopTimer();
		 PWM3_LoadDutyValue(0); //100% -> NPN -> 0
		lamp_t.zeroflag=1;
		lamp_t.lampColor=0;
		lamp_t.lampPWM_ON=0;
		lamp_t.lampPWM_adj=0;
		
	    if(tim0_t.tim0_fun_30s > 30 ){
               FAN_OFF_FUN();
               lamp_t.gFAN_flag=0;
		}
			
	break;

	  case 0xff:
       FUN_15MinutesTurnOff();      

	  break;

      case 0x04: //"White" --OK
        
	   tim0_t.tim0_fun_30s=0;
	    lamp_t.lampWhichColor_ON_flag = White;
		lamp_t.zeroflag=2;
	   lamp_t.white_pwmDuty=111;
			
		PWM3_LoadDutyValue(lamp_t.white_pwmDuty); //PWM cycle duty =50%	
			   
			LAMP_WHITE_ON();	
		
		DELAY_microseconds(200);
         lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		
     
		
	break;

	 case 0x02:  //"Green"   ---OK
	 	tim0_t.tim0_fun_30s=0;
	    lamp_t.lampWhichColor_ON_flag = Green;
		lamp_t.zeroflag=2;
	 
		 lamp_t.green_pwmDuty=111;
			
	      PWM3_LoadDutyValue(lamp_t.green_pwmDuty); //PWM cycle duty =50%
	    	
		 LAMP_GREEN_ON();
		
		  DELAY_microseconds(200);
          lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		 
		break;

	case 0x01: // "Red"

         LAMP_BLUE_OFF();
		LAMP_GREEN_OFF();
		LAMP_WHITE_OFF();
	     tim0_t.tim0_fun_30s=0;
	    lamp_t.lampWhichColor_ON_flag = Red;
		lamp_t.zeroflag=2;
	    lamp_t.lampPWM_ON=Red;
        
         lamp_t.red_pwmDuty=47;
			
		PWM3_LoadDutyValue(lamp_t.red_pwmDuty); //PWM cycle duty =50%	
           LAMP_RED_ON();
           
            DELAY_microseconds(200);
            lamp_t.gFAN_flag=1;//FAN_ON_FUN();
       
		   break;

	 case 0x03: // "BLUE"
	   
      
	    lamp_t.lampWhichColor_ON_flag = Blue;
		lamp_t.zeroflag=2;
	    lamp_t.lampPWM_ON=Blue;
		lamp_t.blue_pwmDuty=111;
        PWM3_LoadDutyValue(lamp_t.blue_pwmDuty); //PWM cycle duty =50%

		LAMP_BLUE_ON();
	
		//DELAY_microseconds(200);
          
		  tim0_t.tim0_fun_30s=0;
           DELAY_microseconds(200);
	       lamp_t.gFAN_flag=1;//FAN_ON_FUN();
      break;
  

	case 0x20: //KEY_ADD "+"
	       if(lamp_t.zeroflag==2){//in process LED on status 
				FAN_OFF_FUN();
				ADJ_LampBrightnessADD();
		     
		       DELAY_microseconds(200);
                   lamp_t.gFAN_flag=1;//FAN_ON_FUN();
				tim0_t.tim0_fun_30s=0;
             
		   }
		  

	break;

	case 0x10: //KEY_SUB "-"
         
		 if(lamp_t.zeroflag==2){ //in process LED on status 
	    	FAN_OFF_FUN();
			ADJ_LampBrightnessSUB();
	
		   // DELAY_microseconds(200);
                lamp_t.gFAN_flag=1;//FAN_ON_FUN();
                tim0_t.tim0_fun_30s=0;
      
		 }
		 
	break;
    
    default:
    

	break;

   }

}

/**************************************************************
	*
	*Function Name:static void ADJ_LampBrightnessADD(void)
	*Function: 
	*Input Ref:NO
	*Return Ref:NO
	*
**************************************************************/
static void ADJ_LampBrightnessADD(void)
{
	 static uint8_t level_r,level_b;
	  switch(lamp_t.lampWhichColor_ON_flag){

	     case 0x01://Color -Red

#if 1	    
                LAMP_BLUE_OFF();
			    LAMP_GREEN_OFF();
				LAMP_WHITE_OFF();
                if(lamp_t.red_pwmDuty > RED_DUTY_MAX_LEVEL) 
					lamp_t.red_pwmDuty=RED_DUTY_MAX_LEVEL;
				else lamp_t.red_pwmDuty =lamp_t.red_pwmDuty + DUTY_STEP_LEVEL ;
				
				if(lamp_t.red_pwmDuty > RED_DUTY_MAX_LEVEL) lamp_t.red_pwmDuty= RED_DUTY_MAX_LEVEL;
				
			     PWM3_LoadDutyValue(lamp_t.red_pwmDuty);
                  LAMP_RED_ON();
                  DELAY_microseconds(200);
	               lamp_t.gFAN_flag=1;//FAN_ON_FUN();
             
	         
#endif 
	     break;

		 case 0x02: //--OK
		 		LAMP_BLUE_OFF();
			    LAMP_RED_OFF();
				LAMP_WHITE_OFF();
		 	  if(lamp_t.green_pwmDuty > GREEN_DUTY_MAX_LEVEL) 
					lamp_t.green_pwmDuty=GREEN_DUTY_MAX_LEVEL;
				else lamp_t.green_pwmDuty =lamp_t.green_pwmDuty + DUTY_STEP_LEVEL ;
				
				if(lamp_t.green_pwmDuty > GREEN_DUTY_MAX_LEVEL) lamp_t.green_pwmDuty= GREEN_DUTY_MAX_LEVEL;
				 pwmDutyArray[1] = lamp_t.green_pwmDuty ;
				
			    PWM3_LoadDutyValue(lamp_t.green_pwmDuty);

			  LAMP_GREEN_ON();
                  DELAY_microseconds(200);
	       lamp_t.gFAN_flag=1;//FAN_ON_FUN();

		 break;

		 case 0x03: // Color blue
                LAMP_RED_OFF();
			    LAMP_GREEN_OFF();
				LAMP_WHITE_OFF();
		 if(lamp_t.blue_pwmDuty > BLUE_DUTY_MAX_LEVEL) 
					lamp_t.blue_pwmDuty=BLUE_DUTY_MAX_LEVEL;
         else lamp_t.blue_pwmDuty =lamp_t.blue_pwmDuty + DUTY_STEP_LEVEL ;
				
				if(lamp_t.blue_pwmDuty > BLUE_DUTY_MAX_LEVEL) lamp_t.blue_pwmDuty= BLUE_DUTY_MAX_LEVEL;
				
			    PWM3_LoadDutyValue(lamp_t.blue_pwmDuty);
				
			  
                LAMP_BLUE_ON();
		 	   DELAY_microseconds(200);
	           lamp_t.gFAN_flag=1;//FAN_ON_FUN();

		 break;

		 case 0x04://Color White
             	LAMP_BLUE_OFF();
			    LAMP_GREEN_OFF();
				LAMP_RED_OFF();
		 	   
		 	 	 if(lamp_t.white_pwmDuty > GREEN_DUTY_MAX_LEVEL) 
					lamp_t.white_pwmDuty=GREEN_DUTY_MAX_LEVEL;
				else lamp_t.white_pwmDuty =lamp_t.white_pwmDuty + DUTY_STEP_LEVEL ;
				
				if(lamp_t.white_pwmDuty > GREEN_DUTY_MAX_LEVEL) lamp_t.white_pwmDuty= GREEN_DUTY_MAX_LEVEL;
                
			    PWM3_LoadDutyValue(lamp_t.white_pwmDuty);
			
				
				LAMP_WHITE_ON();
				
                  DELAY_microseconds(200);
	              lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		 break;

		 default:

		 break;


	  }


}

/**************************************************************
	*
	*Function Name:static void ADJ_LampBrightnessSUB(void)
	*Function: 
	*Input Ref:NO
	*Return Ref:NO
	*
**************************************************************/
static void ADJ_LampBrightnessSUB(void)
{

     static uint8_t level_r,level_b;
	  switch(lamp_t.lampWhichColor_ON_flag){

	     case Red: //

 #if 1
                LAMP_BLUE_OFF();
			    LAMP_GREEN_OFF();
				LAMP_WHITE_OFF();
               if(lamp_t.red_pwmDuty < RED_DUTY_MIN_LEVEL ) 
		   		  lamp_t.red_pwmDuty= RED_DUTY_MIN_LEVEL ;
               else lamp_t.red_pwmDuty = lamp_t.red_pwmDuty - DUTY_STEP_LEVEL ;
		  
		      if(lamp_t.red_pwmDuty < RED_DUTY_MIN_LEVEL ) lamp_t.red_pwmDuty= RED_DUTY_MIN_LEVEL ;
		  			
                 PWM3_LoadDutyValue(lamp_t.red_pwmDuty);
                
             
               
             LAMP_RED_ON();
              DELAY_microseconds(200);
	              lamp_t.gFAN_flag=1;//FAN_ON_FUN();
             
#endif 		

	     break;

		 case Green: //
               LAMP_BLUE_OFF();
			    LAMP_RED_OFF();
				LAMP_WHITE_OFF();
		 	  if(lamp_t.green_pwmDuty < GREEN_DUTY_MIN_LEVEL ) 
		   		  lamp_t.green_pwmDuty= GREEN_DUTY_MIN_LEVEL ;
		      else lamp_t.green_pwmDuty = lamp_t.green_pwmDuty - DUTY_STEP_LEVEL ;
		  
		      if(lamp_t.green_pwmDuty < GREEN_DUTY_MIN_LEVEL ) lamp_t.green_pwmDuty= GREEN_DUTY_MIN_LEVEL ;
		  			pwmDutyArray[1] = lamp_t.green_pwmDuty ;
                 PWM3_LoadDutyValue(lamp_t.green_pwmDuty);
			  
				
			    LAMP_GREEN_ON();
			  DELAY_microseconds(200);
	              lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		 break;

		 case Blue: //BLUE
             	LAMP_RED_OFF();
			    LAMP_GREEN_OFF();
				LAMP_WHITE_OFF();
		 	 
             if(lamp_t.blue_pwmDuty < BLUE_DUTY_MIN_LEVEL ) 
		   		  lamp_t.blue_pwmDuty= BLUE_DUTY_MIN_LEVEL ;
             else lamp_t.blue_pwmDuty = lamp_t.blue_pwmDuty - DUTY_STEP_LEVEL ;
		  
		      if(lamp_t.blue_pwmDuty < BLUE_DUTY_MIN_LEVEL ) lamp_t.blue_pwmDuty= BLUE_DUTY_MIN_LEVEL ;
		       //  lamp_t.blue_pwmDuty ;
                PWM3_LoadDutyValue(lamp_t.blue_pwmDuty);
			
			  
                LAMP_BLUE_ON();
                     DELAY_microseconds(200);
	              lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		 break;

		 case White://
             LAMP_BLUE_OFF();
			    LAMP_GREEN_OFF();
				LAMP_RED_OFF();
		 	 if(lamp_t.white_pwmDuty < WHITE_DUTY_MIN_LEVEL) 
					lamp_t.white_pwmDuty=WHITE_DUTY_MIN_LEVEL;
				else lamp_t.white_pwmDuty =lamp_t.white_pwmDuty - DUTY_STEP_LEVEL ;
				
				if(lamp_t.white_pwmDuty < WHITE_DUTY_MIN_LEVEL) lamp_t.white_pwmDuty= WHITE_DUTY_MIN_LEVEL;
				
			    PWM3_LoadDutyValue(lamp_t.white_pwmDuty);

				
				
				LAMP_WHITE_ON();
               DELAY_microseconds(200);
	              lamp_t.gFAN_flag=1;//FAN_ON_FUN();
		 break;

		 default:

		 break;


	  }


}

/*************************************************************************
 	*
	*Function Name:static void setLevel_PWMA(uint8_t level)
	*Function : hight voltagle
	*Input Ref: NO
	*Output Ref:No
	*
******************************************************************************/
static void setLevel_RED_PWM(uint8_t level)
{
 
	if(level<LEVEL_MIN)level=LEVEL_MIN;
	
      lamp_t.red_pwmDuty =(level)*LEVEL_PWM_STEP;// level * LEVEL_PWM_STEP;
      
      if(lamp_t.red_pwmDuty< RED_DUTY_MIN_LEVEL)
	  	      lamp_t.red_pwmDuty=RED_DUTY_MIN_LEVEL;
	
    if(lamp_t.red_pwmDuty > RED_DUTY_MAX_LEVEL){
		lamp_t.red_pwmDuty= RED_DUTY_MAX_LEVEL;
    }
	PWM3_LoadDutyValue(lamp_t.red_pwmDuty);
	
	
}

static void setLevel_BLUE_PWM(uint8_t level)
{
	if(level<LEVEL_MIN)level=LEVEL_MIN;
	
      lamp_t.blue_pwmDuty =(level)*LEVEL_PWM_STEP;// level * LEVEL_PWM_STEP;
      
      if(lamp_t.blue_pwmDuty< BLUE_DUTY_MIN_LEVEL)
	  	      lamp_t.blue_pwmDuty=BLUE_DUTY_MIN_LEVEL;
	
    if(lamp_t.blue_pwmDuty > BLUE_DUTY_MAX_LEVEL){
		lamp_t.blue_pwmDuty= BLUE_DUTY_MAX_LEVEL;
    }
	PWM3_LoadDutyValue(lamp_t.blue_pwmDuty);
	
	
}


/**************************************************************
	*
	*Function Name:void FUN_15MinutesTurnOff(void)
	*Function: 
	*Input Ref:key be pressed of value
	*Return Ref:NO
	*
**************************************************************/
void FUN_15MinutesTurnOff(void)
{
		lamp_t.lampWhichColor_ON_flag=noColor;
		LAMP_GREEN_OFF();
		LAMP_BLUE_OFF();
		LAMP_WHITE_OFF();
		LAMP_RED_OFF();

		 TMR2_StopTimer();
		 PWM3_LoadDutyValue(0); //100% -> NPN -> 0
		lamp_t.zeroflag=1;
		lamp_t.lampColor=0;
		lamp_t.lampPWM_ON=0;
		lamp_t.lampPWM_adj=0;
		 FAN_OFF_FUN();
		
       
}
/****************************************************************************
    *
    * Function Name: void FAN_FUN(void)
    * Function :
    * Input Ref:NO
    * Return Ref: key value
    * 
 ****************************************************************************/
void FAN_ON_FUN(void)
{
  if(lamp_t.gFAN_flag==1){
       FAN_EN_SetHigh();//ON
       DELAY_milliseconds(2);
       FAN_EN_SetLow() ; //OFF
       DELAY_milliseconds(2);
    }
    else 
       FAN_EN_SetLow() ; //OFF
}

void FAN_OFF_FUN(void)
{
   FAN_EN_SetLow() ;//FAN_RB5_SetHigh() ;
}
/**************************************************************
	*
	*Function Name:void DispalayBattery_Power(uint8_t)
	*Function: display battery power qunantity
	*
	*
	*
**************************************************************/
void BatteryCharing_Power_Estimate(void)
{
   
   //if(adc_t.adcValue < 36 ){ //half of battery value 37*2=7.4v
	//	EUSART_BatteryCharging_TxData(0x01);//(battery_40);

   //} else if(adc_t.adcValue >=36 && adc_t.adcValue <38){ 
   
    if(adc_t.adcValue <38){ // 39*2=7.8V
	   EUSART_BatteryCharging_TxData(0x02);//(battery_60);

   }
   else if(adc_t.adcValue >=38 && adc_t.adcValue <40){//
		 EUSART_BatteryCharging_TxData(0x03);//(battery_80);

   }
   else if(adc_t.adcValue >=40 && adc_t.adcValue < 42 ){
		 EUSART_BatteryCharging_TxData(0x04);//(battery_90);

   }
   else if(adc_t.adcValue ==42 ){
		 EUSART_BatteryCharging_TxData(0x05);//(battery_90);

   }
   else if(adc_t.adcValue >42){
	    EUSART_BatteryCharging_TxData(0x06); //(battery_100);
	   
   }
}
/**************************************************************
	*
	*Function Name:void DispalayBattery_Power(uint8_t)
	*Function: display battery power qunantity
	*
	*
	*
**************************************************************/
void BatteryWorks_Power_Estimate(void)
{
   
   if(adc_t.adcValue < 36 ){ //half of battery value 37*2=7.4v
		//BatteryWoks_TxData(0x01);//(battery_40);
		EUSART_BatteryWorks_TxData(0x01);

   }
   else if(adc_t.adcValue >=36 && adc_t.adcValue <38){ // 39*2=7.8V
	  // BatteryWoks_TxData(0x02);//(battery_60);
	  EUSART_BatteryWorks_TxData(0x02);

   }
   else if(adc_t.adcValue >=38 && adc_t.adcValue <40){//
		// BatteryWorks_TxData(0x03);//(battery_80);
		EUSART_BatteryWorks_TxData(0x03);

   }
   else if(adc_t.adcValue >=40 && adc_t.adcValue < 42 ){
		// BatteryWorks_TxData(0x04);//(battery_90);
		EUSART_BatteryWorks_TxData(0x04);

   }
   else if(adc_t.adcValue ==42  ){
		// BatteryWorks_TxData(0x04);//(battery_90);
		EUSART_BatteryWorks_TxData(0x05);

   }
   else if(adc_t.adcValue >42  ){
		// BatteryWorks_TxData(0x04);//(battery_100);
		EUSART_BatteryWorks_TxData(0x06);

   }
  
}

