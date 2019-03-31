#include "numeric_atd.h"
#include <string>

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes {
	// Ввод параметров числового шифра 
	void numeric::InData(ifstream &ifst)
	{
		ifst >> digit;
		ifst >> message;
		ifst >> owner;
	}

	string CodingNumeric(char message[maxStringeSize], int digit)
	{
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}
		string str_result = "";
		for (int i = 0; i < str_mes.length(); i++)
		{
			int tmp = alf.find(tolower(str_mes[i])); // Номер текущего символа в alf
			if (tmp >= 0)
				str_result += to_string((tmp + (digit % 26)) % 26);
			else
				str_result += str_mes[i];
		}
		return str_result;
	}

	// Вывод параметров числового шифра 
	void numeric::Out(ofstream &ofst)
	{
		ofst << "It is Numeric: digit = " << digit
			<< ", open = " << message
			<< ", code = " << CodingNumeric(message, digit) 
			<< ", owner = " << owner << ". ";
	}

	// Вычисление длины исходного текста
	int numeric::MesLength()
	{
		int length = 0;
		while (message[length] != '\0' && length < maxStringeSize) length++;
		return length;
	}
} // end simple_codes namespace
