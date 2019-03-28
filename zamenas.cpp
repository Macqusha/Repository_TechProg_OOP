#include "zamena_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ����� ������
	void zamena::InData(ifstream &ifst)
	{
		ifst >> rule;
		ifst >> message;
		ifst >> owner;
	}
} // end simple_codes namespace

using namespace std;
const int maxStringeSize = 80;

string codingZamena(char message[maxStringeSize], int rule)
{
	string alf = "abcdefghijklmnopqrstuvwxyz";
	string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
	string SZ2 = "badcfeghjilknmporqtsvuxwzy";
	string SZ3 = "shifrzamenybcdgjklopqtuvwx";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < maxStringeSize)
	{
		str_mes += message[i];
		i++;
	}

	for (int i = 0; i < str_mes.length(); i++) {
		int tmp = alf.find(tolower(str_mes[i])); //����� �������� ������� � alf
		if (tmp >= 0) {
			if (rule == 1) str_mes[i] = SZ1[tmp];
			if (rule == 2) str_mes[i] = SZ2[tmp];
			if (rule == 3) str_mes[i] = SZ3[tmp];
		}
	}
	return str_mes;
}

namespace simple_codes {
	// ����� ���������� ����� ������
	void zamena::Out(ofstream &ofst)
	{
		string rulename = "Incorrect rule number";
		if (rule == 1) rulename = "Atbash"; //�����
		if (rule == 2) rulename = "Pare-change"; //�������� ������
		if (rule == 3) rulename = "Keyword-change"; //���� ������ � ������� ������ SHIFRZAMENY
		ofst << "It is Zamena: rule = " << rulename 
			<<", open = " << message 
			<< ", code = " << codingZamena(message, rule)
			<< ", owner = " << owner << ". ";
	}

	//-----------------------------------------------------
	// ����� ������ ������ ��� ������ ������
	void zamena::OutZamena(ofstream &ofst) {
		Out(ofst);
	}
} // end simple_codes namespace

namespace simple_codes {
	//���������� ����� ��������� ������
	int zamena::MesLength()
	{
		int length = 0;
		while (message[length] != '\0' && length < maxStringeSize) length++;
		return length;
	}
} // end simple_codes namespace