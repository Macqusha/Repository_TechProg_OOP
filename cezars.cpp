#include "cezar_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// Ввод параметров шифра Цезаря
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> rot;
		ifst >> message;
	}
} // end simple_codes namespace

using namespace std;

string codingCezar(char message[20], int rot)
{
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
	return str_mes;
}
namespace simple_codes {
	// Вывод параметров шифра Цезаря
	void cezar::Out(ofstream &ofst)
	{
		ofst << "It is Cezar: rot = " << rot 
			<< ", open = " << message 
			<< ", code = " << codingCezar(message,rot) << "." << endl;
	}
} // end simple_codes namespace


namespace simple_codes {
		//Вычисление длины исходного текста
		int cezar::MesLength()
		{
			int length = 0;
			while (message[length] != '\0' && length < 20) length++;
			return length;
		}
} // end simple_codes namespace