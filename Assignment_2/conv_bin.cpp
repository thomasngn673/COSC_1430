#include <iostream>
#include<string>


std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
int main()
{
    std::string i= toBinary(10);
    std::cout<<i;
}
