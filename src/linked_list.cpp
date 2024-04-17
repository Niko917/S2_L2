#include "list_seq.h"
#include "exceptions.h"
#include <algorithm>


template <typename T>
T List_sequence<T>::Get_First() {

}

//////////////////////////////////////////////////////////

template <typename T>
T List_sequence<T>::Get_Last() {
    return this->*(head);    
}

/////////////////////////////////////////////////////////

template <typename T>
T List_sequence<T>::Get(int index) {

}

////////////////////////////////////////////////////////

template <typename T>
List_sequence<T>* List_sequence<T>::Get_sublist(int start_index, int end_index) {

}

/////////////////////////////////////////////////////////

template <typename T>
int List_sequence<T>::Get_Lenght() {
    return this->size;
}

/////////////////////////////////////////////////////////

template <typename T>
void List_sequence<T>::Append(T item) {

}

////////////////////////////////////////////////////////

template <typename T>
void List_sequence<T>::Prepand(T item) {
    if (this->head == nullptr) {
        // if list is empty
        Node* tmp = new Node();
        tmp->Set_data(item);
        head = tmp;
    }
    else {
        // let's find the biginning of the list


    }

}

////////////////////////////////////////////////////////

template <typename T>
void List_sequence<T>::Insert_At(T item, int index) {

}

////////////////////////////////////////////////////////

template <typename T>
List_sequence<T>* List_sequence<T>::Concatenate(List_sequence<T>* list) {

}

////////////////////////////////////////////////////////
