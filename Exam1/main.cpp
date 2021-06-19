#include "functions.h"
#include <iostream>

using namespace std;

int main()
{
    patient patients[MAX_PATIENTS];
    int npatients = readPatients(patients);
    if (npatients > 0)
    {
        patient oldest = oldestPatient(patients,npatients);
        cout << "Oldest patient: " << oldest.fname << " " << oldest.lname << " " << oldest.SSN << " " << oldest.age << endl;
        cout << "Average age = " << fixed << setprecision(2) << averageAge(patients,npatients);
    }
    else{
        cout << "No patients found" << endl;
    }
    return 0;
    
}
