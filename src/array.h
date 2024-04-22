#include <stddef.h>
#include "Sequence.h"

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
        size_t size = Array.Get_size();
        items = new T[size];

        for (size_t i = 0; i < size; ++i) {
            items[i] = Array->Get(i); 
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

    T operator [] (const int index) const;

    ////////////////////////////////////////////
    // METHODS
    // 
    T Get(int index);

    int Get_size() const;

    void Set(int index, T value);

    T* Resize(size_t New_size);

    Dynamic_Array<T>* Get_subsequence(int start_index, int end_index) const;
};


