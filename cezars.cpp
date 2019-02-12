#include "cezar_atd.h"
#include <string>
using namespace std;
namespace simple_codes {
	// ���� ���������� ����� ������
	void cezar::InData(ifstream &ifst) 
	{
		ifst >> rot;
		ifst >> message;
		ifst >> owner;
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
		int tmp = alf.find(tolower(str_mes[i])); //����� �������� ������� � alf
		if (tmp >= 0)
			str_mes[i] = alf[tmp + (rot % 26)];
	}
	return str_mes;
}
namespace simple_codes {
	// ����� ���������� ����� ������
	void cezar::Out(ofstream &ofst)
	{
		ofst << "It is Cezar: rot = " << rot 
			<< ", open = " << message 
			<< ", code = " << codingCezar(message,rot)
			<< ", owner = " << owner << "." << endl;
	}
} // end simple_codes namespace
