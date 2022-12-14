#include <iostream>
#include<vector>
#include<string>

std::vector<std::string> fizzbuzz(int n);
template <class T> void print_vector(std::vector<T> arr);

int main()
{
    std::vector<std::string> fifteen = fizzbuzz(30);
    print_vector(fifteen);
    std::cout << std::endl;
    return 0;
}


std::vector<std::string> fizzbuzz(int n)
{
    std::vector<std::string> result;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 5 == 0 && i % 3 == 0)  // i%15 seems to be a better solution.
            result.push_back("FizzBuzz");
        else if (i % 5 == 0)
            result.push_back("Buzz");
        else if (i % 3 == 0)
            result.push_back("Fizz");
        else
            result.push_back(std::to_string(i));
    }

    return result;
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
