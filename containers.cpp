#include "container_atd.h"
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
	void container::Out(ofstream &ofst) {
		ofst << "Container contents " << len
			<< " elements." << endl;
		for (int i = 0; i < len; i++) {
			ofst << i << ": ";
			cont[i]->Out(ofst);
		}
	}

	// Вызов мультиметода для элементов контейнера
	void container::MultiMethod(ofstream &ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				cont[i]->MultiMethod(cont[j], ofst);
				cont[i]->Out(ofst);
				cont[j]->Out(ofst);
			}
		}
	}
} // end simple_codes namespace
