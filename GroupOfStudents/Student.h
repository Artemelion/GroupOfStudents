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

    int getMarksCount();
    int getMark(int _subjectIndex);
    void setMark(int _subjectIndex, int _value);

    double getAverage();
    void Print();

    /* 
    
    not needed methods and i don't add its due to difficul realization of it!!!
    
    int* getMarks();
    void setMarks(const int*, int);   
    void setMarksCount(int);
    */ 
};