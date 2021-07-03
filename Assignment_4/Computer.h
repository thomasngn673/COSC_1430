#ifndef COMPUTER_H
#define COMPUTER_H

#include "GenericDevice.h"
#include <string.h>

class Computer: public GenericDevice // Use inheritance and the virtual qualifier when needed
{
    private:
        std::string cpu;
        std::string diskType;
        int diskSizeGB;
        int memSizeGB;
    public:
        Computer(const std::string & _cpu, const std::string & _diskType, const int _diskSizeGB, const int _memSizeGB, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        void print() const;
        std::string getType() const override;
};

#endif

