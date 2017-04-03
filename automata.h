enum States { off, wait, accept, check, cook };

class Automata {

private:
	int i, money, cash;
	std::string exit = "";
	//string exit;

	const char * menu[6] = { "Pepsi", "Coca-cola", "Fanta",
		"Greenfield", "Espresso", "Mirinda" };
	int price[6] = { 40, 45, 50, 55, 60, 65 };

	States floor = off;
	int state = floor;

public:
	Automata();
	void printState();
	void on();
	void coin(int);
	void printMenu();
	void choice(int);
	void checking();
	void cancel();
	void cooking();
	void finish();
	void turn_off();
	void turned_off();
	~Automata();
};