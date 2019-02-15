#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "code_atd.h"
namespace simple_codes {
	// Простейший контейнер на основе одномерного массива
	class container {
		enum { max_len = 100 }; // максимальная длина
		int len; // текущая длина
		code *cont[max_len];
	public:
		void In(ifstream &ifst);	// функция ввода 
		void Out(ofstream &ofst);	// функция вывода
		//вывод длины исходного текста
		int MesLength(ofstream &ofst);
		void Clear();	//очистка контейнера от шифров
		void Sort(); // сортировка контейнера
		container();	//инициализация контейнера
		~container() { Clear(); } //утилизация контейнера
	};
} // end simple_codes namespace
#endif

