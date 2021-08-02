#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class student
{
	string firstName;
	string lastName;
	int age;
	string sex;
	vector<int> marks;
	vector<bool> attendance;
public:
	//CONSTRUCTORS
	student(){};
	student(string firstName, string lastName, int age, string sex);
	//SETTERS
	void SetFirstName(string firstName){ this->firstName = firstName; }
	void SetLastName(string lastName){ this->lastName = lastName; }
	void SetAge(int age){ this->age = age; }
	void SetSex(string sex){ this->sex = sex; }
	void SetInfo(string firstName, string lastName, int age, string sex);
	void SetMark(int mark){ marks.push_back(mark); }
	void SetAttend(bool attend){ attendance.push_back(attend); }
	//GETTERS
	string GetFirstName()const{ return this->firstName; }
	string GetLastName()const{ return this->lastName; }
	int GetAge()const{ return this->age; }
	string GetSex()const{ return this->sex; }
	string GetInfo()const;
	string GetMarks()const;
	string GetAttend()const;
	int GetGPA()const;
	//-----------
	void DeleteStudent();
	~student(){}
	ofstream& SaveToFile();
	ifstream& ReadFromFile();
	//FRIENDS
	friend ostream& operator<<(ostream &os, const student &obj);
	friend istream& operator>>(istream &is, student &obj);
};
bool operator==(const student &a, const student &b);
bool studentSortPredicate(const student *a, const student *b);



#endif