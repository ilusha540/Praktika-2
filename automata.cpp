#include <iostream>
#include "automata.h"
using namespace std;

Automata::Automata() {
	printState();
};

void Automata::printState() {
	switch (state) {
			case(off):
				cout << "Автомат отключен." << endl;
				cash = 0;
				turned_off();
		break;

			case(wait):
				cout << "Ожидание действия:" << endl;
				turn_off();
				break;

			case(accept):
				cout << "Вставьте монеты: ";
				cin >> money;
				coin(money);

				cout << "Выберите напиток из списка ниже: " << endl;
				printMenu();
				cin >> i;
				choice(i);
				break;

			case(check):
				cout << "Проверка: " << endl;
				checking();
				break;

			case(cook):
				cout << "Готовка..." << endl;
				finish();
				break;

			default: cout << " Критическая ошибка." << endl;
	};
};

void Automata::on() {
	cout << "Включение... Добро пожаловать. " << endl;
	exit = "";
	state = wait;
	printState();
};

void Automata::coin(int money) {
	cash += money;
	cout << "Введено " << cash << " монет.\n" << endl;
};

void Automata::printMenu() {
	for (i = 0; i < 6; i++) {
		cout << i + 1 << ". " << menu[i]
			<< "\t" << price[i] << " монет." << endl;
	};
	i = 0;
};

void Automata::choice(int i) {
	cout << "Вы выбрали "
		<< menu[i - 1] << " напиток.\n" << endl;
	state = check;
	printState();
};

void Automata::checking() {
	if (cash >= price[i - 1]) {
		cash -= price[i - 1];
		cooking();
	}
	else {
		cout << "Недостаточно средств.";
		cancel();
	};
	printState();
};

void Automata::cancel() {
	cout << " Отмена. " << endl;
	state = wait;
	printState();
};

void Automata::cooking() {
	state = cook;
	printState();
};

void Automata::finish() {
	cout << "Ваш напиток " << menu[i - 1] << " готовится... ";
	cout << "Заберите напиток." << endl;
	state = wait;
};

void Automata::turn_off() {
	cout << "Хотите отключить автомат? [Да/Нет]" << endl;
	cin >> exit;
	if (exit == "Нет") {
		cout << "Сейчас на счету " << cash << " монет." << endl;
		state = accept;
		printState();
	}
	else {
		cout << "Good Bye!" << endl;
	}
};

void Automata::turned_off() {
	cout << "Хотите включить? [Да/Нет]" << endl;
	cin >> exit;

	if (exit == "Да") {
		on();
	}
};
Automata::~Automata() { };