#include "Printer.h"
#include <iostream>
#include <string>

using namespace std;

Printer::Printer(const int _ppm, const string & _color, const string & _manufacturer, const string & _description, const string & _serialNumber):GenericDevice(_manufacturer, _description, _serialNumber)
{
	ppm = _ppm;
	color = _color;
}

void Printer::print() const 
{
	cout << "Printer: PPM = " << ppm << ", Color Printer = " << color << ", Manufacturer = " << getManufacturer() << ", Description = " << getDescription() << ", SN = " << getSerialNumber() << endl;
}

string Printer::getType() const
{
	return "Printer";
}
