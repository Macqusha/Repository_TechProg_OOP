#pragma once
#ifndef __cezar_atd__
#define __cezar_atd__
// ��������� �������� ������ code
#include "code_atd.h"
namespace simple_codes {
	// ���� ������
	class cezar : public code {
		int rot; // �����
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst);  // ����
		void Out(ofstream &ofst);     // ����� 
		cezar() {} // �������� ��� �������������.
	};
} // end simple_codes namespace
#endif

