#include <cassert>
#include <iostream>
#include "mutable_list.h"
#include "Immutable_List.h"


// -----------------------------------------------------
// List_Sequence TESTS

void Test_Constructors_and_Destructors_LS() {
	List_Sequence<int>* mls_1 = new Mutable_List_Sequence<int>();
	List_Sequence<double>* mls_2 = new Mutable_List_Sequence<double>();
	List_Sequence<char>* imls_3 = new Immutable_List_Sequence<char>();
	List_Sequence<int*>* imls_4 = new Immutable_List_Sequence<int*>();

	
    mls_1->~List_Sequence();
	mls_2->~List_Sequence();
	imls_3->~List_Sequence();
	imls_4->~List_Sequence();
	
    List_Sequence<int>* mls_5 = new Mutable_List_Sequence<int>(10, 10);
	List_Sequence<int>* mls_6 = new Mutable_List_Sequence<int>(*mls_5);
	
    assert(mls_5->Get_length() == 10);
	assert(mls_6->Get_length() == 10);
	assert((*mls_5)[0] == (*mls_6)[0]);
	assert((*mls_5)[1] == (*mls_6)[1]);
	assert((*mls_5)[2] == (*mls_6)[2]);
	assert((*mls_5)[3] == (*mls_6)[3]);
	assert((*mls_5)[4] == (*mls_6)[4]);
	assert((*mls_5)[5] == (*mls_6)[5]);
	assert((*mls_5)[6] == (*mls_6)[6]);
	assert((*mls_5)[7] == (*mls_6)[7]);
	assert((*mls_5)[8] == (*mls_6)[8]);
	assert((*mls_5)[9] == (*mls_6)[9]);
	mls_5->~List_Sequence();
	mls_6->~List_Sequence();
}



void Test_Basic_Operations_LS() {

    List_Sequence<int>* mls = new Mutable_List_Sequence<int>(10, 10);
    
    mls->Set(1, 0);
	mls->Set(2, 1);
	mls->Set(3, 2);
	mls->Set(4, 3);
	mls->Set(5, 4);
	mls->Set(6, 5);
	mls->Set(7, 6);
	mls->Set(8, 7);
	mls->Set(9, 8);
    


    assert((*mls)[0] == mls->Get(0) && mls->Get(0) == 1);
	assert((*mls)[1] == mls->Get(1) && mls->Get(1) == 2);
	assert((*mls)[2] == mls->Get(2) && mls->Get(2) == 3);
	assert((*mls)[3] == mls->Get(3) && mls->Get(3) == 4);
	assert((*mls)[4] == mls->Get(4) && mls->Get(4) == 5);
	assert((*mls)[5] == mls->Get(5) && mls->Get(5) == 6);
	assert((*mls)[6] == mls->Get(6) && mls->Get(6) == 7);
	assert((*mls)[7] == mls->Get(7) && mls->Get(7) == 8);
	assert((*mls)[8] == mls->Get(8) && mls->Get(8) == 9);
	assert((*mls)[9] == mls->Get(9) && mls->Get(9) == 10);


    mls->Pop_back();
	mls->Pop_back();
	mls->Pop_front();
	mls->Pop_front();
	mls->Pop_back();

	assert((*mls)[0] == mls->Get(0) && mls->Get(0) == mls->Get_first());
	assert((*mls)[4] == mls->Get(4) && mls->Get(4) == mls->Get_last());


	mls->Prepend(-2);
	mls->Prepend(-1);
	mls->Append(-8);
	mls->Append(-9);
	mls->Append(-10);

	assert((*mls)[0] == mls->Get(0) && mls->Get(0) == -1);
	assert((*mls)[1] == mls->Get(1) && mls->Get(1) == -2);
	assert((*mls)[7] == mls->Get(7) && mls->Get(7) == -8);
	assert((*mls)[8] == mls->Get(8) && mls->Get(8) == -9);
	assert((*mls)[9] == mls->Get(9) && mls->Get(9) == -10);

	mls->clear();


    List_Sequence<int>* imls = new Immutable_List_Sequence<int>(10, 10);
    
    
    assert((*imls)[0] == imls->Get(0) && imls->Get(0) == 10);
	assert((*imls)[1] == imls->Get(1) && imls->Get(1) == 10);
	assert((*imls)[2] == imls->Get(2) && imls->Get(2) == 10);
	assert((*imls)[3] == imls->Get(3) && imls->Get(3) == 10);
	assert((*imls)[4] == imls->Get(4) && imls->Get(4) == 10);
	assert((*imls)[5] == imls->Get(5) && imls->Get(5) == 10);
	assert((*imls)[6] == imls->Get(6) && imls->Get(6) == 10);
	assert((*imls)[7] == imls->Get(7) && imls->Get(7) == 10);
	assert((*imls)[8] == imls->Get(8) && imls->Get(8) == 10);
	assert((*imls)[9] == imls->Get(9) && imls->Get(9) == 10);

    
    imls->Pop_back();
	imls->Pop_back();
	imls->Pop_front();
	imls->Pop_front();
	imls->Pop_back();
	assert((*imls)[0] == imls->Get(0) && imls->Get(0) == imls->Get_first());
	assert((*imls)[4] == imls->Get(imls->Get_length() - 1) && imls->Get(imls->Get_length() - 1) == imls->Get_last());



	imls->Prepend(-2);
	imls->Prepend(-1);
	imls->Append(-8);
	imls->Append(-9);
	imls->Append(-10);
	
	imls->clear();

}



void Test_Methods_LS() {
    Mutable_List_Sequence<int>* mls_1 = new Mutable_List_Sequence<int>(5, 100);

	Mutable_List_Sequence<int>* mls_2 = new Mutable_List_Sequence<int>(5, 200);

	mls_1->Concat(*mls_2);
	assert(mls_1->Get_length() == 10);

	for (int i = 0; i < 5; ++i) {
		assert(mls_1->Get(i) == 100);
		assert(mls_1->Get(i + 5) == 200);
	}

	assert(mls_2->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(mls_2->Get(i) == 200);
	}

	Immutable_List_Sequence<int>* imls_1 = new Immutable_List_Sequence<int>(5, 100);
	Immutable_List_Sequence<int>* imls_2 = new Immutable_List_Sequence<int>(5, 200);

	imls_1->Concat(*imls_2);
	assert(imls_1->Get_length() == 10);

	for (int i = 0; i < 5; ++i) {
		assert(imls_1->Get(i) == 100);
	}

	assert(imls_2->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(imls_2->Get(i) == 200);
	}


	mls_1->Resize(4);
	assert(mls_1->Get_length() == 4);
	for (int i = 0; i < 4; ++i) {
		assert(mls_1->Get(i) == 100);
	}

	mls_2->Resize(10);
	assert(mls_2->Get_length() == 10);

	for (int i = 0; i < 5; ++i) {
		assert(mls_2->Get(i) == 200);
	}

	assert(imls_2->count(200) == 5);
}


void Test_List_Sequence() {
    Test_Constructors_and_Destructors_LS();
    Test_Basic_Operations_LS();
    Test_Methods_LS();
    std::cout << "All List-Sequence tests passed!\n";
} 
