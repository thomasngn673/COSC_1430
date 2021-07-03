/* Write the implementation of the ElectronicStoreInventory class here */
#include "ElectronicStoreInventory.h"
#include "Printer.h"
#include "Computer.h"

ElectronicStoreInventory::ElectronicStoreInventory()
{
    size = MAX_SIZE;
    count = 0;
    for (int i=0; i< size; i++)
        Inventory[i] = nullptr;
}

ElectronicStoreInventory::ElectronicStoreInventory(const ElectronicStoreInventory & objToCopy)
{
    size = objToCopy.size;
    count = objToCopy.count;
    for (int i =0; i < size; i++)
        if (objToCopy.Inventory[i]!=nullptr)
        {
            if (objToCopy.Inventory[i]->getType() == "Computer")
            {
                Inventory[i] = new Computer((Computer &)*objToCopy.Inventory[i]);
            }
            else if (objToCopy.Inventory[i]->getType() == "Printer")
            {
                Inventory[i] = new Printer((Printer &)*objToCopy.Inventory[i]);   
            }
            
        }
        else
        {
            Inventory[i] = nullptr;
        }
        
}

const ElectronicStoreInventory & ElectronicStoreInventory::operator = (const ElectronicStoreInventory & RHS)
{
    if (this != &RHS)
    {
        size = RHS.size;
        count = RHS.count;
        for (int i =0; i < size; i++)
            if (RHS.Inventory[i]!=nullptr)
            {
                if (RHS.Inventory[i]->getType() == "Computer")
                {
                    Inventory[i] = new Computer((Computer &)*RHS.Inventory[i]);
                }
                else if (RHS.Inventory[i]->getType() == "Printer")
                {
                Inventory[i] = new Printer((Printer &)*RHS.Inventory[i]);   
                }
            
            }
            else
            {
            Inventory[i] = nullptr;
            }   
    }
    return *this;
}

// Write the implementation of the addDevice function here. You can use the code provided on the copy constructor if needed.

// Write the implementation of the removeDevice function here. 

// Write the implementation of the print function here. 
std::cout << "Total number of computers in the store = " << /* Number of Computers identifier */ << std::endl;
std::cout << "Total number of printer in the store = " << /* Number of Printers identifier */ << std::endl;

// Write the implementation of the summary function here. 

ElectronicStoreInventory::~ElectronicStoreInventory()
{
    int _count = 0;
    int i=0;
    while(_count < count)
    {
        if (Inventory[i]!= nullptr)
        {
            delete Inventory[i];
            Inventory[i] = nullptr;
            _count++;
        }
        i++;
    }
}

