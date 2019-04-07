#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <fstream>
using namespace std;
namespace simple_codes {
	// �����, ����������� ��� ��������� �����.
	// �������� �����������, �����������, ��� �����, �������� ���������� 
	class code {
	public:
		char message[20];//Warning. ��� ��������� ������� ������� �������� �������� �� ������� (��. ����������� � zamenas.cpp � cezars.cpp)
		//�������������, ���������� � ���� ����� �� ������
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ����
		virtual void Out(ofstream &ofst) = 0;     // �����
		// �����������
		virtual void MultiMethod(code *other, ofstream &ofst) = 0;
		virtual void MMZamena(ofstream &ofst) = 0;
		virtual void MMCezar(ofstream &ofst) = 0;
		virtual void MMNumeric(ofstream &ofst) = 0;
	};
} // end simple_codes namespace
#endif
