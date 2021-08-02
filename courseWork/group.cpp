#include "group.h"

//CONSTRUCTORS
group::group(string groupName)
{ 
	this->groupName = groupName;
}
group::group(const group &obj)
{
	this->groupName = obj.groupName;
	if (!obj.isEmpty())
	{
		for (size_t i = 0; i < obj.a.size(); i++)
		{
			this->AddStudent(obj.a[i]);
		}
	}
}
//GETTERS
string group::GetStudents()const
{
	string tmp;
	if (!isEmpty())
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			tmp += to_string(i + 1);
			tmp += ".";
			tmp += a[i]->GetFirstName();
			tmp += " ";
			tmp += a[i]->GetLastName();
			tmp += "\n";
		}
		return tmp;
	}
	else
	{
		tmp += "This group has no students!\n";
		return tmp;
	}
}
string group::GetInfoAboutStudent(int pos)
{
	string tmp;
	if (pos < a.size())
	{
		tmp += a[pos - 1]->GetInfo();
		return tmp;
	}
	else
	{
		tmp += "ERROR: This group does not have a student in this position!\n";
		return tmp;
	}
}
string group::GetInfo()
{
	string tmp;
	tmp += "Group is: ";
	tmp += this->groupName;
	tmp += "\nStudents:\n";
	tmp += this->GetStudents();
	return tmp;
}
//-------------------------------
void group::AddStudent(student *obj)
{
	a.push_back(obj);
	this->Sort();
}
void group::DeleteStudent(student *obj)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		if (obj == a[i]) a.erase(a.begin()+i);
	}
}
void group::DeleteGroup()
{
	this->~group();
}
bool group::isEmpty()const
{
	return a.size() == 0;
}
group& group::operator=(const group &obj)
{
	if (this == &obj) return *this;
	this->groupName = obj.groupName;
	if (!obj.isEmpty())
	{
		for (size_t i = 0; i < obj.a.size(); i++)
		{
			this->AddStudent(obj.a[i]);
		}
	}
	return *this;
}

void group::Sort()
{
	sort(a.begin(), a.end(), studentSortPredicate);
}

ofstream& group::SaveToFile()
{
	string tmp;
	tmp += this->groupName;
	tmp += ";";
	for (size_t i = 0; i < a.size(); i++)
	{
		tmp += a[i]->GetFirstName();
		tmp += "@@";
		tmp += a[i]->GetLastName();
		if(i<(a.size()-1))tmp += "@#@";
	}
	ofstream oF("courseWork_group.csv", ios::out);
	oF << tmp;
	oF.close();
	return oF;
}
ifstream& group::ReadFromFile()
{
	ifstream iF("courseWork_group.csv", ios::in);
	string tmp;
	while (!iF.eof())
	{
		iF >> tmp;
		cout << tmp << endl;
	}
	size_t ind = tmp.find(';');
	this->groupName = tmp.substr(0, ind);
	tmp = tmp.substr(ind + 1);


	string tmp2;
	int count = 0, ind2;
	student *temp = new student[7];
	if (tmp.find("@#@") != -1)
	{
		while (tmp.find("@#@") != -1)
		{
			ind = tmp.find("@#@");
			tmp2 = tmp.substr(0, ind);
			ind2 = tmp2.find("@@");
			temp[count].SetFirstName(tmp2.substr(0, ind2));
			tmp2 = tmp2.substr(ind2 + 2);
			temp[count].SetLastName(tmp2);
			this->AddStudent(&temp[count]);
			tmp = tmp.substr(ind + 3);
			count++;
		}
	}
	else if (tmp.find("@@") != -1)
	{
		ind = tmp.find("@@");
		temp[count].SetFirstName(tmp.substr(0, ind));
		tmp = tmp.substr(ind + 2);
		temp[count].SetLastName(tmp);
		this->AddStudent(&temp[count]);
	}
	if (count > 0)
	{
		ind = tmp.find("@@");
		temp[count].SetFirstName(tmp.substr(0, ind));
		tmp = tmp.substr(ind + 2);
		temp[count].SetLastName(tmp);
		this->AddStudent(&temp[count]);
	}

	iF.close();
	return iF;
}
//FRIENDS
ostream& operator<<(ostream &os, const group &obj)
{
	os << "Group is: " << obj.groupName
		<< "\nStudents:\n"
		<<obj.GetStudents();
	return os;
}
istream& operator>>(istream &is, group &obj)
{
	cout << "Name of the group: ";
	is >> obj.groupName;
	for (size_t i = 0; i < obj.a.size(); i++)
	{
		is >> *obj.a[i];
	}
	return is;
}
bool operator==(const group &a, const group &b)
{
	return a.GetGroupName() == b.GetGroupName() && a.GetCountOfStudents() == b.GetCountOfStudents() && a.a == b.a;
}