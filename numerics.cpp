#include "numeric_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// Ввод параметров числового шифра 
	void numeric::InData(ifstream &ifst)
	{
		ifst >> digit;
		ifst >> message;
	}
} // end simple_codes namespace

using namespace std;

string codingNumeric(char message[20], int digit)
{
	string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < 20)
	{
		str_mes += message[i];
		i++;
	}
	string str_result = "";
	for (int i = 0; i < str_mes.length(); i++) {
		int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
		if (tmp >= 0)
			str_result += to_string((tmp + (digit % 26)) % 26);
	}
	return str_result;
}
namespace simple_codes {
	// Вывод параметров числового шифра 
	void numeric::Out(ofstream &ofst)
	{
		ofst << "It is Numeric: digit = " << digit
			<< ", open = " << message
			<< ", code = " << codingNumeric(message, digit) << endl;
	}

	// мультиметод
	void numeric::MultiMethod(code *other, ofstream &ofst) {
		other->MMNumeric(ofst);
	}
	//-----------------------------------------------------
	void numeric::MMZamena(ofstream &ofst) {
		ofst << "Zamena and Numeric" << endl;
	}
	//-----------------------------------------------------
	void numeric::MMCezar(ofstream &ofst) {
		ofst << "Cezar and Numeric" << endl;
	}	//-----------------------------------------------------
	void numeric::MMNumeric(ofstream &ofst) {
		ofst << "Numeric and Numeric" << endl;
	}
} // end simple_codes namespace
