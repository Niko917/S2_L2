#include "Sequence.h"
#include "array_seq.h"


template <typename T>
Array_sequence<T>* Array_sequence<T>::Append(T& item) {
    Array_sequence<T>* instance = Instance();
    instance->Append_Internal(item);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Prepend(T& item) {
    Array_sequence<T>* instance = Instance();
    instance->Prepend_Internal(item);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Insert_At(T& item, int index) {
    Array_sequence<T>* instance = Instance();
    instance->Insert_At(item, index);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Concat(const Sequence<T>& other) {
    Array_sequence<T>* instance = Instance();
    instance->Concat(other);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::Resize(size_t New_size) {
    Array_sequence<T>* instance = Instance();
    instance->Resize(New_size);
    return instance;
}



template <typename T>
Array_sequence<T>* Array_sequence<T>::map(T(*function)(const T&)) {
    Array_sequence<T>* sq = Instance();

    for (int i = 0; i < this->Get_length(); ++i) {
        sq->Set(function((*array)[i]), i);
    }
    
    return sq;
}



template <typename T>
int Array_sequence<T>::find(T& element) const {
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            return i;
        }
    }
    return -1;
}



template <typename T>
int Array_sequence<T>::count(T& element) const {
    int count = 0;
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            count++;
        }
    }
    return count;
}


template <typename T>
Array_sequence<T>* Array_sequence<T>::clear() {
    Array_sequence<T>* instance = Instance();
    instance->clear_Internal();
    return instance;
}




// --------------------------------------------------------

template <typename T>
size_t Array_sequence<T>::Get_length() const {
    return array->Get_size();
}



template <typename T>
void Array_sequence<T>::Append_Internal(const T& item) const {
    return array->Append(item);
}



template <typename T>
void Array_sequence<T>::Prepend_Internal(const T& item) const{
    return array->Prepend(item);
}



template <typename T>
void Array_sequence<T>::Set_Internal(int index, const T& item) {
    return array->Set(index, item);
}



template <typename T>
void Array_sequence<T>::Insert_At_Internal(T& item, int index) {
    return array->Insert_At(item, index);
}



template <typename T>
void Array_sequence<T>::Resize_Internal(size_t New_size) {
    return array->Resize(New_size);
}



template <typename T>
void Array_sequence<T>::Concat_Internal(Array_sequence<T>& other_seq) {
    return array->Concat(other_seq);
}

template <typename T>
void Array_sequence<T>::clear_Internal() {
    array->clear();
}
