#pragma once
#include <iostream>

class Date {
public:
	Date(int, int, int);
	void SetDate(int, int, int);
	void SetDate(Date);
	Date Yesterday();
	Date Tomorrow();
	void ShowDate();
	Date& operator ++();	//prefix
	Date operator ++(int);	//postfix
	Date& operator --();	//prefix
	Date operator --(int);	//postfix
	friend std::ostream& operator <<(std::ostream&, const Date&);
	friend std::istream& operator >> (std::istream&, Date&);
private:
	int day, month, year;
	bool endOfMonth(int);  //проверка за край на месеца
	bool leapYear(int);	   //проверка за високосна година
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
};
