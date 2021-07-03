/* Write the implementation of the ElectronicsStoreInventory class here */
#include "ElectronicsStoreInventory.h"
#include "Printer.h"
#include "Computer.h"

ElectronicsStoreInventory::ElectronicsStoreInventory()
{
    size = MAX_SIZE;
    count = 0;
    for (int i = 0; i < size; i++)
    {
        Inventory[i] = nullptr;
    }
}

ElectronicsStoreInventory::ElectronicsStoreInventory(const ElectronicsStoreInventory & objToCopy)
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

const ElectronicsStoreInventory & ElectronicsStoreInventory::operator = (const ElectronicsStoreInventory & RHS)
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
bool ElectronicsStoreInventory::addDevice(const GenericDevice & _device)
{
	size = _device.size;
	count = _device.count;

	if(size == count)
	{
		return false;
	}
	else
	{
		for (int i =0; i < size; i++)
		    if (_device.Inventory[i]!=nullptr)
		    {
			if (_device.Inventory[i]->getType() == "Computer")
			{
			    Inventory[i] = new Computer((Computer &)*(_device).Inventory[i]);
			}
			else if (_device.Inventory[i]->getType() == "Printer")
			{
			    Inventory[i] = new Printer((Printer &)*(_device).Inventory[i]);   
			}
		    }
		    else
		    {
			Inventory[i] = nullptr;
		    }
		return true;
	}
}

// Write the implementation of the removeDevice function here. 
bool ElectronicsStoreInventory::removeDevice(const std::string & _serialNumber)
{
	for(int i=0; i < size; i++)
	{
		if (Inventory[i]->getSerialNumber() == _serialNumber)
		{
			delete Inventory[i];
			Inventory[i] = nullptr;
			return true;
		}
	}
	return false;
}

// Write the implementation of the print function here.
void ElectronicsStoreInventory::print() const
{
	for(int i = 0; i < size; i++)
	{
		if(Inventory[i]->getType() == "Computer")
		{
			Inventory[i]->getPrint();
		}
		else if(Inventory[i]->getType() == "Printer")
		{
			Inventory[i]->getPrint();
		}
	}
}

// Write the implementation of the summary function here.
void ElectronicsStoreInventory::summary() const
{
	std::cout << "Total number of computers in the store = " << count << std::endl;
	std::cout << "Total number of printer in the store = " << count << std::endl;
}

ElectronicsStoreInventory::~ElectronicsStoreInventory()
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

