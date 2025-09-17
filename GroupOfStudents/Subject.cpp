#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject():name(nullptr) {}

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

Subject::Subject(const Subject& _obj)
{
    if (_obj.name != nullptr)
    {
        name = new char[strlen(_obj.name) + 1];
        strcpy_s(name, strlen(_obj.name) + 1, _obj.name);
    }
    else
    {
        name = nullptr;
    }
}

Subject::~Subject()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

char* Subject::getName()
{
	if (name != nullptr)
    { 
        return name;
	}
	else
	{
		cout << "we don't have name";
	}
}

void Subject::setName(const char* _name)
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
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

