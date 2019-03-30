#pragma once
#ifndef __numeric_atd__
#define __numeric_atd__
// Требуется описание класса code
#include "code_atd.h"
namespace simple_codes {
	// шифр числовой
	class numeric : public code {
	public:
		int digit; // параметр шифра
		// переопределяем интерфейс класса
		void InData(ifstream &ifst);  // ввод
		void Out(ofstream &ofst);     // вывод 
		int MesLength();
		numeric() {} // создание без инициализации.
	};
} // end simple_codes namespace
#endif

#pragma once
