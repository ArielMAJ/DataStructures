#include <iostream>
#include "Implementations/_LIST.h"
using namespace std;

 
int main()
{
    List list(20);
    list.Create();

    cout << endl << "Starting List:" << endl;
    list.Display();
   
     return 0;
}

