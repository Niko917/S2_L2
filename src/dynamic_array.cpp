#include "array_seq.h"
#include "exceptions.h"
#include <algorithm>

template <typename T>
class Dynamic_Array {
private:
    T* items;
    size_t size;
    int capacity;

public:
    Dynamic_Array(int capacity) : capacity(capacity) {}
    
    Dynamic_Array(T* items, int cnt);
    
    Dynamic_Array(const Array_sequence<T>& Array);     
    // copy constructor

    ~Dynamic_Array() = default;

    
    ////////////////////////////////////////////
    // METHODS

    T Get(int index) {
        if (index < 0 || index >= size) {
            throw Index_Out_of_range;
    }
        else {
            auto tmp = this->items[index];
            return tmp;
    }

    }

    int Get_size() const {
        return size;
    }

    void Set(int index, T value) {
        if (index < 0 || index >= size){
            throw Index_Out_of_range;
    }

        else {
            this->items[index] = value;
        }

    }

    T* Resize(size_t New_size) {
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
};
