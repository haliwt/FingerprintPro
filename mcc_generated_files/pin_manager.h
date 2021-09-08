/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F24K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set KEY_RED aliases
#define KEY_RED_TRIS                 TRISAbits.TRISA0
#define KEY_RED_LAT                  LATAbits.LATA0
#define KEY_RED_PORT                 PORTAbits.RA0
#define KEY_RED_WPU                  WPUAbits.WPUA0
#define KEY_RED_OD                   ODCONAbits.ODCA0
#define KEY_RED_ANS                  ANSELAbits.ANSELA0
#define KEY_RED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define KEY_RED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define KEY_RED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define KEY_RED_GetValue()           PORTAbits.RA0
#define KEY_RED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define KEY_RED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define KEY_RED_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define KEY_RED_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define KEY_RED_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define KEY_RED_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define KEY_RED_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define KEY_RED_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set KEY_GREEN aliases
#define KEY_GREEN_TRIS                 TRISAbits.TRISA1
#define KEY_GREEN_LAT                  LATAbits.LATA1
#define KEY_GREEN_PORT                 PORTAbits.RA1
#define KEY_GREEN_WPU                  WPUAbits.WPUA1
#define KEY_GREEN_OD                   ODCONAbits.ODCA1
#define KEY_GREEN_ANS                  ANSELAbits.ANSELA1
#define KEY_GREEN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define KEY_GREEN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define KEY_GREEN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define KEY_GREEN_GetValue()           PORTAbits.RA1
#define KEY_GREEN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define KEY_GREEN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define KEY_GREEN_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define KEY_GREEN_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define KEY_GREEN_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define KEY_GREEN_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define KEY_GREEN_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define KEY_GREEN_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set KEY_BLUE aliases
#define KEY_BLUE_TRIS                 TRISAbits.TRISA2
#define KEY_BLUE_LAT                  LATAbits.LATA2
#define KEY_BLUE_PORT                 PORTAbits.RA2
#define KEY_BLUE_WPU                  WPUAbits.WPUA2
#define KEY_BLUE_OD                   ODCONAbits.ODCA2
#define KEY_BLUE_ANS                  ANSELAbits.ANSELA2
#define KEY_BLUE_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define KEY_BLUE_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define KEY_BLUE_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define KEY_BLUE_GetValue()           PORTAbits.RA2
#define KEY_BLUE_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define KEY_BLUE_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define KEY_BLUE_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define KEY_BLUE_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define KEY_BLUE_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define KEY_BLUE_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define KEY_BLUE_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define KEY_BLUE_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set KEY_WHITE aliases
#define KEY_WHITE_TRIS                 TRISAbits.TRISA3
#define KEY_WHITE_LAT                  LATAbits.LATA3
#define KEY_WHITE_PORT                 PORTAbits.RA3
#define KEY_WHITE_WPU                  WPUAbits.WPUA3
#define KEY_WHITE_OD                   ODCONAbits.ODCA3
#define KEY_WHITE_ANS                  ANSELAbits.ANSELA3
#define KEY_WHITE_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define KEY_WHITE_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define KEY_WHITE_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define KEY_WHITE_GetValue()           PORTAbits.RA3
#define KEY_WHITE_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define KEY_WHITE_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define KEY_WHITE_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define KEY_WHITE_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define KEY_WHITE_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define KEY_WHITE_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define KEY_WHITE_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define KEY_WHITE_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set KEY_ADD aliases
#define KEY_ADD_TRIS                 TRISAbits.TRISA4
#define KEY_ADD_LAT                  LATAbits.LATA4
#define KEY_ADD_PORT                 PORTAbits.RA4
#define KEY_ADD_WPU                  WPUAbits.WPUA4
#define KEY_ADD_OD                   ODCONAbits.ODCA4
#define KEY_ADD_ANS                  ANSELAbits.ANSELA4
#define KEY_ADD_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define KEY_ADD_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define KEY_ADD_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define KEY_ADD_GetValue()           PORTAbits.RA4
#define KEY_ADD_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define KEY_ADD_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define KEY_ADD_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define KEY_ADD_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define KEY_ADD_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define KEY_ADD_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define KEY_ADD_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define KEY_ADD_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set KEY_SUB aliases
#define KEY_SUB_TRIS                 TRISAbits.TRISA5
#define KEY_SUB_LAT                  LATAbits.LATA5
#define KEY_SUB_PORT                 PORTAbits.RA5
#define KEY_SUB_WPU                  WPUAbits.WPUA5
#define KEY_SUB_OD                   ODCONAbits.ODCA5
#define KEY_SUB_ANS                  ANSELAbits.ANSELA5
#define KEY_SUB_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define KEY_SUB_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define KEY_SUB_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define KEY_SUB_GetValue()           PORTAbits.RA5
#define KEY_SUB_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define KEY_SUB_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define KEY_SUB_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define KEY_SUB_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define KEY_SUB_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define KEY_SUB_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define KEY_SUB_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define KEY_SUB_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RED_EN aliases
#define RED_EN_TRIS                 TRISAbits.TRISA6
#define RED_EN_LAT                  LATAbits.LATA6
#define RED_EN_PORT                 PORTAbits.RA6
#define RED_EN_WPU                  WPUAbits.WPUA6
#define RED_EN_OD                   ODCONAbits.ODCA6
#define RED_EN_ANS                  ANSELAbits.ANSELA6
#define RED_EN_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RED_EN_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RED_EN_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RED_EN_GetValue()           PORTAbits.RA6
#define RED_EN_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RED_EN_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RED_EN_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define RED_EN_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define RED_EN_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define RED_EN_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define RED_EN_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define RED_EN_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set GREEN_EN aliases
#define GREEN_EN_TRIS                 TRISAbits.TRISA7
#define GREEN_EN_LAT                  LATAbits.LATA7
#define GREEN_EN_PORT                 PORTAbits.RA7
#define GREEN_EN_WPU                  WPUAbits.WPUA7
#define GREEN_EN_OD                   ODCONAbits.ODCA7
#define GREEN_EN_ANS                  ANSELAbits.ANSELA7
#define GREEN_EN_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define GREEN_EN_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define GREEN_EN_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define GREEN_EN_GetValue()           PORTAbits.RA7
#define GREEN_EN_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define GREEN_EN_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define GREEN_EN_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define GREEN_EN_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define GREEN_EN_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define GREEN_EN_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define GREEN_EN_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define GREEN_EN_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISBbits.TRISB0
#define LED1_LAT                  LATBbits.LATB0
#define LED1_PORT                 PORTBbits.RB0
#define LED1_WPU                  WPUBbits.WPUB0
#define LED1_OD                   ODCONBbits.ODCB0
#define LED1_ANS                  ANSELBbits.ANSELB0
#define LED1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED1_GetValue()           PORTBbits.RB0
#define LED1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set MSP_EN aliases
#define MSP_EN_TRIS                 TRISBbits.TRISB1
#define MSP_EN_LAT                  LATBbits.LATB1
#define MSP_EN_PORT                 PORTBbits.RB1
#define MSP_EN_WPU                  WPUBbits.WPUB1
#define MSP_EN_OD                   ODCONBbits.ODCB1
#define MSP_EN_ANS                  ANSELBbits.ANSELB1
#define MSP_EN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MSP_EN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MSP_EN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MSP_EN_GetValue()             PORTBbits.RB1
#define MSP_EN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MSP_EN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MSP_EN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MSP_EN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MSP_EN_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MSP_EN_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MSP_EN_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define MSP_EN_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set channel_ANB2 aliases
#define channel_ANB2_TRIS                 TRISBbits.TRISB2
#define channel_ANB2_LAT                  LATBbits.LATB2
#define channel_ANB2_PORT                 PORTBbits.RB2
#define channel_ANB2_WPU                  WPUBbits.WPUB2
#define channel_ANB2_OD                   ODCONBbits.ODCB2
#define channel_ANB2_ANS                  ANSELBbits.ANSELB2
#define channel_ANB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define channel_ANB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define channel_ANB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define channel_ANB2_GetValue()           PORTBbits.RB2
#define channel_ANB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define channel_ANB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define channel_ANB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define channel_ANB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define channel_ANB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define channel_ANB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define channel_ANB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define channel_ANB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set BLEE_EN aliases
#define BLEE_EN_TRIS                 TRISBbits.TRISB3
#define BLEE_EN_LAT                  LATBbits.LATB3
#define BLEE_EN_PORT                 PORTBbits.RB3
#define BLEE_EN_WPU                  WPUBbits.WPUB3
#define BLEE_EN_OD                   ODCONBbits.ODCB3
#define BLEE_EN_ANS                  ANSELBbits.ANSELB3
#define BLEE_EN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BLEE_EN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BLEE_EN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BLEE_EN_GetValue()           PORTBbits.RB3
#define BLEE_EN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BLEE_EN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BLEE_EN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define BLEE_EN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define BLEE_EN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define BLEE_EN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define BLEE_EN_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define BLEE_EN_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set WHITE_EN aliases
#define WHITE_EN_TRIS                 TRISBbits.TRISB4
#define WHITE_EN_LAT                  LATBbits.LATB4
#define WHITE_EN_PORT                 PORTBbits.RB4
#define WHITE_EN_WPU                  WPUBbits.WPUB4
#define WHITE_EN_OD                   ODCONBbits.ODCB4
#define WHITE_EN_ANS                  ANSELBbits.ANSELB4
#define WHITE_EN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define WHITE_EN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define WHITE_EN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define WHITE_EN_GetValue()           PORTBbits.RB4
#define WHITE_EN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define WHITE_EN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define WHITE_EN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define WHITE_EN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define WHITE_EN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define WHITE_EN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define WHITE_EN_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define WHITE_EN_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set FUN_EN aliases
#define FUN_EN_TRIS                 TRISBbits.TRISB5
#define FUN_EN_LAT                  LATBbits.LATB5
#define FUN_EN_PORT                 PORTBbits.RB5
#define FUN_EN_WPU                  WPUBbits.WPUB5
#define FUN_EN_OD                   ODCONBbits.ODCB5
#define FUN_EN_ANS                  ANSELBbits.ANSELB5     //0->digital 1->analog
#define FUN_EN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define FUN_EN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define FUN_EN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define FUN_EN_GetValue()           PORTBbits.RB5
#define FUN_EN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define FUN_EN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define FUN_EN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define FUN_EN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define FUN_EN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define FUN_EN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define FUN_EN_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define FUN_EN_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISCbits.TRISC2
#define LED4_LAT                  LATCbits.LATC2
#define LED4_PORT                 PORTCbits.RC2
#define LED4_WPU                  WPUCbits.WPUC2
#define LED4_OD                   ODCONCbits.ODCC2
#define LED4_ANS                  ANSELCbits.ANSELC2
#define LED4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED4_GetValue()           PORTCbits.RC2
#define LED4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED4_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)



// get/set LED3 aliases
#define LED3_TRIS                 TRISCbits.TRISC4
#define LED3_LAT                  LATCbits.LATC4
#define LED3_PORT                 PORTCbits.RC4
#define LED3_WPU                  WPUCbits.WPUC4
#define LED3_OD                   ODCONCbits.ODCC4
#define LED3_ANS                  ANSELCbits.ANSELC4
#define LED3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED3_GetValue()           PORTCbits.RC4
#define LED3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISCbits.TRISC5
#define LED2_LAT                  LATCbits.LATC5
#define LED2_PORT                 PORTCbits.RC5
#define LED2_WPU                  WPUCbits.WPUC5
#define LED2_OD                   ODCONCbits.ODCC5
#define LED2_ANS                  ANSELCbits.ANSELC5
#define LED2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED2_GetValue()           PORTCbits.RC5
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/