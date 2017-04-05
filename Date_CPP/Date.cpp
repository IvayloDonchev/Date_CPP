#include "Date.h"

Date::Date(int d=1, int m=1, int y=2000)
{
	SetDate(d, m, y);
}

void Date::SetDate(int d = 1, int m = 1, int y = 2000)
{
	if (m >= 1 && m <= 12) month = m;
	else month = 1;
	if (y >= 2000 && y <= 2200) year = y;
	else year = 2000;
	if (month == 2 && leapYear(year))
		day = (d >= 1 && d <= 29) ? d : 1;
	else
		day = (d >= 1 && d <= days[month]) ? d : 1;
}

void Date::SetDate(Date date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

Date Date::Yesterday()
{
	Date tmp;
	tmp.SetDate(day, month, year);
	if (tmp.day == 1 && tmp.month == 1)
	{
		tmp.day = 31;
		tmp.month = 12;
		--tmp.year;
	}
	else
		if (tmp.day == 1)
		{
			tmp.day = days[--tmp.month];
			if (tmp.month == 2 && leapYear(year))
				tmp.day = 29;
		}
		else
			--tmp.day;
	return tmp;
}

Date Date::Tomorrow()
{
	Date tmp;
	tmp.SetDate(day, month, year);
	if (endOfMonth(tmp.day) && month == 12)
	{
		tmp.day = 1;
		tmp.month = 1;
		++tmp.year;
	}
	else
		if (endOfMonth(tmp.day))
		{
			tmp.day = 1;
			++tmp.month;
		}
		else
			++tmp.day;
	return tmp;
}

void Date::ShowDate()
{
	std::cout << day << "." << month << "." << year << std::endl;
}

Date & Date::operator++()
{
	*this = Tomorrow();
	return *this;
}

Date Date::operator++(int)
{
	Date result = *this;
	*this = Tomorrow();
	return result;
}

Date & Date::operator--()
{
	*this = Yesterday();
	return *this;
}

Date Date::operator--(int)
{
	Date result = *this;
	*this = Yesterday();
	return result;
}

bool Date::endOfMonth(int d)
{
	if (month == 2 && leapYear(year))
		return d == 29;
	else
		return d == days[month];
}

bool Date::leapYear(int y)
{
	/*if(y%400==0) return true;
	if(y%100==0) return false;
	if(y%4==0) return true;
	return false; */
	//return (y%400==0)?true:((y%100==0)?false:((y%4)==0)?true:false);
	return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

std::ostream & operator<<(std::ostream &out, const Date &d)
{
	out << d.day << "." << d.month << "." << d.year;
	return out;
}

std::istream & operator>>(std::istream &ent, Date &d)
{
	int day, month, year;
	std::cout << "Enter the day: ";
	ent >> day;
	std::cout << "Enter the month: ";
	ent >> month;
	std::cout << "Enter the year: ";
	ent >> year;
	d.SetDate(day, month, year);
	return ent;
}
