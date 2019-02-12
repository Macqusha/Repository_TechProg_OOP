// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "code_atd.h"
#include <string>

namespace simple_codes {
	// Сигнатуры требуемых внешних функций
	void Clear();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
}
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}

	ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		cout << "Ошибка с файлом";
		return -1;
	}
	cout << "Start" << endl;

	simple_codes::container* begin = new simple_codes::container;
	begin->In(in);
	begin->Out(out);

	cout << "Stop" << endl;

	in.close();
	out.close();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
