#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "code_atd.h"
namespace simple_codes {
	// Простейший контейнер на основе одномерного массива
	class container {
		enum { max_len = 100 }; // Максимальная длина
		int len; // Текущая длина
		code *cont[max_len];
	public:
		void In(ifstream &ifst);	// Функция ввода 
		void Out(ofstream &ofst);	// Функция вывода
		// Вывод длины исходного текста
		int MesLength(ofstream &ofst);
		void OutZamena(ofstream &ofst); // Функция вывода шифров замены
		void Clear();	// Очистка контейнера от шифров
		void Sort(); // Сортировка контейнера
		container();	// Инициализация контейнера
		~container() { Clear(); } // утилизация контейнера
	};
} // end simple_codes namespace
#endif

