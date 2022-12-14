// g++ -Wall -Wextra -o a.exe ./01_Vectors.cpp; ./a.exe; rm ./a.exe;

#include <iostream>
#include <vector>

template <class T>
void print(std::vector<T> arr);

int main()
{
    // Initializing empty vector;
    std::vector<int> arr0;
    std::cout << "Array 0:" << std::endl;
    std::cout << "\t";
    print(arr0);
    std::cout << "\tSize: " << arr0.size() << std::endl;
    std::cout << "\tCapacity: " << arr0.capacity() << std::endl << std::endl;

    // Initializing vector with a set of values;
    std::vector<int> arr1 = {1, 2, 3, 4, 11, 7};
    std::cout << "Array 1:" << std::endl;
    std::cout << "\t";
    print(arr1);
    std::cout << "\tSize: " << arr1.size() << std::endl;
    std::cout << "\tCapacity: " << arr1.capacity() << std::endl << std::endl;

    // Adding element at the end of the vector;
    arr1.push_back(15);
    std::cout << "\t";
    print(arr1);
    std::cout << "\tNew Size: " << arr1.size() << std::endl;
    std::cout << "\tNew Capacity: " << arr1.capacity() << std::endl << std::endl;

    // Removing element at the end of the vector;
    arr1.pop_back();
    std::cout << "\t";
    print(arr1);
    std::cout << "\tNew Size: " << arr1.size() << std::endl;
    std::cout << "\tNew Capacity: " << arr1.capacity() << std::endl << std::endl;

    // Initializing vector with fill constructor;
    std::vector<int> arr2(5, 8);
    std::cout << "Array 2:" << std::endl;
    std::cout << "\t";
    print(arr2);
    std::cout << "\tSize: " << arr2.size() << std::endl;
    std::cout << "\tCapacity: " << arr2.capacity() << std::endl << std::endl;



    return 0;
}

template <class T>
void print(std::vector<T> arr)
// Prints vector.
{
    std::cout << ("[");
    for (unsigned pos = 0; pos < arr.size(); ++pos)
    {
        std::cout << arr[pos];
        if (pos != arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return;
}
