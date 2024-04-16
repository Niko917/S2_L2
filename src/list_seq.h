#include "Sequence.h"
#include <cstddef>

template <typename T>

class List_sequence : public Sequence<T> {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    size_t size;

public:
    List_sequence() = default; // construct by default
    
    List_sequence(T* items, int count); 
    // copy elements from given array
    
    ~List_sequence() {} // destructor by default
    
    List_sequence(const List_sequence<T>& list);
    // copy constructor

    

};
