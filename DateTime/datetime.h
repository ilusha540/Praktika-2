class DateTime {
private:
	int day, month, year;
	double difference;
	time_t t = time(0);   // get current date
	struct tm * now = localtime(&t);

	const char * weekday[7] = { "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };

	const char * monthname[12] = { "January", "February",
		"March", "April", "May",
		"June", "July", "August",
		"September", "October", "November",
		"December" };

public:
	DateTime();
	DateTime(int, int, int);
	DateTime(const DateTime &obj);
	void printToday();
	void printYesterday();
	void printTommorow();
	void printFuture(int);
	void printPast(int);
	void printMonth();
	void printWeekDay();
	~DateTime();
};

