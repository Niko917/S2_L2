#pragma once

#include <cstddef>
#include "exceptions.h"

template <typename T>

struct Node {
    
    T item;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) : item(data), next(nullptr), prev(nullptr) {}

};

template <typename T>

class Doubly_Circular_Linked_list {
private:
    Node<T>* head;
    Node<T>* tail;

    size_t size;

public:
   

    Doubly_Circular_Linked_list(T* items, size_t count);

    Doubly_Circular_Linked_list();


    Doubly_Circular_Linked_list(int size, T default_element);

    // copy constructor 
    Doubly_Circular_Linked_list(const Doubly_Circular_Linked_list<T>& list);

    // Destructor 
    ~Doubly_Circular_Linked_list ();


    ///////////////////////////////////////////////
    ///METHODS
    ///
    
    Node<T>* GetNode(int index) const;


    T Get_first() const;

    T Get_last() const;

    T Get(size_t index) const;

    void Set(T item, size_t index);

    Doubly_Circular_Linked_list<T>* Get_sublist(size_t start_index, size_t end_index) const;

    size_t Get_length() const;

    void Append(T item);

    void Prepend(T item);

    void Pop_front();

    void Pop_back();

    void Insert_At(T item, size_t index);

    void Resize(size_t New_size);

    Doubly_Circular_Linked_list<T>* Concat(Doubly_Circular_Linked_list<T>* list);

    bool empty() const;

    void clear();

    T& operator[](const size_t index) const;
};



// -------------------------------------
// constructors and Destructors


template <typename T>
Doubly_Circular_Linked_list<T>::Doubly_Circular_Linked_list() : head(nullptr), tail(nullptr), size(0) {}



template <typename T>
Doubly_Circular_Linked_list<T>::Doubly_Circular_Linked_list(T* items, size_t count) {
    for (int i = 0; i < count; ++i) {
        this->Append(items[i]);
    }
}



template <typename T>
Doubly_Circular_Linked_list<T>::Doubly_Circular_Linked_list(const Doubly_Circular_Linked_list<T>& list) : Doubly_Circular_Linked_list() {
    Node<T>* current = list.head;
    if (current) {
        do {
            this->Append(current->item);
            current = current->next;
        }
        while (current != list.head);
    }
}


template<typename T>
Doubly_Circular_Linked_list<T>::Doubly_Circular_Linked_list(int size, T default_element):Doubly_Circular_Linked_list() {
	if (size <= 0) {
		throw ERRORS::Index_Out_of_range;
	}
	else {
		for (int i = 0; i < size; ++i) {
			this->Append(default_element);
		}
	}
}



template <typename T>
Doubly_Circular_Linked_list<T>::~Doubly_Circular_Linked_list() {
    clear();
}

////////////////////////////////////////
///METHODS

template <typename T>
Node<T>* Doubly_Circular_Linked_list<T>::GetNode(int index) const {
    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}



template <typename T>
T Doubly_Circular_Linked_list<T>::Get_first() const {
    if (!head) throw ERRORS::Sequence_is_empty;
    return head->item;
}



template <typename T>
T Doubly_Circular_Linked_list<T>::Get_last() const {
    if (!tail) throw ERRORS::Sequence_is_empty;
    return tail->item;
}



template <typename T>
T Doubly_Circular_Linked_list<T>::Get(size_t index) const {
    if (index >= size) throw ERRORS::Index_Out_of_range;

    if (head == nullptr) throw ERRORS::Sequence_is_empty;
    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    if (current == nullptr) throw ERRORS::Null_pointer_error;
    return current->item;
}



template <typename T>
Doubly_Circular_Linked_list<T>* Doubly_Circular_Linked_list<T>::Get_sublist(size_t start_index,
                                                                            size_t end_index) const {
    if (start_index < 0 || end_index < 0 || start_index >= size || end_index >= size 
                                                                    || start_index > end_index) {
        throw ERRORS::Index_Out_of_range;
    }

    Doubly_Circular_Linked_list<T>* Sublist = new Doubly_Circular_Linked_list<T>();
    Node<T>* current = head;
    for (int i = 0; i < start_index; ++i) {
        current = current->next;
    }
    for (int i = start_index; i <= end_index; ++i) {
        Sublist->Append(current->item);
        current = current->next;
    }
    return Sublist;
}



template <typename T>
size_t Doubly_Circular_Linked_list<T>::Get_length() const {
    return size;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Set(T item, size_t index) {
    if (index >= Get_length()) {
        throw ERRORS::Index_Out_of_range; 
    }
    
    Node<T>* current = GetNode(index);
    current->item = item;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Append(T item) {
    Node<T>* new_node = new Node<T>(item);
    if (size == 0) {
        tail = head = new_node;
        head->next = head;
        head->prev = head;
    }
    else {
        new_node->next = head;
        new_node->prev = tail;

        
        tail->next = new_node;
        head->prev = new_node;
        tail = new_node; 
    }
    size++;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Prepend(T item) {
    Node<T>* new_node = new Node<T>(item);
    if (size == 0) {
        tail = head = new_node;
        head->next = head->prev = new_node;
    }
    else {
        head->prev = new_node;
        tail->next = new_node;

        new_node->next = head;
        new_node->prev = tail;
        head = new_node;    
    }
    size++;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Pop_front() {
    if (head == nullptr) throw ERRORS::Sequence_is_empty;

    Node<T>* to_remove = head;

    if (head == tail) {
        head = nullptr; 
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    
    delete to_remove;
    size--;

    if (size == 0) {
        head = tail = nullptr;
    }
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Pop_back() {
    if (head == nullptr) throw ERRORS::Sequence_is_empty;

    Node<T>* to_remove = head;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    delete to_remove;

    size--;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::Insert_At(T item, size_t index) {
    if (index < 0 || index > size) throw ERRORS::Index_Out_of_range;
    if (index == 0) {
        Prepend(item);
    }
    else if (index == size) {
        Append(item);
    }
    else {
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        Node<T>* new_node = new Node<T>(item);
    
        new_node->prev = current->prev;
        new_node->next = current;

        current->prev->next = new_node;
        current->prev = new_node;
        
        size++;
    }
}


template <typename T>
void Doubly_Circular_Linked_list<T>::Resize(size_t New_size) {
    while (New_size > Get_length()) {
        Append(T()); 
    }
    while (New_size < Get_length()) {
        Node<T>* to_remove = tail;
        if (tail->prev == head) {
            head->next = head;
            head->prev = head;
            tail = head;
        }
        else if (tail->prev) {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        else {
            head = nullptr;
            tail = nullptr;
        }

        delete to_remove;
        size--;
        if (this->size == 0) {
            break;
        }
    }
}



template <typename T>
Doubly_Circular_Linked_list<T>* Doubly_Circular_Linked_list<T>::Concat(Doubly_Circular_Linked_list<T>* list) {
    Doubly_Circular_Linked_list<T>* common_list = new Doubly_Circular_Linked_list<T>(*this);
    // used copy constructor to copy base list into common list
    Node<T>* current = list->head;
    if (current){
        do {
            common_list->Append(current->item);
            current = current->next;
        }
        while (current != list->head);
    }
    return common_list;
}


template <typename T>
bool Doubly_Circular_Linked_list<T>::empty() const {
    if (this->Get_length() == 0) {
        return true;
    }
    return false;
}



template <typename T>
void Doubly_Circular_Linked_list<T>::clear() {
    
    while (size > 0) {
        Node<T>* next = head->next;
        delete head;
        head = next;
        if (head == tail) {
            head->next = nullptr;
            head->prev = nullptr;
        }
        size--;
    }
    head = nullptr;
    tail = nullptr;
}



template <typename T>
T& Doubly_Circular_Linked_list<T>::operator[](const size_t index) const {
    if (index >= size) {
        throw ERRORS(ERRORS::Index_Out_of_range);
    } 
    return GetNode(index)->item;
}
