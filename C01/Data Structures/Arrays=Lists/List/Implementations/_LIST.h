#ifndef LIST_H
#define LIST_H

#pragma once

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

#endif