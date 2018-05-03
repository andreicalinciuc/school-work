#include "MyClass.h"

int IntCompare::CompareElements (void* e1, void* e2)
{
    return *(int*)e1 > *(int*)e2;
}

template <class T>
ArrayIterator<T>::ArrayIterator()
{
    Current = 0;
}

template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator ++ ()
{
    ++Current;
    return *this;
}

template <class T>
ArrayIterator<T>& ArrayIterator<T>::operator -- ()
{
    --Current;
    return *this;
}

template <class T>
bool ArrayIterator<T>::operator = (ArrayIterator<T>& otherIterator)
{
    Current = otherIterator.Current;
    return 1;
}

template <class T>
bool ArrayIterator<T>::operator != (ArrayIterator<T>& otherIterator)
{
    return Current != otherIterator.Current;
}

template <class T>
int ArrayIterator<T>::GetElement()
{
    return Current;
}

template <class T>
Array<T>::Array()
{
    Capacity = 0;
    Size = 0;
}

template <class T>
Array<T>::~Array()
{
    delete[] List;
}

template <class T>
Array<T>::Array (int capacity)
{
    Capacity = capacity;
    List = new T* [Capacity];
    Size = 0;
}

template <class T>
Array<T>::Array (const Array<T> &otherArray)
{
    if (otherArray.Size > Capacity)
    {
        Capacity = otherArray.Capacity;
        List = new T* [otherArray.Capacity];
    }
    Size = otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[i] = otherArray.List[i];
    }
}

template <class T>
T& Array<T>::operator [] (int index)
{
    return *List[index];
}

template <class T>
const Array<T>& Array<T>::operator += (const T &newElem)
{
    List[++Size] = (int*)&newElem;
    return *this;
}

template <class T>
const Array<T>& Array<T>::Insert (int index, const T &newElem)
{
    for (int i = Size - 1; i >= index; --i)
    {
        List[i+1] = List[i];
    }
    ++Size;
    List[index] = (int*)&newElem;
    return *this;
}

template <class T>
const Array<T>& Array<T>::Insert (int index, const Array<T> otherArray)
{
    for (int i = Size - 1; i >= index; --i)
    {
        List[i + otherArray.Size] = List[i];
    }
    Size += otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[index+i] = otherArray.List[i];
    }
    return *this;
}

template <class T>
const Array<T>& Array<T>::Delete (int index)
{
    for (int i = index; i < Size; ++i)
    {
        List[i] = List[i+1];
    }
    --Size;
    return *this;
}

template <class T>
bool Array<T>::operator = (const Array<T> &otherArray)
{
    if (otherArray.Size > Capacity)
    {
        this->~Array();
        Capacity = otherArray.Capacity;
        List = new T* [otherArray.Capacity];
    }
    Size = otherArray.Size;
    for (int i = 0; i < otherArray.Size; ++i)
    {
        List[i] = otherArray.List[i];
    }
    return 1;
}

template <class T>
void Array<T>::Sort()
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (*List[i] > *List[j]) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
void Array<T>::Sort (int (*compare) (const T&, const T&))
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (compare(*List[i], *List[j])) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
void Array<T>::Sort (Compare *comparator)
{
    for (int i = 0; i < Size - 1; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if (comparator->CompareElements(List[i], List[j])) std::swap (List[i], List[j]);
        }
    }
}

template <class T>
int Array<T>::BinarySearch (const T& elem)
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        if (elem == *List[m]) return m;
        else if (elem < *List[m]) d = m - 1;
        else if (elem > *List[m]) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::BinarySearch (const T& elem, int (*compare) (const T&, const T&))
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        int tmp = compare (elem, *List[m]);
        if (tmp == 0) return m;
        else if (tmp < 0) d = m - 1;
        else if (tmp > 0) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::BinarySearch (const T& elem, Compare *comparator)
{
    int s = 0, d = Size - 1, m;
    while (s <= d)
    {
        m = (s + d) / 2;
        int tmp = comparator->CompareElements ((void*)&elem, List[m]);
        if (tmp == 0) return m;
        else if (tmp < 0) d = m - 1;
        else if (tmp > 0) s = m + 1;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem) 
{
    for (int i = 0; i < Size; ++i)
    {
        if (*List[i] == elem) return i;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem, int (*compare) (const T&, const T&))
{
    for (int i = 0; i < Size; ++i)
    {
        if (compare(*List[i], elem) == 0) return i;
    }
    return -1;
}

template <class T>
int Array<T>::Find (const T& elem, Compare *comparator)
{
    for (int i = 0; i < Size; ++i)
    {
        if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
    }
    return -1;
}

template <class T>
int Array<T>::GetSize()
{
    return Size;
}

template <class T>
int Array<T>::GetCapacity()
{
    return Capacity;
}

template <class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    ArrayIterator<T> aux;
    aux.Current = 0;
    return aux;
}

template <class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    ArrayIterator<T> aux;
    aux.Current = Size;
    return aux;
}

template class ArrayIterator <int>;
template class Array <int>;
