#include "numeric_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ��������� ����� 
	void numeric::InData(ifstream &ifst)
	{
		ifst >> digit;
		ifst >> message;
		ifst >> owner;
	}
} // end simple_codes namespace

using namespace std;
const int maxStringeSize = 80;

string codingNumeric(char message[maxStringeSize], int digit)
{
	string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < maxStringeSize)
	{
		str_mes += message[i];
		i++;
	}
	string str_result = "";
	for (int i = 0; i < str_mes.length(); i++) {
		int tmp = alf.find(tolower(str_mes[i])); //����� �������� ������� � alf
		if (tmp >= 0)
			str_result += to_string((tmp + (digit % 26)) % 26);
	}
	return str_result;
}
namespace simple_codes {
	// ����� ���������� ��������� ����� 
	void numeric::Out(ofstream &ofst)
	{
		ofst << "It is Numeric: digit = " << digit
			<< ", open = " << message
			<< ", code = " << codingNumeric(message, digit) 
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace

namespace simple_codes {
	//���������� ����� ��������� ������
	int numeric::MesLength()
	{
		int length = 0;
		while (message[length] != '\0' && length < maxStringeSize) length++;
		return length;
	}
} // end simple_codes namespace