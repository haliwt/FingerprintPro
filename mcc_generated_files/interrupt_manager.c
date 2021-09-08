/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.04
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB 	          :  MPLAB X 5.45
*/



#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    INTCONbits.IPEN = 0;
}

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(PIE0bits.TMR0IE == 1 && PIR0bits.TMR0IF == 1)
    {
        TMR0_ISR();
    }
    // else if(PIE0bits.INT0IE == 1 && PIR0bits.INT0IF == 1)
    // {
    //     INT0_ISR();
    // }
    //else if(PIE0bits.INT1IE == 1 && PIR0bits.INT1IF == 1)
   // {
     //   INT1_ISR();
   // }
    // else if(PIE0bits.INT2IE == 1 && PIR0bits.INT2IF == 1)
    // {
    //     INT2_ISR();
    // }
    // else if(INTCONbits.PEIE == 1)
    // {
    //     if(PIE3bits.TXIE == 1 && PIR3bits.TXIF == 1)
    //     {
    //         EUSART_TxDefaultInterruptHandler();
    //     } 
    //     else if(PIE3bits.RCIE == 1 && PIR3bits.RCIF == 1)
    //     {
    //         EUSART_RxDefaultInterruptHandler();
    //     } 
    //     else
    //     {
    //         //Unhandled Interrupt
    //     }
    // }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
