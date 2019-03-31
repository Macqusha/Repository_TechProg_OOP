#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <fstream>
using namespace std;
namespace simple_codes {
	// Класс, обобщающает все имеющиеся шифры
	// Является абстрактным, обеспечивая, тем самым, проверку интерфейса 
	const int maxStringeSize = 80;
	class code {
	public:
		char message[maxStringeSize]; //Исходный текст
		char owner[maxStringeSize];	// Владелец 
		// Иденитфикация, порождение и ввод шифра из потока
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // Ввод
		virtual void Out(ofstream &ofst) = 0;     // Вывод
		// Вывод только шифров замены
		virtual void OutZamena(ofstream &ofst);
		// Вычисление длины исходного кода
		virtual int MesLength() = 0;
		// Сравнение двух объектов
		bool Compare(code &other);
	};
	
} // end simple_codes namespace
#endif
