#pragma once
template <typename T>
class SortedList {

public:
    // Constructor and Destructor
    SortedList();
    ~SortedList();
    
    bool IsFull();
    bool IsEmpty();

    void ResetPointer();

    int Add(T& _item);

    int Delete(T _item);

    int GetLength();

    int GetNextItem(T& _item);

    int GetItem(T& _item);

    int QuickSort(int _start, int _end);

private:

    T* Array;
    int mLength;
    int mCurrentPointer;
};

template <typename T>
SortedList<T>::SortedList() {
    this->mLength = 0;
    this->mCurrentPointer = -1;
    this->Array = new T[ARRAY_SZIE];
    return;
}

template <typename T>
SortedList<T>::~SortedList() {
    this->Array = nullptr;
    delete[] this->Array;
    return;
}

template <typename T>
bool SortedList<T>::IsFull() {
    if(this->mLength > ARRAY_SZIE - 1) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
bool SortedList<T>::IsEmpty() {
    if (this->mLength == 0) {
        return true;
    }
    else {
        return false;
    }
}
template <typename T>
int SortedList<T>::Add(T& _item) {

    if(IsEmpty()) {
        this->Array[mLength] = _item;
        this->mLength++;
        return 1;
    }
    else if (mLength > ARRAY_SZIE - 1){
        T* temp = new T[ARRAY_SZIE];
        temp = this->Array;
        this->Array = nullptr;
        delete[] this->Array;

        this->Array = new T[ARRAY_SZIE + ADD_SIZE];
        this->Array = temp;
        temp = nullptr;
        delete[] temp;

        this->Array[mLength] = _item;
        mLength++;

        return 1;
    }
    else {
        this->Array[mLength] = _item;
        mLength++;
        QuickSort(0, this->mLength - 1);
        return 1;
    }
}

template <typename T>
int SortedList<T>::QuickSort(int _start, int _end) {
    if(_start >= _end) {
        return 1;
    }
    int pivot = _start;
    int i = _start + 1;
    int j = _end;
    int temp;

    while(i <= j) {
        while(this->Array[i] >= this->Array[pivot]) {
            i++;
        }
        while(this->Array[j] <= this->Array[pivot] && j > _start) {
            j--;
        }
        if(i > j) {
            T tempT = this->Array[i];
            this->Array[i] = this->Array[pivot];
            this->Array[pivot] = tempT;
        }
        else {
            T tempT = this->Array[j];
            this->Array[j] = this->Array[i];
            this->Array[i] = tempT;
        }
        QuickSort(_start, j - 1);
        QuickSort(j + 1, _end);   
    }
    return 1;
}
template <typename T>
void SortedList<T>::ResetPointer() {
    this->mCurrentPointer = -1;
    return;
}

template <typename T>
int SortedList<T>::GetLength() {
    return this->mLength;
}

template <typename T>
int SortedList<T>::GetNextItem(T& _item) {
    this->mCurrentPointer++;
    
    _item = this->Array[mCurrentPointer];
    if(mCurrentPointer == mLength) {
        return -1;
    }
    else {
        return this->mCurrentPointer;
    }
}

template <typename T>
int SortedList<T>::GetItem(T& _item) {
    
    int left = 0;
    int right = mLength - 1;
    int centre = (left + right) / 2;
    bool isFound = false;

    while (!isFound) {
        if (this->Array[centre] == _item) {
            _item = this->Array[centre];
            isFound = true;
        }
        else if (this->Array[centre] < _item) {
            left = centre;
            centre = (centre + right) / 2;
            if(left >= right) { break; }
        }
        else if (this->Array[centre] > _item) {
            right = centre;
            centre = (centre + left) / 2;
            if(left >= right) { break; }
        }
    }
    return isFound;
}

template <typename T>
int SortedList<T>::Delete(T _item) {
    if(!GetItem(_item)) { return 0; }
    else {
        int left = 0;
        int right = this->mLength;
        int centre =(left + right) / 2;

        bool isFound = false;
        while (!isFound) {
            if (this->Array[centre] == _item) {
                for(int i = centre; i < this->mLength - 1; i++) {
                    this->Array[i] = this->Array[i + 1];
                    this->mLength--;
                    isFound = true;
                }
            }
            else if (this->Array[centre] < _item) {
                left = centre;
                centre = (centre + right) / 2;
                if(left >= right) { break; }
            }
            else if (this->Array[centre] > _item) {
                right = centre;
                centre = (centre + left) / 2;
                if(left >= right) { break; }
            }
        }
        return 1;   
    }
}
