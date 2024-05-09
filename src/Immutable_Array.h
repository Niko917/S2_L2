#pragma once

#include "array.h"
#include "array_seq.h"

template <typename T>
class Immutable_Array_Sequence : public Array_sequence<T> {

public:

    
    Immutable_Array_Sequence(int size, const T& item) : Array_sequence<T>(size, item) {}


    Immutable_Array_Sequence(const Array_sequence<T>& other) : Array_sequence<T>(other) {}


    Immutable_Array_Sequence() : Array_sequence<T>() {}


    // -------------------------------------------------------

    Array_sequence<T>* Instance() override {
        return new Immutable_Array_Sequence(*this);
    }

    Array_sequence<T>* Mutability() const override {
        return new Immutable_Array_Sequence();
    }

    Array_sequence<T>* Mutability(int size, const T& item) const {
        return new Immutable_Array_Sequence(size, item);
    }

};
