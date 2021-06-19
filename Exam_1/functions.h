#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_PATIENTS = 100;

struct patient
{
    string fname;
    string lname;
    string SSN;
    int age;
};

int readPatients(patient patients[])
{
    int count = 0;

    while (cin >> patients[count].fname >> patients[count].lname >> patients[count].SSN >> patients[count].age){
	    count++;
    }
    return count;
}

patient oldestPatient(patient patients[], int size)
{
    int i, max, old;
    
    max = patients[0].age;
    for (i = 0; i < size; ++i)
    {
        if (max <= patients[i].age)
        {
            max = patients[i].age;
        }
    }
    
    for (i = 0; i < size; ++i)
    {
        if (max == patients[i].age)
        {
            old = i;
            break;
        }
    }
    return patients[old];
}

double averageAge(patient patients[], int size)
{
   int i, sum;
   double avg, sum_doub;
   
   for(i = 0; i < size; ++i)
   {
       sum = patients[i].age + sum;
   }
   sum_doub = sum;
   avg = sum_doub / size;
   return avg;
}

#endif
