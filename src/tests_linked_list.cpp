#include "tests_linked_list.hpp"


// -------------------------------------------------------
// Doubly-Circular-Linked-list TESTS


void Test_Constructors_and_Destructors_LL() {
    
    Doubly_Circular_Linked_list<int>* ll_1 = new Doubly_Circular_Linked_list<int>();

	Doubly_Circular_Linked_list<double>* ll_2 = new Doubly_Circular_Linked_list<double>();
    
	Doubly_Circular_Linked_list<char>* ll_3 = new Doubly_Circular_Linked_list<char>();

	Doubly_Circular_Linked_list<int*>* ll_4 = new Doubly_Circular_Linked_list<int*>();
	
    Doubly_Circular_Linked_list<double**>* ll_5 = new Doubly_Circular_Linked_list<double**>();

    assert(ll_1->empty());	
	assert(ll_2->empty());
	assert(ll_3->empty());
	assert(ll_4->empty());
	assert(ll_5->empty());


	ll_1->~Doubly_Circular_Linked_list();
	ll_2->~Doubly_Circular_Linked_list();
	ll_3->~Doubly_Circular_Linked_list();
	ll_4->~Doubly_Circular_Linked_list();
	ll_5->~Doubly_Circular_Linked_list();

    Doubly_Circular_Linked_list<int>* ll_6 = new Doubly_Circular_Linked_list<int>(10, 10);
	Doubly_Circular_Linked_list<int>* ll_7 = new Doubly_Circular_Linked_list<int>(10, 15);
	Doubly_Circular_Linked_list<int>* ll_8 = new Doubly_Circular_Linked_list<int>(*ll_6);

	assert(ll_6->Get_length() == 10);
	assert(ll_7->Get_length() == 10);
	assert(ll_8->Get_length() == 10);


    assert((*ll_6)[0] == (*ll_8)[0]);
	assert((*ll_6)[1] == (*ll_8)[1]);
	assert((*ll_6)[2] == (*ll_8)[2]);
	assert((*ll_6)[3] == (*ll_8)[3]);
	assert((*ll_6)[4] == (*ll_8)[4]);
	assert((*ll_6)[5] == (*ll_8)[5]);
	assert((*ll_6)[6] == (*ll_8)[6]);
	assert((*ll_6)[7] == (*ll_8)[7]);
	assert((*ll_6)[8] == (*ll_8)[8]);
	assert((*ll_6)[9] == (*ll_8)[9]);

    
    ll_6->~Doubly_Circular_Linked_list();
	ll_7->~Doubly_Circular_Linked_list();
	ll_8->~Doubly_Circular_Linked_list();

}



void Test_Basic_Operations_LL() {

    Doubly_Circular_Linked_list<double>* ll = new Doubly_Circular_Linked_list<double>();
	assert(ll->empty());

    double tmp_1 = 100;
    double tmp_2 = 1000;
    double tmp_3 = 10;
    double tmp_4 = 1;
    double tmp_5 = 10000;

    ll->Append(100);
	ll->Append(1000);
	ll->Prepend(10);
	ll->Prepend(1);
	ll->Append(10000);
	assert(ll->Get_length() == 5);
	assert(ll->Get(0) == 1);
	assert(ll->Get(1) == 10);
	assert(ll->Get(2) == 100);
	assert(ll->Get(3) == 1000);
	assert(ll->Get(4) == 10000);


    assert(ll->Get_first() == 1);
	assert(ll->Get_last() == 10000);
	ll->Pop_front();

	ll->Pop_back();
	assert(ll->Get_length() == 3);

	assert(ll->Get_first() == 100);

	assert(ll->Get_last() == 10000);

    
    ll->Set(1, 0.0);
    ll->Set(2, 1.0);
    ll->Set(3, 2.0);

	//assert((*ll)[0] == 0.0);
	//assert((*ll)[1] == 1.0);
	//assert((*ll)[2] == 2.0);
}


void Test_Methods_LL() {
    Doubly_Circular_Linked_list<float>* ll_1 = new Doubly_Circular_Linked_list<float>(10, 15);
	Doubly_Circular_Linked_list<int>* ll_2 = new Doubly_Circular_Linked_list<int>(50, 0);

	ll_1->Resize(5);
	ll_2->Resize(10);
	assert(ll_1->Get_length() == 5);
	assert(ll_2->Get_length() == 10);
	ll_1->Resize(10);
	assert(ll_1->Get_length() == 10);
}


void Test_Linked_list() {
    Test_Constructors_and_Destructors_LL();
    Test_Basic_Operations_LL();
    Test_Methods_LL();
    std::cout << "All Doubly-circular linked list tests passed!\n";


}


