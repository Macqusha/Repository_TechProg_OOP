#include "numeric_atd.h"
#include <string>

using namespace std;
const int MAX_STRING_SIZE = 80;

namespace simple_codes {
	// Ввод параметров числового шифра 
	void numeric::InData(ifstream &ifst)
	{
		ifst >> digit;
		ifst >> message;
		ifst >> owner;
	}

	string CodingNumeric(char message[MAX_STRING_SIZE], int digit)
	{
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < MAX_STRING_SIZE)
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
		while (message[length] != '\0' && length < MAX_STRING_SIZE) length++;
		return length;
	}

	// Мультиметод
	void numeric::MultiMethod(code *other, ofstream &ofst) 
	{
		other->MMNumeric(ofst);
	}

	void numeric::MMZamena(ofstream &ofst) 
	{
		ofst << "Zamena and Numeric" << endl;
	}

	void numeric::MMCezar(ofstream &ofst) 
	{
		ofst << "Cezar and Numeric" << endl;
	}

	void numeric::MMNumeric(ofstream &ofst) 
	{
		ofst << "Numeric and Numeric" << endl;
	}

} // end simple_codes namespace
