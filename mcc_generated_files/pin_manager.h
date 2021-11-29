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

// get/set BLUE_EN aliases
#define BLUE_EN_TRIS                 TRISAbits.TRISA3
#define BLUE_EN_LAT                  LATAbits.LATA3
#define BLUE_EN_PORT                 PORTAbits.RA3
#define BLUE_EN_WPU                  WPUAbits.WPUA3
#define BLUE_EN_OD                   ODCONAbits.ODCA3
#define BLUE_EN_ANS                  ANSELAbits.ANSELA3
#define BLUE_EN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define BLUE_EN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define BLUE_EN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define BLUE_EN_GetValue()           PORTAbits.RA3
#define BLUE_EN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define BLUE_EN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define BLUE_EN_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define BLUE_EN_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define BLUE_EN_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define BLUE_EN_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define BLUE_EN_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define BLUE_EN_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set WHITE_EN aliases
#define WHITE_EN_TRIS                 TRISAbits.TRISA4
#define WHITE_EN_LAT                  LATAbits.LATA4
#define WHITE_EN_PORT                 PORTAbits.RA4
#define WHITE_EN_WPU                  WPUAbits.WPUA4
#define WHITE_EN_OD                   ODCONAbits.ODCA4
#define WHITE_EN_ANS                  ANSELAbits.ANSELA4
#define WHITE_EN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define WHITE_EN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define WHITE_EN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define WHITE_EN_GetValue()           PORTAbits.RA4
#define WHITE_EN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define WHITE_EN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define WHITE_EN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define WHITE_EN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define WHITE_EN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define WHITE_EN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define WHITE_EN_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define WHITE_EN_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

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

// get/set MP3428A_EN aliases
#define MP3428A_EN_TRIS                 TRISBbits.TRISB1
#define MP3428A_EN_LAT                  LATBbits.LATB1
#define MP3428A_EN_PORT                 PORTBbits.RB1
#define MP3428A_EN_WPU                  WPUBbits.WPUB1
#define MP3428A_EN_OD                   ODCONBbits.ODCB1
#define MP3428A_EN_ANS                  ANSELBbits.ANSELB1
#define MP3428A_DISABLE_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MP3428A_EN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MP3428A_EN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MP3428A_EN_GetValue()           PORTBbits.RB1
#define MP3428A_EN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MP3428A_EN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MP3428A_EN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MP3428A_EN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MP3428A_EN_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MP3428A_EN_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MP3428A_EN_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define MP3428A_EN_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

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



// get/set DET_BATT aliases
#define DET_BATT_TRIS                 TRISCbits.TRISC0
#define DET_BATT_LAT                  LATCbits.LATC0
#define DET_BATT_PORT                 PORTCbits.RC0
#define DET_BATT_WPU                  WPUCbits.WPUC0
#define DET_BATT_OD                   ODCONCbits.ODCC0
#define DET_BATT_ANS                  ANSELCbits.ANSELC0
#define DET_BATT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define DET_BATT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define DET_BATT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define DET_BATT_GetValue()           PORTCbits.RC0
#define DET_BATT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define DET_BATT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define DET_BATT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define DET_BATT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define DET_BATT_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define DET_BATT_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define DET_BATT_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define DET_BATT_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

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

// get/set FAN_EN aliases RC3
#define FAN_EN_TRIS                 TRISCbits.TRISC3
#define FAN_EN_LAT                  LATCbits.LATC3
#define FAN_EN_PORT                 PORTCbits.RC3
#define FAN_EN_WPU                  WPUCbits.WPUC3
#define FAN_EN_OD                   ODCONCbits.ODCC3
#define FAN_EN_ANS                  ANSELCbits.ANSELC3
#define FAN_EN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define FAN_EN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define FAN_EN_Toggle()             do { LATCbits.LATC3 = ~LATBbits.LATC3; } while(0)
#define FAN_EN_GetValue()           PORTCbits.RC3
#define FAN_EN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define FAN_EN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define FAN_EN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define FAN_EN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define FAN_EN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define FAN_EN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define FAN_EN_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define FAN_EN_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

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