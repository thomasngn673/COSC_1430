#include "Student1430.h"
#include <string>
using namespace std;

Student1430::Student1430()
{
	firstName = "";
	lastName = "";
	for(int i = 1; i <= 4; i++)
	{
		exams[i] = 0;
	}
	average = 0;
}

Student1430::Student1430(string f, string l, int e[])
{
	firstName = f;
	lastName = l;
	for(int i = 1; i <= 4; i++)
	{
		exams[i] = e[i];
	}
	updateAverage();
}

string Student1430::getFirstName()
{
	return firstName;
}

string Student1430::getLastName()
{
	return lastName;
}

double Student1430::getAverage()
{
	updateAverage();
	return average;
}

string Student1430::finalGrade()
{
	if (average >= 90)
	{
		return "A";
	}
	else if (average <90 && average >= 80)
	{
		return "B";
	}
	else if (average < 80 && average >= 70)
	{
		return "C";
	}
	else if (average < 70 && average >= 60)
	{
		return "D";
	}
	else if (average < 60)
	{
		return "F";
	}
}

void Student1430::setFirstName(string f)
{
	firstName = f;
}

void Student1430::setLastName(string l)
{
	lastName = l;
}

void Student1430::setExamGrade(int grade, int pos)
{
	exams[pos] = grade;
}

void Student1430::updateAverage()
{
	int tot = 0;
	for(int i = 1; i <= 4; i++)
	{
		tot = tot + exams[i];
	}
	average = tot/4;
}
