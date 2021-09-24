/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
	  uint8_t keyValue;
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
     LAMP_Init_Value();

    while (1)
    {
         
          
          if(BATT_DetectedGetValue()==1){//Battery be charing be detected
                ADC_Battery_ConversionValue_Voltage();
                DisplayBattery_Power_Estimate();
                MP3428A_ENABLE_SetLow() ;
          }
          else{ //don't charing battery 
          if(lamp_t.Power_On ==1){
               MP3428A_ENABLE_SetLow() ;
               if(lamp_t.getMinutes15_flag ==1 && BATT_DetectedGetValue()==0){
                  lamp_t.getMinutes15_flag =0;
                  // LAMP_ShutOff();
                  MP3428A_DISABLE_SetHigh();
                  lamp_t.Power_On=0;
              }
              if(lamp_t.switch_dev==0 &&  BATT_DetectedGetValue()==0 ){ //Display Battery of capacity
                  if(tim0_t.tim0_noBatt_s>120 )
                       lamp_t.switch_dev++;
                  ADC_Battery_ConversionValue_Voltage();    
                  DisplayBattery_Power_Estimate();
                
              }
              if(tim0_t.tim0_noBatt_s>120 && BATT_DetectedGetValue()==0 ){
                  tim0_t.tim0_noBatt_s=0;
                  ADC_Battery_ConversionValue_Voltage();    
                  DisplayBattery_Power_Estimate();
                  LowVotalge_Detected();
            }
               
          }
               
          } 
        keyValue=  KEY_Scan();
        checkMode(keyValue);
        checkRun();
        
       
        
        }
}
/**
 End of File
*/