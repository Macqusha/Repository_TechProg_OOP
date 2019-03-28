#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "code_atd.h"

namespace simple_codes {
	// Сигнатуры требуемых внешних функций
	void Clear();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
}
using namespace std;

int main()
{
	ifstream in;
	in.open("in.txt");
	if (!in.is_open())
	{
		cout << "Error opening in.txt";
		return -1;
	}

	ofstream out;
	out.open("out.txt");
	if (!out.is_open())
	{
		cout << "Error opening out.txt";
		return -1;
	}

	cout << "Start" << endl;
	simple_codes::container* begin = new simple_codes::container;
	begin->In(in);
	out << "Filled container. " << endl;
	begin->Sort();
	begin->Out(out);
	out << endl;
	begin->OutZamena(out);
	out << endl;
	begin->Clear();
	out << "Empty container. " << endl;
	begin->Out(out);
	cout << "Stop" << endl;

	in.close();
	out.close();
	return 0;
}