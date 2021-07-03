#ifndef PRINTER_H
#define PRINTER_H

#include "GenericDevice.h"
#include <string>

class Printer: public GenericDevice // Use inheritance and the virtual qualifier when needed
{
    private:
        int ppm;
        std::string color;
    public:
        Printer(const int _ppm, const std::string & _color, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        void print() const;
        std::string getType() const;
};

#endif
