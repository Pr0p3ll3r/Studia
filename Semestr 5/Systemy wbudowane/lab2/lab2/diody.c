#include "diody.h"

void LED_konf(){
	diodDDR = 0xFF;
	diodPORT = 0x00;
}
void LED_Set(unsigned int LED_number){
	diodPORT = LED_number;
}

void LED_Clear(unsigned int LED_number){
	if(diodPort != 0b00000000){
		diodPort = ~LED_number;
	}
}

void LED_Toggle(unsigned int LED_number){
	diodPORT^=LED_number;
}

unsigned int LED_GetState(insigned int LED_number){
	if(diodPORT == LED_number){
		return 1;
	}else return 0;
}