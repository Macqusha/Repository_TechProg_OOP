#pragma once
#ifndef __zamena_atd__
#define __zamena_atd__
#include <string>
// ��������� �������� ������ code
#include "code_atd.h"
namespace simple_codes {
	// ���� ������
	class zamena : public code {
		int rule; // ������� ������
		char message[20];//warning
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst);  // ����
		void Out(ofstream &ofst);    // ����� 
		zamena() {} // �������� ��� �������������.
	};
} // end simple_codes namespace
#endif