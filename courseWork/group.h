#ifndef GROUP_H
#define GROUP_H
#pragma once
#include "student.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class group
{
	vector<student*> a;
	string groupName;
public:
	//CONSTRUCTORS
	group(){};
	group(string groupName);
	group(const group &obj);
	//SETTERS
	void SetGroupName(string groupName){ this->groupName = groupName; }
	//GETTERS
	string GetGroupName()const{ return this->groupName; }
	int GetCountOfStudents()const{ return this->a.size(); }
	string GetStudents()const;
	string GetInfoAboutStudent(int pos);
	string GetInfo();
	//----------
	void AddStudent(student *obj);
	void DeleteStudent(student *obj);
	void DeleteGroup();
	~group(){}
	bool isEmpty()const;
	group& operator=(const group &obj);
	student& operator[](int pos){ return *this->a[pos]; }
	void Sort();
	ofstream& SaveToFile();
	ifstream& ReadFromFile();
	//FRIENDS
	friend ostream& operator<<(ostream &os, const group &obj);
	friend istream& operator>>(istream &is, group &obj);
	friend bool operator==(const group &a, const group &b);
};




#endif