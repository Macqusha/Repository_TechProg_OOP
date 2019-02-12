#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "code_atd.h"
#include <string>
namespace simple_codes {
	// ѕростейший контейнер на основе одномерного массива
	class container {
		enum { max_len = 100 }; // максимальна€ длина
		int len; // текуща€ длина
		code *cont[max_len];
	public:
		void In(ifstream &ifst);     // ввод 
		void Out(ofstream &ofst);    // вывод 
		void Clear();  // очистка контейнера от шифров
		container();    // инициализаци€ контейнера
		~container() { Clear(); } // утилизаци€ контейнера
	};
} // end simple_codes namespace
#endif

