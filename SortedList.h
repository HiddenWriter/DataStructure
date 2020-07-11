#pragma once
template <typename T>
class SortedList {

public:
    // Constructor and Destructor
    SortedList();
    ~SortedList();

    int SortAndAdd(T _item);

    int Delete(T _item);

    int GetLength();

    int GetItem(T& _item);

private:

    T* Array;
    int mLength;

};