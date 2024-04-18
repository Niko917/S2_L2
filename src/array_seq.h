#include "Sequence.h"
#include <algorithm>


template <typename T>

class Array_sequence : public Sequence<T> {
private:
    Dynamic_Array<T>* Array;

public:
    Array_sequence (T* items, int count) {
        this->Array = new Dynamic_Array<T> (items, count);
    }
};
