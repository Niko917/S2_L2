#include "tests_dynamic.hpp"

// ----------------------------------------------------
// DYNAMIC_ARRAY TESTS


void Test_Constructors_and_Destructors_DA() {

    Dynamic_Array<int> default_array;
    assert(default_array.Get_size() == 0);

    Dynamic_Array<int> sized_array(5);
    assert(sized_array.Get_size() == 5);

    Dynamic_Array<int> copied_array(sized_array);
    assert(copied_array.Get_size() == sized_array.Get_size());

    int items[] = {1, 2, 3, 4, 5};
    Dynamic_Array<int> array_from_items(items, 5);
    for (int i = 0; i < 5; ++i) {
        assert(array_from_items.Get(i) == items[i]);
    }

}



void Test_Basic_Operations_DA() {

    Dynamic_Array<int> array(3);

    Dynamic_Array<double>* da = new Dynamic_Array<double>();
    assert(da->empty());


    
    da->Append(100);
	da->Append(1000);
	da->Prepend(10);
	da->Prepend(1);
	da->Append(10000);
	assert(da->Get_size() == 5);
	assert(da->Get(0) == 1);
	assert(da->Get(1) == 10);
	assert(da->Get(2) == 100);
	assert(da->Get(3) == 1000);
	assert(da->Get(4) == 10000);



    assert(da->Get_first() == 1);
	assert(da->Get_last() == 10000);
	da->Pop_back();
	assert(da->Get_size() == 3);
	assert(da->Get_first() == 10);
	assert(da->Get_last() == 1000);
	double f = 1;
	da->Set(f, 0);
	f = 2;
	da->Set(f, 1);
	f = 3;
	da->Set(f, 2);
	assert((*da)[0] == 1);
	assert((*da)[1] == 2);
	assert((*da)[2] == 3);


    int items[] = {1, 2, 3, 4, 5};
    Dynamic_Array<int> array_from_items(items, 5);

    array_from_items.Insert_At(7, 2);
    assert(array_from_items.Get(2) == 7);
}



void Test_Methods_DA() {
	Dynamic_Array<float>* da_1 = new Dynamic_Array<float>(10, 15);
	Dynamic_Array<int>* da_2 = new Dynamic_Array<int>(50, 0);
	
    da_1->Resize(5);
	assert(da_1->Get_size() == 5);


}


void Test_Dynamic_Array() {
    Test_Constructors_and_Destructors_DA();
    Test_Basic_Operations_DA();
    Test_Methods_DA();
    std::cout << " All Dynamic_Array tests passed\n";
}


