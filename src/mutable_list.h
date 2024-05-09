#pragma once

#include "list_seq.h"

template <typename T>
class Mutable_List_Sequence : public List_Sequence<T> {
public:
    List_Sequence<T>* Instance() override {
        return this;
    }

    List_Sequence<T>* Mutability() const override {
        return new Mutable_List_Sequence();
    }

    List_Sequence<T>* Mutability(int size, const T& item) const override {
        return new Mutable_List_Sequence(size, item);
    }

    // ----------------------------------------------------
    // constructors

	Mutable_List_Sequence(int size, const T& item) : List_Sequence<T>(size, item) {}

	Mutable_List_Sequence() : List_Sequence<T>() {}

	Mutable_List_Sequence(const List_Sequence<T>& other) : List_Sequence<T>(other) {}
};
