
/*

template <typename T>
class Mutable_Array_Sequence : public Array_sequence<T> {
public:
    Mutable_Array_Sequence() : Array_sequence<T>() {}
    Mutable_Array_Sequence(T* items, int count) : Array_sequence<T>(items, count) {}

    Array_sequence<T>* Instance() override {
        return this;
    }

    Sequence<T>* Append(T item) override {
        this->array->Append(item);
        return this;
    }

    Sequence<T>* Prepend(T item) override {
        this->array.Prepend(item);
        return this;
    }

    Sequence<T>* Insert_At(T item, int index) override {
        this->array->Insert_At(item, index);
        return this;
    }

    Sequence<T>* Concat(const Sequence<T>& other_seq) override {
        this->array->Concat(other_seq);
        return this;
    }

    Sequence<T>* Get_subsequence(int start_index, int end_index) override {
        if (start_index < 0 || end_index > this->array->Get_size() || start_index >= end_index) {
            throw Index_Out_of_range;
        }

        int new_Size = end_index - start_index;
        T* subArray = new T[new_Size];
        for (int i = 0; i < new_Size; ++i) {
            subArray[i] = this->array->Get(start_index + i);
        }
        return new Mutable_Array_Sequence<T>(subArray, new_Size);
    }
};


// ---------------------------------------------------------------------------------------


template <typename T>
class Immutable_Array_Sequence : public Array_sequence<T> {
public:
    Immutable_Array_Sequence() : Array_sequence<T>() {}
    Immutable_Array_Sequence(T* items, int count) : Array_sequence<T>(items, count) {}

    Immutable_Array_Sequence(const Immutable_Array_Sequence<T>& other_Arr) : Array_sequence<T>(other_Arr->array->Get_data(), other_Arr->Get_size()) {}

    Array_sequence<T>* Instance() override {
        return new Immutable_Array_Sequence(*this);
    }

    Sequence<T>* Append(T item) override {
        Dynamic_Array<T>* new_Arr = new Dynamic_Array<T>(this->array->Get_size() + 1);

        for (size_t i = 0; i < this->array->Get_size(); ++i) {
            new_Arr->Set(i, this->array->Get(i));
        }
        new_Arr->Set(this->array->Get_szie(), item);
        return new Immutable_Array_Sequence<T>(new_Arr->Get_data(), new_Arr->Get_size());
    }

    
    Sequence<T>* Prepend(T item) override {
        Dynamic_Array<T>* new_Arr = new Dynamic_Array<T>(this->array->Get_size() + 1);
        new_Arr->Set(0, item);
        for (size_t i = 0; i < this->array->Get_szie(); ++i) {
            new_Arr->Set(i + 1, this->array->Get(i));
        }
        return new Immutable_Array_Sequence<T>(new_Arr->Get_data(), new_Arr->Get_size());
    }
    
    Sequence<T>* Insert_At(T item, int index) override {
        if (index < 0 || index > this->array->Get_size()) {
            throw Index_Out_of_range;
        }
        Dynamic_Array<T>* new_Array = new Dynamic_Array<T>(this->array->Get_size() + 1);
        for (size_t i = 0; i < index; ++i) {
            new_Array->Set(i, this->array->Get(i));
        }
        new_Array->Set(index, item);
        for (size_t i = index; i < this->array->Get_size(); ++i) {
            new_Array->Set(i + 1, this->array->Get(i));
        }
        return new Immutable_Array_Sequence<T>(new_Array->Get_data(), new_Array->Get_size());
    }
    

    Sequence<T>* Concat(const Sequence<T>& other_seq) override {
        int new_Size = this->array->Get_size() + other_seq.Get_length();
        Dynamic_Array<T>* new_Array = new Dynamic_Array<T>(new_Size);
        for (size_t i = 0; i < this->array->Get_size(); ++i) {
            new_Array->Set(i, this->array->Get(i));
        }
        for (size_t i = 0; i < other_seq.Get_length(); ++i) {
            new_Array->Set(this->array->Get_size() + i, other_seq[i]);
        }
        return new Immutable_Array_Sequence<T>(new_Array->Get_data(), new_Array->Get_size());
    }

    Sequence<T>* Get_subsequence(int start_index, int end_index) override {
        if (start_index < 0 || end_index >= this->array->Get_size() || start_index > end_index) {
            throw Index_Out_of_range;
        }
        int new_Size = end_index - start_index + 1;
        Dynamic_Array<T>* new_Array = new Dynamic_Array<T>(new_Size);
        for (int i = 0; i < new_Size; ++i) {
            new_Array->Set(i, this->array->Get(start_index + i));
        }
        return new Immutable_Array_Sequence<T>(new_Array->Get_data(), new_Array->Get_size());
    }
};
*/


