#pragma once
class Subject
{
	char* name;
public:
	Subject();
	Subject(const char* _name);
	~Subject();

	void GetSubject();
	void SetSubject(const char* _name);

	void Print();

};

