#pragma once
#ifndef __zamena_atd__
#define __zamena_atd__
// ��������� �������� ������ code
#include "code_atd.h"
namespace simple_codes {
	// ���� ������
	class zamena : public code {
	public:
		int rule; // ������� ������
		// �������������� ��������� ������
		void InData(ifstream &ifst);  // ����
		void Out(ofstream &ofst);    // ����� 
		int MesLength();
		// ����� ������ ������ ������
		void OutZamena(ofstream &ofst);
		zamena() {} // �������� ��� �������������
	};
} // end simple_codes namespace
#endif
