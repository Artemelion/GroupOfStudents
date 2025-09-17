#include "Student.h"
#include "Subject.h"

#pragma once
class Group
{
	char* name;
	Student* StudentsList;
	int countStudents;

	Student** SubjectMarksList;

// + в main ещё нужно создать двухмерный динамический
// массив группы студентов + подвязать SubjectMarksList
public:
	Group();
	Group(const char* _name, Student* _StudentsList, int _countStudents, Subject* _subjectList, int _countSubjects);
	~Group();
	Student* GetMarkList();
	Student* SetMarkList(int* marks, int size);
	/*Student* AddMarkList(int* marks, int size);
	Student* DeleteMarkList();
	Student* EditMarkList(int index, int mark);*/
	Student* PrintMarkList();
	Student* AverageMarkList();
	Student* MaxMarkList();
	Student* MinMarkList();
	
	void PrintAll();	

	void GetName();
	Student GetStudent(int index);
	int GetCountStudents();
	Subject GetSubject(int index);
	int GetCountSubjects();

	void SetName(const char* _name);
	void SetStudent(int index, Student student);
	void SetCountStudents(int _countStudents);
	void SetSubject(int index, Subject subject);
	void SetCountSubjects(int _countSubjects);
};

