#include "led.h"

static void LEDDispalayBattery_Power(battery_id batid);
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

	     case battery_20:
		 	LED_40_SetLow() ;
			
			LED_60_SetLow();
		    LED_80_SetLow();
			LED_100_SetLow();

	     break;

		 case battery_40: //40% battery power
            LED_40_SetHigh() ;
			
			LED_60_SetLow();
		    LED_80_SetLow();
			LED_100_SetLow();
         
		 break;

		 case battery_60:
		 	
			LED_40_SetHigh() ;
			LED_60_SetHigh();
		    LED_80_SetLow();
			LED_100_SetLow();

		 break;

		 case battery_80:
			LED_40_SetHigh() ;
			LED_60_SetHigh();
		 
		    LED_80_SetHigh();
			LED_100_SetLow();
		 

		 break;

		 case battery_100:
		 	LED_40_SetHigh() ;
			LED_60_SetHigh();
		 
		    LED_80_SetHigh();
			LED_100_SetHigh();

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
   BATTERY_ADCValue();
   
   if(adc_t.adcValue > 4600){
		LEDDispalayBattery_Power(battery_100);

   }

   if(adc_t.adcValue <4600 && adc_t.adcValue > 4500){
	   LEDDispalayBattery_Power(battery_80);

   }

   if(adc_t.adcValue < 4500 && adc_t.adcValue >4300){
		 LEDDispalayBattery_Power(battery_60);

   }

   if(adc_t.adcValue < 4300 && adc_t.adcValue >3500){
		 LEDDispalayBattery_Power(battery_40);

   }

   if(adc_t.adcValue < 3500 ){
		 LEDDispalayBattery_Power(battery_20);

   }


}