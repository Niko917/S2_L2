#pragma once

#include "Sequence.h"
#include <algorithm>
#include <cstddef>
#include "array.h"
#include "exceptions.h"

template <typename T>

class Array_sequence : public Sequence<T> {
private:

    Dynamic_Array<T>* array = new Dynamic_Array<T>;
    
    void Append_Internal(const T& item);

    void Prepend_Internal(const T& item);

    void Pop_back_Internal();

    void Pop_front_Internal();

    void Set_Internal(const T& item, size_t index);

    void Insert_At_Internal(const T& item, size_t index);

    void Resize_Internal(size_t New_size);

    void Concat_Internal(Array_sequence<T>& other_seq);

    void clear_Internal();


public:
    
    Array_sequence();

    Array_sequence(T* items, size_t count);

    Array_sequence(const Array_sequence<T>& other);

    Array_sequence(const Dynamic_Array<T>& arr);

    Array_sequence(int size, const T& item);

    ~Array_sequence();

//////////////////////////////////////////////////////////////////////////////////
    ///METHODS
   
    virtual Array_sequence<T>* Instance() = 0;

    virtual Array_sequence<T>* Mutability() const = 0;


    // -----------------------------------------------------

    T Get_first() const override {
        return array->Get(0);
    }

    T Get_last() const override {
        return array->Get(array->Get_size() - 1);
    }

    T Get(size_t index) const override {
        return array->Get(index);
    }
    
    size_t Get_length() const override;

    // ---------------------------------------------------

    Array_sequence<T>* Append(const T& item) override;

    Array_sequence<T>* Prepend(const T& item) override;

    Array_sequence<T>* Pop_back() override;

    Array_sequence<T>* Pop_front() override;

    Array_sequence<T>* Insert_At(const T& item, size_t index) override;

    Array_sequence<T>* Set(const T& item, size_t index) override;
 
    Array_sequence<T>* Get_subsequence(size_t start_index, size_t end_index) const override;

    Array_sequence<T>* Concat(Sequence<T>& other) override;

    Array_sequence<T>* Resize(size_t New_size) override;

    Array_sequence<T>* clear() override;

    // -----------------------------------------------------


    Array_sequence<T>* map(T(*function)(const T&)) override;

    int find(const T& element) const override;

    int count(const T& element) const override;

    // -----------------------------------------------------

    T& operator[](const int index) const override {
        return (*array)[index];
    }
    
};



/// --------------------------------------------------------
/// Constructors and destructors


template <typename T>
Array_sequence<T>::Array_sequence() {
    array = new Dynamic_Array<T>();
}

template <typename T>
Array_sequence<T>::Array_sequence(int size, const T& item) : Array_sequence() {
    array = new Dynamic_Array<T>(size, item);
}


template <typename T>
Array_sequence<T>::Array_sequence(T* items, size_t count) : array(Dynamic_Array<T>(count)) {
    for (int i = 0; i < count; ++i) {
        array->Set(i, items[i]);
    }
}


template <typename T>
Array_sequence<T>::Array_sequence(const Array_sequence<T>& other) : Array_sequence() {
    for (int i = 0; i < other.Get_length(); ++i) {
        array->Append(other.Get(i));
    }
}


template <typename T>
Array_sequence<T>::Array_sequence(const Dynamic_Array<T>& arr) : Array_sequence() {
    for (int i = 0; i < arr.Get_size(); ++i) {
        array->Append(arr.Get(i));
    }
}



template <typename T>
Array_sequence<T>::~Array_sequence() {
    array->~Dynamic_Array<T>();
}


/// -------------------------------------------------------



template <typename T>
Array_sequence<T>* Array_sequence<T>::Append(const T& item) {
    Array_sequence<T>* instance = Instance();
    instance->Append_Internal(item);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Prepend(const T& item) {
    Array_sequence<T>* instance = Instance();
    instance->Prepend_Internal(item);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Pop_back() {
    Array_sequence<T>* instance = Instance();
    instance->Pop_back_Internal();
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Pop_front() {
    Array_sequence<T>* instance = Instance();
    instance->Pop_front_Internal();
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Insert_At(const T& item, size_t index) {
    Array_sequence<T>* instance = Instance();
    instance->Insert_At_Internal(item, index);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Set(const T& item, size_t index) {
    Array_sequence<T>* instance = Instance();
    instance->Set_Internal(item, index);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Concat(Sequence<T>& other) {
    Array_sequence<T>* instance = Instance();
    for (int i = 0; i < other.Get_length(); ++i) {
        instance->Append(other.Get(i));
    }
    return instance;
}


template <typename T>
Array_sequence<T>* Array_sequence<T>::Get_subsequence(size_t start_index, size_t end_index) const {
    if (end_index > this->Get_length() || start_index > end_index) {
        throw ERRORS::Index_Out_of_range;
    }


    else {
        Array_sequence<T>* new_Arr_seq = Mutability();
        
        for (int i = start_index; i <= end_index; ++i) {
            new_Arr_seq->Append(this->Get(i));
        }

        return new_Arr_seq;
    }
}


template <typename T>
Array_sequence<T>* Array_sequence<T>::Resize(size_t New_size) {
    Array_sequence<T>* instance = Instance();
    instance->Resize_Internal(New_size);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::map(T(*function)(const T&)) {
    Array_sequence<T>* sq = Instance();

    for (int i = 0; i < this->Get_length(); ++i) {
        sq->Set(function((*array)[i]), i);
    }
    
    return sq;
}



template <typename T>
int Array_sequence<T>::find(const T& element) const {
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            return i;
        }
    }
    return -1;
}



template <typename T>
int Array_sequence<T>::count(const T& element) const {
    int count = 0;
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            count++;
        }
    }
    return count;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::clear() {
    Array_sequence<T>* instance = Instance();
    instance->clear_Internal();
    return instance;
}




// --------------------------------------------------------

template <typename T>
size_t Array_sequence<T>::Get_length() const {
    return array->Get_size();
}



template <typename T>
void Array_sequence<T>::Append_Internal(const T& item) {
    array->Append(item);
}



template <typename T>
void Array_sequence<T>::Prepend_Internal(const T& item) {
    array->Prepend(item);
}



template <typename T>
void Array_sequence<T>::Pop_back_Internal() {
    array->Pop_back();
}



template <typename T>
void Array_sequence<T>::Pop_front_Internal() {
    array->Pop_front();
}



template <typename T>
void Array_sequence<T>::Set_Internal(const T& item, size_t index) {
    array->Set(item, index);
}



template <typename T>
void Array_sequence<T>::Insert_At_Internal(const T& item, size_t index) {
    array->Insert_At(item, index);
}



template <typename T>
void Array_sequence<T>::Resize_Internal(size_t New_size) {
    array->Resize(New_size);
}



template <typename T>
void Array_sequence<T>::clear_Internal() {
    array->clear();
}
