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
    
    

    for (int i = 0; i < 9; ++i) {
        int value = i;    
        int index = i + 1;  
        mls->Set(value, index);
    }


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

    int pr_1 = -2;
    int pr_2 = -1;
    int ap_1 = -8;
    int ap_2 = -9;
    int ap_3 = -10;

	mls->Prepend(pr_1);
	mls->Prepend(pr_2);
	mls->Append(ap_1);
	mls->Append(ap_2);
	mls->Append(ap_3);
	assert((*mls)[0] == mls->Get(0) && mls->Get(0) == -1);
	assert((*mls)[1] == mls->Get(1) && mls->Get(1) == -2);
	assert((*mls)[7] == mls->Get(7) && mls->Get(7) == -8);
	assert((*mls)[8] == mls->Get(8) && mls->Get(8) == -9);
	assert((*mls)[9] == mls->Get(9) && mls->Get(9) == -10);

	mls->clear();


    List_Sequence<int>* imls = new Immutable_List_Sequence<int>(10, 10);
    

    for (int i = 0; i < 8; ++i) {
        int value = i;
        int ind = i + 1;
        imls->Set(value, ind);
    }

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



	imls->Prepend(pr_1);
	imls->Prepend(pr_2);
	imls->Append(ap_1);
	imls->Append(ap_2);
	imls->Append(ap_3);
	assert((*imls)[0] == imls->Get(0) && imls->Get(0) == 10);
	assert((*imls)[1] == imls->Get(1) && imls->Get(1) == 10);
	assert((*imls)[7] == imls->Get(7) && imls->Get(7) == 10);
	assert((*imls)[8] == imls->Get(8) && imls->Get(8) == 10);
	assert((*imls)[9] == imls->Get(9) && imls->Get(9) == 10);

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
	assert(imls_1->Get_length() == 5);

	for (int i = 0; i < 5; ++i) {
		assert(imls_1->Get(i) == 100);
	}
	assert(imls_2->Get_length() == 5);

	for (int i = 0; i < 5; ++i) {
		assert(imls_2->Get(i) == 200);
	}

	imls_1->map([](const auto& item) -> auto { return item * 2; });
	assert(imls_1->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(imls_1->Get(i) == 100);
	}

	mls_2->map([](const auto& item) -> auto { return item * 2; });
	assert(mls_2->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(mls_2->Get(i) == 400);
	}

	mls_1->Resize(5);
	assert(mls_1->Get_length() == 5);
	for (int i = 0; i < 5; ++i) {
		assert(mls_1->Get(i) == 100);
	}

	mls_2->Resize(10);
	assert(mls_2->Get_length() == 10);

	for (int i = 0; i < 5; ++i) {
		assert(mls_2->Get(i) == 400);
		assert(mls_2->Get(i + 5) == 15);
	}

	assert(mls_2->find(15) == 5);
	assert(imls_2->count(200) == 5);
}


void Test_List_Sequence() {
    Test_Constructors_and_Destructors_LS();
    Test_Basic_Operations_LS();
    Test_Methods_LS();
} 
