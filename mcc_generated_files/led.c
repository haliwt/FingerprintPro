#include "led.h"
#include "adcc.h"
#include "tmr0.h"
#include "pin_manager.h"
#include "headlamp.h"

static void LEDDispalayBattery_Power(battery_id batid);
/**************************************************************
	*
	*Function Name:void LowVoltageAlarm(void)
	*Function: battery low votlage alarm
	*
	*
	*
**************************************************************/
void LowVoltageAlarm(void)
{
	if(tim0_t.tim0_lowVoltage_flag>120){
		if(tim0_t.tim0_falg >49){
						LED_40_SetHigh() ;
						LED_60_SetHigh();
						LED_80_SetHigh();
						LED_100_SetHigh();
						if(tim0_t.tim0_falg >99)
							tim0_t.tim0_falg = 0;
					}
					else{
						LED_100_SetLow() ;
						LED_40_SetLow();
						LED_60_SetLow();
						LED_80_SetLow();
			
					}
	}
	else{
		tim0_t.tim0_lowVoltage_flag = 125;
		LAMP_ShutOff();
		//MP3428A_DISABLE();
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
static void LEDDispalayBattery_Power(battery_id batid)
{

      
      switch(batid){

         case battery_20://detected low votlage don't run
			lamp_t.gbatteryLifePercent = 1;
			
			    if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					LED_60_SetHigh();
					LED_80_SetHigh();
					LED_100_SetHigh();
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_100_SetLow() ;
					LED_40_SetLow();
					LED_60_SetLow();
					LED_80_SetLow();
		
				}
			
		 
		 break;

		 case battery_40: //40% battery power
		    if(BATT_DetectedGetValue()==1){
				if(tim0_t.tim0_falg >49){
					LED_40_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_40_SetLow() ;
		
				}
			}
			else{
			    LED_40_SetHigh() ;
			}
			LED_60_SetHigh();
		    LED_80_SetHigh();
			LED_100_SetHigh();
         
		 break;

		 case battery_60:
			if(BATT_DetectedGetValue()==1){
					if(tim0_t.tim0_falg >49){
						LED_60_SetHigh() ;
						if(tim0_t.tim0_falg >99)
							tim0_t.tim0_falg = 0;
					}
					else{
						LED_60_SetLow() ;
					
				}
			}
			else{
			    LED_60_SetLow() ;
			}
			LED_40_SetLow() ;
		
		    LED_80_SetHigh();
			LED_100_SetHigh();

		 break;

		 case battery_80:
			if(BATT_DetectedGetValue()==1){
				if(tim0_t.tim0_falg >49){
					LED_80_SetHigh() ;
					if(tim0_t.tim0_falg >99)
						tim0_t.tim0_falg = 0;
				}
				else{
					LED_80_SetLow() ;
					
		
			}
		   }
		   else{
				LED_80_SetLow() ;

		   }
			LED_40_SetLow() ;
			LED_60_SetLow();
			LED_100_SetHigh();
			
		 

		 break;

		 case battery_100:
			if(BATT_DetectedGetValue()==1){
					if(tim0_t.tim0_falg >49){
						LED_100_SetHigh() ;
						if(tim0_t.tim0_falg >99)
							tim0_t.tim0_falg = 0;
					}
					else{
						LED_100_SetLow() ;
						
			
				}
			}
			else{
			   LED_100_SetLow() ;
			}
		 	
		 	LED_40_SetLow();
			LED_60_SetLow();
		    LED_80_SetLow();
			
		 break;

		 case battery_full:
			LED_100_SetLow() ;
		    LED_40_SetLow();
			LED_60_SetLow();
		    LED_80_SetLow();


		 break;

		 default :
		 	 

		 break;



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
void DisplayBattery_Power_Estimate(void)
{
   
  if(adc_t.adcValue < 30 ){
	  LEDDispalayBattery_Power(battery_20);
	  
  }
  else if(adc_t.adcValue < 32 && adc_t.adcValue >=30){ //half of battery value
		LEDDispalayBattery_Power(battery_40);

   }
   else if(adc_t.adcValue >=32 && adc_t.adcValue < 35){
	   LEDDispalayBattery_Power(battery_60);

   }
   else if(adc_t.adcValue >=35 && adc_t.adcValue <37){
		 LEDDispalayBattery_Power(battery_80);

   }
   else if(adc_t.adcValue >=37 && adc_t.adcValue < 40){
		 LEDDispalayBattery_Power(battery_100);

   }
   else  if(adc_t.adcValue >=40){
		 LEDDispalayBattery_Power(battery_full);

   	}

   

}