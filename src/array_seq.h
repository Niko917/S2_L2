#include "Sequence.h"
#include <algorithm>


template <typename T>

class Array_sequence : Sequence<T> {
private:
    T* items;
    size_t size;
    int capacity;

public:
    Array_sequence(int capacity) : capacity(capacity) {}
    
    Array_sequence(T* items, int cnt);
    
    Array_sequence(const Array_sequence<T>& Array);     
    // copy constructor
    

    ~Array_sequence() = default;

    ////////////////////////////////////////////
    // METHODS

    T Get(int index);

    int Get_size() const;

    void Set(int index, T value);

    T* Resize(size_t New_size);
};
