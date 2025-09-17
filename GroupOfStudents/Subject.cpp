#include "Subject.h"
#include <iostream>
using namespace std; 

Subject::Subject()
{
	name = nullptr;
}
Subject::Subject(const char* _name)
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
}
Subject::~Subject()
{
		delete[] name;
}

void Subject::GetSubject()
{
	if (name != nullptr)
	{
		cout << name << endl;
	}
}
void Subject::SetSubject(const char* _name)
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

void Subject::Print()
{
	if (name != nullptr)
	{
		cout << name << endl;
	}
}

