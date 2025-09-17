#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(nullptr), marks(nullptr), size(0){}
Student::Student(const char* _name, int* _marks, int _size)
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

	if (_marks != nullptr && _size > 0)
	{
		size = _size;
		marks = new int[size];
		for (int i = 0; i < size; i++)
		{
			marks[i] = _marks[i];
		}
	}
	else
	{
		size = 0;
		marks = nullptr;
	}
}
Student::~Student()
{
	delete[] name;
	delete[] marks;
}

void Student::AddStudent(const char* _name, int* _marks, int _size)
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

	if (marks != nullptr)
	{
		delete[] marks;
	}
	if (_marks != nullptr && _size > 0)
	{
		size = _size;
		marks = new int[size];
		for (int i = 0; i < size; i++)
		{
			marks[i] = _marks[i];
		}
	}
	else
	{
		size = 0;
		marks = nullptr;
	}
}
void Student::DeleteStudent()
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
		size = 0;
	}
}

void Student::Print()
{
	if (name != nullptr)
	{
		cout << "Name: " << name << endl;
	}
	else
	{
		cout << "Name: nullptr" << endl;
	}

	if (marks != nullptr && size > 0)
	{
		cout << "Marks: ";
		for (int i = 0; i < size; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Marks: nullptr" << endl;
	}
}

void Student::GetName()
{
	if (name != nullptr)
	{
		cout << "Name: " << name << endl;
	}
	else
	{
		cout << "Name: nullptr" << endl;
	}
}
int Student::GetMark(int index)
{
	if (marks != nullptr && index >= 0 && index < size)
	{
		return marks[index];
	}
	else
	{
		cout << "Invalid index or marks is nullptr" << endl;
		return -1;
	}
}
int Student::GetSize()
{
	return size;
}

void Student::SetName(const char* _name)
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
void Student::SetMark(int index, int mark)
{
	if (marks != nullptr && index >= 0 && index < size)
	{
		marks[index] = mark;
	}
	else
	{
		cout << "Invalid index or marks is nullptr" << endl;
	}
}
void Student::SetSize(int _size)
{
	if (marks != nullptr)
	{
		delete[] marks;
	}
	if (_size > 0)
	{
		size = _size;
		marks = new int[size];
		for (int i = 0; i < size; i++)
		{
			marks[i] = 0; // инициализируем нулями
		}
	}
	else
	{
		size = 0;
		marks = nullptr;
	}
}
