// Write the implementation of the student class here
#include "student.h"
#include <iostream>
#include <string>

student::student(const std::string & _fname, const std::string & _lname, int _PSID, int _ngrades)
{
	fname = _fname;
	lname = _lname;
	PSID = _PSID;
	ngrades = _ngrades;
	grades = new int[ngrades];
}

student::student(const student & objToCopy)
{
	fname = objToCopy.fname;
	lname = objToCopy.lname;
	PSID = objToCopy.PSID;
	ngrades = objToCopy.ngrades;
	grades = new int[ngrades]; // allocate memory for array,not a private member
	for(int i = 0; i < ngrades; i++)
	{
		grades[i] = objToCopy.grades[i];
	}
}

student & student::operator = (const student &RHS)
{
	fname = RHS.fname;
	lname = RHS.lname;
	PSID = RHS.PSID;
	ngrades = RHS.ngrades;
	grades = new int[ngrades]; // allocate memory for array,not a private member
	if(this != &RHS)
	{
		for(int i = 0; i < ngrades; i++)
		{
			grades[i] = RHS.grades[i];
		}
	}
	return *this;
}

student::~student()
{
	delete [] grades;
}

void student::setGrades()
{
	for(int i = 0; i < ngrades; i++)
	{
		std::cin >> grades[i];
	}
}

void student::print() const
{
	std::cout << fname << " " << lname << " " << PSID << " ";
	for(int i = 0; i < ngrades; i++)
	{
		std::cout << grades[i] << " ";
	}
	std::cout << std::endl;
}
