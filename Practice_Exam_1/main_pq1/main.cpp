#include <iostream>

using namespace std;

int main()
{
    int option;
    while(1)
    {
        cin >> option;
        switch (option)
        {
            case 1: cout << "Option 1" << endl;
                    break;
            case 2: cout << "Option 2" << endl;
                    break;
            case 3: cout << "Option 3" << endl;
                    break;
            case 4: cout << "Option 4" << endl;
                    break;
            case 0: break;
            default:cout << "Invalid Option" << endl;
                    break;
        }
    }

    return 0;
}
