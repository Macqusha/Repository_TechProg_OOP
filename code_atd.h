#pragma once
#ifndef __code_atd__
#define __code_atd__
#include <string>
#include <fstream>
using namespace std;
namespace simple_codes {
	// �����, ����������� ��� ��������� �����.
	// �������� �����������, �����������, ��� �����, 
	// �������� ���������� 
	class code {
	public:
		char message[20];
		// �������������, ���������� � ���� ����� �� ������
		static  code* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;  // ����
		virtual void Out(ofstream &ofst) = 0;     // �����
	};
} // end simple_codes namespace
#endif
