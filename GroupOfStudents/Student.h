#pragma once

class Student
{
private:
    char* name;
    int* marks;
	int marksCount; // edit size to marksCount to understand better

public:
    Student();
    Student(const char* _name, int _marksCount);
    Student(const Student& _obj);
    ~Student();

    char* getName();
    void setName(const char* _name);

    int* getMarks();
    void setMarks(const int* _marks, int _count);

    int getMarksCount();
    void setMarksCount(int _newCount);

    int getMark(int _subjectIndex);
    void setMark(int _subjectIndex, int _value);

    void Print();
    double getAverage();

    
};
