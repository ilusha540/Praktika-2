#include <iostream>
#include <fstream>
#include <string>

struct Phone {
	int number;
	std::string name;
	std::string address;
};

struct PhoneBook {
	Phone *phone;
	int count;
};


PhoneBook* load();
void menu();
void print(PhoneBook *phone_book);
void find(PhoneBook *phone_book);
void add();

int main() {
	setlocale(LC_ALL, "RUS");
	menu();
	return 0;
}

void print(PhoneBook *phone_book) {
	std::cout << "\nPhone Book: " << std::endl;
	for (int j = 0; j < phone_book->count; ++j)
		std::cout << phone_book->phone[j].number << ' ' << phone_book->phone[j].name << ' ' << phone_book->phone[j].address << std::endl;
	std::cout << std::endl;
}

void menu() {
	PhoneBook *phone_book = load();
	int ans;
	do {
		std::cout << "Please Enter: " << std::endl;
		std::cout << "1 - Find" << std::endl;
		std::cout << "2 - Print" << std::endl;
		std::cout << "3 - Add" << std::endl;
		std::cout << "4 - exit" << std::endl;

		std::cin >> ans;
		switch (ans) {
		case 1:
			find(phone_book);
			break;
		case 2:
			print(phone_book);
			break;
		case 3:
			add();
			phone_book = load();
			break;
		case 4:
			break;
		default:
			std::cout << "Invalid command" << std::endl;
		}
	} while (ans != 4);
	delete[] phone_book->phone;
	delete phone_book;
}

void find(PhoneBook *phone_book) {
	bool found = false;
	int ans, _number;
	std::string _name, _street;
	std::cout << "Find by: " << std::endl;
	std::cout << "1 - Name" << std::endl;
	std::cout << "2 - Number" << std::endl;
	std::cout << "3 - Street" << std::endl;
	std::cin >> ans;
	switch (ans) {
	case 1:
		std::cout << "Please enter Name: ";
		std::cin >> _name;
		for (int i = 0; i < phone_book->count; ++i) {
			if (_name == phone_book->phone[i].name) {
				std::cout << "Found!" << std::endl;
				std::cout << phone_book->phone[i].number << ' ' << phone_book->phone[i].name << ' ' << phone_book->phone[i].address << std::endl;
				found = true;
			}
		}
		break;
	case 2:
		std::cout << "Please enter Number: ";
		std::cin >> _number;
		for (int i = 0; i < phone_book->count; ++i) {
			if (_number == phone_book->phone[i].number) {
				std::cout << "Found!" << std::endl;
				std::cout << phone_book->phone[i].number << ' ' << phone_book->phone[i].name << ' ' << phone_book->phone[i].address << std::endl;
				found = true;
			}
		}
		break;
	case 3:
		std::cout << "Please enter Number: ";
		std::cin >> _street;
		for (int i = 0; i < phone_book->count; ++i) {
			if (_street == phone_book->phone[i].address) {
				std::cout << "Found!" << std::endl;
				std::cout << phone_book->phone[i].number << ' ' << phone_book->phone[i].name << ' ' << phone_book->phone[i].address << std::endl;
				found = true;
			}
		}
		break;
	default:
		std::cout << "Invalid command" << std::endl;
	}

	if (!found)
		std::cout << "Sorry, not found" << std::endl;

	std::cout << std::endl;
	std::cin.clear();
}

void add() {
	int number;
	std::string name, address;
	std::cout << "Please enter Number: ";
	std::cin >> number;
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Address: ";
	std::cin >> address;
	std::ofstream out("Text.txt", std::ios::app);
	out << '\n' << number << ' ' << name << ' ' << address;
	out.close();
}

PhoneBook* load() {
	std::ifstream in("Text.txt");
	PhoneBook *phone_book = new PhoneBook;
	phone_book->phone = new Phone[100];
	phone_book->count = 0;

	if (!in.good())
		std::cout << "File can't be found" << std::endl;

	while (!in.eof()) {
		in >> phone_book->phone[phone_book->count].number;
		in >> phone_book->phone[phone_book->count].name;
		in >> phone_book->phone[phone_book->count].address;
		phone_book->count++;
	}
	in.close();
	return phone_book;
}