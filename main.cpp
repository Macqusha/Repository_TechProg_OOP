﻿#include <iostream>
#include <fstream>
#include <string>
#include "container_atd.h"
#include "code_atd.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect command line! "
			"Waited: command infile outfile" << endl;
		return -8;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	// Проверка наличия файла входных данных
	if (!ifst.is_open())
	{
		cout << "Error opening in.txt";
		return -6;
	}
	// Проверка возможности создания файла выходных данных
	if (!ofst.is_open())
	{
		cout << "Error opening out.txt";
		return -7;
	}

	// Проверка содержимого входного файла
	int i = 0; // Номер строки, которую будем считывать
	char* buferStr = new char; // Буфер для строки
	int typecode; // Тип шифра, с которым работаем
	int param; // Параметр шифра, с которым работаем
	string mes; // Исходный текст шифра, с которым работаем
	string owner; // Владелец шифра, с которым работаем

	// Цикл проверки
	while (!ifst.eof())
	{
		switch (i % 4) {
		case 0:
			i++;
			if (!(ifst >> typecode) || (typecode < 1) || (typecode > 3)) // Нельзя считать число или некорректный ключ
			{
				cout << "Error. Wrong type. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		case 1:
			i++;
			if (!(ifst >> param)) // Нельзя считать число
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -2;
			}
			if ((param < 0) || ((typecode == 1) && ((param < 1) || (param > 3))))  // Некорректный параметр
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -2;
			}
			break;
		case 2:
			i++;
			if (!(ifst >> mes)) // Нельзя считать строку
			{
				cout << "Error. Wrong message. Parametr #" << i << "." << endl;
				return -3;
			}
			break;
		case 3:
			i++;
			if (!(ifst >> owner)) // Нельзя считать строку
			{
				cout << "Error. Wrong owner. Parametr #" << i << "." << endl;
				return -4;
			}
			break;
		}
	}

	// Проверка, закончился ли файл в процессе введения шифра
	if (i % 4 != 0)
	{
		cout << "Error. Unexpected end of file. Parametr #" << i << "." << endl;
		return -5;
	}

	// Переоткрытие файла входных данных
	ifst.close();
	ifst.open(argv[1]);

	cout << "Start" << endl;
	simple_codes::container* begin = new simple_codes::container;
	begin->In(ifst);
	ofst << "Filled container. " << endl;
	begin->Sort();
	begin->Out(ofst);
	ofst << endl;
	begin->OutZamena(ofst);
	ofst << endl;
	begin->MultiMethod(ofst);
	ofst << endl;
	begin->Clear();
	ofst << "Empty container. " << endl;
	begin->Out(ofst);
	cout << "Stop" << endl;

	ifst.close();
	ofst.close();
	return 0;
}