#ifndef ELECTRONICSSTOREINVENTORY_H
#define ELECTRONICSSTOREINVENTORY_H

#include "GenericDevice.h"
#include "Printer.h"
#include "Computer.h"

const int MAX_SIZE=100;

class ElectronicsStoreInventory
{
    private: 
        GenericDevice *Inventory[MAX_SIZE];
        int size;   // capacity of the store
        int count;  // number of devices currently in the store
    public:
        ElectronicsStoreInventory();
        ElectronicsStoreInventory(const ElectronicsStoreInventory & objToCopy);
        const ElectronicsStoreInventory & operator = (const ElectronicsStoreInventory & RHS);
        bool addDevice(const GenericDevice & _device);  // returned value: False if count == size, True if device added to inventory
        bool removeDevice(const std::string & _serialNumber); // returned value: False if device is not in the inventory, True if device deleted from inventory.
        void print() const;
        void summary() const;
        ~ElectronicsStoreInventory();
};

#endif

