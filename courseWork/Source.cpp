#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "group.h"
#include "lesson.h"
#include <iostream>
#include "date.h"
#include <Windows.h>
#include <vector>
using namespace std;

//void SetColor(WORD wAttributes){
//	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hOUTPUT, wAttributes);
//}
//void SetPos(COORD dwCursorPosition){
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
//}
//void SetNewColor(){
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
//}
//void ReturnColor(){
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//}
//void Print(int stroka = -1){
//	COORD cd;
//	cd.X = 0; cd.Y = 0;
//	SetPos(cd);
//	if (stroka == 0){
//		SetNewColor();
//		cout << " ������� ��������\n";
//		ReturnColor();
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 1){
//		cout << " ������� ��������\n";
//		SetNewColor();
//		cout << " ������� ������\n";
//		ReturnColor();
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 2){
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		SetNewColor();
//		cout << " ������ ����\n";
//		ReturnColor();
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 3){
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		SetNewColor();
//		cout << " ������ �����\n";
//		ReturnColor();
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 4){
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		SetNewColor();
//		cout << " ������ ���������\n";
//		ReturnColor();
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 5){
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		SetNewColor();
//		cout << " ��������� ���\n";
//		ReturnColor();
//		cout << " ��������� � ������\n";
//		cout << " �����\n";
//	}
//	else if (stroka == 6){
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		SetNewColor();
//		cout << " ��������� � ������\n";
//		ReturnColor();
//		cout << " �����\n";
//	}
//	else
//	{
//		cout << " ������� ��������\n";
//		cout << " ������� ������\n";
//		cout << " ������ ����\n";
//		cout << " ������ �����\n";
//		cout << " ������ ���������\n";
//		cout << " ��������� ���\n";
//		cout << " ��������� � ������\n";
//		SetNewColor();
//		cout << " �����\n";
//		ReturnColor();
//	}
//}
//void PrintCur(COORD dwCursorPosition){
//	SetPos(dwCursorPosition);
//	SetNewColor();
//	cout << char(18);
//	ReturnColor();
//}
//void main()
//{
//	/*student *s = new student[2];
//	cin >> s[1];
//	cout << s[1];
//	system("pause");*/
//	setlocale(LC_ALL, "RUSSIAN");
//	COORD cd;
//	cd.X = 0;
//	cd.Y = 0;
//begin:
//	system("cls");
//	Print(cd.Y);
//	PrintCur(cd);
//	int ch = _getch();
//start:
//	ch = _getch();
//	int iCount;
//	student *sTmp=new student[100];
//	switch (ch)
//	{//77 - �����, 75 - ����, Esc - 27, 72-�����, 80-����, 13-enter
//	case 80: if (cd.Y<7){ cd.Y++; Print(cd.Y); PrintCur(cd); }
//			 else{ cd.Y = 0; Print(cd.Y); PrintCur(cd); } break;// ������� 80 ���, 72 ����
//	case 72: if (cd.Y>0){ cd.Y--; Print(cd.Y); PrintCur(cd); }
//			 else{ cd.Y = 7; Print(cd.Y); PrintCur(cd); } break;// ������� 80 ���, 72 ����
//	case 13:
//	{
//		switch (cd.Y)
//		{
//		case 0:
//		{
//			system("cls");
//			cout << "������� ���������� ���������: ";
//			cin >> iCount;
//			for (size_t i = 0; i < iCount; i++)
//			{
//				cin >> sTmp[i];
//				cout << "������� " << sTmp[i].GetFirstName() << " " << sTmp[i].GetLastName() << " ������." << endl;
//			}
//			goto begin; break;
//		}
//		case 1:
//		{
//			system("cls");
//			group gTmp;
//			cin >> gTmp;
//			int q;
//			cout << "*�������� �������� � ��� ������?\n";
//			cout << "1.��\n";
//			cout << "2.���\n";
//			cout << "�������� �������: ";
//			cin >> q;
//			goto begin; break;
//		}
//		case 2:
//		{
//
//		}
//		case 3:
//		{
//
//		}
//		case 4:
//		{
//			system("cls");
//			for (size_t i = 0; i < 2; i++)
//			{
//				cout << sTmp[i];
//			}
//			system("pause");
//			goto begin; break;
//		}
//		case 5:
//		{
//
//		}
//		case 6:
//		{
//
//		}
//		case 7:
//		{
//
//		}
//		}
//	}
//	case 27: goto end; break;
//	}// Esc
//	goto start;
//end:
//	cout << "\b ";
//	cd.Y = 3;
//	SetPos(cd);
//	cout << ch;
//}
void main()
{
	vector<group> VgTmp;
	group gTmp;
begin:
	setlocale(LC_ALL, "RUSSIAN");
	system("cls");
	cout << "***������� ����***\n"
		<< "1. ������� ������\n"
		<< "2. ������ �����\n"
		<< "3. ������ ����\n"
		<< "4. ������� ������\n"
		<< "5. ������� ��������\n"
		<< "6. ��������� ���\n"
		<< "7. ��������� � ������\n"
		<< "8. �����\n"
		<< "�������� �����: ";
	int line;
	cin >> line;
	switch (line)
	{
	case 1:
	{
		system("cls");
		cin >> gTmp;
		VgTmp.push_back(gTmp);
		cout << "�������� �������� � ��� ������?\n"
			<< "1. ��\n"
			<< "2. ���\n"
			<< "�������� �����: ";
		int q;
		cin >> q;
		switch (q)
		{
		case 1:
		{
			cout << "������� ���������� ���������: ";
			int sCount;
			cin >> sCount;
			student *sTmp = new student[sCount];
			for (size_t i = 0; i < sCount; i++)
			{
				cin >> sTmp[i];
				VgTmp[VgTmp.size()-1].AddStudent(&sTmp[i]);
				cout << "������� " << sTmp[i].GetFirstName() << " " << sTmp[i].GetLastName() << " ��� ��������." << endl;
			}
			system("pause");
		}
		default:
		{
			goto begin; break;
		}
		}
		goto begin;  break;
	}
	case 2:
	{
		system("cls");
		for (size_t i = 0; i < VgTmp.size(); i++)
		{
			cout << i + 1 << ". " << VgTmp[i].GetGroupName() << endl;
		}
		cout << "�������� ������(�� ������) ��� ������� 0 ����� �����: ";
		int gNum;
		cin >> gNum;
		if (gNum <= VgTmp.size() && gNum > 0)
		{
			cout << VgTmp[gNum-1] << endl;
			cout << "�������� ��������(�� ������) ��� ������� 0 ����� �����: ";
			int sNum;
			cin >> sNum;
			if (sNum <= VgTmp[gNum-1].GetCountOfStudents() && sNum > 0)
			{
				cout << VgTmp[gNum-1][sNum-1] << endl;
			}
			else if (sNum == 0)
			{
				goto begin; break;
			}
			else { cout << "������ �������� �� ����������!\n"; }
		}
		else if (gNum == 0)
		{
			goto begin;  break;
		}
		else { cout << "����� ������ �� ����������!\n"; }
		system("pause");
		goto begin;  break;
	}
	case 3:
	{
		system("cls");
		for (size_t i = 0; i < VgTmp.size(); i++)
		{
			cout << i + 1 << ". " << VgTmp[i].GetGroupName() << endl;
		}
		cout << "�������� ������(�� ������): ";
		int num;
		cin >> num;
		lesson lTmp("template", VgTmp[num - 1]);
		cin >> lTmp;
		lTmp.SetAttendance();
		lTmp.SetMarks();
		lTmp.FinishLesson();
		system("pause");
		goto begin; break;
	}
	case 4:
	{
		system("cls");
		for (size_t i = 0; i < VgTmp.size(); i++)
		{
			cout << i + 1 << ". " << VgTmp[i].GetGroupName() << endl;
		}
		cout << "�������� ������(�� ������): ";
		int num;
		cin >> num;
		cout << "�� ������������� ������ ������� ������ " << VgTmp[num - 1].GetGroupName() << "?" << endl;
		cout << "1. ��\n";
		cout << "2. ���\n";
		cout << "�����: ";
		int q;
		cin >> q;
		if (q == 1){ VgTmp[num - 1].DeleteGroup(); }
		else{ goto begin; break; }
		cout << "�������� ������ �������\n";
		system("pause");
		goto begin; break;
	}
	case 5:
	{
		system("cls");
		for (size_t i = 0; i < VgTmp.size(); i++)
		{
			cout << i + 1 << ". " << VgTmp[i].GetGroupName() << endl;
		}
		cout << "�������� ������(�� ������) ��� ������� 0 ����� �����: ";
		int gNum;
		cin >> gNum;
		if (gNum <= VgTmp.size() && gNum > 0)
		{
			cout << VgTmp[gNum-1] << endl;
			cout << "�������� ��������(�� ������) ��� ������� 0 ����� �����: ";
			int sNum;
			cin >> sNum;
			if (sNum <= VgTmp[gNum - 1].GetCountOfStudents() && sNum > 0)
			{
				cout << "�� ������������� ������ ������� �������� " << VgTmp[gNum - 1][sNum - 1].GetFirstName() << " " << VgTmp[gNum - 1][sNum - 1].GetLastName() << "?" << endl;
				cout << "1. ��\n";
				cout << "2. ���\n";
				cout << "�����: ";
				int q;
				cin >> q;
				if (q == 1){ VgTmp[gNum - 1][sNum - 1].DeleteStudent(); }
				else{ goto begin; break; }
				cout << "�������� ������ �������\n";
			}
		}
		else if (gNum == 0)
		{
			goto begin;  break;
		}
		else { cout << "����� ������ �� ����������!\n"; }
		system("pause");
		goto begin;  break;
	}
	case 6:
	{
		system("cls");
		for (size_t i = 0; i < VgTmp.size(); i++)
		{
			VgTmp[i].SaveToFile();
			for (size_t j = 0; j < VgTmp[i].GetCountOfStudents(); j++)
			{
				VgTmp[i][j].SaveToFile();
			}
		}
		cout << "������� ���������!\n";
		system("pause");
		goto begin; break;
	}
	case 7:
	{
		system("cls");
		student *s = new student;
		s->ReadFromFile();
		gTmp.AddStudent(s);
		for (size_t i = 0; i < gTmp.GetCountOfStudents(); i++)
		{
			cout << gTmp[i] << endl;
		}
		system("pause");
		goto begin; break;
	}
	}
}