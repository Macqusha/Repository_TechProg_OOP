#pragma once
#ifndef __cezar_atd__
#define __cezar_atd__
// Требуется описание класса code
#include "code_atd.h"
namespace simple_codes {
	// Шифр цезаря
	class cezar : public code {
	public:
		int rot; // Сдвиг
		// Переопределяем интерфейс класса
		void InData(ifstream &ifst);  // Ввод
		void Out(ofstream &ofst);     // Вывод 
		int MesLength();
		cezar() {} // Создание без инициализации.
	};
} // end simple_codes namespace
#endif

