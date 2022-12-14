// g++ -Wall -Wextra -o a.exe ./02_2D_Vectors.cpp; ./a.exe; rm ./a.exe;

#include <iostream>
#include <vector>

template <class T> void print_vector(std::vector<T> arr);
template <class T> void print_2D_vector(std::vector< std::vector<T> > arr);

int main()
{
    // Initializing 2D vector. It's similar to 1D vectors;
    std::cout << "Array 0:" << std::endl;
    std::vector< std::vector<int> > arr0 =
    {
        {1, 2},
        {3, 4, 5},
        {6, 7, 8, 9},
        {13, 14},
        {15}
    };
    print_2D_vector(arr0);
    std::cout << "Size of Array 0: " << arr0.size() << std::endl;
    for (unsigned line = 0; line < arr0.size(); ++line)
        std::cout << "\tLength of line " << line << ": " << arr0[line].size() << std::endl;
    std::cout << "Capacity of Array 0: " << arr0.capacity() << std::endl;
    for (unsigned line = 0; line < arr0.size(); ++line)
        std::cout << "\tCapacity of line " << line << ": " << arr0[line].capacity() << std::endl;

    std::cout << std::endl << "Matrix 0:" << std::endl;
    std::vector< std::vector<int> > mat0 =
    {
        {11, 21, 31, 41},
        {12, 22, 32, 42},
        {13, 23, 33, 43},
    };
    print_2D_vector(mat0);
    return 0;
}

template <class T>
void print_vector(std::vector<T> arr)
// Prints vector.
{
    std::cout << ("[");
    for (T value : arr)
        std::cout << value << ", ";
    if (arr.size() > 0)
        std::cout << "\b\b";
    std::cout << "]";

    return;
}


template <class T>
void print_2D_vector(std::vector< std::vector<T> > arr)
// Prints vector.
{
    std::vector<T> last_element = arr[arr.size() - 1];
    arr.pop_back();

    std::cout << "[";
    for (std::vector<T> vect : arr)
    {
        print_vector(vect);
        std::cout << ",\n ";
    }
    print_vector(last_element);
    std::cout << "]" << std::endl;

    return;
}
