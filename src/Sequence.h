#pragma once

#include <stdlib.h>


template <typename T>

class Sequence {
    public:
        
        virtual T Get_first() const = 0; // pure virtual function 
        virtual T Get_last() const = 0;
        
        virtual T Get(int index) const = 0;

        virtual size_t Get_length() const = 0;

        virtual Sequence<T>* Get_subsequence(int start_index, int end_index) const = 0;
        
        virtual T& operator [] (const int index) const = 0;
        //////////////////////////////////////////////////////////////////////////////
        // OPERATIONS
        
        virtual Sequence<T>* Append (T& item) = 0;

        virtual Sequence<T>* Prepend(T& item) = 0;

        virtual Sequence<T>* Insert_At(T& item, int index) = 0;

        virtual Sequence<T>* Concat(Sequence<T>& other_seq) = 0;

        virtual Sequence<T>* Resize(size_t New_size) = 0;

        virtual Sequence<T>* Set(int index, T& value) = 0;

        virtual Sequence<T>* map(T(*function)(const T&)) = 0;
        
        int find(T element) const = 0;

        int count(T element) const = 0;

        virtual Sequence<T>* clear() = 0;

        virtual ~Sequence() {}
        
};



