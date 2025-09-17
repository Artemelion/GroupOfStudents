#pragma once

class Subject
{
private:
    char* name;

public:
    Subject();
    Subject(const char* _name);
    Subject(const Subject& _obj);
    ~Subject();

    char* getName();
    void setName(const char* _name);

    void Print();
};
