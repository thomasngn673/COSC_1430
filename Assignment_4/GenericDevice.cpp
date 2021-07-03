#include "GenericDevice.cpp"

using namespace std;


GenericDevice::GenericDevice(const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber)
{

}

string GenericDevice::getManufacturer() const
{

}

string GenericDevice::getDescription() const
{

}

string GenericDevice::getSerialNumber() const
{

}

string GenericDevice::getType() const
{

}

void GenericDevice::print() const
{
	cout << "Manufacturer: " << manufacturer << ", Description: " << description << ", Type: Other: << endl;
}

GenericDevice::~GenericDevice()
{

}

