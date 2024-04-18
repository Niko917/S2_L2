#include <stdlib.h>

template <typename T>

class Sequence {
    public:
        virtual T Get_first() const = 0; // clear virtual function
        
        virtual T Get_last() const = 0;
        
        virtual T Get(int index) const = 0;

        virtual int Get_lenght() const = 0;

        virtual Sequence<T>* Get_subsequence(int start_index, int end_index) const = 0;

        //////////////////////////////////////////////////////////////////////////////
        // OPERATIONS
        
        virtual Sequence<T>* Append (T item) const = 0;

        virtual Sequence<T>* Prepand(T item) const = 0;

        virtual Sequence<T>* Insert_At(T item, int index) const = 0;

        virtual Sequence<T>* Concat(Sequence<T>* list) const = 0;

        virtual ~Sequence<T> () {}
};
