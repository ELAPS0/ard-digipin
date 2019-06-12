#include "Digipin.h"

Digipin::Digipin(){
	pin = 0xff;
	strcpy(name, "noname");
	state = DIGIPIN_OFF; 
}

Digipin::Digipin(uint8_t _pin, const char* _name, DIGIPIN_STATE _state, bool _inverse_state){
	init (_pin, _name, _state, _inverse_state);
}
/*
pin 		- номер выхода, состоянием которого будет управлять экземпляр класса  
name 		- имя, отображаемое в логе
state 		- начальное состояние выхода
inverse_state 	- инвертирование состояния пина, относительно логического состояния (полезно для реле)
*/
void Digipin::init(uint8_t _pin, const char* _name, DIGIPIN_STATE _state, bool _inverse_state){
	pin = _pin;
	strncpy(name, _name,MAX_NAME_LEN);
	name[MAX_NAME_LEN-1] = '\0';
	state = _state; 
	inverse_state = _inverse_state;
	
	pinMode (pin, OUTPUT);
	set_state();
}
void Digipin::set_state(){

	uint8_t pin_state = inverse_state?(state==DIGIPIN_ON?LOW:HIGH):(state==DIGIPIN_ON?HIGH:LOW);

	digitalWrite(pin, pin_state);
	Serial.print(name);
    Serial.print( state==DIGIPIN_ON?"ON":"OFF");
	if (inverse_state){
		Serial.print(". Real pin state  ");
        	Serial.print( pin_state==HIGH?"HIHG":"LOW");
	}
	Serial.println("");
}	
void Digipin::turn_on()
{
	state = DIGIPIN_ON;
	set_state();
}
void Digipin::turn_off()
{
	state = DIGIPIN_OFF;
	set_state();
}
void Digipin::turn_back()
{
	state = state==DIGIPIN_ON?DIGIPIN_OFF:DIGIPIN_ON;
	set_state();
}

