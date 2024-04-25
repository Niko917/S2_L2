#ifndef ARRAY_H
#define ARRAY_H

#include <cstring>
#include <stddef.h>
#include "Sequence.h"

template <typename T>

class Dynamic_Array {
private:
    T* items;
    size_t size;
    int capacity;

public:
    Dynamic_Array() {
        items = nullptr;
        size = 0;
    };

    Dynamic_Array(size_t size) {
        T* arr = new T[size];
        items = arr;
        this->size = size;
    }

    Dynamic_Array(const Dynamic_Array<T>& Array) {
        size = Array.Get_size();
        T* tmp = new T[size];
        items = tmp;
        
        memcpy(items, Array.items, size * sizeof(T));
    }


    Dynamic_Array(T* items, int count) {
        this->items = new T[count];
        memcpy(this->items, items, count * sizeof(T));
        size = count;
    }

    ~Dynamic_Array() {
        delete[] items;
    }

    T& operator [] (const int index) const;

    ////////////////////////////////////////////
    // METHODS
    //
    
    T* Get_data() const;

    T Get(int index) const;

    int Get_size() const;

    void Set(int index, T value);

    void Resize(size_t New_size);
};

#endif // ARRAY_H
