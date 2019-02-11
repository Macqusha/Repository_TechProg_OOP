#include "container_atd.h"
#include <string>
namespace simple_codes {
	// Инициализация контейнера
	container::container() : len(0) { }
	// Очистка контейнера от элементов
	void container::Clear() {
		for (int i = 0; i < len; i++) {
			delete cont[i];
		}
		len = 0;
	}

	// Ввод содержимого контейнера
	void container::In(ifstream &ifst) {
		while (!ifst.eof()) {
			if (((cont[len] = code::In(ifst)) != 0) && len < 99) {
				len++;
			}
		}
	}

	// Вывод содержимого контейнера
	void container::Out(ofstream &ofst, string open_text) {
		ofst << "Container contents " << len
			<< " elements." << endl;
		for (int i = 0; i < len; i++) {
			ofst << i << ": ";
			cont[i]->Out(ofst,open_text);
		}
	}
} // end simple_codes namespace
