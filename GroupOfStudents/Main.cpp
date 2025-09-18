#include <iostream>
#include "Subject.h"
#include "Student.h"
#include "Group.h"
using namespace std;


int main()
{
    Group group("KH-241");

    Subject* s1 = new Subject("Programming");
    Subject* s2 = new Subject("Operating systems");
    Subject* s3 = new Subject("Mathematics");

    group.AddSubject(s1);
    group.AddSubject(s2);
    group.AddSubject(s3);

    Student* st1 = new Student("Artyom", group.getSubjectsCount());
    group.AddStudent(st1);
	group.SetMark(0, 0, 12); // we have subjectCount == marksCount
    group.SetMark(0, 1, 11);
    group.SetMark(0, 2, 10);




    Student* st2 = new Student(*st1); 



    st2->setName("Andrey");
    group.AddStudent(st2);

    group.SetMark(1, 0, 8); // we have subjectCount == marksCount
    group.SetMark(1, 1, 7);
    group.SetMark(1, 2, 5);

    group.PrintMarksTable();
    group.PrintAverages();
    group.PrintMinMaxBySubject();

	return 0;
}