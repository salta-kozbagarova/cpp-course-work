#ifndef LESSON_H
#define LESSON_H
#pragma once
#include <string>
#include "date.h"
#include "group.h"
#include "student.h"
#include <iostream>
#include <fstream>
using namespace std;

class lesson
{
	string theme;
	string date;
	group gr;
	bool finished = false;
	int countPresent = 0;
public:
	//CONSTRUCTORS
	lesson();
	lesson(string theme, group gr);
	//SETTERS
	void SetAttendance();
	void SetMarks();
	void SetTheme(string theme){ this->theme = theme; }
	void SetGroup(group gr){ this->gr = gr; }
	//GETTERS
	string GetTheme(){ return this->theme; }
	group GetGroup(){ return this->gr; }
	string GetFinishTime()const;
	int GetCountPresent(){ return this->countPresent; }
	string GetInfo()const;
	//--------
	void FinishLesson(){ this->finished = true; }
};

ostream& operator<<(ostream &os, const lesson &obj);
istream& operator>>(istream &is, lesson &obj);



#endif