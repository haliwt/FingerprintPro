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
        
        if(lamp_t.Power_On ==1){
            MSP_EN_SetLow() ;
          
             CPUDOZEbits.IDLEN =0;
             CPUDOZEbits.DOZE=0;
             CPUDOZEbits.DOZE = 0x00;
          if(lamp_t.getMinutes15_flag ==1){
               lamp_t.getMinutes15_flag =0;
               LAMP_ShutOff();
               lamp_t.Power_On=0;
           }
           else{
              if(lamp_t.switch_dev==0){
                  if(tim0_t.tim0_noBatt_s>120)
                       lamp_t.switch_dev++;
                  ADC_Battery_ConversionValue_Voltage();    
                  DisplayBattery_Power_Estimate();
                
              }
              if(BATT_DetectedGetValue()==1 ){//Battery be charing be detected
                ADC_Battery_ConversionValue_Voltage();
                DisplayBattery_Power_Estimate();
              }
              else{
                if(tim0_t.tim0_noBatt_s>120){
                    tim0_t.tim0_noBatt_s=0;
                    ADC_Battery_ConversionValue_Voltage();    
                    DisplayBattery_Power_Estimate();
                }

                
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