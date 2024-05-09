#pragma once

#include "array_seq.h"

template <typename T>
class Mutable_Array_Sequence : public Array_sequence<T> {

private:
    Dynamic_Array<T>* array = new Dynamic_Array<T>;

public:

    
	Mutable_Array_Sequence(int size, const T& item) : Array_sequence<T>(size, item) {}

	Mutable_Array_Sequence() : Array_sequence<T>() {}

	Mutable_Array_Sequence(const Array_sequence<T>& other) : Array_sequence<T>(other) {}
    
    
    // -----------------------------------------------------

    Array_sequence<T>* Instance() override {
        return this;
    }

    Array_sequence<T>* Mutability() const override {
        return new Mutable_Array_Sequence();
    }

    Array_sequence<T>* Mutability(int size, const T& item) const  {
        return new Mutable_Array_Sequence(size, item);
    }

};


