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
        
       
         if(DET_BATT_GetValue()==1){//Battery be charing be detected + adapter
                ADC_Battery_ConversionValue_Voltage();
                BatteryCharing_Power_Estimate();
                MP3428A_EN_SetLow() ;
          }
          else{ //Battery don't charing 
            if(lamp_t.Power_On ==1){
                MP3428A_EN_SetLow() ;
                if(lamp_t.getMinutes15_flag ==1){
                    lamp_t.getMinutes15_flag =0;
                    // LAMP_ShutOff();
                    MP3428A_DISABLE_SetHigh();
                    lamp_t.Power_On=0;
                }
                if(lamp_t.switch_dev==0  ){ //Display Battery of capacity
                    if(tim0_t.tim0_noBatt_s>120 )
                        lamp_t.switch_dev++;
                    ADC_Battery_ConversionValue_Voltage();    
                    BatteryWorks_Power_Estimate();
                  
                }
                if(tim0_t.tim0_noBatt_s>120 ){
                    tim0_t.tim0_noBatt_s=0;
                    ADC_Battery_ConversionValue_Voltage();    
                    BatteryWorks_Power_Estimate();
                    LowVotalge_Detected();
              }
                
            }
          } 
        EUSART_SetRxInterruptHandler(RxData_EUSART);
        EUSART_InputCmd_Run();
        checkRun();
     }
}
/**
 End of File
*/