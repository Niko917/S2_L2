#include "Sequence.h"
#include <cstddef>

template <typename T>

class List_sequence : public Sequence<T> {
private:
    class Node {
    private:
        T item;
        Node* next;
    public:

        int data() {return this->item;}

        Node* Next() {return this->next;}

        void Set_data(int data) {this->item = data;}

        void Set_Next(Node* nd) {this->next = nd;}

        Node() {next = nullptr;}
    };

    Node* head;
    size_t size;

    friend T Get_First();
    friend T Get_Last();
    friend T Get(int index);
    friend void Append(T item);
    friend void Prepand(T item);
    friend  void Insert_At(T item, int index);
    friend List_sequence<T>* Concatenate(List_sequence<T>* list);

 

public:

    List_sequence(T* items, int count); 
    // copy elements from given array
    
    ~List_sequence() {} // destructor by default
    
    List_sequence(const List_sequence<T>& list);
    // copy constructor

/////////////////////////////////////////////
    /// METHODS
    
    T Get_First();

    T Get_Last();

    T Get(int index);

    List_sequence<T>* Get_sublist(int start_index, int end_index);

    int Get_Lenght();

    void Append(T item);

    void Prepand(T item);

    void Insert_At(T item, int index);

    List_sequence<T>* Concatenate(List_sequence<T>* list);

};
