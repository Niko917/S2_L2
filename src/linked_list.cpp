#include <algorithm>
#include <iterator>
#include <new>
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
   
    Doubly_Circular_Linked_list(size_t size) : head(nullptr), tail(nullptr), size(0) {}

    Doubly_Circular_Linked_list(T* items, int count) {
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }

    Doubly_Circular_Linked_list() {}

    // copy constructor 
    Doubly_Circular_Linked_list(const Doubly_Circular_Linked_list<T>& list)
                   : Doubly_Circular_Linked_list() {
        Node<T>* current = list.head;
        if (current) {
            do {
                Append(current->item);
                current = current->next;
            }
            while (current != head);
        }
    }

    // Destructor 
    ~Doubly_Circular_Linked_list () {
        if (head){
            Node<T>* current = head;
            do {
                Node<T>* next = current->next;
                delete current;
                current = next;
            } while (current != head);
        }
    }


    ///////////////////////////////////////////////
    ///METHODS
    ///
    T Get_first();

    T Get_last();

    T Get(int index);

    Doubly_Circular_Linked_list<T>* Get_sublist(int start_index, int end_index);

    int Get_lenght();

    void Append(T item);

    void Prepand(T item);

    void Insert_At(T item, int index);

    Doubly_Circular_Linked_list<T>* Concat(Doubly_Circular_Linked_list<T>* list);
};

//////////////////////////////////////////////////////////////////////////////////////
///METHODS

template <typename T>
T Doubly_Circular_Linked_list<T>::Get_first() {
    if (!head) throw List_is_empty;
    return head->item;
}

template <typename T>
T Doubly_Circular_Linked_list<T>::Get_last() {
    if (!tail) throw List_is_empty;
    return tail->item;
}

template <typename T>
T Doubly_Circular_Linked_list<T>::Get(int index) {
    if (index < 0 || index >= size) throw Index_Out_of_range;
    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->item;
}


template <typename T>
Doubly_Circular_Linked_list<T>* Doubly_Circular_Linked_list<T>::Get_sublist(int start_index,
                                                                            int end_index) {
    if (start_index < 0 || end_index < 0 || start_index >= size || end_index >= size 
                                                                    || start_index > end_index) {
        throw Index_Out_of_range;
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
int Doubly_Circular_Linked_list<T>::Get_lenght() {
    return size;
}


template <typename T>
void Doubly_Circular_Linked_list<T>::Append(T item) {
    Node<T>* new_node = new Node<T>(item);
    if (size == 0) {
        new_node = head = tail;
        head->prev = head->next = new_node;
    }
    else {
        new_node->next = head;
        new_node->prev = tail;

        head->prev = new_node;
        tail->next = new_node;
        new_node = tail;
    }
    size++;
}

template <typename T>
void Doubly_Circular_Linked_list<T>::Prepand(T item) {
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
        new_node = head;
    }
    size++;
}

template <typename T>

void Doubly_Circular_Linked_list<T>::Insert_At(T item, int index) {
    if (index < 0 || index > size) throw Index_Out_of_range;
    if (index == 0) {
        Prepand(item);
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
        new_node->next = current;
        current->prev = new_node->prev;
        current->prev->next = new_node;
        current->prev = new_node;
        
        size++;
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
