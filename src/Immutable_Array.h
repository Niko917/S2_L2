#pragma once

#include "array_seq.h"

template <typename T>
class Immutable_Array_Sequence : public Array_sequence<T> {
public:
    Array_sequence<T>* Instance() override {
        return new Immutable_Array_Sequence(*this);
    }

	Immutable_Array_Sequence(int size, const T& item) : Array_sequence<T>(size, item) {}
	Immutable_Array_Sequence() : Array_sequence<T>() {}
};
