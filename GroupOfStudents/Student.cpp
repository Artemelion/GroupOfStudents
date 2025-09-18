#include "Student.h"
#include <iostream>
using namespace std;

Student::Student():name(nullptr), marks(nullptr), marksCount(0) {}
Student::Student(const char* _name, int _marksCount)
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

    if (_marksCount > 0)
    {
        marks = new int[_marksCount];
        for (int i = 0; i < _marksCount; i++)
        {
            marks[i] = 0;
        }
        marksCount = _marksCount;
    }
    else
    {
		cout << "We don't have marks count or/and _name" << endl;
        marks = nullptr;
        marksCount = 0;
    }
}
Student::Student(const Student& _obj)
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

    if (_obj.marks != nullptr && _obj.marksCount > 0)
    {
        marks = new int[_obj.marksCount];
        for (int i = 0; i < _obj.marksCount; i++)
        {
            marks[i] = _obj.marks[i];
        }
        marksCount = _obj.marksCount;
    }
    else
    {
        marks = nullptr;
        marksCount = 0;
    }
}
Student::~Student()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    marksCount = 0;
}

char* Student::getName() { return name; }
int Student::getMarksCount() { return marksCount; }

void Student::setName(const char* _name)
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
int Student::getMark(int _subjectIndex)
{
    if (marks == nullptr) { return 0; }
    if (_subjectIndex < 0) { return 0; }
    if (_subjectIndex >= marksCount) { return 0; }
    return marks[_subjectIndex];
}
void Student::setMark(int _subjectIndex, int _value)
{
    if (marks == nullptr) { return; }
    if (_subjectIndex < 0) { return; }
    if (_subjectIndex >= marksCount) { return; }
    marks[_subjectIndex] = _value;
}
double Student::getAverage()
{
    if (marks == nullptr) { return 0.0; }
    if (marksCount <= 0) { return 0.0; }
    int sum = 0;
    for (int i = 0; i < marksCount; i++)
    {
        sum += marks[i];
    }
    return (double)sum/(double)marksCount;
}

void Student::Print()
{
    cout << "Name: ";
    if (name != nullptr) { cout << name << "\n"; }
    else { cout << "No name\n"; }

    cout << "Marks: ";
    if (marks != nullptr && marksCount > 0)
    {
        for (int i = 0; i < marksCount; i++)
        {
            cout << marks[i];
            if (i < marksCount - 1) { cout << ' '; }
        }
        cout << "\n";
    }
    else
    {
        cout << "No marks\n";
    }
}
