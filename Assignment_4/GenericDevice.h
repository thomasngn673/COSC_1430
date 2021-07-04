#ifndef GENERICDEVICE_H
#define GENERICDEVICE_H

#include <iostream>
#include <string>

using namespace std;

class GenericDevice     // use the virtual qualifier when needed
{
    private:
        string manufacturer;
        string description;
        string serialNumber;
    public:
        GenericDevice(const string & _manufacturer, const string & _description, const string & _serialNumber);
        string getManufacturer() const;
        string getDescription() const;
        string getSerialNumber() const;
        virtual string getType() const;	// 'pure virtual class' allows 'Computer' and 'Printer' to overwrite the virtual function
        virtual void print() const;
        ~GenericDevice(){}
};

#endif
