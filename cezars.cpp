#include "cezar_atd.h"
#include <string>

using namespace std;
const int MAX_STRING_SIZE = 80;

namespace simple_codes {
	// Ввод параметров шифра Цезаря
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> rot;
		ifst >> message;
		ifst >> owner;
	}

	string CodingCezar(char message[MAX_STRING_SIZE], int rot)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < MAX_STRING_SIZE)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(str_mes[i]); // Номер текущего символа в alf
			if (tmp >= 0)
				str_mes[i] = alf[(tmp + (rot % 26)) % 26];
			tmp = ALF.find(str_mes[i]); // Номер текущего символа в ALF
			if (tmp >= 0)
				str_mes[i] = ALF[(tmp + (rot % 26)) % 26];
		}
		return str_mes;
	}

	// Вывод параметров шифра Цезаря
	void cezar::Out(ofstream &ofst)
	{
		ofst << "It is Cezar: rot = " << rot 
			<< ", open = " << message 
			<< ", code = " << CodingCezar(message,rot)
			<< ", owner = " << owner << ". ";
	}

	// Вычисление длины исходного текста
	int cezar::MesLength()
	{
		int length = 0;
		while (message[length] != '\0' && length < MAX_STRING_SIZE) length++;
		return length;
	}
} // end simple_codes namespace