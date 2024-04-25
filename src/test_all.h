#pragma once

#include "array.h"
#include "list.h"
#include "exceptions.h"
#include "array_seq.h"
#include "list_seq.h"
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <ostream>



template <typename T>
void Test_DynamicArray() {
    
    // constructor testing
    Dynamic_Array<T> array(5);
    assert(array.Get_size() == 5);

    Dynamic_Array<T> default_arr(0);
    assert(default_arr.Get_size() == 0);

    // testing Set method and operator
    for (int i = 0; i < array.Get_size(); ++i) {
        array.Set(i, T(i));
    }

    for (int i = 0; i < array.Get_size(); ++i) {
        assert(array[i] == T(i));
    }

    // copy testing
    Dynamic_Array<T> copy_testing(array);
    for (int i = 0; i < copy_testing.Get_size(); ++i) {
        assert(copy_testing.Get_size(i) == array.Get_size(i));
    }

    // Resize testing
    size_t old_size = array.Get_size();
    size_t new_size = 10;
    array.Resize(new_size);
    assert(array.Get_size() == new_size);

    for (int i = 0; i < std::min(old_size, new_size); ++i) {
        assert(array.Get_size(i) == T(i));
    }

    for (size_t i = old_size; i < new_size; ++i) {
        assert(array.Get_size(i) == T()); // new value set by default
    }

    // --------------------------------------------------
    // exceptions check
    try {
        array.Get(-1);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    
    try {
        array.Get(array.Get_size());
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }

    try {
        array.Resize(-1);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }

    try {
        array.Resize(0);
        array.Get_size();
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }

    try {
        array.Set(-1, 5);
        assert(false);

        array.Set(array.Get_size(), 5);
        assert(false);

        array.Set(11, 5);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    
    std::cout << "All Dynamic_array tests pessed!\n";
}




template <typename T>
void test_Doubly_circular_linked_list() {

    // ---------------------------------------
    // constructors testing

    Doubly_Circular_Linked_list<T> list;
    assert(list.Get_length() == 0);

    T items[] {T(1), T(2), T(3)};
    int count = sizeof(items) / sizeof(items[0]);     
    Doubly_Circular_Linked_list<T> list_for_constructor(items, count);

    
    bool correctOrder = true;
    for (int i = 0; i < count; ++i) {
        if (list_for_constructor.Get(i) != items[i]) {
            correctOrder = false;
            break;
        }
    }
    assert(correctOrder);

    // --------------------------------------------------
    // Append and Prepend check

    list.Append(T(1));
    
    assert(list.Get_length() == 1);
    assert(list.Get_first() == T(1));
    assert(list.Get_last() == T(1));

    
    list.Prepend(T(0));

    assert(list.Get_length() == 2);
    assert(list.Get_first() == T(0));
    assert(list.Get_last() == T(1));


    
    assert(list.Get(0) == T(0)); 
    assert(list.Get(1) == T(1));
    assert(list[0] == T(0));
    assert(list[1] == T(1));


    
    list.Insert_At(T(2), 1); // Inserting in the middle
    assert(list.Get_length() == 3);
    assert(list.Get(1) == T(2));

    // --------------------------------------
    // Cocnatenation

    Doubly_Circular_Linked_list<T> list_1;
    list_1.Append(T(1));
    list_1.Append(T(2));
    list_1.Append(T(3));

    Doubly_Circular_Linked_list<T> list_2;
    list_2.Append(T(4));
    list_2.Append(T(5));
    list_2.Append(T(6));

    list_1.Concat(list_2);

    assert(list_1.Get_length() == 6);

    assert(list_1.Get(0) == T(1));
    assert(list_1.Get(1) == T(2)); 
    assert(list_1.Get(2) == T(3));
    assert(list_1.Get(3) == T(4));
    assert(list_1.Get(4) == T(5));
    assert(list_1.Get(5) == T(6));

    assert(list_1.Get(0).prev == list_1.Get(5));
    assert(list_1.Get(5).next == list_1.Get(0));

    
    // --------------------------------------------
    // Get_sublist check
    Doubly_Circular_Linked_list<T> list_for_sublist;
    list_for_sublist.Append(T(1));
    list_for_sublist.Append(T(2));
    list_for_sublist.Append(T(3));
    list_for_sublist.Append(T(4));
    list_for_sublist.Append(T(5));

    int start_index = 1;
    int end_index = 3;
    
    Doubly_Circular_Linked_list<T> sublist = list_for_sublist.Get_sublist(start_index, end_index);
    assert(sublist.Get_length() == (end_index - start_index + 1));
    
    bool correctOrder_get_length = true;
    for (int i = 0; i <= end_index - start_index; ++i) {
        if (sublist.Get(i) != list_for_sublist.Get(i + start_index)) {
            correctOrder_get_length = false;
            break;
        }
    }
    assert(correctOrder_get_length);
    assert(sublist.Get(0).prev == sublist.Get(sublist.Size() - 1));
    assert(sublist.Get(sublist.Size() - 1).next == sublist.Get(0));





    // ------------------------------------------
    // exceptions check

    try {
        list.Insert_At(5, 0);
        assert(list.Get_first() == 5);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }

    try {
        assert(list_for_constructor.Get_last() == 3);
    } 
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }

    try {
        assert(list.Get(0) == 5);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    
    // ----------------------------------------------
    // Get_sublist check

    try {
        list_for_sublist.Get_sublist(-1, 3);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    try {
        list_for_sublist.Get_sublist(1, -3);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    try {
        list_for_sublist.Get_sublist(6, 2);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
    try {
        list_for_sublist.Get_sublist(2, 6);
        assert(false);
    }
    catch (const SEQUENCE_EXCEPTION& err) {
        std::cout << err.what() << '\n';
    }
}

