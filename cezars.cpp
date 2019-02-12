#include "cezar_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// Ввод параметров шифра Цезаря
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> message;//warning
		ifst >> rot;
	}
} // end simple_codes namespace

using namespace std;
namespace simple_codes {
	// Вывод параметров шифра Цезаря
	void cezar::Out(ofstream &ofst)
	{
		//-----------------------------------------------------------cezar codiing
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < 20)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) {
			int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
			if (tmp >= 0)
				str_mes[i] = alf[tmp + (rot % 26)];
		}
		//-----------------------------------------------------------cezar codiing
		ofst << "It is Cezar: rot = "
			<< rot << ", open = " << message << ", code = " << str_mes << endl;
	}
} // end simple_codes namespace
