#include <cstddef>

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
    
    Node<T>* GetNode(int index) const;


    T Get_first();

    T Get_last();

    T Get(int index);

    Doubly_Circular_Linked_list<T>* Get_sublist(int start_index, int end_index);

    int Get_length();

    void Append(T item);

    void Prepand(T item);

    void Insert_At(T item, int index);

    Doubly_Circular_Linked_list<T>* Concat(Doubly_Circular_Linked_list<T>* list);
};


