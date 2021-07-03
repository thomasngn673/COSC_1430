#include <iostream>
#include <string>
#include "Computer.h"

using namespace std;

Computer::Computer(const string & _cpu, const string & _diskType, const int _diskSizeGB, const int _memSizeGB, const string & _manufacturer, const string & _description, const string & _serialNumber):GenericDevice(_manufacturer, _description, _serialNumber)
{
	cpu = _cpu;
	diskType = _diskType;
	diskSizeGB = _diskSizeGB;
	memSizeGB = _memSizeGB;
}

void Computer::print() const
{
	cout << "Computer: CPU = " << cpu << ", Disk type = " << diskType << ", Disk size (GB) = " << diskSizeGB << ", Manufacturer = " << getManufacturer() << ", Description = " << getDescription() << ", SN = " <<  getSerialNumber() << endl;	
}

string Computer::getType() const
{
	return "Computer";	
}

