#pragma once
#ifndef __zamena_atd__
#define __zamena_atd__
// ��������� �������� ������ code
#include "code_atd.h"
namespace simple_codes {
	// ���� ������
	class zamena : public code {
		int rule; // ������� ������
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst);  // ����
		void Out(ofstream &ofst);    // ����� 
		// �����������
		virtual void MultiMethod(code *other, ofstream &ofst);
		virtual void MMZamena(ofstream &ofst);
		virtual void MMCezar(ofstream &ofst);
		zamena() {} // �������� ��� �������������.
	};
} // end simple_codes namespace
#endif
