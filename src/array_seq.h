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
    
    void Append_Internal(const T& item) const;

    void Prepend_Internal(const T& item) const;

    void Set_Internal(int index, const T& item);

    void Insert_At_Internal(T& item, int index);

    void Resize_Internal(size_t New_size);

    void Concat_Internal(Array_sequence<T>& other_seq);

    void clear_Internal();


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

    T Get_first() const override;

    T Get_last() const override {
        return array->Get(array->Get_size() - 1);
    }

    T Get(int index) const override {
        return array->Get(index);
    }
    
    size_t Get_length() const override;


    Array_sequence<T>* Append(T& item) override;

    Array_sequence<T>* Prepend(T& item) override;

    Array_sequence<T>* Insert_At(T& item, int index) override;
 
    Array_sequence<T>* Get_subsequence(int start_index, int end_index) const override;

    Array_sequence<T>* Concat(const Sequence<T>& other_arr) override;

    Array_sequence<T>* Resize(size_t New_size) override;

    Array_sequence<T>* clear() override;

    // -----------------------------------------------------


    Array_sequence<T>* map(T(*function)(const T&)) override;

    int find(T& element) const override;

    int count(T& element) const override;

    // -----------------------------------------------------

    T& operator[](const int index) const override {
        return (*array)[index];
    }
    
};

// ----------------------------------------------------------------------------------------

