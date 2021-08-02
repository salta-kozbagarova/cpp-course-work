#include "lesson.h"

//CONSTRUCTORS
lesson::lesson()
{
	Date tmp;
	this->date = tmp.GetCurrentDT();
}
lesson::lesson(string theme, group gr)
{
	this->theme = theme;
	this->gr = gr;
	Date tmp;
	this->date = tmp.GetCurrentDT();
}
//SETTERS
void lesson::SetAttendance()
{
	bool b;
	cout << "Insert attendance:" << endl;
	for (size_t i = 0; i < gr.GetCountOfStudents(); i++)
	{
		cout << gr[i].GetFirstName() << " " << gr[i].GetLastName() << ": ";
		cin >> b;
		if (b == true){ countPresent++; }
		gr[i].SetAttend(b);
	}
}
void lesson::SetMarks()
{
	int m;
	cout << "Set marks:" << endl;
	for (size_t i = 0; i < gr.GetCountOfStudents(); i++)
	{
		cout << gr[i].GetFirstName() << " " << gr[i].GetLastName() << ": ";
		cin >> m;
		gr[i].SetMark(m);
	}
}
//GETTERS
string lesson::GetFinishTime()const
{
	string tmp;
	Date dtmp;
	if (this->finished)tmp = dtmp.GetCurrentDT();
	else tmp = "Unfinished";
	return tmp;
}

string lesson::GetInfo()const
{
	string tmp;
	tmp += "Theme of the lesson: \t\t" + this->theme;
	tmp += "\nGroup: \t\t\t\t" + this->gr.GetGroupName();
	tmp += "\nStarted: \t\t\t" + this->date;
	tmp += "\nFinished: \t\t\t" + this->GetFinishTime();
	tmp += "\nCount of present students: \t" + to_string(this->countPresent);
	tmp += "\n";
	return tmp;
}
//---------------------------
ostream& operator<<(ostream &os, const lesson &obj)
{
	os << obj.GetInfo();
	return os;
}
istream& operator>>(istream &is, lesson &obj)
{
	string tmp;
	cout << "Enter the theme of the lesson: ";
	is >> tmp;
	obj.SetTheme(tmp);
	return is;
}