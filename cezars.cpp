#include "cezar_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ����� ������
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> rot;
	}
} // end simple_codes namespace

using namespace std;
namespace simple_codes {
	// ����� ���������� ����� ������
	void cezar::Out(ofstream &ofst, string open_text)
	{
		//-----------------------------------------------------------cezar codiing

		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		for (int i = 0; i < open_text.length(); i++) {
			int tmp = alf.find(tolower(open_text[i])); //����� �������� ������� � alf
			if (tmp >= 0)
				open_text[i] = alf[tmp + (rot % 26)];
		}
		//-----------------------------------------------------------cezar codiing
		ofst << "It is Cezar: rot = "
			<< rot << ", code = " << open_text << endl;
	}
} // end simple_codes namespace
