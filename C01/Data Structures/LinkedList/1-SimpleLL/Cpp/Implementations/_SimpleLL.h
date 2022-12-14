#ifndef SLLIST_H
#define SLLIST_H

#pragma once

class SLList
{
private:
    int *A;
    int length;
    int max_length;

public:
    // Constructor
    List();

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