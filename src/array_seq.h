#include "Sequence.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include "array.h"
#include "exceptions.h"

template <typename T>

class Array_sequence : public Sequence<T> {
protected:
    Dynamic_Array<T>* array;

    virtual Sequence<T> AppendInternal(T item) = 0;

public:
    Array_sequence() : array(new Dynamic_Array<T>()) {}
    Array_sequence(T* items, int count) : array(Dynamic_Array<T>(count)) {
        for (int i = 0; i < count; ++i) {
            array->Set(i, items[i]);
        }
    }
    virtual ~Array_sequence() {delete array;}

//////////////////////////////////////////////////////////////////////////////////
    ///METHODS
    
    T Get_first() const override {
        return array->Get_first();
    }

    T Get_last() const override {
        return array->Get(array->Get_size() - 1);
    }

    T Get(int index) const override {
        return array->Get(index);
    }
    
    T Get_length() const override {
        return array->Get_size();
    }

    virtual Sequence<T>* Get_subsequence(int start_index, int end_index) const = 0;


    T& operator[](const int index) const override {
        return (*array)[index];
    }

    virtual Sequence<T>* Append(T item) = 0;

    virtual Sequence<T>* Prepend(T item) = 0;

    virtual Sequence<T>* Insert_At(T item, int index) = 0;

    virtual Sequence<T>* Concat(const Sequence<T>& other_arr) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Mutable_Array_Sequence : public Array_sequence<T> {
public:

    Mutable_Array_Sequence() : Array_sequence<T>() {}
    Mutable_Array_Sequence(T* items, int count) : 
    Array_sequence<T>(items, count) {}

    Sequence<T>* Append(T item) override {
        this->array->Resize(this->array->Get_size() + 1);
        this->array->Set(this->array->Get_size() - 1, item);
        return this;
    }

    Sequence<T>* Prepand(T item) override {
        this->array-Resize(this->array->Get_size() + 1);

        for (size_t i = this->array->Get_size() - 1; i > 0; --i) {
            this->array->Set(i, this->array->Get(i - 1));
        }

        this->array->Set(0, item);
        return this;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index > this->array->Get_size()) throw Index_Out_of_range;

        this->array->Resize(this->array->Get_size() + 1);
        
        for (size_t i = this->array->Get_size() - 1; i > index; --i) {
            this->array->Set(i, this->array->Get(i - 1));
        }
        
        this->array->Set(index, item);
        return this;
    }


    Sequence<T>* Concat(Sequence<T>* list) override {
        size_t newSize = this->array->Get_size() + list->GetLength();
        this->array->Resize(newSize);
        
        for (int i = 0; i < list->GetLength(); ++i) {
            this->array->Set(this->array->Get_size() - list->GetLength() + i, list->Get(i));
        }

        return this;
    }
   
    Sequence<T>* Get_subsequence(int start_index, int end_index) const override {
        if (start_index < 0 || end_index < 0 || start_index > end_index || end_index >= this->array->Get_size()) {
            throw Invalid_sequence_type;
        }

        Mutable_Array_Sequence<T>* subsequence = new Mutable_Array_Sequence<T> ();

        for (int i = start_index; i <= end_index; ++i) {
            subsequence = Append(this->array->Get(i));
        }
        return subsequence;
    }

    virtual ~Mutable_Array_Sequence() {} 
};

/////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Immutable_Array_Sequence : public Array_sequence<T> { 
public:
    Immutable_Array_Sequence() : Array_sequence<T>() {}
    Immutable_Array_Sequence(const Immutable_Array_Sequence<T>& sequence) : Array_sequence<T>(sequence) {}

    Sequence<T>* Append(T item) override {
        Dynamic_Array<T>* newArray = new Dynamic_Array<T>(this->array->Get_size() + 1);
        for (size_t i = 0; i < this->array->Get_size(); ++i) {
            newArray->Set(i, this->array->Get(i));
        }
        newArray->Set(this->array->Get_size(), item);
        Immutable_Array_Sequence<T>* newSequence = new Immutable_Array_Sequence<T>();
        delete newSequence->array;
        newSequence->array = newArray;
        return newSequence;
    }

    Sequence<T>* Prepend(T item) override {
        Dynamic_Array<T>* newArray = new Dynamic_Array<T>(this->array->Get_size() + 1);
        newArray->Set(0, item);
        for (size_t i = 0; i < this->array->Get_size(); ++i) {
            newArray->Set(i + 1, this->array->Get(i));
        }
        Immutable_Array_Sequence<T>* newSequence = new Immutable_Array_Sequence<T>();
        delete newSequence->array;
        newSequence->array = newArray;
        return newSequence;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index > this->array->Get_size()) throw std::out_of_range("Index out of range");
        Dynamic_Array<T>* newArray = new Dynamic_Array<T>(this->array->Get_size() + 1);
        for (size_t i = 0; i < index; ++i) {
            newArray->Set(i, this->array->Get(i));
        }
        newArray->Set(index, item);
        for (size_t i = index; i < this->array->Get_size(); ++i) {
            newArray->Set(i + 1, this->array->Get(i));
        }
        Immutable_Array_Sequence<T>* newSequence = new Immutable_Array_Sequence<T>();
        delete newSequence->array;
        newSequence->array = newArray;
        return newSequence;
    }

    Sequence<T>* Concat(Sequence<T>* list) override {
        size_t newSize = this->array->Get_size() + list->GetLength();
        Dynamic_Array<T>* newArray = new Dynamic_Array<T>(newSize);
        for (size_t i = 0; i < this->array->Get_size(); ++i) {
            newArray->Set(i, this->array->Get(i));
        }
        for (int i = 0; i < list->GetLength(); ++i) {
            newArray->Set(this->array->Get_size() + i, list->Get(i));
        }
        Immutable_Array_Sequence<T>* newSequence = new Immutable_Array_Sequence<T>();
        delete newSequence->array;
        newSequence->array = newArray;
        return newSequence;
    }

    virtual ~Immutable_Array_Sequence() {}
};

