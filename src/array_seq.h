#include "Sequence.h"
#include <algorithm>
#include <cstddef>
#include "array.h"
#include "exceptions.h"

template <typename T>

class Array_sequence : public Sequence<T> {
private:
    Dynamic_Array<T>* array;

public:
    Array_sequence() : array(Dynamic_Array<T>(0)) {}
    Array_sequence(T* items, int count) : array(Dynamic_Array<T>(items, count)) {}

//////////////////////////////////////////////////////////////////////////////////
    ///METHODS
    T Get_first() const override {
        return array->Get_first();
    }

    T Get_last() const override {
        return array->Get_last();
    }

    T Get(int index) const override {
        return array->Get(index);
    }
    
    T Get_length() const override {
        return array->Get_size();
    }

    Sequence<T>* Get_subsequence(int start_index, int end_index) const override {
        Dynamic_Array<T>* subarray = array.Get_subsequence(start_index, end_index);
        return new Array_sequence<T>(*subarray);
    }

    ///////////////////////////////////////////////////////////////////////////////
    ///OPERATORS OVERLOADING

    T& operator[](const int index) const override {
        return array[index];
    }

    Sequence<T>* Append(T item) override {
        array->Resize(array->Get_size() + 1);
        array->Set(array->Get_size() - 1, item);
        return this;
    }

    Sequence<T>* Prepand(T item) override {
        Dynamic_Array<T> New_Arr(array->Get_size() + 1);
        array->Set(0, item);

        for (int i = 0; i < New_Arr.Get_size(); ++i) {
            New_Arr.Set(i + 1, array.Get(i));
        }
        array = New_Arr;
        return this;
    }

    Sequence<T>* Insert_At(T item, int index) override {
        if (index < 0 || index > array.Get_size()) {
            throw Index_Out_of_range;
        }

        Dynamic_Array<T> newArray(array.Get_size() + 1);
        for (int i = 0; i < index; ++i) {
            // setting items until index
            newArray.Set(i, array.Get(i));
        }

        newArray.Set(index, item);
        
        // setting items after index 
        for (int i = index; i < array.Get_size(); ++i) {
            newArray.Set(i + 1, array.Get(i));
        }
        
        array = newArray;
        return this;
    }

    Sequence<T>* Concat(const Sequence<T>& other_arr) override {
        size_t new_size = array->Get_size() + other_arr.Get_lenght();
        Dynamic_Array<T> new_Arr(new_size);

        for (size_t i = 0; i < array->Get_size(); ++i){
            new_Arr.Set(i, array.Get(i));
        }

        for (size_t j = 0; j < other_arr.Get_lenght(); ++j) {
            new_Arr.Set(j + array->Get_size(), other_arr.Get(j));
        }
        array = new_Arr;
        return this;
    }
};
