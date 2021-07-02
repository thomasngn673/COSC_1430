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
        std::string getManufacturer() const;
        std::string getDescription() const;
        std::string getSerialNumber() const;
        std::string getType() const;
        void print() const;
        ~GenericDevice(){}
};

#endif
