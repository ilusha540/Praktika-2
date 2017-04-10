#include "Automata.h"

//private
void Automata::on(){
	system("cls");
	cout << "Launching...";
	delay(2);
	au_state = CHOICE;
}

void Automata::off(){
	au_state = OFF;
	system("cls");
	cout << "Shutdown...";
	delay(2);
	printState();
}

void Automata::coin(){
	au_state = CHOICE;
	int cash;
	cin >> cash;
	au_cash += cash;
}

void Automata::printMenu() {
	cout << "Your balance: " << au_cash << " rub.\n";
	cout << "Select a drink:" << endl;
	cout << "Number\t\tDrink\t\t\tCost\n";
	int num = 1;
	for(int i = 0; i < 5; i++){
		if(num < 5){
			cout << num << "\t\t" << au_menu[i];
			cout << "\t\t\t" << au_price[i] << "\n";
			num++;
		}
	}
	cout << "...or replenish the balance (usage 'r' for replenish).\n";
	cout << "Enter 'cancel' to receive change: ";
	choice();
}

void Automata::printState(){
	system("cls");
	switch (au_state){
	case CHOICE:
		printMenu();
		break;
	case CHECK:
		cout << "Not enough money. ";
		printMenu();
		break;
	case COOK:
		cook();
		finish();
		break;
	case OFF:	
		cout << "The machine is off. Enter start to 'start' the machine\n";
		cout << "or 'exit' for output\n";
		cout << "(Use 'stop' to stop the machine running): ";
		break;
	}
}

void Automata::choice(){
	string ch;
	cin >> ch;
	int num;
	if(ch == "1" || ch == "2" || ch == "3" || ch == "4"){
		num = stoi(ch);
		cout << num;
		check(num - 1);
	} else if( ch == "r") {
		coin();
	} else if( ch == "cancel"){
		cancel();
	} else if ( ch == "stop"){
		off();
	} else {
		printState();
	}
}

void Automata::check(int number){
	if(au_cash >= au_price[number]){
		au_cash -= au_price[number];
		au_state = COOK;
		
	} else {
		au_state = CHECK;
	}
	printState();
}

void Automata::cancel(){
	if(au_cash != 0){
		au_cash = 0;
		system("cls");
		cout << "Get change.";
		delay(3);
	}
	printState();
}

void Automata::cook(){
	cout << "Please wait..." << endl;
	delay(4);
}

void Automata::finish(){
	cout << "Drink is ready.";
	delay(2);
	au_state = CHOICE;
}

void Automata::delay(int sec){
	time_t timeReference, timeGet;
	time(&timeReference);
	timeReference += sec;
	while(true){
		if( time(&timeGet) == timeReference ){
			break;
		}
	}
}

//public
Automata::Automata(){
	au_state = OFF;
	au_cash = 0;
	string buff;
	int ibuff;
	ifstream fin("menu.txt");
	for(int i = 0; i < 4; i++){
		fin >> buff;
		au_menu[i] = buff;
		fin >> buff;
		ibuff = stoi(buff);
		au_price[i] = ibuff;
	}
	fin.close();
}

void Automata::offline(){
	string status;
	while(true){
		printState();
		cin.clear();
		
		if(au_state == OFF){
			cin >> status;
			if(status == "start") on();
			else if(status == "exit") break;
		} 
	}
}