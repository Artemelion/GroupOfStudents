#include "Group.h"
#include <iostream>
using namespace std;

Group::Group() :name(nullptr), students(nullptr), studentsCount(0), subjects(nullptr), subjectsCount(0) {}
Group::Group(const char* _name) :name(nullptr), students(nullptr), studentsCount(0), subjects(nullptr), subjectsCount(0)
{
    if (_name != nullptr)
    {
        name = new char[strlen(_name) + 1];
        strcpy_s(name, strlen(_name) + 1, _name);
    }
}
Group::Group(const Group& _obj) :name(nullptr), students(nullptr), studentsCount(0), subjects(nullptr), subjectsCount(0)
{
    if (_obj.name != nullptr)
    {
        name = new char[strlen(_obj.name) + 1];
        strcpy_s(name, strlen(_obj.name) + 1, _obj.name);
    }

    if (_obj.subjectsCount > 0 && _obj.subjects != nullptr)
    {
        subjectsCount = _obj.subjectsCount;
        subjects = new Subject * [subjectsCount];
        for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
        {
            if (_obj.subjects[subjectIndex] != nullptr)
            {
                subjects[subjectIndex] = new Subject(*(_obj.subjects[subjectIndex]));
            }
            else
            {
                subjects[subjectIndex] = nullptr;
            }
        }
    }

    if (_obj.studentsCount > 0 && _obj.students != nullptr)
    {
        studentsCount = _obj.studentsCount;
        students = new Student * [studentsCount];
        for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
        {
            if (_obj.students[studentIndex] != nullptr)
            {
                students[studentIndex] = new Student(*(_obj.students[studentIndex]));
            }
            else
            {
                students[studentIndex] = nullptr;
            }
        }
    }
}
Group::~Group()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }

    if (students != nullptr)
    {
        for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
        {
            if (students[studentIndex] != nullptr)
            {
                delete students[studentIndex];
                students[studentIndex] = nullptr;
            }
        }
        delete[] students;
        students = nullptr;
    }
    studentsCount = 0;

    if (subjects != nullptr)
    {
        for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
        {
            if (subjects[subjectIndex] != nullptr)
            {
                delete subjects[subjectIndex];
                subjects[subjectIndex] = nullptr;
            }
        }
        delete[] subjects;
        subjects = nullptr;
    }
    subjectsCount = 0;
}

void Group::AddStudent(Student* _ptr)
{
    if (_ptr == nullptr)
    {
        return;
    }
    Student** newArray = new Student * [studentsCount + 1];
    for (int i = 0; i < studentsCount; i++)
    {
        newArray[i] = students[i];
    }
    newArray[studentsCount] = _ptr;
    if (students != nullptr)
    {
        delete[] students;
    }
    students = newArray;
    studentsCount = studentsCount + 1;
}
void Group::AddSubject(Subject* _ptr)
{
    if (_ptr == nullptr)
    {
        return;
    }
    Subject** newArray = new Subject * [subjectsCount + 1];
    for (int j = 0; j < subjectsCount; j++)
    {
        newArray[j] = subjects[j];
    }
    newArray[subjectsCount] = _ptr;
    if (subjects != nullptr)
    {
        delete[] subjects;
    }
    subjects = newArray;
    subjectsCount = subjectsCount + 1;
}

char* Group::getName()
{
    return name;
}
void Group::setName(const char* _name)
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
}

int Group::getStudentsCount()
{
    return studentsCount;
}
int Group::getSubjectsCount()
{
    return subjectsCount;
}

Student* Group::GetStudent(int _index)
{
    if (_index < 0 || _index >= studentsCount || students == nullptr)
    {
        return nullptr;
    }
    return students[_index];
}
Subject* Group::GetSubject(int _index)
{
    if (_index < 0 || _index >= subjectsCount || subjects == nullptr)
    {
        return nullptr;
    }
    return subjects[_index];
}
void Group::SetMark(int _studentIndex, int _subjectIndex, int _value)
{
    if (_studentIndex < 0 || _studentIndex >= studentsCount)
    {
        return;
    }
    if (students == nullptr)
    {
        return;
    }
    if (students[_studentIndex] == nullptr)
    {
        return;
    }
    (*students[_studentIndex]).setMark(_subjectIndex, _value);
}
int Group::GetMark(int _studentIndex, int _subjectIndex)
{
    if (_studentIndex < 0 || _studentIndex >= studentsCount)
    {
        return 0;
    }
    if (students == nullptr)
    {
        return 0;
    }
    if (students[_studentIndex] == nullptr)
    {
        return 0;
    }
    return (*students[_studentIndex]).getMark(_subjectIndex);
}

void Group::PrintMarksTable()
{
    cout << "Table:\n";
    cout << "Name";
    for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
    {
        cout << ' ';
        if (subjects[subjectIndex] != nullptr && (*subjects[subjectIndex]).getName() != nullptr)
        {
            cout << (*subjects[subjectIndex]).getName();
        }
        else
        {
            cout << "Subject" << (subjectIndex + 1);
        }
    }
    cout << "\n";

    for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
    {
        if (students[studentIndex] != nullptr && (*students[studentIndex]).getName() != nullptr)
        {
            cout << (*students[studentIndex]).getName();
        }
        else
        {
            cout << "No name";
        }
        for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
        {
            cout << ' ' << GetMark(studentIndex, subjectIndex);
        }
        cout << "\n";
    }
}

double Group::GetStudentAverage(int _studentIndex)
{
    if (_studentIndex < 0 || _studentIndex >= studentsCount) { return 0.0; }
    if (students == nullptr || students[_studentIndex] == nullptr) { return 0.0; }
    if (subjectsCount <= 0) { return 0.0; }

    int sum = 0;
    int countInAverage = subjectsCount;

    for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
    {
        int value = (*students[_studentIndex]).getMark(subjectIndex);
        sum += value;
    }

    return (double)sum / (double)countInAverage;
}
double Group::GetSubjectAverage(int _subjectIndex)
{
    if (_subjectIndex < 0 || _subjectIndex >= subjectsCount) { return 0.0; }

    int sum = 0;
    int countInAverage = 0;

    for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
    {
        if (students != nullptr && students[studentIndex] != nullptr)
        {
            int value = (*students[studentIndex]).getMark(_subjectIndex);
            sum += value;
            countInAverage = countInAverage + 1;
        }
    }

    if (countInAverage == 0) { return 0.0; }
    return (double)sum / (double)countInAverage;
}
double Group::GetGroupAverage()
{
    if (subjectsCount <= 0 || studentsCount <= 0) { return 0.0; }

    int sum = 0;
    int countInAverage = 0;

    for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
    {
        if (students != nullptr && students[studentIndex] != nullptr)
        {
            for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
            {
                int value = (*students[studentIndex]).getMark(subjectIndex);
                sum += value;
                countInAverage = countInAverage + 1;
            }
        }
    }

    if (countInAverage == 0) { return 0.0; }
    return (double)sum / (double)countInAverage;
}


void Group::PrintAverages()
{
    cout << "Student averages:\n";
    for (int studentIndex = 0; studentIndex < studentsCount; studentIndex++)
    {
        if (students[studentIndex] != nullptr && (*students[studentIndex]).getName() != nullptr)
        {
            cout << (*students[studentIndex]).getName() << ": ";
        }
        else
        {
            cout << "No name: ";
        }
        cout << GetStudentAverage(studentIndex) << "\n";
    }

    cout << "Subject averages:\n";
    for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
    {
        if (subjects[subjectIndex] != nullptr && (*subjects[subjectIndex]).getName() != nullptr)
        {
            cout << (*subjects[subjectIndex]).getName() << ": ";
        }
        else
        {
            cout << "Subject" << (subjectIndex + 1) << ": ";
        }
        cout << GetSubjectAverage(subjectIndex) << "\n";
    }

    cout << "Group average: " << GetGroupAverage() << "\n";
}
void Group::PrintMinMaxBySubject()
{
    for (int subjectIndex = 0; subjectIndex < subjectsCount; subjectIndex++)
    {
        cout << "Subject ";
        if (subjects[subjectIndex] != nullptr && (*subjects[subjectIndex]).getName() != nullptr)
        {
            cout << (*subjects[subjectIndex]).getName() << ": ";
        }
        else
        {
            cout << "Subject" << (subjectIndex + 1) << ": ";
        }

        if (studentsCount == 0)
        {
            cout << "no students\n";
            continue;
        }

        int firstStudentIndex = -1;
        for (int i = 0; i < studentsCount; i++)
        {
            if (students != nullptr && students[i] != nullptr)
            {
                firstStudentIndex = i;
                break;
            }
        }

        if (firstStudentIndex == -1)
        {
            cout << "no students\n";
            continue;
        }

        int minValue = GetMark(firstStudentIndex, subjectIndex);
        int maxValue = minValue;
        int minStudentIndex = firstStudentIndex;
        int maxStudentIndex = firstStudentIndex;

        for (int studentIndex = firstStudentIndex + 1; studentIndex < studentsCount; studentIndex++)
        {
            if (students != nullptr && students[studentIndex] != nullptr)
            {
                int value = GetMark(studentIndex, subjectIndex);
                if (value < minValue) { minValue = value; minStudentIndex = studentIndex; }
                if (value > maxValue) { maxValue = value; maxStudentIndex = studentIndex; }
            }
        }

        cout << "min " << minValue << " by ";
        if (students[minStudentIndex] != nullptr && (*students[minStudentIndex]).getName() != nullptr)
        {
            cout << (*students[minStudentIndex]).getName();
        }
        else
        {
            cout << "No name";
        }
        cout << ", max " << maxValue << " by ";
        if (students[maxStudentIndex] != nullptr && (*students[maxStudentIndex]).getName() != nullptr)
        {
            cout << (*students[maxStudentIndex]).getName();
        }
        else
        {
            cout << "No name";
        }
        cout << "\n";
    }
}
