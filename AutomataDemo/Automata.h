#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Automata{
private:
	int au_cash;
	enum {CHOICE, CHECK, COOK, OFF};
	int au_count;
	string au_menu[4];
	int au_price[4];
	int au_state;
	void on();
	void off();
	void coin();
	void printMenu();
	void printState();
	void choice();
	void check(int);
	void cancel();
	void cook();
	void finish();
	void delay(int);
public:
	Automata();
	void offline();
};