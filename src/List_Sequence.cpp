#include "Sequence.h"
#include "list_seq.h"


template <typename T>
T List_Sequence<T>::Get_first() {
    return Linked_list->Get_first();
}



template <typename T>
T List_Sequence<T>::Get_last() {
    return Linked_list->Get_last();
}



template <typename T>
T List_Sequence<T>::Get(int index) {
    return Linked_list->Get(index);
}



template <typename T>
int List_Sequence<T>::Get_length() {
    return Linked_list->Get_length();
}



template <typename T>
void List_Sequence<T>::Append_Internal(const T& item) const {
    return Linked_list->Append(item);
}



template <typename T>
void List_Sequence<T>::Prepend_Internal(const T& item) const {
    return Linked_list->Prepend(item);
}



template <typename T>
void List_Sequence<T>::Set_Internal(const T& item, int index) {
    return Linked_list->Set(index, item);
}



template <typename T>
void List_Sequence<T>::Insert_At_Internal(T& item, int index) {
    return Linked_list->Insert_At(item, index);
}



template <typename T>
void List_Sequence<T>::Resize_Internal(size_t New_size) {
    return Linked_list->Resize(New_size);
}


template <typename T>
void List_Sequence<T>::Concat_Internal(const Sequence<T>& list) {
    return Linked_list->Concat(list);
}




template <typename T>
void List_Sequence<T>::clear_Internal() {
    return Linked_list->clear();
}




template <typename T>
T& List_Sequence<T>::operator[](const int index) {
        if (index < 0 || index >= Linked_list->Get_length()) throw ERRORS::Index_Out_of_range;

        Node<T>* current = Linked_list->GetNode(index);
        return current->item;
}

// ----------------------------------

template <typename T>
List_Sequence<T>* List_Sequence<T>::Append(const T& item) {
    List_Sequence<T>* instance = Instance();
    instance = Append_Internal(item);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Prepend(const T& item) {
    List_Sequence<T>* instance = Instance();
    instance = Prepend_Internal(item);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Insert_At(const T& item, int index) {
    List_Sequence<T>* instance = Instance();
    instance = Insert_At_Internal(item, index);
    return instance;
}



template <typename T>
List_Sequence<T>* List_Sequence<T>::Concat(const Sequence<T>& list) {
    List_Sequence<T>* instance = Instance();
    instance = Concat_Internal(list);
    return instance;
}
