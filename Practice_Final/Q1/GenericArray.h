#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

using namespace std;

template <typename T>
class GenericArray
{
    private:
        T **values;
        int count;
        int size;
    
    public:
        GenericArray(int _size);
        GenericArray(const GenericArray &ObjToCopy);
        const GenericArray &operator=(const GenericArray &RHSObj);
        void push_back(const T &Element);
        void pop_back();
        void print();
        const T &at(int pos);
        ~GenericArray();
};

template <typename T>
GenericArray<T>::GenericArray(int _size)
{
    size = _size;
    count = 0;
    values = new T *[size];
    for (int i = 0; i < size; i++)
        values[i] = nullptr;
}

template <typename T>
GenericArray<T>::GenericArray(const GenericArray &ObjToCopy)
{
    size = ObjToCopy.size;
    count = ObjToCopy.count;
    values = new T *[size];
    for (int i = 0; i < size; i++)
    {
        if (ObjToCopy.values[i] != nullptr)
        {
            values[i] = new T;
            *values[i] = *ObjToCopy.values[i];
        }
        else
            values[i] = nullptr;
    }
}

template <typename T>
const GenericArray<T> & GenericArray<T>::operator=(const GenericArray &RHSObj)
{
    if (this != &RHSObj)
    {
        size = RHSObj.size;
        count = RHSObj.count;
        delete[] values;
        values = new T *[size];
        for (int i = 0; i < size; i++)
            values[i] = nullptr;
        for (int i = 0; i < size; i++)
        {
            if (RHSObj.values[i] != nullptr)
            {
                values[i] = new T;
                *values[i] = *RHSObj.values[i];
            }
            else
                values[i] = nullptr;
        }
    }
    return *this;
}

template <typename T>
GenericArray<T>::~GenericArray()
{
    for(int i = 0;i<size;i++)
        if (values[i]!=nullptr)
        {
            delete values[i];
            values[i]=nullptr;
        }
    delete [] values;
    values = nullptr;
}

// Write the implementation of the requested member functions here
template <typename T>
void GenericArray<T>::push_back(const T &Element)
{
    values[count] = new T;
    *values[count] = Element;
    count = count + 1;
}
    
template <typename T>
void GenericArray<T>::pop_back()
{
    delete values[count];
    values[count] = nullptr;
    count = count - 1;
}
    
template <typename T>
void GenericArray<T>::print()
{
    for(int i=0; i<count; i++)
    {
        cout << *(values[i]) << " ";
    }
    cout << endl;
}
    
template <typename T>
const T& GenericArray<T>::at(int pos)
{
    return *(values[pos]);
}


#endif
