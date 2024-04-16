#include "array_seq.h"
#include "exceptions.h"
#include <algorithm>

template <typename T>
T Array_sequence<T>::Get(int index) {
    if (index < 0 || index >= size){
        throw Index_Out_of_range;
    }
    else {
        auto tmp = this->items[index];
        return tmp;
    }
}

/////////////////////////////////////////////////////////

template <typename T>
int Array_sequence<T>::Get_size() const {
    return size;
}

/////////////////////////////////////////////////////////

template <typename T>
void Array_sequence<T>::Set(int index, T value) {
    if (index < 0 || index >= size){
        throw Index_Out_of_range;
    }

    else {
        this->items[index] = value;
    }
}

/////////////////////////////////////////////////////////

template <typename T>
T* Array_sequence<T>::Resize (size_t New_size) {
    if (New_size < 0) {
        throw Index_Out_of_range;
    }

    else {
        T* New_arr = new T[New_size];
        if (New_arr == nullptr) throw Memory_allocation_error;
        
        std::copy(items, items + std::min(size, New_size), New_arr);

        delete[] items;
        items = New_arr;

        return New_arr;
    }
}


