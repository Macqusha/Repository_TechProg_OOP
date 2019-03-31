#include <iostream>
#include <fstream>
#include <string>
#include "container_atd.h"
#include "code_atd.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	// Начало проверок
	// Проверка наличия файла входных данных
	if (!ifst.is_open())
	{
		cout << "Error opening in.txt";
		return -5;
	}
	// Проверка возможности создания файла выходных данных
	if (!ofst.is_open())
	{
		cout << "Error opening out.txt";
		return -6;
	}

	// Проверка содержимого входного файла
	int i = 0; // Номер строки, которую будем считывать
	char* buferStr = new char; // Буфер для строки
	int typecode; // Тип шифра, с которым работаем
	int param; // Параметр шифра, с которым работаем
	string mes; // Исходный текст шифра, с которым работаем
	string owner; // Владелец шифра, с которым работаем
	int error_code = 0; // Код ошибки

	// Цикл проверки
	while (!ofst.eof() && (error_code == 0))
	{
		switch (i % 4) {
		case 0:
			if (!(ifst >> typecode)) // Нельзя считать число
			{
				if (!(ifst >> buferStr) && (i > 0)) // Конец данных и не пустой файл - ошибки нет
					goto noerrors;
				else  // Пустой файл или ошибка в данных
				{
					error_code = 1;
					break;
				}
			}
			else
			{
				if ((typecode < 1) || (typecode > 3)) // Ошибка в данных
				{
					error_code = 1;
					break;
				}
			}
			i++;
			break;
		case 1:
			if (!(ifst >> param)) error_code = 2;	// Внезапный конец файла или не число
			if ((typecode == 1) && ((param < 1) || (param > 3))) error_code = 2; // Несоответствие параметра допустимым ключам 1, 2, 3
			if ((typecode == 2) && (param < 0)) error_code = 2; // Несоответствие параметра допустимым сдвигам (неотрицательное)
			if ((typecode == 3) && (param < 0)) error_code = 2; // Несоответствие параметра допустимым числам (неотрицательное)
			i++;
			break;
		case 2:
			if (!(ifst >> mes)) error_code = 3; // Внезапный конец файла 
			i++;
			break;
		case 3:
			if (!(ifst >> owner)) error_code = 4; // Внезапный конец файла 
			i++;
			break;
		}
	}
	// Определение типа ошибки
	switch (error_code) {
	case 1:
		cout << "Error. Wrong type. Line " << i << "." << endl;
		return -1;
		break;
	case 2:
		cout << "Error. Wrong parameter. Line " << i << "." << endl;
		return -2;
		break;
	case 3:
		cout << "Error. Wrong message. Line " << i << "." << endl;
		return -3;
		break;
	case 4:
		cout << "Error. Wrong owner. Line " << i << "." << endl;
		return -4;
		break;
	}

	// Проверка оконечна без ошибок
noerrors:;
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
	begin->Clear();
	ofst << "Empty container. " << endl;
	begin->Out(ofst);
	cout << "Stop" << endl;

	ifst.close();
	ofst.close();
	return 0;
}