/**
   EXT_INT Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     ext_int.c
 
   @Summary
     This is the generated driver implementation file for the EXT_INT driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for EXT_INT.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
         Device            :  PIC18F24K40
         Driver Version    :  1.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.31 and above
         MPLAB             :  MPLAB X 5.45
 */ 

 /**
   Section: Includes
 */
#include <xc.h>
#include "ext_int.h"
#include "pin_manager.h"
#include "led.h"
#include "delay.h"
#include "headlamp.h"

void (*INT0_InterruptHandler)(void);
void (*INT1_InterruptHandler)(void);
void (*INT2_InterruptHandler)(void);

void INT0_ISR(void)
{
    EXT_INT0_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT0_CallBack();    
}


void INT0_CallBack(void)
{
    // Add your custom callback code here
    if(INT0_InterruptHandler)
    {
        INT0_InterruptHandler();
    }
}

void INT0_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT0_InterruptHandler = InterruptHandler;
}

void INT0_DefaultInterruptHandler(void){
    // add your INT0 interrupt custom code
    // or set custom function using INT0_SetInterruptHandler()
}
void INT1_ISR(void)
{
    EXT_INT1_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT1_CallBack();    
}


void INT1_CallBack(void)
{
    // Add your custom callback code here
    INT1_InterruptHandler=&INT1_UserDefineFunction;
    if(INT1_InterruptHandler)
    {
        INT1_InterruptHandler();
    }
}

void INT1_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT1_InterruptHandler = InterruptHandler;
}

void INT1_DefaultInterruptHandler(void){
    // add your INT1 interrupt custom code
    // or set custom function using INT1_SetInterruptHandler()
}
void INT2_ISR(void)
{
    EXT_INT2_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT2_CallBack();    
}


void INT2_CallBack(void)
{
    // Add your custom callback code here
    //INT2_InterruptHandler=&INT1_UserDefineFunction;
    if(INT2_InterruptHandler)
    {
        INT2_InterruptHandler();
    }
}

void INT2_SetInterruptHandler(void (* InterruptHandler)(void)){
    INT2_InterruptHandler = InterruptHandler;
}

void INT2_DefaultInterruptHandler(void){
    // add your INT2 interrupt custom code
    // or set custom function using INT2_SetInterruptHandler()
}

void EXT_INT_Initialize(void)
{
    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    //EXT_INT0_InterruptFlagClear();   
    //EXT_INT0_risingEdgeSet();    
    // Set Default Interrupt Handler
    //INT0_SetInterruptHandler(INT0_DefaultInterruptHandler);
    //EXT_INT0_InterruptEnable();      

    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    EXT_INT1_InterruptFlagClear();   
    //EXT_INT1_risingEdgeSet();   
    EXT_INT1_fallingEdgeSet() ;//WT.EDIT 
    // Set Default Interrupt Handler
    INT1_SetInterruptHandler(INT1_DefaultInterruptHandler);
    EXT_INT1_InterruptEnable();      

    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    //EXT_INT2_InterruptFlagClear();   
    //EXT_INT2_risingEdgeSet();    
    // Set Default Interrupt Handler
    //INT2_SetInterruptHandler(INT2_DefaultInterruptHandler);
    //EXT_INT2_InterruptEnable();      

}
/*****************************************************************************
     * 
     *Function Name:void INT1_UserDefineFunction(void)
     *Function :
     *
     *
     *
******************************************************************************/
void INT1_UserDefineFunction(void)
{
    static uint8_t int_flag;
    int_flag = int_flag^ 0x01;
    if(int_flag == 1){
            lamp_t.Power_On =1;
          //  POWER_SetLow() ; //power on
			DELAY_microseconds(500) ;
			  
	}
	else{
		lamp_t.Power_On =0;
       // POWER_SetHigh();//power off
		
			  
		}
        
}
    
    


