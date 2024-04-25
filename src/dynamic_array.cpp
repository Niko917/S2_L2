#include "exceptions.h"
#include <algorithm>
#include <cstring>
#include "array.h"


template <typename T>
T* Dynamic_Array<T>::Get_data() const {
    return this->items;
}

template <typename T>
T Dynamic_Array<T>::Get(int index) const {
    if (index < 0 || index >= size) {
        throw ERRORS::Index_Out_of_range;
    }
    else {
        auto tmp = this->items[index];
        return tmp;
    }
}

template <typename T>
int Dynamic_Array<T>::Get_size() const{
    if (size == 0) throw ERRORS::Sequence_is_empty;
    return size;
}

template <typename T>
void Dynamic_Array<T>::Set(int index, T value) {
    if (index < 0 || index >= size){
        throw ERRORS::Index_Out_of_range;
    }
    value = items[index];
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
T& Dynamic_Array<T>::operator[](const int index) const {
    return this->items[index];
}
