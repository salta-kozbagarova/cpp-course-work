#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Date
{
	short month, day, year;
	short hour, min, seconds;
public:
	//SETTERS
	void SetDate(int day, int month, int year);
	void SetTime(int hour, int min, int seconds);
	//GETTERS
	string GetCurrentDate();
	string GetCurrentTime();
	string GetCurrentDT();
};

ostream& operator<<(ostream &os, Date &obj);
istream& operator>>(istream &is, Date &obj);

#endif