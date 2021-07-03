#include <iostream>

using namespace std;

Computer::Computer(const std::string & _cpu, const std::string & _diskType, const int _diskSizeGB, const int _memSizeGB, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber)
{

}

void Computer::print() const
{
std::cout << "Computer: CPU = " << /* cpu identifier */ << ", Disk type = " << /* diskType identifier */ << ", Disk size (GB) = " << /* diskSizeGB identifier */ << ", Manufacturer = " << /* Manufacturer identifier */ << ", Description = " << /* Description identifier */ << ", SN = " << /* SerialNumber identifier */ << std::endl;	
}

string Computer::getType() const
{

}

