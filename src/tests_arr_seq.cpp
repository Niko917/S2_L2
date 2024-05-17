#include <algorithm>
#include <cassert>
#include <iostream>
#include "mutable_array.h"
#include "Immutable_Array.h"


// ----------------------------------------------------
// ARRAY_SEQUENCE TESTS



void Test_Constructors_and_Destructors_AS() {

    Array_sequence<int>* as_int = new Mutable_Array_Sequence<int>();

    Array_sequence<double>* as_double = new Mutable_Array_Sequence<double>();

    Array_sequence<char>* as_char = new Immutable_Array_Sequence<char>();

    Array_sequence<int*>* as_int_ptr = new Immutable_Array_Sequence<int*>();


    as_int->~Array_sequence();
	as_double->~Array_sequence();
	as_char->~Array_sequence();
	as_int_ptr->~Array_sequence();

    Array_sequence<int>* mas_5 = new Mutable_Array_Sequence<int>(10, 10);
	Array_sequence<int>* mas_6 = new Mutable_Array_Sequence<int>(*mas_5);


	assert(mas_5->Get_length() == 10);
	assert(mas_6->Get_length() == 10);
	assert((*mas_5)[0] == (*mas_6)[0]);
	assert((*mas_5)[1] == (*mas_6)[1]);
	assert((*mas_5)[2] == (*mas_6)[2]);
	assert((*mas_5)[3] == (*mas_6)[3]);
	assert((*mas_5)[4] == (*mas_6)[4]);
	assert((*mas_5)[5] == (*mas_6)[5]);
	assert((*mas_5)[6] == (*mas_6)[6]);
	assert((*mas_5)[7] == (*mas_6)[7]);
	assert((*mas_5)[8] == (*mas_6)[8]);
	assert((*mas_5)[9] == (*mas_6)[9]);
	mas_5->~Array_sequence();
	mas_6->~Array_sequence();
}



void Test_Basic_Operations_AS() {

    Array_sequence<int>* mas = new Mutable_Array_Sequence<int>(10, 10);


    mas->Set(1, 0);
	mas->Set(2, 1);
	mas->Set(3, 2);
	mas->Set(4, 3);
	mas->Set(5, 4);
	mas->Set(6, 5);
	mas->Set(7, 6);
	mas->Set(8, 7);
	mas->Set(9, 8);


    
    assert((*mas)[0] == mas->Get(0) && mas->Get(0) == 1);
	assert((*mas)[1] == mas->Get(1) && mas->Get(1) == 2);
	assert((*mas)[2] == mas->Get(2) && mas->Get(2) == 3);
	assert((*mas)[3] == mas->Get(3) && mas->Get(3) == 4);
	assert((*mas)[4] == mas->Get(4) && mas->Get(4) == 5);
	assert((*mas)[5] == mas->Get(5) && mas->Get(5) == 6);
	assert((*mas)[6] == mas->Get(6) && mas->Get(6) == 7);
	assert((*mas)[7] == mas->Get(7) && mas->Get(7) == 8);
	assert((*mas)[8] == mas->Get(8) && mas->Get(8) == 9);
	assert((*mas)[9] == mas->Get(9) && mas->Get(9) == 10);



	mas->Pop_back();
	mas->Pop_back();
	mas->Pop_front();
	mas->Pop_front();
	mas->Pop_back();
	assert((*mas)[0] == mas->Get(0) && mas->Get(0) == mas->Get_first());
	assert((*mas)[4] == mas->Get(4) && mas->Get(4) == mas->Get_last());
	mas->Prepend(-2);
	mas->Prepend(-1);
	mas->Append(-8);
	mas->Append(-9);
	mas->Append(-10);
	assert((*mas)[0] == mas->Get(0) && mas->Get(0) == -1);
	assert((*mas)[1] == mas->Get(1) && mas->Get(1) == -2);
	assert((*mas)[7] == mas->Get(7) && mas->Get(7) == -8);
	assert((*mas)[8] == mas->Get(8) && mas->Get(8) == -9);
	assert((*mas)[9] == mas->Get(9) && mas->Get(9) == -10);

	mas->clear();

}



void Test_Methods_AS() {

    Mutable_Array_Sequence<int>* mas_1 = new Mutable_Array_Sequence<int>(5, 100);
	Mutable_Array_Sequence<int>* mas_2 = new Mutable_Array_Sequence<int>(5, 200);
	
    mas_1->Concat(*mas_2);
	assert(mas_1->Get_length() == 10);
	
    for (int i = 0; i < 5; ++i) {
		assert(mas_1->Get(i) == 100);
		assert(mas_1->Get(i + 5) == 200);
	}
	assert(mas_2->Get_length() == 5);
	
    for (int i = 0; i < 5; ++i) {
		assert(mas_2->Get(i) == 200);
	}



    Immutable_Array_Sequence<int>* imas_1 = new Immutable_Array_Sequence<int>(5, 100);
	Immutable_Array_Sequence<int>* imas_2 = new Immutable_Array_Sequence<int>(5, 200);

	imas_1->Concat(*imas_2);
	assert(imas_1->Get_length() == 5);
	
    for (int i = 0; i < 5; ++i) {
		assert(imas_1->Get(i) == 100);
	}
	
    assert(imas_2->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(imas_2->Get(i) == 200);
	}
    


	
    assert(imas_1->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(imas_1->Get(i) == 100);
	}

	mas_2->Resize(10);
	assert(mas_2->Get_length() == 10);
	for (int i = 0; i < 5; ++i) {
		assert(mas_2->Get(i) == 200);
	}


	assert(imas_2->count(200) == 5);

}



void Test_Array_Sequence() {
    Test_Constructors_and_Destructors_AS();
    Test_Basic_Operations_AS();
    Test_Methods_AS();
    std::cout << "All Array_sequence tests passed! \n";
}


