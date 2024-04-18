#include "exceptions.h"
#include <algorithm>
#include <cstring>

template <typename T>

class Dynamic_Array {
private:
    T* items;
    size_t size;
    int capacity;

public:
    Dynamic_Array(size_t size) {
        T* arr = new T[size];
        items = arr;
        this->size = size;
    }

    Dynamic_Array(const Dynamic_Array<T>& Array) {
        size_t size = Array.size();
        items = new T[size];

        for (size_t i = 0; i < size; ++i) {
            items[i] = Array[i]; 
        }
        this->size = size;
    }
    // Copy constructor
    
    Dynamic_Array(T* items, int count) {
        this->items = new T[count];
        memcpy(this->items, items, count * sizeof(T));
        size = count;
    }

    ~Dynamic_Array() {
        delete[] items;
    }

    ////////////////////////////////////////////
    // METHODS
    // 
    T Get(int index);

    int Get_size() const;

    void Set(int index, T value);

    T* Resize(size_t New_size);
};

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

        return New_arr;
    }
}

