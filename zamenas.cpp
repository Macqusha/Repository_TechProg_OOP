#include "zamena_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ����� ������
	void zamena::InData(ifstream &ifst)
	{
		ifst >> message;//warning
		ifst >> rule;
	}
} // end simple_codes namespace

using namespace std;
namespace simple_codes {
	// ����� ���������� ����� ������
	void zamena::Out(ofstream &ofst)
	{
		//-----------------------------------------------------------codiing
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
		string SZ2 = "badcfeghjilknmporqtsvuxwzy";
		string SZ3 = "shifrzamenybcdgjklopqtuvwx";
		string rulename = "Incorrect rule number";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < 20)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) {
			int tmp = alf.find(tolower(str_mes[i])); //����� �������� ������� � alf
			if (tmp >= 0) {
				if (rule == 1) {
					rulename = "Atbash"; //�����
					str_mes[i] = SZ1[tmp];
				}
				if (rule == 2) {
					rulename = "Pare-change"; //�������� ������
					str_mes[i] = SZ2[tmp];
				}
				if (rule == 3) {
					rulename = "Keyword-change"; //���� ������ � ������� ������ SHIFRZAMENY
					str_mes[i] = SZ3[tmp];
				}
			}
		}
		//-----------------------------------------------------------codiing
		ofst << "It is Zamena: rule = " << rulename <<", open = " << message 
			<< ", code = " << str_mes << "." << endl;
	}
} // end simple_codes namespace
