#ifndef GENERICDEVICE_H
#define GENERICDEVICE_H

#include <iostream>
#include <string>

class GenericDevice     // use the virtual qualifier when needed
{
    private:
        std::string manufacturer;
        std::string description;
        std::string serialNumber;
    public:
        GenericDevice(const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        virtual std::string getManufacturer() const;
        virtual std::string getDescription() const;
        virtual std::string getSerialNumber() const;
        virtual std::string getType() const;
        virtual void print() const;
        ~GenericDevice(){}
};

#endif
