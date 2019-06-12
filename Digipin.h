/*
Обертка над цифровым выходом Arduino
Предназначена для работы с реле, индикаторами и т.д.

*/
#ifndef DIGIPIN_LIB
#define DIGIPIN_LIB

#include <Arduino.h>

#define MAX_NAME_LEN	64

//состояние выхода  
enum DIGIPIN_STATE {
      DIGIPIN_ON,
      DIGIPIN_OFF
    };


class Digipin
{
	DIGIPIN_STATE	state;
	uint8_t 	pin; 
	char 		name[MAX_NAME_LEN];
	//выходной уровень инвертируется относительно значения state
	bool 		inverse_state;
	void set_state();
public:
	Digipin();
	Digipin(uint8_t _pin, const char * _name, DIGIPIN_STATE _state, bool _inverse_state);
	void init(uint8_t _pin, const char * _name, DIGIPIN_STATE _state, bool _inverse_state);
	void turn_on();
	void turn_off();
    /*инвертирует состояние вывода*/
	void turn_back();
    DIGIPIN_STATE get_state(){return state;};
};


#endif
