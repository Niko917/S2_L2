#pragma once

#include <complex>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <new>
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
    size_t capacity;

public:
    Dynamic_Array();

    Dynamic_Array(size_t size); 

    Dynamic_Array(const Dynamic_Array<T>& Array);

    Dynamic_Array(T* items, size_t count);

    Dynamic_Array(size_t size, const T& default_element);

    ~Dynamic_Array();

    T& operator [] (const int& index) const;

    ////////////////////////////////////////////
    // METHODS
    //
    
    T* Get_data() const;

    T Get(size_t index) const;

    size_t Get_size() const;

    T Get_first() const;

    T Get_last() const;

    void Set(const T& value, size_t index);

    void Resize(size_t New_size);

    void reallocation();

    void Append(const T& item);

    void Prepend(const T& item);

    void Pop_back();

    void Pop_front();

    void Insert_At(const T& item, size_t index);

    bool empty() const;

    void clear();
};


/// ----------------------------------------------------
/// Constructors and Destructors

template <typename T>
Dynamic_Array<T>::Dynamic_Array(size_t size, const T& default_element) {
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
    this->capacity = size;
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
Dynamic_Array<T>::Dynamic_Array() {
    this->items = nullptr;
    this->size = 0;
    this->capacity = 0;
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
    if (this->Get_size() == 0){
        return true;
    }
    return false;
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
    if (index >= this->Get_size()) {
        throw ERRORS::Index_Out_of_range;
    }
    return (*this)[index];
}



template <typename T>
size_t Dynamic_Array<T>::Get_size() const{
    return this->size;
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
void Dynamic_Array<T>::Set(const T& value, size_t index) {
    if (index >= size){
        throw ERRORS::Index_Out_of_range;
    }
    items[index] = value;
}



template <typename T>
void Dynamic_Array<T>::Resize(size_t New_size) {
    
    if (New_size == 0) {
        this->clear();
    }
    else if (New_size < this->Get_size()) {
        size_t df = this->Get_size() - New_size;
        for (size_t i = 0; i < df; ++i) {
            this->Pop_back();
        }
    }
    else if (New_size > this->Get_size()) {
        T* new_arr = new T[New_size];
        for (size_t i = 0; i < this->Get_size(); ++i) {
            new_arr[i] = this->items[i];
        }

        for (size_t i = this->Get_size(); i < New_size; ++i) {
            new_arr[i] = T();
        }
        delete[] this->items;
        this->items = new_arr;
        this->size = New_size;
    }
}



template <typename T>
void Dynamic_Array<T>::Append(const T& item) {
    reallocation();
    this->items[this->size] = item;
    this->size++;
}


template <typename T>
void Dynamic_Array<T>::Prepend(const T& item) {
    if (this->size >= this->capacity) {
		this->capacity *= 2;
		T* new_array = new T[this->capacity];
		new_array[0] = item;
		for (size_t i = 0; i < this->size; ++i) {
			new_array[i + 1] = this->items[i];
		}
		delete[] this->items;
		this->items = new_array;
	}
	else {
		for (size_t i = this->size; i > 0; --i) {
			this->items[i] = this->items[i - 1];
		}
		this->items[0] = item;
	}
	this->size++;
}



template <typename T>
void Dynamic_Array<T>::Pop_back() {
    if (this->empty()) {
        throw ERRORS::Sequence_is_empty;
    }
    else {
        this->capacity--;
        T* new_array = new T[this->capacity];
        for (size_t i = 0; i < this->size - 1; ++i) {
            new_array[i] = this->items[i];
        }
        delete[] this->items;
        this->items = new_array;
        this->size--;

    }
}


template <typename T>
void Dynamic_Array<T>::Pop_front() {
    if (this->empty()) {
        throw ERRORS::Sequence_is_empty;
    }
    else {
        T* new_arr = new T[this->capacity];
        for (size_t i = 1; i < this->size; ++i) {
            new_arr[i - 1] = this->items[i];
        }
        delete[] this->items;
        this->items = new_arr;
        this->size--;
    }

}



template <typename T>
void Dynamic_Array<T>::reallocation() {
    if (this->size == this->capacity) {
        size_t new_capacity = this->capacity == 0 ? 1 : this->capacity * 2;
    
        // std::cout << "Capacity: " << this->capacity << ", New capacity: " << new_capacity << std::endl;

        T* new_array = new T[new_capacity];
    
        for (size_t i = 0; i < this->size; ++i) {
            new_array[i] = this->items[i];
        }

        delete[] this->items;
        this->items = new_array;
        this->capacity = new_capacity;
    }
}



template <typename T>
void Dynamic_Array<T>::Insert_At(const T& item, size_t index) {

    if (index > this->size) throw ERRORS::Index_Out_of_range;

    if (this->empty() && index != 0) throw ERRORS::Sequence_is_empty;
   
    if (this->size >= this->capacity) {
        reallocation();
    }

    for (size_t i = this->size; i >= index; --i) {
        items[i] = items[i - 1];
    }

    items[index] = item;
    this->size++;

}


template <typename T>
T& Dynamic_Array<T>::operator[](const int& index) const {
    if (index < 0 || index >= size) throw ERRORS::Index_Out_of_range;
    return this->items[index];
}
