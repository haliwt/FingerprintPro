#ifndef __RUN_H__
#define __RUN_H__
#include "../mcc_generated_files/mcc.h"

extern volatile uint8_t transOngoingFlag;

typedef struct {

   uint8_t lampColor;
   uint8_t Power_On ;
   uint8_t eusartTx_Num;
   uint8_t eusartTx_flag;
   uint8_t ADD_flag;
   uint8_t SUB_flag;
   uint8_t batteryStatus;
   uint8_t InputOrder[2];
 }RUN_T;

RUN_T run_t;



void EUSART_InputCmd_Run(void);
void RxData_EUSART(void);
void EUSART_BatteryWorks_TxData(uint8_t index);
void EUSART_BatteryCharging_TxData(uint8_t index);
void EUSART_Adapter_TxData(uint8_t index);

#endif 