#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

//SETTERS
void Date::SetDate(int day, int month, int year)
{
	month = (short)month;
	day = (short)day;
	year = (short)year;
}

void Date::SetTime(int hour, int min, int seconds)
{
	hour = (short)hour;
	min = (short)min;
	seconds = (short)seconds;
}
//GETTERS
string Date::GetCurrentDate()
{
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);

	month = (short)ptr->tm_mon + 1;
	day = (short)ptr->tm_mday;
	year = (short)ptr->tm_year + 1900;

	string tmp;
	tmp += to_string(day);
	tmp += ".";
	tmp += to_string(month);
	tmp += ".";
	tmp += to_string(year);
	tmp += "\n";
	return tmp;
}

string Date::GetCurrentTime()
{
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);

	hour = (short)ptr->tm_hour;
	min = (short)ptr->tm_min;
	seconds = (short)ptr->tm_sec;

	string tmp;
	tmp += to_string(hour);
	tmp += ":";
	tmp += to_string(min);
	tmp += ":";
	tmp += to_string(seconds);
	tmp += "\n";
	return tmp;
}

string Date::GetCurrentDT()
{
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);

	month = (short)ptr->tm_mon + 1;
	day = (short)ptr->tm_mday;
	year = (short)ptr->tm_year + 1900;

	hour = (short)ptr->tm_hour;
	min = (short)ptr->tm_min;
	seconds = (short)ptr->tm_sec;

	string tmp;
	tmp += to_string(day);
	tmp += ".";
	tmp += to_string(month);
	tmp += ".";
	tmp += to_string(year);
	tmp += " ";
	tmp += to_string(hour);
	tmp += ":";
	tmp += to_string(min);
	tmp += ":";
	tmp += to_string(seconds);
	return tmp;
}
//---------------------------
ostream& operator<<(ostream &os, Date &obj)
{
	os << obj.GetCurrentDT();
	return os;
}

istream& operator>>(istream &is, Date &obj)
{
	int day, month, year, hour, min, seconds;
	cout << "Enter a date:\nDay: ";
	is >> day;
	cout << "Month: ";
	is >> month;
	cout << "Year: ";
	is >> year;
	cout << "Enter a time:\nHour: ";
	is >> hour;
	cout << "Minute: ";
	is >> min;
	cout << "Second: ";
	is >> seconds;
	obj.SetDate(day, month, year);
	obj.SetTime(hour, min, seconds);
	return is;
}