#pragma once
#ifndef __cezar_atd__
#define __cezar_atd__
// Требуется описание класса code
#include "code_atd.h"
namespace simple_codes {
	// шифр цезаря
	class cezar : public code {
	public:
		int rot; // сдвиг
		// переопределяем интерфейс класса
		void InData(ifstream &ifst);  // ввод
		void Out(ofstream &ofst);     // вывод 
		int MesLength();
		cezar() {} // создание без инициализации.
	};
} // end simple_codes namespace
#endif

