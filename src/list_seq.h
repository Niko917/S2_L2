#pragma once

#include "list.h"
#include "Sequence.h"
#include "exceptions.h"
#include <climits>

template <typename T>
class List_Sequence : public Sequence<T> {

protected:
    Doubly_Circular_Linked_list<T>* Linked_list;

    void Append_Internal(const T& item) const;
    void Prepend_Internal(const T& item) const;
    void Set_Internal(const T& item, int index);
    void Insert_At_Internal(T& item, int index);
    void Resize_Internal(size_t New_size);
    void Concat_Internal(const Sequence<T>& list);
    void clear_Internal();

public:
    
    List_Sequence() : Linked_list(new Doubly_Circular_Linked_list<T>()) {}
    List_Sequence(T* items, int count) : Linked_list(new Doubly_Circular_Linked_list<T>(items, count)) {}
    ~List_Sequence() {delete Linked_list;}
    
    List_Sequence<T>* Instance() = 0;


    T Get_first() override;
    
    T Get_last() override;

    T Get(int index) override;

    int Get_length() override;
    
    // --------------------------------------------------

    List_Sequence<T>* Append(const T& item) override;

    List_Sequence<T>* Prepend(const T& item) override;

    List_Sequence<T>* Insert_At(const T& item, int index) override;

    List_Sequence<T>* Concat(const Sequence<T>& list) override;

    T& operator[](const int index) override;

};

////////////////////////////////////////////////////////////////////////////
