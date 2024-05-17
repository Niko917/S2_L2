

#include "Sequence.h"
#include "Immutable_List.h"
#include "Immutable_Array.h"
#include "exceptions.h"
#include "mutable_list.h"
#include "mutable_array.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>

// -----------------------------------------------------------------------------------------------------------------


template <typename T>
struct Element {
	std::string name;
	std::string Sequence_type;

	Sequence<T>* seq;

	Element(std::string name, std::string Sequence_type, Sequence<T>* seq) : name(name), Sequence_type(Sequence_type), seq(seq) {}
};

template <typename T>
using Variable = Element<T>;

template <typename T>
std::unique_ptr<Variable<T>> Mut_El(std::string name, std::string Sequence_type, Sequence<T>* seq) {
	return Variable<T>(name, Sequence_type, seq);
}

template <typename T>
std::vector<Variable<T>> vars;

// -----------------------------------------------------------------------------------------------------------------


void menu();
void run();
int Create_sequence();
int Remove_sequence();
int check_flag();
int Print_sequence();
int Get();
int Set();
int Push();
int pop();
int Get_size();
int is_empty();
int Get_subseq();
int Concatenation();
int find();
int count();

// -----------------------------------------------------------------------------------------------------------------
// 

void menu() {
	std::cout << "MENU\n";
	std::cout << "Available Commands:\n";
	std::cout << "0. exit \n";									
	std::cout << "1. Menu\n";									
	std::cout << "2. Create sequence\n";						
	std::cout << "3. Remove sequence\n";						
	std::cout << "4. check flag\n";							
	std::cout << "5. Print sequence\n";							
	std::cout << "6. Get\n";									
	std::cout << "7. Set\n";									
	std::cout << "8. Push\n";									
	std::cout << "9. Pop\n";									
	std::cout << "10. Get size\n";								
	std::cout << "11. is empty\n";								
	std::cout << "12. get subsequence\n";						
	std::cout << "13. concatenation\n";							
	std::cout << "14. find\n";									
	std::cout << "15. count\n";

	std::cout << "Warning" << ": the program will finish after 10 unsuccessful inputs\n";
}


void run() {
	menu();
	int bad_count = 10;
	int flag = 1;
	std::string command;

	while (bad_count) {
		flag = 1;
		std::cout << ">>> ";
		std::cin >> command;
		if (command == "0") {
			std::cout << "Are you sure? (y / n)\n";
			std::cout << ">>> ";
			std::cin >> command;
			if (command == "yes" || command == "y" || command == "YES") {
				exit(0);
			}
		}
		else if (command == "1") { // menu
			menu();
			bad_count = 10;
		}
		else if (command == "2") { // create
			flag = Create_sequence();
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			else {
				std::cout << ">>> ";
				std::cin >> command;
			}
			menu();
			bad_count = 10;
		}
		else if (command == "3") { // remove
			flag = Remove_sequence();
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			std::cout << ">>> ";
			std::cin >> command;
			menu();
			bad_count = 10;
		}
		else if (command == "4") { 
			check_flag();
			std::cout << ">>> ";
			std::cin >> command;
			menu();
		}
		else if (command == "5") { // print sequence
			flag = Print_sequence();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "6") { // get
			flag = Get();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "7") { // set
			flag = Set();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "8") { // push
			flag = Push();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "9") { // pop
			flag = pop();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "10") { // get size
			flag = Get_size();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "11") { // is empty
			flag = is_empty();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "12") { // get subseq
			flag = Get_subseq();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "13") { // concat
			flag = Concatenation();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "14") { // find
			flag = find();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else if (command == "15") { // count
			flag = count();
			std::cout << ">>> ";
			std::cin >> command;
			if (flag) {
				std::cout << "The operation aborted\n";
			}
			menu();
			bad_count = 10;
		}
		else {
			std::cout << command << '\n';
			bad_count--;
		}
	}
}

// -----------------------------------------------------------------------------------------------------------------


int findVarByName(std::string name_sequence) {
	for (int i = 0; i < vars<int>.size(); ++i) {
		if (vars<int>[i].name == name_sequence) {
			return i;
		}
	}
	return -1; 
}

// -----------------------------------------------------------------------------------------------------------------

void promptAbort() {
	std::cout << "Enter '" << "abort" << "' to finish the operation \n";
}

// -----------------------------------------------------------------------------------------------------------------
// Functions for creating sequence and elements 

bool isValidSizeSeq(const std::string& s_size) {
	size_t pos;
	try {
		int size = std::stoi(s_size, &pos);

		if (pos != s_size.length()) {
			return false;
		}
		if (size < 0 || size > 1000) {
			return false;
		}
	}
	catch (...) {
		return false;
	}

	return true;
}

bool isValidName(const std::string& nameseq) {
	bool flag = false;
	if (nameseq.size() == 0 || isdigit(nameseq[0])) {
		return false;
	}
	for (int i = 0; i < nameseq.size(); ++i) {
		if (isdigit(nameseq[i])) {
			flag = true;
		}
		else if (!isdigit(nameseq[i]) && flag || !isalpha(nameseq[i]) && !isdigit(nameseq[i])) {
			return false;
		}
	}
	return true;
}

bool isValidInt(std::string s_defaultElement) {
	size_t pos;
	try {
		int defaultElement = std::stoi(s_defaultElement, &pos);

		if (pos != s_defaultElement.length()) {
			return false;
		}
	}
	catch (...) {
		return false;
	}

	return true;
}

bool isValidIndex(const std::string& s_index, size_t size) {
	size_t pos;
	try {
		int index = std::stoi(s_index, &pos);

		if (pos != s_index.length()) {
			return false;
		}
		if (index < 0 || index >=  size) {
			return false;
		}
	}
	catch (...) {
		return false;
	}

	return true;
}

std::string Get_Sequence_type() {
	std::cout << "Sequence\n";
	std::cout << "Linked List Sequence:\n";
	std::cout << "    Mutable List Sequence (mut_ls)\n";
	std::cout << "    Immutable List Sequence (immut_ls)\n";
	std::cout << "\n";
	std::cout << "Dynamic Array Sequence\n";
	std::cout << "    Mutable Array Sequence (mut_arr)\n";
	std::cout << "    Immutable Array Sequence (immut_arr)\n";

	std::cout << "Input the type of sequence (mut_ls / immut_ls / mut_arr / immut_arr)\n";

	std::string Sequence_type;
	int bad_count = 10;

	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> Sequence_type;

		if (Sequence_type == "mut_ls") {
			break;
		}
		else if (Sequence_type == "immut_ls") {
			break;
		}
		else if (Sequence_type == "mut_arr") {
			break;
		}
		else if (Sequence_type == "immut_arr") {
			break;
		}
		else if (Sequence_type == "abort") {
			break;
		}
		else {
			std::cout << "Sequence_type = '" << Sequence_type << "' is not valid type of sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return "ERR-0001-ATTEXP"; // attempts expired
	}
	else if (Sequence_type == "abort") {
		return "ERR-1111-FUNCINTERR"; // function interrupted
	}
	return Sequence_type;
}

int Get_Size_Sequence() {
	std::string s_sizeseq;
	int size_seq = -1;
	int bad_count = 10;

	std::cout << "Input the " << "size" << " of sequence (0 - 1000)\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_sizeseq;
		if (isValidSizeSeq(s_sizeseq)) {
			size_t pos;
			size_seq = std::stoi(s_sizeseq, &pos);
			break;
		}
		else if (s_sizeseq == "abort") {
			break;
		}
		else {
			std::cout << "SizeSeq = '" << s_sizeseq << "' is not a valid size for sequnce\n";
			bad_count--;
		}
	}

	if (s_sizeseq == "abort") {
		return -1111;
	}
	else if (bad_count == 0) {
		return -1;
	}

	return size_seq;
}

int Get_Type_Fill() {
	std::string s_type_fill;
	int type_fill = -1;
	int bad_count = 10;

	std::cout << "Input the " << "type of fill" << " (1 = by default element / 2 = by hand)\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_type_fill;
		if (s_type_fill == "1" || s_type_fill == "2") {
			if (s_type_fill == "1") {
				type_fill = 1;
			}
			else {
				type_fill = 2;
			}
			break;
		}
		else if (s_type_fill == "abort") {
			break;
		}
		else {
			std::cout << "TypeFill = '" << s_type_fill << "' is not type of fill sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return -1;
	}
	else if (s_type_fill == "abort") {
		return -1111;
	}

	return type_fill;
}

std::string Get_Name_Element() {
	promptAbort();

	std::string name_sequence;
	int bad_count = 10;

	std::cout << "Input the " << "name" << " of sequence \n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> name_sequence;
		
		if (name_sequence == "abort") {
			break;
		}
		else if (isValidName(name_sequence)) {
			if (findVarByName(name_sequence) == -1) {
				break;
			}
			else {
				std::cout << "NameSeq = '" << name_sequence << "' is already taken\n";
				bad_count--;
			}
		}
		else {
			std::cout << "NameSeq = '" << name_sequence << "' is not a valid name of sequence\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return "ERR-0001-ATTEXP"; // attempts expired
	}
	else if (name_sequence == "abort") {
		return "ERR-1111-FUNCINTERR"; // function interrupted
	}

	return name_sequence;
}



int fillSeq(Sequence<int>*& seq, int size, int typefill) {
	Sequence<int>* new_seq = seq->Mutability();

	int bad_count = 10;
	std::string element;
	std::string forERR = "NONE";

	if (typefill == 1) {
		std::cout << "Input the " << "default element" << " for sequence\n";

		while (bad_count) {
			std::cout << ">>> ";
			std::cin >> element;

			if (isValidInt(element)) {
				size_t pos;
				int el;
				for (int i = 0; i < size; ++i) {
					el = std::stoi(element, &pos);
					try {
						new_seq = new_seq->Append(el);
					}
					catch (const SEQUENCE_EXCEPTION& e) {
                        std::cerr << "An error occured: " << e.what() << std::endl;
						break;
					}
				}
				break;
			}
			else if (element == "abort") {
				forERR = "ERR-1111-FUNCINTERR";
			}
			else {
				std::cout << "Element = '" << element << "' is not a valid element for sequence\n";
				bad_count--;
			}
		}
	}
	else {
		int i = 0;
		while (bad_count && i < size) {
			std::cout << "Input the " << "[" << i << "]" << " for sequence\n";
			std::cout << ">>> ";
			std::cin >> element;

			if (isValidInt(element)) {
				size_t pos;
				int el = std::stoi(element, &pos);
				try {
					new_seq = new_seq->Append(el);
				}
				catch (const SEQUENCE_EXCEPTION& e) {
                    std::cerr << "An error occured: " << e.what() << std::endl;
					break;
				}
				i++;
			}
			else if (element == "abort") {
				forERR = "ERR-1111-FUNCINTERR";
			}
			else {
				std::cout << "Element = '" << element << "' is not a valid element for sequence\n";
				bad_count--;
			}
		}
	}

	if (forERR.substr(0, 3) == "ERR") {
		return -1110;
	}
	else if (forERR != "NONE") {
		return -11;
	}

	seq = new_seq;
	return 0;
}

void infoSeq(int index) {
	if (index >= 0 && index < vars<int>.size()) {
		std::cout << std::setw(65) << "Sequence " << index << '\n';

		std::cout << "The name of sequence " << vars<int>[index].name << '\n';
		if ((vars<int>[index].Sequence_type).compare("mut_ls") == 0) {
			std::cout << "The type of sequence: " << "Mutable List Sequence\n";
		}
		else if ((vars<int>[index].Sequence_type).compare("immut_ls") == 0) {
			std::cout << "The type of sequence: " << "Immutable List Sequence\n";
		}
		else if ((vars<int>[index].Sequence_type).compare("mut_arr") == 0) {
			std::cout << "The type of sequence: " << "Mutable Array Sequence\n";
		}
		else if ((vars<int>[index].Sequence_type).compare("immut_arr") == 0) {
			std::cout << "The type of sequence: " << "Immutable Array Sequence\n";
		}

		std::cout << "The size of sequence: " << vars<int>[index].seq->Get_length() << '\n';
	}
	else {
		std::cout << "Index is out of range\n";
	}
}

void createVar(Sequence<int>* seq, std::string Sequence_type, std::string name ) {
	Variable<int>* new_var = new Variable<int>(name, Sequence_type, seq);
	vars<int>.push_back(*new_var);
}

int Create_sequence() {
	std::string name_element = Get_Name_Element();
	if (name_element.substr(0, 3) == "ERR") {
		return -1010;
	}

	std::string Sequence_type = Get_Sequence_type();
	if (Sequence_type.substr(0, 3) == "ERR") {
		return -1010;
	}

	int size_sequence = Get_Size_Sequence();
	if (size_sequence < 0) {
		return -1010;
	}

	int type_fill = Get_Type_Fill();
	if (type_fill < 0 || type_fill > 2) {
		return -1010;
	}


	Sequence<int>* seq;
	int flag = 0;

	if (Sequence_type.compare("immut_ls") == 0) {
		seq = new Immutable_List_Sequence<int>();
	}
	else if (Sequence_type.compare("immut_arr") == 0) {
		seq = new Immutable_Array_Sequence<int>();
	}
	else if (Sequence_type.compare("mut_ls") == 0) {
		seq = new Mutable_List_Sequence<int>();
	}
	else if (Sequence_type.compare("mut_arr") == 0) {
		seq = new Mutable_Array_Sequence<int>();
	}

	flag = fillSeq(seq, size_sequence, type_fill);
	
	if (flag == 0) {
		createVar(seq, Sequence_type, name_element);
		infoSeq(vars<int>.size() - 1);
		return 0;
	}
	else {
		return -1110;
	}
				
}

// -----------------------------------------------------------------------------------------------------------------


int select() {
	promptAbort();
	check_flag();

	std::string name_sequence;
	int bad_count = 10;

	std::cout << "Input the " << "name" << " of sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> name_sequence;
		int index = findVarByName(name_sequence);
		if (index != -1) {
			return index;
		}
		if (name_sequence == "abort") {
			return -1011;
		}
		else {
			std::cout << "Name seq = '" << name_sequence << "' is not found\n";
			bad_count--;
		}
	}

	return -1011;
}

// -----------------------------------------------------------------------------------------------------------------


int Remove_sequence() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -1110;
	}

	int index = select();

	if (index < 0) {
		return -1110;
	}

	vars<int>.erase(vars<int>.begin() + index);
	return 0;
}

// -----------------------------------------------------------------------------------------------------------------
// Functions for output

int check_flag() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return 1;
	}

	for (int i = 0; i < vars<int>.size(); ++i) {
		infoSeq(i);
	}

	return 0;
}

int Print_sequence() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -11;
	}

	int index = select();

	if (index < 0) {
		return -11;
	}
	
	std::cout << "Sequence :\n";
	for (int i = 0; i < vars<int>[index].seq->Get_length(); ++i) {
		std::cout << vars<int>[index].seq->Get(i) << " ";
	}
	std::cout << "\n";
		
	return 0;
}

// -----------------------------------------------------------------------------------------------------------------



int Get() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1000;
	}

	std::string s_indexseq;
	int indexseq = -1;
	int bad_count = 10;
		
	std::cout << "Input the " << "index" << " of sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_indexseq;
		if (isValidIndex(s_indexseq, vars<int>[index].seq->Get_length())) {
			size_t pos;
			indexseq = std::stoi(s_indexseq, &pos);
			std::cout << vars<int>[index].name << "[" << indexseq << "]" << " = " << vars<int>[index].seq->Get(indexseq) << "\n";
			break;
		}
		else if (s_indexseq == "abort") {
			break;
		}
		else {
			std::cout << "Index = '" << indexseq << "' is not a valid index for sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return -1011;
	}
	else if (s_indexseq == "abort") {
		return -1;
	}
	return indexseq;
}

int Set() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1111;
	}
	
	std::string s_indexseq;
	size_t indexseq = -1;
	std::string s_value;
	int value;
	int bad_count = 10;
	bool isnew = false;

	std::cout << "Input the " << "index" << " of sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_indexseq;
		if (isValidIndex(s_indexseq, vars<int>[index].seq->Get_length())) {
			size_t pos;
			indexseq = std::stoi(s_indexseq, &pos);
			break;
		}
		else if (s_indexseq == "abort") {
			break;
		}
		else {
			std::cout << "Index = '" << s_indexseq << "' is not valid index for sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return -1011;
	}
	else if (s_indexseq == "abort") {
		return -1;
	}

	bad_count = 10;

	std::cout << "Input the " << "new value" << " of " << vars<int>[index].name << "[" << indexseq << "]" << "\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_value;
		if (isValidInt(s_value)) {
			size_t pos;
			int value = std::stoi(s_value, &pos);

			if (vars<int>[index].Sequence_type != "immut_arr" && vars<int>[index].Sequence_type != "immut_ls") {
				vars<int>[index].seq = vars<int>[index].seq->Set(value, indexseq);
			}
			else {
				Sequence<int>* seq_copy = vars<int>[index].seq->Mutability();
				for (int i = 0; i < vars<int>[index].seq->Get_length(); ++i) {
					seq_copy = seq_copy->Append(vars<int>[index].seq->Get(i));
				}
				seq_copy = vars<int>[index].seq->Set(value, indexseq);
				
				int j = 1;
				std::string new_name = vars<int>[index].name;
				new_name += '_';
				new_name += std::to_string(j);
				while (isValidName(new_name) == false && j < 10) {
					j++;
					new_name.pop_back();
					new_name += std::to_string(j);
				}
				createVar(seq_copy, vars<int>[index].Sequence_type, new_name);
				isnew = true;
			}
			break;
		}
		else if (s_value == "abort") {
			break;
		}
		else {
			std::cout << "Value = '" << s_value << "' is not valid value\n";
			bad_count--;
		}
	}
	if (s_value == "abort") {
		return -101;
	}
	else if (isnew) {
		std::cout << "When the operation was performed, a new sequence created\n";
		return 0;
	}
	else if (bad_count == 0) {
		return -111;
	}
	
	return 0;
}



int Push() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1111;
	}

	std::string s_typepush;
	std::string s_value;
	int value;
	int bad_count = 10;
	bool isnew = false;

	std::cout << "Input the " << "type of pushing" << " in sequence (1 = Append / 2 = Prepend)\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_typepush;
		if (s_typepush == "1" || s_typepush == "2") {
			break;
		}
		else if (s_typepush == "abort") {
			break;
		}
		else {
			std::cout << "Type pushing = '" << s_typepush << "' is not type of pushing for sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return -1011;
	}
	else if (s_typepush == "abort") {
		return -1;
	}

	bad_count = 10;

	std::cout << "Input the " << "item for Append / Prepend" << "\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_value;
		if (isValidInt(s_value)) {
			size_t pos;
			int value = std::stoi(s_value, &pos);

			if (vars<int>[index].Sequence_type != "immut_arr" && vars<int>[index].Sequence_type != "immut_ls") {
				if (s_typepush == "1") {
					vars<int>[index].seq = vars<int>[index].seq->Append(value);
				}
				else {
					vars<int>[index].seq = vars<int>[index].seq->Prepend(value);
				}
			}
			else {
				Sequence<int>* seq_copy = vars<int>[index].seq->Mutability();
				for (int i = 0; i < vars<int>[index].seq->Get_length(); ++i) {
					seq_copy = seq_copy->Append(vars<int>[index].seq->Get(i));
				}

				if (s_typepush == "1") {
					seq_copy = vars<int>[index].seq->Append(value);
				}
				else {
					seq_copy = vars<int>[index].seq->Prepend(value);
				}

				int j = 1;
				std::string new_name = vars<int>[index].name;
				new_name += '_';
				new_name += std::to_string(j);
				while (isValidName(new_name) == false && j < 10) {
					j++;
					new_name.pop_back();
					new_name += std::to_string(j);
				}
				createVar(seq_copy, vars<int>[index].Sequence_type, new_name);
				isnew = true;
			}
			break;
		}
		else if (s_value == "abort") {
			break;
		}
		else {
			std::cout << "Value = '" << s_value << "' is not a valid value\n";
			bad_count--;
		}
	}
	if (s_value == "abort") {
		return -101;
	}
	else if (isnew) {
		std::cout << "When the operation was perform, a new sequence created\n";
		return 0;
	}
	else if (bad_count == 0) {
		return -111;
	}

	return 0;
}



int pop() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1111;
	}

	std::string s_typepop;
	std::string s_value;
	int value;
	int bad_count = 10;
	bool isnew = false;

	std::cout << "Input the " << "type of pop" << " in sequence (1 = Pop_back / 2 = pop_front)\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_typepop;
		if (s_typepop == "1" || s_typepop == "2") {
			break;
		}
		else if (s_typepop == "abort") {
			break;
		}
		else {
			std::cout << "Type pushing = '" << s_typepop << "' is not type of pop for sequnce\n";
			bad_count--;
		}
	}

	if (bad_count == 0) {
		return -1011;
	}
	else if (s_typepop == "abort") {
		return -1;
	}

	bad_count = 10;

	if (vars<int>[index].Sequence_type != "immut_arr" && vars<int>[index].Sequence_type != "immut_ls") {
		if (s_typepop == "1") {
			vars<int>[index].seq = vars<int>[index].seq->Pop_back();
		}
		else {
			vars<int>[index].seq = vars<int>[index].seq->Pop_front();
		}
	}
	else {
		Sequence<int>* seq_copy = vars<int>[index].seq->Mutability();
		for (int i = 0; i < vars<int>[index].seq->Get_length(); ++i) {
			seq_copy = seq_copy->Append(vars<int>[index].seq->Get(i));
		}

		if (s_typepop == "1") {
			seq_copy = vars<int>[index].seq->Pop_back();
		}
		else {
			seq_copy = vars<int>[index].seq->Pop_front();
		}

		int j = 1;
		std::string new_name = vars<int>[index].name;
		new_name += '_';
		new_name += std::to_string(j);
		while (isValidName(new_name) == false && j < 10) {
			j++;
			new_name.pop_back();
			new_name += std::to_string(j);
		}
		createVar(seq_copy, vars<int>[index].Sequence_type, new_name);
		isnew = true;
	}
	
	if (isnew) {
		std::cout << "When the operation was perform, a new sequence created\n";
		return 0;
	}

	return 0;
}

int Get_size() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();
	if (index < 0) {
		return -101;
	}
	
	std::cout << vars<int>[index].name << ".size = " << vars<int>[index].seq->Get_length() << "\n";
	
	return 0;
}

int is_empty() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();
	if (index < 0) {
		return -101;
	}

	if (index != -1) {
		if (vars<int>[index].seq->empty()) {
			std::cout << vars<int>[index].name << " is empty" << "\n";
		}
		else {
			std::cout << vars<int>[index].name << " is not empty" << "\n";
		}
	}

	return 0;
}

// -----------------------------------------------------------------------------------------------------------------
// 

int Concatenation() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	bool isnew = false;

	int index_1 = select();

	if (index_1 < 0) {
		return -1111;
	}

	std::string wait = "";
	std::cout << ">>> ";
	std::cin >> wait;


	int index_2 = select();

	if (index_2 < 0) {
		return -1111;
	}

	if (vars<int>[index_1].Sequence_type != "immut_arr" && vars<int>[index_1].Sequence_type != "immut_ls") {
		vars<int>[index_1].seq = vars<int>[index_1].seq->Concat(*(vars<int>[index_2].seq));
	}
	else {
		Sequence<int>* seq_copy = vars<int>[index_1].seq->Mutability();
		for (int i = 0; i < vars<int>[index_1].seq->Get_length(); ++i) {
			seq_copy = seq_copy->Append(vars<int>[index_1].seq->Get(i));
		}
		for (int i = 0; i < vars<int>[index_2].seq->Get_length(); ++i) {
			seq_copy = seq_copy->Append(vars<int>[index_2].seq->Get(i));
		}

		int j = 1;
		std::string new_name = vars<int>[index_1].name;
		new_name += '_';
		new_name += std::to_string(j);
		while (isValidName(new_name) == false && j < 10) {
			j++;
			new_name.pop_back();
			new_name += std::to_string(j);
		}
		createVar(seq_copy, vars<int>[index_1].Sequence_type, new_name);
		isnew = true;
	}

	if (isnew) {
		std::cout << "When the operation performed, a new sequence was create\n";
	}

	return 0;
}

int Get_subseq() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1000;
	}

	std::string s_firstindex;
	int firstindex = -1;
	std::string s_secondtindex;
	int secondindex = -1;
	int bad_count = 10;
	bool isnew = false;

	std::cout << "Input the " << "the start index " << "you want to take"  << " in this sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_firstindex;
		if (isValidIndex(s_firstindex, vars<int>[index].seq->Get_length())) {
			size_t pos;
			firstindex = std::stoi(s_firstindex, &pos);
			break;
		}
		else if (s_firstindex == "abort") {
			break;
		}
		else {
			std::cout << "Start index = '" << s_firstindex << "' is not valid\n";
			bad_count--;
		}
	}

	if (s_firstindex == "abort") {
		return -101;
	}
	else if (bad_count == 0) {
		return -1;
	}

	bad_count = 10;

	std::cout << "Input the " << "the finish index " << "you want to take" << " in this sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_secondtindex;
		if (isValidIndex(s_secondtindex, vars<int>[index].seq->Get_length())) {
			size_t pos;
			secondindex  = std::stoi(s_secondtindex, &pos);
			break;
		}
		else if (s_secondtindex == "abort") {
			break;
		}
		else {
			std::cout << "Finish index = '" << s_secondtindex << "' is not valid index\n";
			bad_count--;
		}
	}

	if (s_secondtindex == "abort") {
		return -101;
	}
	else if (bad_count == 0) {
		return -1;
	}

	int j = 1;
	std::string new_name = "sub_";
	new_name += vars<int>[index].name;

	try {
		Sequence<int>* res_seq = vars<int>[index].seq->Mutability();
		for (int i = firstindex; i <= secondindex; ++i) {
			res_seq = res_seq->Append(vars<int>[index].seq->Get(i));
		}
		createVar(res_seq, vars<int>[index].Sequence_type, new_name);
		isnew = true;
	}
	catch (const SEQUENCE_EXCEPTION& e) {
        std::cerr << "An error occured: " << e.what() << std::endl;
		return -1111;
	}
	

	if (isnew) {
		std::cout << "When the operation was perform, a new sequence was create\n";
	}
	return 0;
}

int find() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1000;
	}

	std::string s_value;
	int value = -1;
	int bad_count = 10;

	std::cout << "Input the " << "the value you want to find" << " in sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_value;
		if (isValidInt(s_value)) {
			size_t pos;
			int value = std::stoi(s_value, &pos);
			std::cout << vars<int>[index].name << ".find(" << value << ") = ";
			std::cout << vars<int>[index].seq->find(value) << "\n";
			break;
		}
		else if (s_value == "abort") {
			break;
		}
		else {
			std::cout << "Value = '" << s_value << "' is not valid value\n";
			bad_count--;
		}
	}

	if (s_value == "abort") {
		return -101;
	}
	else if (bad_count == 0) {
		return -111;
	}

	return 0;
}

int count() {
	if (vars<int>.size() == 0) {
		std::cout << "There are no sequences\n";
		return -10;
	}

	int index = select();

	if (index < 0) {
		return -1000;
	}

	std::string s_value;
	int value = -1;
	int bad_count = 10;

	std::cout << "Input the " << "the value you want to count" << " in sequence\n";
	while (bad_count) {
		std::cout << ">>> ";
		std::cin >> s_value;
		if (isValidInt(s_value)) {
			size_t pos;
			int value = std::stoi(s_value, &pos);
			std::cout << vars<int>[index].name << ".count(" << value << ") = ";
			std::cout << vars<int>[index].seq->count(value) << "\n";
			break;
		}
		else if (s_value == "abort") {
			break;
		}
		else {
			std::cout << "Value = '" << s_value << "' is not valid value\n";
			bad_count--;
		}
	}

	if (s_value == "abort") {
		return -101;
	}
	else if (bad_count == 0) {
		return -111;
	}

	return 0;
}
