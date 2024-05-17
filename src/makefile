# compiler definition
CXX = g++

# compilation options
CXXFLAGS = -g -std=c++17

# name of object file (.o)
TARGET = lab_2

# cpp files for compiling
SRC = tests_dynamic.cpp \
	tests_linked_list.cpp \
	tests_list_seq.cpp \
	tests_arr_seq.cpp \
	User.cpp \
	main.cpp 

# creating obj from cpp
OBJ = $(SRC:.cpp=.o)


all: $(TARGET)

# linking obj to cpp
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# cleaning
clean:
	rm -f $(OBJ) $(TARGET)


.PHONY: all clean
