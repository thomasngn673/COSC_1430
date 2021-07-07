#include <iostream>
#include "student.h"


int main()
{
    student myStudent("CARLOS","RINCON",123456,4);
    myStudent.setGrades();
    myStudent.print();
    return 0;
}
