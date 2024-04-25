#pragma once

#include <stdlib.h>


template <typename T>

class Sequence {
    public:
        
        virtual T Get_first() const = 0; // pure virtual function
        
        virtual T Get_last() const = 0;
        
        virtual T Get(int index) const = 0;

        virtual int Get_length() const = 0;

        virtual Sequence<T>* Get_subsequence(int start_index, int end_index) const = 0;
        
        virtual T& operator [] (const int index) const = 0;
        //////////////////////////////////////////////////////////////////////////////
        // OPERATIONS
        
        virtual Sequence<T>* Append (T item) = 0;

        virtual Sequence<T>* Prepend(T item) = 0;

        virtual Sequence<T>* Insert_At(T item, int index) = 0;

        virtual Sequence<T>* Concat(Sequence<T>& other_seq) = 0;

        virtual ~Sequence() {}
        
};



