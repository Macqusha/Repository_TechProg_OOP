#pragma once
#ifndef __numeric_atd__
#define __numeric_atd__
// ��������� �������� ������ code
#include "code_atd.h"
namespace simple_codes {
	// ���� ��������
	class numeric : public code {
	public:
		int digit; // �������� �����
		// �������������� ��������� ������
		void InData(ifstream &ifst);  // ����
		void Out(ofstream &ofst);     // ����� 
		int MesLength();
		numeric() {} // �������� ��� �������������.
	};
} // end simple_codes namespace
#endif

#pragma once
