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

    if(run_t.InputOrder[0]=='O'){

	    switch (run_t.InputOrder[1])
	    {

	        case 0x5A: //power Off 
	            /* code */
	                lamp_t.lampColor= 0x80;
					tim0_t.tim0_fun_30s=0;
	            break;
	            
	        case 0x52: //"R" rend Led
		        LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
		
				TMR2_StartTimer();
				DELAY_microseconds(200);
	           FAN_OFF_FUN();
			
	           lamp_t.lampColor= 0x52;
	        break;
	        
	        case 0x47:  //"Green"
	        	LAMP_RED_OFF();
				LAMP_BLUE_OFF();
				LAMP_WHITE_OFF();
			
		
			 	TMR2_StartTimer();
				DELAY_microseconds(200);
				FAN_OFF_FUN();
	             lamp_t.lampColor= 0x47;
	        break;
	        
	        case 0x42: //"Blue"
	            LAMP_GREEN_OFF();
			
				LAMP_WHITE_OFF();
				LAMP_RED_OFF();
			   TMR2_StartTimer();
				DELAY_microseconds(200);
				FAN_OFF_FUN();
	           lamp_t.lampColor= 0x42;
	        break;
	        
	        case 0x57: //"White"
	            LAMP_GREEN_OFF();
				LAMP_BLUE_OFF();
			
				LAMP_RED_OFF();
				
				TMR2_StartTimer();
				DELAY_microseconds(200);
				FAN_OFF_FUN();
	            lamp_t.lampColor= 0x57; //KEY_WHITE
	        break;
	        
	      
	       case 0x3f: //"Close" ,turn off LED
	       	    DELAY_microseconds(200);
	            lamp_t.lampColor= 0x3f;
	        break;

			case 0xff :
			 
	             DELAY_microseconds(200);
	            lamp_t.lampColor= 0xff;
                FAN_OFF_FUN();


			break;
	    
	       default:
	        break;
	    }
    }
    if(run_t.InputOrder[0]=='B'){
            TX1REG = 'B';
	    switch(run_t.InputOrder[1]){

		   case 0x31 : //brightness "+"
		   	  DELAY_microseconds(200);
	        
	          lamp_t.lampColor= 0x20;

		   break;

		   case 0x32 : //brightnes "-"

	        	DELAY_microseconds(200);
	            lamp_t.lampColor= 0x10;

		   break;

		   default: 

		   break;

		}

}
}

/******************************************************************************
	 * 
	 * Function Name: void EUSART_BatteryWorks_TxData(uint8_t index)
	 * Function:has a battery for works don't has adapter
	 * Input Ref: battery quntity of value voltagle
	 * Return Ref:NO
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
   

	outputBuf[0]='B'; //0x42
	outputBuf[1]='A'; //0x41
	outputBuf[2]='T'; //0x54	// 'M' for motor board
    outputBuf[3]='T'; //0x54
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
   

	outputBuf[0]='B'; //0x42
	outputBuf[1]='A'; //0x41
	outputBuf[2]='T'; //0x54	// 'M' for motor board
    outputBuf[3]='A'; //0x41
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
			
			if(inputBuf[0]=='F'){ //0x46
	            // TX1REG = inputBuf[0];//recdata[i]; // ???????? // ??
                 
			}
			else i=0;
		}
		else if(i==1){
            
	        if(inputBuf[1]=='P'){ //0x50
	           //  TX1REG = inputBuf[1];//recdata[i]; // ???????? // ??
            }
            else i=0;
		}
        else if(i==2){
			 
			 if(inputBuf[2]=='B') //bightness
			   run_t.InputOrder[0]=inputBuf[2];
			 else if(inputBuf[2]=='O') //order
               run_t.InputOrder[0]=inputBuf[2];
			 else i=0;
        }
		else if(i==3){
			 run_t.InputOrder[1]=inputBuf[3];
             
		}
		
	    i++;
		if(i==4)i=0;
        
     PIE3bits.RC1IE = 1; 
     PIE3bits.TX1IE = 1;
      
    
    
}

