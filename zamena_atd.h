#pragma once
#ifndef __zamena_atd__
#define __zamena_atd__
// Требеутся описание класса code
#include "code_atd.h"
namespace simple_codes {
	// шифр замены
	class zamena : public code {
		int rule; // правило замены
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst);  // ввод
		void Out(ofstream &ofst);    // вывод 
		int MesLength();
		// вывод только шифров замены
		void OutZamena(ofstream &ofst);
		zamena() {} // создание без инициализации.
	};
} // end simple_codes namespace
#endif
