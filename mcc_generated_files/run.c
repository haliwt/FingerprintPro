#include "run.h"

RUN_T run_t;
volatile uint8_t transOngoingFlag;
volatile uint8_t outputBuf[5];
static uint8_t inputBuf[4];
/******************************************************************************
 * 
 *Function Name: void EUSART_InputCmd_Run(void)
 * 
 * 
 *****************************************************************************/
void EUSART_InputCmd_Run(void)
{
	
    switch (run_t.InputOrder[0])
    {
        case 0xff: //power Off 
            /* code */
                lamp_t.lampColor= 0x80;
            break;
            
        case 0x52: //"R" rend Led
           lamp_t.lampColor= 0x08;
        break;
        
        case 0x47:  //"Green"
             lamp_t.lampColor= 0x02;
        break;
        
        case 0x42: //"Blue"
           lamp_t.lampColor= 0x03;
        break;
        
        case 0x57: //"White"
             lamp_t.lampColor= 0x01; //KEY_WHITE
        break;
        
        case 0x01: //lamp "+"
            lamp_t.lampColor= 0x20;
        
        break;
        
        case 0x02: //lamp "-"
             lamp_t.lampColor= 0x10;
        break;
        
        case 0x3f: //"Close" ,turn off LED
            lamp_t.lampColor= 0;
        break; 
    
       default:
        break;
    }
	
}
/******************************************************************************
 * 
 *Function Name: EUSART_TxData(uint8_t index) 
 * 
 * 
 *****************************************************************************/
void EUSART_BatteryWorks_TxData(uint8_t index)
{
   

	outputBuf[0]='B'; //0x46
	outputBuf[1]='A'; //0x50
	outputBuf[2]='T'; //0x42	// 'M' for motor board
    outputBuf[3]='W';
	outputBuf[4]=index+0x30;	// change to ascii number for decimal number 0~9
   if(run_t.eusartTx_flag ==0){
   	   PIE3bits.TXIE=0;
      if(transOngoingFlag==0){
            TX1REG = outputBuf[run_t.eusartTx_Num];
	        run_t.eusartTx_Num++;
            
       }
	   transOngoingFlag=1;
	   if(run_t.eusartTx_Num==5)run_t.eusartTx_flag=1;
	    PIE3bits.TXIE=1;
   	}
   
}

/******************************************************************************
 * 
 *Function Name: void EUSART_BatteryCharging_TxData(uint8_t index)
 * 
 * 
 *****************************************************************************/
void EUSART_BatteryCharging_TxData(uint8_t index)
{
   

	outputBuf[0]='B'; //0x46
	outputBuf[1]='A'; //0x50
	outputBuf[2]='T'; //0x42	// 'M' for motor board
    outputBuf[3]='T';
	outputBuf[4]=index+0x30;	// change to ascii number for decimal number 0~9
   if(run_t.eusartTx_flag ==0){
   	   PIE3bits.TXIE=0;
      if(transOngoingFlag==0){
            TX1REG = outputBuf[run_t.eusartTx_Num];
	        run_t.eusartTx_Num++;
            
       }
	   transOngoingFlag=1;
	   if(run_t.eusartTx_Num==5)run_t.eusartTx_flag=1;
	    PIE3bits.TXIE=1;
   	}
   
}
/******************************************************************************
 * 
 *Function Name: void EUSART_BatteryCharging_TxData(uint8_t index)
 * 
 * 
 *****************************************************************************/
void EUSART_Adapter_TxData(uint8_t index)
{
   

	outputBuf[0]='B'; //0x46
	outputBuf[1]='A'; //0x50
	outputBuf[2]='T'; //0x42	// 'M' for motor board
    outputBuf[3]='A';
	outputBuf[4]=index+0x30;	// change to ascii number for decimal number 0~9
   if(run_t.eusartTx_flag ==0){
   	   PIE3bits.TXIE=0;
      if(transOngoingFlag==0){
            TX1REG = outputBuf[run_t.eusartTx_Num];
	        run_t.eusartTx_Num++;
            
       }
	   transOngoingFlag=1;
	   if(run_t.eusartTx_Num==5)run_t.eusartTx_flag=1;
	    PIE3bits.TXIE=1;
   	}
   
}
/*****************************************************
 * 
 *Function Name: void RxData_EUSART(void)
 *Receive Interrupt EUSART of data
 *
 *
*****************************************************/
void RxData_EUSART(void)
{
    static uint8_t i;
    PIE3bits.RC1IE = 0;
        
        
        inputBuf[i]=RC1REG;
        PIE3bits.TX1IE = 0;
		if(i==0){
			
			if(inputBuf[0]=='F'){
	            // TX1REG = inputBuf[0];//recdata[i]; // ???????? // ??
                 
			}
			else i=0;
		}
		else if(i==1){
            
	        if(inputBuf[1]=='P'){
	           //  TX1REG = inputBuf[1];//recdata[i]; // ???????? // ??
            }
            else i=0;
		}
        else if(i==2){
           run_t.InputOrder[0]=inputBuf[2];
        }
		
	    i++;
		if(i==3)i=0;
        
     PIE3bits.RC1IE = 1; 
     PIE3bits.TX1IE = 1;
      
    
    
}

