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
		// Мультиметод
		virtual void MultiMethod(code *other, ofstream &ofst);
		virtual void MMZamena(ofstream &ofst);
		virtual void MMCezar(ofstream &ofst);
		virtual void MMNumeric(ofstream &ofst);
		cezar() {} // Создание без инициализации.
	};
} // end simple_codes namespace
#endif

