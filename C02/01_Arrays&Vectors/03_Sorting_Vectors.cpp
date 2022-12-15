// g++ -Wall -Wextra -o a.exe ./03_Sorting_Vectors.cpp; ./a.exe; rm ./a.exe;
/*
The sort function works by passing the memory positions of the first and last value of the arrays.
E.g.
    sort(firstValueMemoryPosition, lastValueMemoryPosition);
    sort(vect.begin(), vect.end());
    sort(array, array + sizeOfArray);
*/

#include <iostream>     // std::cout, std::cin, etc;
#include <algorithm>    // std::sort(start,end);
#include <vector>       // std::vector<T>;

template <class T> void printVector(std::vector<T> arr);
void printArray(int array[], int length);

int main()
{
    // Initializing vector;
    std::vector<int> vect = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 2, 7, 4, 3, 2, 9};
    std::cout << "Initial vector:\t";
    // Printing initial vector;
    printVector(vect);
    // Sorting vector (built-in function);
    std::sort(vect.begin(), vect.end());
    std::cout << "Sorted vector:\t";
    // Printing sorted array;
    printVector(vect);

    std::cout << std::endl;

    // Initializing array;
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 2, 7, 4, 3, 2, 9};
    std::cout << "Initial array:\t";
    // Printing initial array;
    printArray(array, 16);
    // Sorting array (built-in function);
    std::sort(array, array + 16);
    std::cout << "Sorted array:\t";
    // Printing sorted array;
    printArray(array, 16);

    return 0;
}

template <class T>
void printVector(std::vector<T> arr)
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

void printArray(int array[], int length)
// Prints array of given length.
{
    printf("[");
    for (int pos = 0; pos < length; ++pos)
    {
        printf("%d", array[pos]);
        if (pos != length - 1)
            printf(", ");
    }
    printf("]\n");

    return;
}
