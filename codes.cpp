
// Необходима подключить информацию обо всех имеющихся
// шифрах
#include "zamena_atd.h"
#include "cezar_atd.h"
#include "numeric_atd.h"
using namespace std;
#include "code_atd.h"

namespace simple_codes {
	// Ввод параметров обобщеннго шифра 
	code* code::In(ifstream &ifst) {
		code *sp;
		int k;
		ifst >> k;
		switch (k) 
		{
		case 1:
			sp = new zamena;
			break;
		case 2:
			sp = new cezar;
			break;
		case 3:
			sp = new numeric;
			break;
		default:
			return 0;
		}
		sp->InData(ifst);
		return sp;
	}
} // end simple_codes namespace

