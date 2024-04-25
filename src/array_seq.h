#pragma once

#include "Sequence.h"
#include <algorithm>
#include <cstddef>
#include "array.h"
#include "exceptions.h"

template <typename T>

class Array_sequence : public Sequence<T> {
protected:
    Dynamic_Array<T>* array;


public:
    Array_sequence() : array(new Dynamic_Array<T>()) {}
    Array_sequence(T* items, int count) : array(Dynamic_Array<T>(count)) {
        for (int i = 0; i < count; ++i) {
            array->Set(i, items[i]);
        }
    }

    Array_sequence(const Array_sequence<T>& other) {
        for (int i = 0; i < other.Get_length(); ++i) {
            array->Append(other.Get(i));
        }
    }

    virtual ~Array_sequence() {delete array;}

//////////////////////////////////////////////////////////////////////////////////
    ///METHODS
   
    virtual Array_sequence<T>* Instance() = 0;    

    T Get_first() const override {
        return array->Get_first();
    }

    T Get_last() const override {
        return array->Get(array->Get_size() - 1);
    }

    T Get(int index) const override {
        return array->Get(index);
    }
    
    T Get_length() const override {
        return array->Get_size();
    }

    virtual Sequence<T>* Get_subsequence(int start_index, int end_index) const = 0;


    T& operator[](const int index) const override {
        return (*array)[index];
    }
    

    virtual Sequence<T>* Append(T item) = 0;

    virtual Sequence<T>* Prepend(T item) = 0;

    virtual Sequence<T>* Insert_At(T item, int index) = 0;

    virtual Sequence<T>* Concat(const Sequence<T>& other_arr) = 0;
};

// ----------------------------------------------------------------------------------------

