#include <iostream>
using namespace std;

class List
{
private:
    int *A;
    int length;
    int max_length;
    // int sorted;

public:
    // Constructor
    List(int initial_size);

    // Methods
    void Create();
    void Display();
    void Append(int value);
    void Push(int value);
    void Insert(int index, int x);
    void SortedInsert(int value);
    void Delete(int value);
    int  Pop(int index);
    void Reverse();
    void RightShiftAll();
    void RightShiftRange(int start, int end);
    void LeftShiftAll();
    void LeftShiftRange(int start, int end);
    void Swap(int *x, int *y);
    // int  Find(int value);
    int  LinearSearch(int value);
    int  BinarySearch(int value);
    int  BinarySearchLeftMost(int value);
    void Set(int index, int value);
    int  Get(int index);
    int  Max();
    int  Min();
    int  Sum();
    float Avg();
    bool IsSorted();
    // void Sort();

    // Destructor
    ~List();
};

 
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


// ******************************************************************************** 
// Implementations of the class (could be in a diff file I think)

// Constructor
List::List(int initial_size)
{
    // We will assume the array won't be sorted after populated.
    // sorted = 1;
    // The current length is 0. The List is "empty".
    length = 0;
    // Saving the max length.
    max_length = initial_size;
    // allocating space for the vector.
    A = new int [initial_size];
}

// This "properly creates" the List.
void List::Create()
{
    cout << "List length: ";
    cin >> length;
    cout << endl << "Elements:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << "Position " << i << ": ";
        cin >> A[i];
    }
}

// Displays the List.
void List::Display()
{
    for(int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Appends to the end of the List.
void List::Append(int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        A[length] = value;
        length++;
    }
}

// Inserts at position 0.
void List::Push(int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        for(int i = length; i > 0; i--)
            A[i] = A[i-1];
        A[0] = value;
        length++;
    }
}

// Inserts at a given position.
void List::Insert(int index, int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        for(int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = value;
        length++;
    }
}

// Inserts at a given position.
void List::SortedInsert(int value)
{    
//     if (!sorted)
//     {
//         cout << "The array must be sorted for this to work." << endl;
//         return;
//     }

    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        int i;
        // if (sorted == 1)
        // {
        for (i = length; i > 0 && value < A[i - 1]; i--)
            A[i] = A[i-1];
        A[i] = value;
        // }
        // else if (sorted == -1)
        // {
        //     for (i = length; value > A[i] && i > 0; i--)
        //         A[i] = A[i-1];
        //     A[i] = value;
        // }
        length++;
    }
}

// Pops (deletes and returns a value) at a given index/position.
int List::Pop(int index)
{
    if (index >= length || index < 0)
    {
        cout << "Invalid index, returning 0." << endl;
        return 0;
    }

    // Saving the popped value for returning it later.
    int popped_value = A[index];

    // The vector will be shorter.
    length--;

    // Moving values to the front to occupy the value we're deleting.
    for (int i = index; i < length; i++)
        A[i] = A[i+1];

    // Returning the popped value.
    return popped_value; 
}

// Deletes a specific value and returns it.
void List::Delete(int value)
{
    // int index = Find(value);
    int index = LinearSearch(value);
    if (index >= 0)
        Pop(index);
}

void List::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int List::LinearSearch(int value)
{
    for(int i = 0; i < length; i++)
    {
        if(value == A[i])
        {
            // This moves the searched item to the first spot. It makes little sense to me tbh.
            // Swap(&A[i], &A[0]);


            // This is called "transposition". A little better than the one above (to me).
            // The value is gonna be one spot nearer the beginning of the list.
            // if (i > 0)
            // {
            //     i--; // This is so we can return the correct position after the search.
            //     Swap(&A[i + 1], &A[i]);
            // }

            return i;
        }
    }
    return -1;
}

int List::BinarySearch(int value)
{
//     if (!sorted)
//     {
//         cout << "The array must be sorted for binary search to work." << endl;
//         return -1;
//     }

    int left = 0;
    int right = length - 1;

    int mid;
    
    // If sorted
    // if (sorted == 1)
    // {
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (value == A[mid]) return mid;

        if (value > A[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    // }
    // If sorted backwards
    // else if (sorted == -1)
    // {
    //     while (left <= right)
    //     {
    //         mid = (left + right) / 2;

    //         if (value == A[mid]) return mid;

    //         if (value < A[mid])
    //             left = mid + 1;
    //         else
    //             right = mid - 1;
    //     }
    // }
    return -1;
}

// The difference here is that this one is \Theta(log n) while the normal
// one is \omega(1) in the best case scenario.
// This one will try to find the left most value in the case of repeating
// numbers in the list.
int List::BinarySearchLeftMost(int value)
{
//     if (!sorted)
//     {
//         cout << "The array must be sorted for binary search to work." << endl;
//         return -1;
//     }

    int left = 0;
    int right = length - 1;
    int mid;
    int pos = -1;

    // If sorted
    // This will return the left most ocurrence.
    // if (sorted == 1)
    // {
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (value == A[mid])
        {
            if (A[mid] != A[mid - 1])
                return mid;
            pos = mid;
        }

        if (value > A[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    // }
    // If sorted backwards
    // This will return the right most ocurrence (which would be the left most if sorted normally)
    // else if (sorted == -1)
    // {
    //     while (left <= right)
    //     {
    //         mid = (left + right) / 2;

    //         if (value == A[mid])
    //         {
    //             if (A[mid] != A[mid + 1])
    //                 return mid;
    //             pos = mid;
    //         }

    //         if (value > A[mid])
    //             right = mid - 1;
    //         else
    //             left = mid + 1;
    //     }
    // }
    return pos;
}

// int List::Find(int value)
// {
//     if (sorted)
//         return BinarySearchLeftMost(value);
//     return LinearSearch(value);
// }

List::~List()
{
    // We allocated space for the List. So we need to make sure to free it too.
    delete [] A;
}

int List::Get(int index)
{
    if (index < length && index >= 0)
        return A[index];
    cout << "Invalid index, returning 0." << endl;
    return 0;
}

void List::Set(int index, int value)
{
    if (index < length && index >= 0)
        A[index] = value;
}

int List::Max()
{
    int max_pos = 0;

    for (int i = 1; i < length; i++)
    {
        if (A[i] > A[max_pos])
            max_pos = i;
    }
    return max_pos;
}

int List::Min()
{
    int min_pos = 0;

    for (int i = 1; i < length; i++)
    {
        if (A[i] < A[min_pos])
            min_pos = i;
    }
    return min_pos;
}

int List::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

float List::Avg()
{
    return 1.0 * Sum() / length;
}

void List::Reverse()
{
    for (int start = 0, end = length - 1; start < end; start++, end--)
        Swap(&A[start], &A[end]);
    // if (sorted)
    //     sorted *= -1;
}

void List::RightShiftAll()
{
    RightShiftRange(0, length - 1);
}

void List::RightShiftRange(int start, int end)
{
    int tmp = A[end];
    for (int i = end; i > start; i--)
        A[i] = A[i - 1];
    A[start] = tmp;
}

void List::LeftShiftAll()
{
    LeftShiftRange(0, length - 1);
}

void List::LeftShiftRange(int start, int end)
{
    int tmp = A[start];
    for (int i = start; i < end; i++)
        A[i] = A[i + 1];
    A[end] = tmp;
}

bool List::IsSorted()
{
    for (int i = 1; i < length; i++)
    {
        if (A[i] < A[i - 1])
            return false;
    }
    return true;
}