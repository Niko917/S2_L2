#pragma once

#include <stdlib.h>


template <typename T>

class Sequence {

    public:

        
        virtual T Get_first() const = 0; // pure virtual function

        virtual T Get_last() const = 0;
        
        virtual T Get(size_t index) const = 0;

        virtual size_t Get_length() const = 0;

        virtual Sequence<T>* Get_subsequence(size_t start_index, size_t end_index) const = 0;

        bool empty() const {
            if (this->Get_length() == 0) {
                return true;
            }
            return false;
        }
        
        virtual T& operator [] (const int index) const = 0;

    // --------------------------------------------------------------------------------- 
    // OPERATIONS
        
        virtual Sequence<T>* Append (const T& item) = 0;

        virtual Sequence<T>* Prepend(const T& item) = 0;

        virtual Sequence<T>* Pop_back() = 0;

        virtual Sequence<T>* Pop_front() = 0;

        virtual Sequence<T>* Insert_At(const T& item, size_t index) = 0;

        virtual Sequence<T>* Concat(Sequence<T>& other) = 0;

        virtual Sequence<T>* Resize(size_t New_size) = 0;

        virtual Sequence<T>* Set(const T& item, size_t index) = 0;

        virtual Sequence<T>* map(T(*function)(const T&)) = 0;
        
        virtual int find(const T& element) const = 0;

        virtual int count(const T& element) const = 0;

        virtual Sequence<T>* clear() = 0;

        virtual ~Sequence() {}
        
    // -----------------------------------------------------------------------------

        virtual Sequence<T>* Instance() = 0;

        virtual Sequence<T>* Mutability() const = 0;

        virtual Sequence<T>* Mutability(int size, const T& item) const = 0;
        
};



