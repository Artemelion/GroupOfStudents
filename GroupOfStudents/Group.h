#pragma once
#include "Student.h"
#include "Subject.h"

class Group
{
private:
    char* name;

    Student** students;
    int studentsCount;

    Subject** subjects;
    int subjectsCount;

public:
    Group();
    Group(const char* _name);
    Group(const Group& _obj);
    ~Group();

    void AddStudent(Student* _ptr);
    void AddSubject(Subject* _ptr);

    char* getName();
    void setName(const char* _name);

    int getStudentsCount();
    int getSubjectsCount();

    Student* GetStudent(int _index);
    Subject* GetSubject(int _index);

    void SetMark(int _studentIndex, int _subjectIndex, int _value);
    int  GetMark(int _studentIndex, int _subjectIndex);

    void PrintMarksTable();
    double GetStudentAverage(int _studentIndex);
    double GetSubjectAverage(int _subjectIndex);
    double GetGroupAverage();


    void PrintAverages();
    void PrintMinMaxBySubject();
};
