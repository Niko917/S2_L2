#pragma once

#include "list_seq.h"

template <typename T>
class Immutable_List_Sequence : public List_Sequence<T> {
public:
    List_Sequence<T>* Instance() override {
        return new Immutable_List_Sequence(*this);
    }

    List_Sequence<T>* Mutability() const override {
        return new Immutable_List_Sequence();
    }

    List_Sequence<T>* Mutability(int size, const T& item) const override {
        return new Immutable_List_Sequence(size, item);
    }


	Immutable_List_Sequence(int size, const T& item) : List_Sequence<T>(size, item) {}


	Immutable_List_Sequence() : List_Sequence<T>() {}
};
