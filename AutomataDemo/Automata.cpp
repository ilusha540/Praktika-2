#include "Automata.h"
using namespace std;
#include <iostream>

Automata::Automata(void)
{
	printState();

	prices[0] = 32;
	prices[1] = 25;
	prices[2] = 55;
	prices[3] = 40;

	menu[0] = "Coffee";
	menu[1] = "Tea";
	menu[2] = "Pepsi";
	menu[3] = "Milk";

	state = off;

	cash = 0;


}


void Automata::coin(int usermoney)
{
	cash +=usermoney;
	cout << "On you account " << cash << endl;
}

void Automata::printMenu()
{
	for (numb = 0; numb < 4; numb++)
	{
		cout << numb + 1 << ". " << 
			menu[numb] << " price = " <<
			prices[numb] << endl; 
	}

}

void Automata::choice(int numb)
{	
	if ((numb < 1) || (numb > 4))
	{
		cout << "Not found this item" << endl;
		system("cls");
		cout << "Select a item from the list below:" << endl;
		printMenu();
		cout << "Choose a drink" << endl;
		cin >> numb;
		choice(numb);
	} else
	{
	
	cout << "Your choice - " << menu[numb-1] << endl;
	state = STATES::check;
	printState();
	}

}

void Automata::check()
{
	if (cash >= prices[numb-1])
	{
		cash = cash - prices[numb-1];
		cook();
	} else 
	{
		cout << "There are not enough funds on your account. Refill your balance" << endl;
		cancel();
		system("cls");
	}
}

void Automata::cancel()
{
	cout << "Cancel" << endl;
	state = wait;
	printState();
}


void Automata::cook()
{
	cout << "Wait... Your drink will be ready soon" << endl;
	state = STATES::cook;
	printState();
}

void Automata::finish()
{
	cout << "Take away your drink" << endl;
	cout << "Want something else? yes/no" << endl;
	cin >> resolve;
	if (resolve == "yes")
	{
		system("cls");
		state = wait;
		printState();
	}
	else 
	{
		system("cls");
		cout<< "Thank you!" << endl;
	}
}

void Automata::offauto()
{
	cout << "Do you want to turn off the machine? yes/no" << endl;
	cin >> resolve;
	if (resolve == "yes") 
	{
		state = off;
	} else
	{
		cout << "On your account " << cash << endl;
		state = STATES::accept;
	}
}

void Automata::on()
{
	cout << "Do you want to turn on the machine? yes/no" << endl;
	cin >> resolve;
	if (resolve == "yes") 
	{
		system("cls");
		cout << "Hello! The machine is on." << endl;
		state = wait;
		printState();
	} else
	{
		system("cls");
		cout << "Good bye!" << endl;
		//on();
	} 
}


void Automata::printState()
{
	switch (state) 
	{
	case(off):
		cout << "The machine does not work" << endl;
		on();
		break;

	case(wait):
		cout << "Wait... " << endl;

	case(accept):
		cout << "Insert money" << endl; 
		cin >> usermoney;
		system("cls");
		if (usermoney < 1000)
		{
			coin(usermoney);
			printMenu();
			cout << "Choose a drink" << endl;
			cin >> numb;
			system("cls");
			choice(numb);
			break;
		}
			else 
		{
			cout << "Maximum cash = 1000.\nEnter the amount again" << endl;
			cin >> usermoney;
			coin(usermoney);
			printMenu();
			cout << "Choose a drink" << endl;
			cin >> numb;
			system("cls");
			choice(numb);
			
		}

	case(STATES::check):
		cout << "Wait... We check the funds on the account" << endl;
		check();
		break;

	case(STATES::cook):
		cout << "Cooking... Cooking " << endl;
		finish();
		break;
	}
}