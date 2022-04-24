#include <iostream>
#include "Implementations/_LIST.h"
using namespace std;

 
int main()
{
    List list(20);
    list.Create();

    cout << endl << "Starting List:" << endl;
    list.Display();
    
    cout << "Max: " << list.Get(list.Max()) << "; ";
    cout << "Min: " << list.Get(list.Min()) << "; ";
    cout << "Avg: " << list.Avg() << "; ";
    cout << "Sum: " << list.Sum() << "; ";
    cout << "\nSetting list[0] = -1;" << endl;
    list.Set(0, -1);
    list.Display();

    cout << endl << "Appending (to the end):" << endl;
    list.Append(33);
    list.Display();

    cout << endl << "Inserting at positon \"1\":" << endl;
    list.Insert(1, 22);
    list.Display();

    cout << endl << "Popping at position \"1\":" << endl;
    cout << "Popped " << list.Pop(1) << "." << endl;
    list.Display();

    cout << endl << "Linear Search for value \"2\":" << endl;
    cout << "Found at position " << list.LinearSearch(2) << endl;
    list.Display();

    cout << endl << "Binary Search for value \"2\":" << endl;
    cout << "Found at position " << list.BinarySearch(2) << endl;
    list.Display();

    cout << endl << "Binary Search \"Left Most\" for value \"2\":" << endl;
    cout << "Found at position " << list.BinarySearchLeftMost(2) << endl;
    list.Display();

    cout << endl << "Reversed array:" << endl;
    list.Reverse();
    list.Display();

    cout << endl << "Reversed array:" << endl;
    list.Reverse();
    list.Display();

    cout << endl << "Sorted Insert:" << endl;
    list.SortedInsert(5);
    list.Display();

    cout << endl << "LeftShiftAll:" << endl;
    list.LeftShiftAll();
    list.Display();
    cout << endl << "IsSorted: " << list.IsSorted() << endl;

    cout << endl << "RightShiftAll:" << endl;
    list.RightShiftAll();
    list.Display();
    cout << endl << "IsSorted: " << list.IsSorted() << endl;

    return 0;
}

