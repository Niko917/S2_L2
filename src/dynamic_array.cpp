#include "exceptions.h"
#include <algorithm>
#include <cstring>
#include "array.h"


template <typename T>
T Dynamic_Array<T>::Get(int index) {
    if (index < 0 || index >= size) {
        throw Index_Out_of_range;
    }
    else {
        auto tmp = this->items[index];
        return tmp;
    }
}

template <typename T>
int Dynamic_Array<T>::Get_size() const {
    if (this->Get_size() == 0) throw Sequence_is_empty;
    return size;
}

template <typename T>
void Dynamic_Array<T>::Set(int index, T value) {
    if (index < 0 || index >= size){
        throw Index_Out_of_range;
    }

    else {
        this->items[index] = value;
    }
}

template <typename T>
T* Dynamic_Array<T>::Resize(size_t New_size) {
    if (New_size < 0) {
        throw Index_Out_of_range;
    }

    else {
        T* New_arr = new T[New_size];
       
        std::copy(items, items + std::min(size, New_size), New_arr);

        delete[] items;
        items = New_arr;
        size = New_size;

        return this;
    }
}


template <typename T>
Dynamic_Array<T>* Dynamic_Array<T>::Get_subsequence(int start_index, int end_index) const {
    if (start_index < 0 || end_index < 0 || start_index >= size || end_index > size || start_index > end_index) {
        throw Index_Out_of_range;
    }
    
    size_t subsize = end_index - start_index;
    T* subitems = new T[subsize];
    
    for (int i = 0; i < subsize; ++i) {
        subitems[i] = items[start_index + i];
    }
    
    return new Dynamic_Array<T>(subitems, subsize);
}
