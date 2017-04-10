#pragma once
#include <iostream>
#include <string>
using namespace std;

enum STATES {off, wait, accept, check, cook};
class Automata
{
private:
	int cash, usermoney, numb;
	string menu[4];
	int prices[4];
	STATES state;
	string resolve;
public:
	Automata();
	void on();
	void offauto();
	void coin(int usermoney);
	void printMenu();
	void printState();
	void choice(int numb);
	void check();
	void cancel();
	void cook();
	void finish();
};
