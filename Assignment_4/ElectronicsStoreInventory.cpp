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
	if(size == count)	// Amount of devices is exceeding inventory capacity, return false
	{
		return false;
	}
	else if (count < size)
	{
		if (_device.getType() == "Computer")
		{
		    Inventory[count] = new Computer((Computer &)(_device));
		}
		else if (_device.getType() == "Printer")
		{
		    Inventory[count] = new Printer((Printer &)(_device));   
		}
		count = count + 1;	// Increase count of 'device' by 1
	}
	return true;
}

// Write the implementation of the removeDevice function here. 
bool ElectronicsStoreInventory::removeDevice(const std::string & _serialNumber)
{
	// Check if serialNumber is in inventory
	
	// Delete item of corresponding serialNumber and shift remaining items that follow deleted item
	for(int i = 0; i < count; i++)
	{
		if (Inventory[i]->getSerialNumber() == _serialNumber)
		{
			delete Inventory[i]; 	// Delete current item
			count = count - 1;	// Update count by removing an item
			for(int j = i; j < count; j++)
			{
				// If the next value is 'Computer', then shift it to the left
				if(Inventory[j+1]->getType() == "Computer")
				{
					Inventory[j] =  new Computer((Computer &)*(Inventory[j+1]));
				}
				
				// If next value is 'Printer', then shift it to the left
				else if(Inventory[j+1]->getType() == "Printer")
				{
					Inventory[j] = new Printer((Printer &)*(Inventory[j+1]));
				}
			}
			return true;
		}
	}
	return false;	// Return false if the serial number wasn't found
}

// Write the implementation of the print function here.
void ElectronicsStoreInventory::print() const
{
	for(int i = 0; i < count; i++)
	{
		Inventory[i]->print();
	}
}

// Write the implementation of the summary function here.
void ElectronicsStoreInventory::summary() const
{
	int compCount=0, printCount=0;

	for(int i = 0; i < count; i++)
	{
		if(Inventory[i]->getType() == "Computer")
		{
			compCount = compCount + 1;
		}
		else if(Inventory[i]->getType() == "Printer")
		{
			printCount = printCount + 1;
		}
	}
	std::cout << "Total number of computers in the store = " << compCount << std::endl;
	std::cout << "Total number of printer in the store = " << printCount << std::endl;
}

ElectronicsStoreInventory::~ElectronicsStoreInventory()
{
    int _count = 0;
    int i = 0;
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

