#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <fstream>
using namespace std;
namespace simple_codes {
	// Класс, обобщающает все имеющиеся шифры.
	// Является абстрактным, обеспечивая, тем самым, проверку интерфейса 
	class code {
	public:
		char message[20];//Warning. При изменении размера массива обратить внимание на условие (см. кодирование в zamenas.cpp и cezars.cpp)
		//иденитфикация, порождение и ввод шифра из потока
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ввод
		virtual void Out(ofstream &ofst) = 0;     // вывод
		virtual int MesLength() = 0; //Вычисление длины исходного когда
		// сравнение двух объектов
		bool Compare(code &other);
	};
} // end simple_codes namespace
#endif
