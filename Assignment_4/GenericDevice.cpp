#include "GenericDevice.h"
#include <iostream>
#include <string>

using namespace std;

GenericDevice::GenericDevice(const string & _manufacturer, const string & _description, const string & _serialNumber)
{
	manufacturer = _manufacturer;
	description = _description;
	serialNumber = _serialNumber;
}

string GenericDevice::getManufacturer() const
{
	return manufacturer;
}

string GenericDevice::getDescription() const
{
	return description;
}

string GenericDevice::getSerialNumber() const
{
	return serialNumber;
}

string GenericDevice::getType() const
{

}

void GenericDevice::print() const
{
	cout << "Manufacturer: " << manufacturer << ", Description: " << description << ", Type: Other:" << endl;
}

GenericDevice::~GenericDevice()
{
	manufacturer = 0;
	description = 0;
	serialNumber = 0;
}

