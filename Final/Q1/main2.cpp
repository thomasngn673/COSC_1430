#include <iostream>
#include "student.h"

int main()
{
	char option;
	student myStudent("CARLOS","RINCON",123456,4);
	std::cin >> option;
	myStudent.setGrades();
	student tempStudent = myStudent;
	tempStudent.setGrades();
	myStudent.print();
	tempStudent.print();
}
