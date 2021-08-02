#include "student.h"

//CONSTRUCTORS
student::student(string firstName, string lastName, int age, string sex)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->sex = sex;
}
//SETTERS
void student::SetInfo(string firstName, string lastName, int age, string sex)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->sex = sex;
}
//GETTERS
string student::GetInfo()const
{
	string tmp;
	tmp += "First Name is:\t";
	tmp += this->firstName;
	tmp += "\nLast Name is:\t";
	tmp += this->lastName;
	tmp += "\nAge is:\t\t";
	tmp += to_string(this->age);
	tmp += "\nSex is:\t\t";
	tmp += this->sex;
	tmp += "\nMarks:\t\t";
	tmp += this->GetMarks();
	tmp += "Attendance:\t";
	tmp += this->GetAttend();
	tmp += "GPA:\t\t";
	tmp += to_string(this->GetGPA());
	tmp += "\n";
	return tmp;
}

string student::GetMarks()const
{
	string tmp;
	if (marks.size() > 0)
	{
		for (size_t i = 0; i < marks.size(); i++)
		{
			tmp += " " + to_string(marks[i]);
		}
		tmp += "\n";
		return tmp;
	}
	else
	{
		tmp += "This student doesn't have any marks yet.\n";
		return tmp;
	}
}

string student::GetAttend()const
{
	string tmp;
	if (attendance.size()>0)
	{
		for (size_t i = 0; i < attendance.size(); i++)
		{
			if (attendance[i])tmp += " present";
			if (!attendance[i])tmp += " absent";
		}
		tmp += "\n";
		return tmp;
	}
	else
	{
		tmp += "This student has not attended any lessons yet.\n";
		return tmp;
	}
}

int student::GetGPA()const
{
	int gpa=0;
	if (marks.size()>0)
	{
		for (size_t i = 0; i < marks.size(); i++)
		{
			gpa += marks[i];
		}
		gpa /= marks.size();
	}
	return gpa;
}
//----------------------------
void student::DeleteStudent()
{
	this->~student();
}
ofstream& student::SaveToFile()
{
	string tmp;
	tmp += this->firstName;
	tmp += ";";
	tmp += this->lastName;
	tmp += ";";
	tmp += to_string(this->age);
	tmp += ";";
	tmp += this->sex;
	tmp += ";";
	for (size_t i = 0; i < marks.size(); i++)
	{
		tmp += to_string(marks[i]);
		if (i < (marks.size() - 1))tmp += "@@";
	}
	tmp += ";";
	for (size_t i = 0; i < attendance.size(); i++)
	{
		tmp += to_string(attendance[i]);
		if (i < (attendance.size() - 1))tmp += "@@";
	}
	tmp += ";";
	tmp += to_string(this->GetGPA());
	ofstream oF("courseWork_student.csv", ios::out| ios::app);
	oF << tmp;
	oF.close();
	return oF;
}
ifstream& student::ReadFromFile()
{
	ifstream iF("courseWork_student.csv", ios::in);
	string tmp;
	while (!iF.eof())
	{
		iF >> tmp;
		cout << tmp << endl;
	}
	size_t ind = tmp.find(';');
	this->firstName = tmp.substr(0, ind);
	tmp = tmp.substr(ind + 1);

	ind = tmp.find(";");
	this->lastName = tmp.substr(0, ind);
	tmp = tmp.substr(ind + 1);

	ind = tmp.find(";");
	this->age = stoi(tmp.substr(0, ind));
	tmp = tmp.substr(ind + 1);

	ind = tmp.find(";");
	this->sex = tmp.substr(0, ind);
	tmp = tmp.substr(ind + 1);

	ind = tmp.find(";");
	string tmp2 = tmp.substr(0, ind);
	int count=0, m, ind2;
	while (tmp2.find("@@") != -1)
	{
		ind2 = tmp2.find("@@");
		m = stoi(tmp2.substr(0, ind2));
		this->SetMark(m);
		tmp2 = tmp2.substr(ind2 + 2);
		count++;
	}
	if (count > 0)
	{
		m = stoi(tmp2);
		this->SetMark(m);
	}
	tmp = tmp.substr(ind + 1);

	ind = tmp.find(";");
	string tmp3 = tmp.substr(0, ind);
	int a;
	count = 0;
	while (tmp3.find("@@") != -1)
	{
		ind2 = tmp3.find("@@");
		a = stoi(tmp3.substr(0, ind2));
		this->SetAttend(a);
		tmp3 = tmp3.substr(ind2 + 2);
		count++;
	}
	if (count > 0)
	{
		a = stoi(tmp3);
		this->SetAttend(a);
	}
	tmp = tmp.substr(ind + 1);

	iF.close();
	return iF;
}
ostream& operator<<(ostream &os, const student &obj)
{
	os << obj.GetInfo();
	return os;
}
istream& operator>>(istream &is, student &obj)
{
	cout << "Name?";
	is >> obj.firstName;
	cout << "Last Name?";
	is >> obj.lastName;
	cout << "Age?";
	is >> obj.age;
	cout << "Sex?";
	is >> obj.sex;
	return is;
}
bool operator==(const student &a, const student &b)
{
	return a.GetFirstName() == b.GetFirstName() && a.GetLastName() == b.GetLastName() && a.GetAge() == b.GetAge() && a.GetSex() == b.GetSex();
}
bool studentSortPredicate(const student *a, const student *b)
{
	string str1 = a->GetFirstName() + a->GetLastName();
	string str2 = b->GetFirstName() + b->GetLastName();
	return str1 < str2;
}