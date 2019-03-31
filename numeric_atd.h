#pragma once
#ifndef __numeric_atd__
#define __numeric_atd__
// Требуется описание класса code
#include "code_atd.h"
namespace simple_codes {
	// Шифр числовой
	class numeric : public code {
	public:
		int digit; // Параметр шифра
		// переопределяем интерфейс класса
		void InData(ifstream &ifst);  // Ввод
		void Out(ofstream &ofst);     // Вывод 
		int MesLength();
		numeric() {} // Создание без инициализации
	};
} // end simple_codes namespace
#endif

#pragma once
