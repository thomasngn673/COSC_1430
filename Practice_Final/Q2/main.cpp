#include "Student1430.h"
#include <iostream>

class FileNotFoundException {};

using namespace std;

int main(int argc, char**argv) 
{
   string s1, s2;
   int grade;
   int a = 0;
   
   Student1430 s;
   
   ifstream infile(argv[1]);
   
   // Define the try and cath blocks here
   try
   {
	   if(!infile)
	   {
		   throw FileNotFoundException();
	   }
	   else
	   {
		   infile.open(argv[1]);
	   }
   }
   catch (...)
   {
	   cout << "File not found.\n";
	   return -1;
   }
  
   
   while(!infile.eof())
   {
      infile >> s1 >> s2;
      s.setFirstName(s1);
      s.setLastName(s2);
      
      for(int i =0; i<4; i++)
      {
         infile >> grade;
         s.setExamGrade(grade, i+1);
      }
      
      cout << s.getFirstName() << " " << s.getLastName() << " has an average of " << s.getAverage();
      cout << " and will get a " << s.finalGrade() << endl;
      
      if(s.finalGrade() == "A")
         a++;
   }
   
   cout << endl << "Total A in class: " << a << endl;
         
   infile.close();
   
   return 0;
}
