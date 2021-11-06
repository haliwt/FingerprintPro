
/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr0.h"
#include "headlamp.h"

/***************************************************************************************
   * 
   * Function Name:void TMR0_Initialize(void)
   *Function: Timer1  :prescale = 8,Timer1 period = 10ms .Tosc =1/8Mhz =0.125us
   *          TMR0H = (T1 period)/(4*prescale*Tosc)= 10/(4*8*0.125*10^-3)=250 -1=249(0xF9)
   *          postscaler =10 ,Timer0 = period * postscaler =10ms
   * 
***************************************************************************************/
/**
  Section: TMR0 APIs
*/
TIM0 tim0_t;

void (*TMR0_InterruptHandler)(void); //function pointer 

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface

    // T0CS FOSC/4; T0CKPS 1:8; T0ASYNC synchronised; 
    T0CON1 = 0x43;

    // TMR0H 249; 
    TMR0H = 0xF9;

    // TMR0L 0; 
    TMR0L = 0x00;

    // Clear Interrupt flag before enabling the interrupt
    PIR0bits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    PIE0bits.TMR0IE = 1;

    // Set Default Interrupt Handler
    TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);

    // T0OUTPS 1:10; T0EN enabled; T016BIT 8-bit; 
    T0CON0 = 0x89;

	TMR0_StartTimer();
}

void TMR0_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 1;
}

void TMR0_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 0;
}

uint8_t TMR0_ReadTimer(void)
{
    uint8_t readVal;

    // read Timer0, low register only
    readVal = TMR0L;

    return readVal;
}

void TMR0_WriteTimer(uint8_t timerVal)
{
    // Write to Timer0 registers, low register only
    TMR0L = timerVal;
 }

void TMR0_Reload(uint8_t periodVal)
{
   // Write to Timer0 registers, high register only
   TMR0H = periodVal;
}

void TMR0_ISR(void)
{
    // clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    // ticker function call;
    // ticker is 1 -> Callback function gets called every time this ISR executes
    TMR0_CallBack();

    // add your TMR0 interrupt custom code
}
/******************************************************************
   * 
   * Function Name:void TMR0_CallBack(void)
   * Function :T(timer0) = 10ms ,postscaler=10,Tosc = 1/8MHz = 0.125us 
   * define Timer = (4*pre*poster*Tosc) *TMR0 =
   * 
******************************************************************/
void TMR0_CallBack(void)
{
    // Add your custom callback code here timer is 10ms
     static uint16_t temp_5s,temp;
     tim0_t.tim0_falg ++ ;
     temp_5s++;
     if(temp_5s >99){ //1s
        temp_5s=0;
        tim0_t.tim0_BattStatus++;
        tim0_t.tim0_noBatt_s++;
        tim0_t.tim0_autoShutOff_lamp++;
		tim0_t.tim0_fun_30s++;

     }
   

     if(tim0_t.tim0_autoShutOff_lamp>899){//900s =15minute
          lamp_t.getMinutes15_flag =1;
          tim0_t.tim0_autoShutOff_lamp=0;
          
     }

    if(TMR0_InterruptHandler)
    {
        TMR0_InterruptHandler();
    }
}

void TMR0_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR0_InterruptHandler = InterruptHandler;
}

void TMR0_DefaultInterruptHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
}

/**
  End of File
*/