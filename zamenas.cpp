#include "zamena_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ����� ������
	void zamena::InData(ifstream &ifst)
	{
		ifst >> rule;
	}
} // end simple_codes namespace

using namespace std;
namespace simple_codes {
	// ����� ���������� ����� ������
	void zamena::Out(ofstream &ofst, string open_text)
	{
		//-----------------------------------------------------------codiing
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
		string SZ2 = "badcfeghjilknmporqtsvuxwzy";
		string SZ3 = "shifrzamenybcdgjklopqtuvwx";
		string rulename = "Incorrect rule number";
		for (int i = 0; i < open_text.length(); i++) {
			int tmp = alf.find(tolower(open_text[i])); //����� �������� ������� � alf
			if (tmp >= 0) {
				if (rule == 1) {
					rulename = "Atbash"; //�����
					open_text[i] = SZ1[tmp];
				}
				if (rule == 2) {
					rulename = "Pare-change"; //�������� ������
					open_text[i] = SZ2[tmp];
				}
				if (rule == 3) {
					rulename = "Keyword-change"; //���� ������ � ������� ������ SHIFRZAMENY
					open_text[i] = SZ3[tmp];
				}
			}
		}
		//-----------------------------------------------------------codiing
		ofst << "It is Zamena: rule = " << rulename
			<< ", code = " << open_text << "." << endl;
	}
} // end simple_codes namespace
