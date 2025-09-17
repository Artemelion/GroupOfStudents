#pragma once
class Student
{
	char* name;
	int* marks;
	int size;


	int countSubjects;
	int countOfMarks;

	Subject* SubjectList;
	Student* MarkList;

public: 
	Student();
	Student(const char* _name, int* _marks, int _size);
	~Student();

	void AddStudent(const char* _name, int* _marks, int _size);
	void DeleteStudent();
	void Print();

	void GetName();
	int GetMark(int index);
	int GetSize();

	void SetName(const char* _name);
	void SetMark(int index, int mark);
	void SetSize(int _size);

};

