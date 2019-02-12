#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "code_atd.h"
namespace simple_codes {
	// ���������� ��������� �� ������ ����������� �������
	class container {
		enum { max_len = 100 }; // ������������ �����
		int len; // ������� �����
		code *cont[max_len];
	public:
		void In(ifstream &ifst);	// ������� ����� 
		void Out(ofstream &ofst);	// ������� ������
		//����� ����� ��������� ������
		int MesLength(ofstream &ofst);
		void Clear();	//������� ���������� �� ������
		void Sort(); // ���������� ����������
		container();	//������������� ����������
		~container() { Clear(); } //���������� ����������
	};
} // end simple_codes namespace
#endif

