#include "Group.h"
#include <iostream>
using namespace std;

Group::Group() : name(nullptr), StudentsList(nullptr), countStudents(0), SubjectList(nullptr), countSubjects(0)
{}

Group::Group(const char* _name, Student* _StudentsList, int _countStudents, Subject* _subjectList, int _countSubjects)
{
	if (_name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	else
	{
		name = nullptr;
	}

	if (_StudentsList != nullptr && _countStudents > 0)
	{
		countStudents = _countStudents;
		StudentsList = new Student[countStudents];
		for (int i = 0; i < countStudents; i++)
		{
			StudentsList[i] = _StudentsList[i];
		}
	}
	else
	{
		countStudents = 0;
		StudentsList = nullptr;
	}

	if (_subjectList != nullptr && _countSubjects > 0)
	{
		countSubjects = _countSubjects;
		SubjectList = new Subject[countSubjects];
		for (int i = 0; i < countSubjects; i++)
		{
			SubjectList[i] = _subjectList[i];
		}
	}
	else
	{
		countSubjects = 0;
		SubjectList = nullptr;
	}
}
Group::~Group()
{
	delete[] name;
	delete[] StudentsList;
	delete[] SubjectList;
}

Student* Group::GetMarkList()
{
	if (MarkList != nullptr)
	{
		return MarkList;
	}
	else
	{
		cout << "No marks ." << endl;
		return nullptr;
	}
}

//Student* Group::SetMarkList(int* marks, int size)
//{
//
//	if (marks != nullptr && size > 0)
//	{
//		if (MarkList != nullptr)
//		{
//			delete[] MarkList;
//		}
//		MarkList = new Student[size];
//		for (int i = 0; i < size; i++)
//		{
//			MarkList[i] = marks[i];
//		}
//		return MarkList;
//	}
//	else
//	{
//		MarkList = nullptr;
//		return nullptr;
//	}
//}


Student* Group::PrintMarkList()
{
	return nullptr;
}

Student* Group::AverageMarkList()
{
	return nullptr;
}

Student* Group::MaxMarkList()
{
	return nullptr;
}

Student* Group::MinMarkList()
{
	return nullptr;
}


void Group::PrintAll()
{
	cout << "Group Name: ";
	if (name != nullptr)
	{
		cout << name << endl;
	}
	else
	{
		cout << "no of group name" << endl;
	}

	cout << "Students List:" << endl;

	if (StudentsList == nullptr || StudentsList <= 0)
	{
		cout << "no students" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < countStudents; i++)
		{
			StudentsList[i].Print();
		}
	}

	cout << "Subjects List:" << endl;

	if (SubjectList == nullptr || SubjectList <= 0)
	{
		cout << "no subjects" << endl;
		return;
	}
	else
	
	for (int i = 0; i < countSubjects; i++)
	{
		SubjectList[i].Print();
	}

}
void Group::GetName()
{
	if (name != nullptr)
	{
		cout << name << endl;
	}
	else
	{
		cout << "no of group name" << endl;
	}

}

Student Group::GetStudent(int index)
{
	return Student();
}

int Group::GetCountStudents()
{
	return countStudents;
}

Subject Group::GetSubject(int index)
{
	return Subject();
}

int Group::GetCountSubjects()
{
	return countSubjects;
}

void Group::SetName(const char* _name)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (_name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	else
	{
		name = nullptr;
	}
}

void Group::SetStudent(int index, Student student)
{
	if (index < 0 || index >= countStudents || StudentsList == nullptr)
	{
		cout << "Invalid index or StudentsList is nullptr" << endl;
		return;
	}
	else
	{
		StudentsList[index] = student;
	}
}

void Group::SetCountStudents(int _countStudents)
{
	if (StudentsList != nullptr)
	{
		delete[] StudentsList;
	}
	if (_countStudents > 0)
	{
		countStudents = _countStudents;
		StudentsList = new Student[countStudents];
	}
	else
	{
		countStudents = 0;
		StudentsList = nullptr;
	}
}

void Group::SetSubject(int index, Subject subject)
{
	if (index < 0 || index >= countSubjects || SubjectList == nullptr)
	{
		cout << "Invalid index or subjectList is nullptr" << endl;
		return;
	}
	else
	{
		SubjectList[index] = subject;
	}
}

void Group::SetCountSubjects(int _countSubjects)
{
	if (SubjectList != nullptr)
	{
		delete[] SubjectList;
	}
	if (_countSubjects > 0)
	{
		countSubjects = _countSubjects;
		SubjectList = new Subject[countSubjects];
	}
	else
	{
		countSubjects = 0;
		SubjectList = nullptr;
	}
}
