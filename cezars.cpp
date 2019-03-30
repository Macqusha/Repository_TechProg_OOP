#include "cezar_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// Ввод параметров шифра Цезаря
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> rot;
		ifst >> message;
		ifst >> owner;
	}
} // end simple_codes namespace

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes {
	string codingCezar(char message[maxStringeSize], int rot)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) {
			int tmp = alf.find(str_mes[i]); //номер текущего символа в alf
			if (tmp >= 0)
				str_mes[i] = alf[(tmp + (rot % 26)) % 26];
			tmp = ALF.find(str_mes[i]); //номер текущего символа в ALF
			if (tmp >= 0)
				str_mes[i] = ALF[(tmp + (rot % 26)) % 26];
		}
		return str_mes;
	}
} // end simple_codes namespace

namespace simple_codes {
	// Вывод параметров шифра Цезаря
	void cezar::Out(ofstream &ofst)
	{
		ofst << "It is Cezar: rot = " << rot 
			<< ", open = " << message 
			<< ", code = " << codingCezar(message,rot)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace


namespace simple_codes {
		//Вычисление длины исходного текста
		int cezar::MesLength()
		{
			int length = 0;
			while (message[length] != '\0' && length < maxStringeSize) length++;
			return length;
		}
} // end simple_codes namespace