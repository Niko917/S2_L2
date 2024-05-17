#include <iostream>
#include "tests_linked_list.hpp"
#include "tests_list_seq.hpp"
#include "tests_dynamic.hpp"
#include "tests_arr_seq.hpp"
#include "UI.hpp"




int main() {

    Test_Dynamic_Array();
    Test_Linked_list();

    Test_Array_Sequence();
    Test_List_Sequence();

    run();
    return 0;
}
