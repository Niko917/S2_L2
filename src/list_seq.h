#include "list.h"
#include "Sequence.h"
#include "exceptions.h"
#include <climits>

template <typename T>
class List_Sequence : public Sequence<T> {

private:
    Doubly_Circular_Linked_list<T>* Linked_list;
public:
    
    List_Sequence() : Linked_list(new Doubly_Circular_Linked_list<T>()) {}
    List_Sequence(T* items, int count) : Linked_list(new Doubly_Circular_Linked_list<T>(items, count)) {}
    ~List_Sequence() {delete Linked_list;}

    T Get_first() const override {
        return Linked_list->Get_first();
    }
    
    T Get_last() const override {
        return Linked_list->Get_last();
    }

    T Get(int index) const override {
        return Linked_list->Get(index);
    }

    int Get_length() const override {
        return Linked_list->Get_length();
    }

    Sequence<T>* Get_subsequence(int start_index, int end_index) const override {
        Doubly_Circular_Linked_list<T> sublist = this->Linked_list->Get_sublist(start_index, end_index);
        List_Sequence<T>* sequence = new List_Sequence<T>;
        Node<T>* current = sublist->head;

        for (int i = start_index; i <= end_index; ++i) {
            sequence->Append(current->item);
            current = current->next;
        }
        delete sublist;
        return sequence;
    }

    Sequence<T>* Append(T item) override {
        Linked_list.Append(item);
        return this;
    }

    Sequence<T>* Prepand(T item) override {
        Linked_list.Prepand(item);
        return this;
    }

    Sequence<T>* Insert_At(T item, int index) override {
        Linked_list.Insert_At(item, index);
        return this;
    }

    Sequence<T>* Concat(Sequence<T>& list) override {
        for (int i = 0; i < list.Get_length(); ++i) {
            Linked_list.Append(list.Get(i));
        }
        return this;
    }


    T& operator[](const int index) const override {
        if (index < 0 || index >= Linked_list.Get_length()) throw Index_Out_of_range;

        Node<T>* current = Linked_list.GetNode(index);
        return current->item;
    }
};

////////////////////////////////////////////////////////////////////////////

