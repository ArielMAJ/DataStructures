#include <iostream>
#include <cstdlib>
using namespace std;

class Array
{
private:
    int *A;
    int max_length;
    int length;
public:
    Array(int max_length, int length, bool populate=false);
    int Get(int index);
    void Set(int index, int x);
    void Display();
    void MergeToSelf(Array &B);
    Array MergeAndReturn(Array &B);
    ~Array();
};

int main()
{ 
    Array X(10, 5, true);
    Array Y(10, 4, true);
 
    Array Z = X.MergeAndReturn(Y);

    cout << "Original array:\n";
    X.Display();
    cout << "Merged and returned array:\n";
    Z.Display();
    X.MergeToSelf(Y);
    cout << "Array merged to self:\n";
    X.Display();
 
    return 0;
}

Array::Array(int max_length, int length, bool populate)
{
    this->max_length = max_length;
    this->length = length;

    A = new int [max_length];

    if (populate)
    {
        cout << "Enter ints in sorted manner" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Enter element " << i << " : " << flush;
            cin >> A[i];
        }
        cout << "\n";
    }
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -0;
}

void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n\n";
}

void Array::MergeToSelf(Array &B){
    int *C = new int[length + B.length];
    int i, j, k;
    i = j = k = 0;

    while (i < length && j < B.length)
    {
        if (A[i] < B.Get(j))
            C[k++] = A[i++];
        else
            C[k++] = B.Get(j++);
    }

    for (; i < length; i++)
        C[k++] = A[i];
    for (; j < B.length; j++)
        C[k++] = B.Get(j);

    delete[] A;
    length = max_length = length + B.length;
    A = C;
}

Array Array::MergeAndReturn(Array &B){
    Array C(length + B.length, length + B.length);
    int i, j, k;
    i = j = k = 0;

    while (i < length && j < B.length){
        if (A[i] < B.Get(j)){
            C.Set(k++, A[i++]);
        } else {
            C.Set(k++, B.Get(j++));
        }
    }
    for (; i < length; i++){
        C.Set(k++, A[i]);
    }
    for (; j < B.length; j++){
        C.Set(k++, B.Get(j));
    }
    return C;
}

Array::~Array()
{
    delete [] A;
}
