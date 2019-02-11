#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <string>
#include <fstream>
using namespace std;
namespace simple_codes {
	//  ласс, обобщающает все имеющиес€ шифры.
	// явл€етс€ абстрактным, обеспечива€, тем самым, 
	// проверку интерфейса 
	class code {
	public:
		// иденитфикаци€, порождение и ввод шифра из потока
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ввод
		virtual void Out(ofstream &ofst, string open_text) = 0;     // вывод
	};
} // end simple_codes namespace
#endif
