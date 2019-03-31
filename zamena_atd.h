#pragma once
#ifndef __zamena_atd__
#define __zamena_atd__
// Требеутся описание класса code
#include "code_atd.h"
namespace simple_codes {
	// Шифр замены
	class zamena : public code {
	public:
		int rule; // Правило замены
		// Переопределяем интерфейс класса
		void InData(ifstream &ifst);  // Ввод
		void Out(ofstream &ofst);    // Вывод 
		int MesLength();
		// Вывод только шифров замены
		void OutZamena(ofstream &ofst);
		zamena() {} // Создание без инициализации
	};
} // end simple_codes namespace
#endif
