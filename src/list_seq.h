#pragma once

#include "list.h"
#include "Sequence.h"
#include "exceptions.h"
#include <climits>
#include <cstddef>

template <typename T>
class List_Sequence : public Sequence<T> {

protected:

    Doubly_Circular_Linked_list<T>* Linked_list;

    void Append_Internal(T item) const;

    void Prepend_Internal(T item) const;

    void Pop_front_Internal();

    void Pop_back_Internal();

    void Set_Internal(T item, size_t index);

    void Insert_At_Internal(T item, size_t index);

    void Resize_Internal(size_t New_size);

    void clear_Internal();


public:
   
    List_Sequence();

    List_Sequence(T* items, size_t count) : Linked_list(new Doubly_Circular_Linked_list<T>(items, count)) {}

    List_Sequence(int size, T item);

    ~List_Sequence();
    
    // -----------------------------------------------------

    virtual List_Sequence<T>* Instance() = 0;

    virtual List_Sequence<T>* Mutability() const = 0;

    virtual List_Sequence<T>* Mutability(int size, const T& item) const = 0;


    T Get_first() const override;
    
    T Get_last() const override;

    T Get(size_t index) const override;

    size_t Get_length() const override;
    
    // --------------------------------------------------

    List_Sequence<T>* Append(T item) override;

    List_Sequence<T>* Prepend(T item) override;

    List_Sequence<T>* Pop_front() override;

    List_Sequence<T>* Pop_back() override;

    List_Sequence<T>* Insert_At(T item, size_t index) override;

    List_Sequence<T>* Set(T item, size_t index) override;

    List_Sequence<T>* Get_subsequence(size_t start_index, size_t end_index) const override;

    List_Sequence<T>* Concat(Sequence<T>& other) override;

    List_Sequence<T>* Resize(size_t New_size) override;

    List_Sequence<T>* clear() override;

    List_Sequence<T>* map(T(*function)(const T&)) override;

    int find(T element) const override;
    
    int count(T element) const override;

    T& operator[](const int index) const override;

};



/// ------------------------------------------------------
/// Constructors and Destructors

template <typename T>
List_Sequence<T>::List_Sequence() {
    Linked_list = new Doubly_Circular_Linked_list<T>();
}



template <typename T>
List_Sequence<T>::List_Sequence(int size, T item) {
    Linked_list = new Doubly_Circular_Linked_list<T>();
    for (int i = 0; i < size; i++) {
        Linked_list->Append(item);
    }
}



template <typename T>
List_Sequence<T>::~List_Sequence() {
    Linked_list->~Doubly_Circular_Linked_list<T>();
}

/// -------------------------------------------------------



template <typename T>
T List_Sequence<T>::Get_first() const {
    return Linked_list->Get_first();
}



template <typename T>
T List_Sequence<T>::Get_last() const {
    return Linked_list->Get_last();
}



template <typename T>
T List_Sequence<T>::Get(size_t index) const {
    return Linked_list->Get(index);
}



template <typename T>
size_t List_Sequence<T>::Get_length() const {
    return Linked_list->Get_length();
}



template <typename T>
void List_Sequence<T>::Append_Internal(T item) const {
    Linked_list->Append(item);
}



template <typename T>
void List_Sequence<T>::Prepend_Internal(T item) const {
    Linked_list->Prepend(item);
}



template <typename T>
void List_Sequence<T>::Pop_front_Internal() {
    Linked_list->Pop_front();
}



template<typename T>
void List_Sequence<T>::Pop_back_Internal() {
    Linked_list->Pop_back();
}



template <typename T>
void List_Sequence<T>::Set_Internal(T item, size_t index) {
    Linked_list->Set(index, item);
}



template <typename T>
void List_Sequence<T>::Insert_At_Internal(T item, size_t index) {
    Linked_list->Insert_At(item, index);
}



template <typename T>
void List_Sequence<T>::Resize_Internal(size_t New_size) {
    Linked_list->Resize(New_size);
}



template <typename T>
void List_Sequence<T>::clear_Internal() {
    Linked_list->clear();
}



template <typename T>
T& List_Sequence<T>::operator[](const int index) const {
        if (index < 0 || index >= Linked_list->Get_length()) throw ERRORS::Index_Out_of_range;

        Node<T>* current = Linked_list->GetNode(index);
        return current->item;
}

// --------------------------------------------------------

template <typename T>
List_Sequence<T>* List_Sequence<T>::Append(T item) {
    List_Sequence<T>* instance = Instance();
    instance->Append_Internal(item);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Prepend(T item) {
    List_Sequence<T>* instance = Instance();
    instance->Prepend_Internal(item);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Pop_front() {
    List_Sequence<T>* instance = Instance();
    instance->Pop_front_Internal();
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Pop_back() {
    List_Sequence<T>* instance = Instance();
    instance->Pop_back_Internal();
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Insert_At(T item, size_t index) {
    List_Sequence<T>* instance = Instance();
    instance->Insert_At_Internal(item, index);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Set(T item, size_t index) {
    List_Sequence<T>* instance = Instance();
    instance->Set(item, index);
    return instance;

}


template <typename T>
List_Sequence<T>* List_Sequence<T>::Resize(size_t New_size) {
    List_Sequence<T>* instance = Instance();
    instance->Resize(New_size);
    return instance;
}




template <typename T>
List_Sequence<T>* List_Sequence<T>::Concat(Sequence<T>& other) {
    List_Sequence<T>* instance = Instance();
    for (int i = 0; i < other.Get_length(); ++i) {
        instance->Append(other.Get(i));
    }
    return instance;
}




template<typename T>
List_Sequence<T>* List_Sequence<T>::Get_subsequence(size_t start_index, size_t end_index) const {
    if (start_index < 0 || end_index > static_cast<int>(this->Get_length()) || end_index > start_index) {
        throw ERRORS::Index_Out_of_range;
    }


    else {
        List_Sequence<T>* new_List_sequence = Mutability();
        
        for (int i = start_index; i <= end_index; ++i) {
        new_List_sequence->Append(this->Get(i));
    }

    return new_List_sequence;
    }
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::clear() {
    List_Sequence<T>* instance = Instance();
    instance->clear_Internal();
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::map(T(*function)(const T&)) {
    List_Sequence<T>* sq = Instance();

    for (int i = 0; i < this->Get_length(); ++i) {
        sq->Set(function((Linked_list->GetNode(i)->item)), i);
    }

    return sq;
}



template <typename T>
int List_Sequence<T>::find(T element) const {
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            return i;
        }
    }

    return -1;
}



template <typename T>
int List_Sequence<T>::count(T element) const {

    int count  = 0;
    for (int i = 0; i < this->Get_length(); ++i) {
        if (element == this->Get(i)) {
            count++;
        }
    }
    return count;
}
