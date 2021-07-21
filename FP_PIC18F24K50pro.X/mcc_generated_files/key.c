#include "key.h"



/****************************************************************************
    *
    * Function Name: void UNIPOLAR_MOTOR_Init(void)
    * Function :Initial motor for GPIO 
    * Input Ref:NO
    * Return Ref: key value
    * 
 ****************************************************************************/
uint8_t  KEY_Scan(void)
{
    static uint16_t  k1=0 ;
    static uint16_t  k2=0 ;
    static uint16_t  k3=0 ;
    static uint16_t  k4=0 ;
    static uint16_t  k5=0 ;
	static uint16_t  k6=0 ;
    uint8_t cnt;
    
    
    if(KEY_RED() ==0){
        if(k1<200)
        k1++;   
    }
    else {  
      k1=0;  
    }
    
    if(KEY_GREEN() ==0){
       if(k2<200)
        k2++; 
       
    }
    else{
        
        k2=0; 
    }  
    
    if(KEY_BLUE() ==0){
       if(k3<200)
        k3++; 
       
    }
    else{
        
        k3=0; 
    } 
    
    if(KEY_WHITE() ==0){
       if(k4<200)
        k4++; 
       
    }
    else{
        
        k4=0; 
    }  
    
    if(KEY_ADD() ==0){ //"+"
       if(k5<200)
        k5++; 
       
    }
    else{
        
        k5=0; 
    } 

	if(KEY_SUB() ==0){ //"-"
       if(k6<200)
        k6++; 
       
    }
    else{
        
        k6=0; 
    } 
	
    cnt =0;
    if(k1==190){
       cnt= 0x1  ;  //KEY_RED
    } 
    if(k2==190){
        cnt= 0x2  ; //KEY_GREEN 
    }
    if(k3==190){
        cnt= 0x4  ;  //KEY_BLUE 
    }
    if(k4==190){
        cnt= 0x8  ;  //KEY_WHITE
    }
    if(k5==190){
        cnt= 0x10 ;   //KEY_ADD
    }
	if(k6==190){
	  cnt =0x20;      //KEY_SUB
	}
    return cnt ;
    
}
   
