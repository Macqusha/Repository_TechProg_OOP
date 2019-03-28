#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <fstream>
using namespace std;
namespace simple_codes {
	// Класс, обобщающает все имеющиеся шифры.
	// Является абстрактным, обеспечивая, тем самым, проверку интерфейса 
	const int maxStringeSize = 80;
	class code {
	public:
		char message[maxStringeSize];//Warning. При изменении размера массива обратить внимание на условие (см. кодирование в zamenas.cpp и cezars.cpp)
		char owner[maxStringeSize];//владелец текста
		//иденитфикация, порождение и ввод шифра из потока
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ввод
		virtual void Out(ofstream &ofst) = 0;     // вывод
		// вывод только шифров замены
		virtual void OutZamena(ofstream &ofst);
		//Вычисление длины исходного когда
		virtual int MesLength() = 0;
		// сравнение двух объектов
		bool Compare(code &other);
	};
	
} // end simple_codes namespace
#endif
