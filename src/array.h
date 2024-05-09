#pragma once

#include <cstring>
#include <stddef.h>
#include "Sequence.h"
#include "exceptions.h"
#include <algorithm>
#include <cstring>
#include "array.h"


template <typename T>

class Dynamic_Array {
private:
    T* items;
    size_t size;
    int capacity;

public:
    Dynamic_Array() {};

    Dynamic_Array(size_t size); 

    Dynamic_Array(const Dynamic_Array<T>& Array);

    Dynamic_Array(T* items, size_t count);

    Dynamic_Array(size_t size, const T default_element);

    ~Dynamic_Array();

    T& operator [] (const int index) const;

    ////////////////////////////////////////////
    // METHODS
    //
    
    T* Get_data() const;

    T Get(size_t index) const;

    size_t Get_size() const;

    T Get_first() const;

    T Get_last() const;

    void Set(T value, size_t index);

    void Resize(size_t New_size);

    void Append(T item);

    void Prepend(T item);

    void Pop_back();

    void Pop_front();

    void Insert_At(T item, size_t index);

    bool empty() const;

    void clear();
};


/// ----------------------------------------------------
/// Constructors and Destructors

template <typename T>
Dynamic_Array<T>::Dynamic_Array(size_t size, const T default_element) {
    this->items = new T[size];
    this->size = size;
    this->capacity = size;
    std::fill(this->items, this->items + size, default_element);
}


template <typename T>
Dynamic_Array<T>::Dynamic_Array(size_t size) {
    T* arr = new T[size];
    this->items = arr;
    this->size = size;
}


template <typename T>
Dynamic_Array<T>::Dynamic_Array(const Dynamic_Array<T>& Array) {
    this->size = Array.Get_size();
    T* tmp = new T[size];
    items = tmp;

    memcpy(items, Array.items, size * sizeof(T));
}


template <typename T>
Dynamic_Array<T>::Dynamic_Array(T* items, size_t count) {
    this->items = new T[count];
    memcpy(this->items, items, count * sizeof(T));
    this->size = count;
}


template <typename T>
Dynamic_Array<T>::~Dynamic_Array() {
    delete[] this->items;
}



/// ----------------------------------------------------

template <typename T>
T* Dynamic_Array<T>::Get_data() const {
    return this->items;
}



template <typename T>
bool Dynamic_Array<T>::empty() const {
    return (!this->Get_size()) ? false : true;
}


template <typename T>
void Dynamic_Array<T>::clear() {
    delete[] this->items;
    this->items = nullptr;
    this->size = 0;
    this->capacity = 0;
}



template <typename T>
T Dynamic_Array<T>::Get(size_t index) const {
    if (index < 0 || index >= size) {
        throw ERRORS::Index_Out_of_range;
    }
    else {
        auto tmp = this->items[index];
        return tmp;
    }
}



template <typename T>
size_t Dynamic_Array<T>::Get_size() const{
    return size;
}


template <typename T>
T Dynamic_Array<T>::Get_first() const {
    if (this->empty()) throw ERRORS::Sequence_is_empty;
    return *items;
}


template <typename T>
T Dynamic_Array<T>::Get_last() const {
    if (this->empty()) throw ERRORS::Sequence_is_empty;
    return *(items + size - 1);
}


template <typename T>
void Dynamic_Array<T>::Set(T value, size_t index) {
    if (index < 0 || index >= size){
        throw ERRORS::Index_Out_of_range;
    }
    items[index] = value;
}



template <typename T>
void Dynamic_Array<T>::Resize(size_t New_size) {

    T* New_arr = new T[New_size];
    if (items == nullptr) {
        throw ERRORS::Null_pointer_error;
    }
    else {
        std::copy(items, items + std::min(size, New_size), New_arr);

        delete[] items;

        items = New_arr;
        size = New_size;
    }
}



template <typename T>
void Dynamic_Array<T>::Append(T item) {
    if (size >= capacity) {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        Resize(new_capacity);
    }
    items[size] = item;
    size++;
}



template <typename T>
void Dynamic_Array<T>::Prepend(T item) {
    Insert_At(item, 0);
}


template <typename T>
void Dynamic_Array<T>::Pop_back() {
    if (size <= 0) throw ERRORS::Sequence_is_empty;
    T* new_items = new T[size - 1];

    memcpy(new_items, items + 1, size - 1 * sizeof(T));
    delete[] items;
    items = new_items;
    size--;
}


template <typename T>
void Dynamic_Array<T>::Pop_front() {
    if (size <= 0) throw ERRORS::Sequence_is_empty;

    T* new_items = new T[size - 1];
    memcpy(new_items, items, (size - 1) * sizeof(T));

    delete[] items;
    items = new_items;
    size--;
}


template <typename T>
void Dynamic_Array<T>::Insert_At(T item, size_t index) {
    if (index < 0 || index > size) {
        throw ERRORS(ERRORS::Index_Out_of_range);
    }

    if (size >= capacity) {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        Resize(new_capacity);
    }

    for (size_t i = size; i > index; --i) {
        items[i] = items[i - 1];
    }

    items[index] = item;
    size++;
}


template <typename T>
T& Dynamic_Array<T>::operator[](const int index) const {
    if (index < 0 || index >= size) throw ERRORS::Index_Out_of_range;
    return this->items[index];
}
