#pragma once

#include <algorithm>
#include <exception>
#include <string>
#include <stdexcept>


enum class ERRORS{
    Index_Out_of_range,
    Memory_allocation_error,
    Sequence_is_empty,
    Invalid_sequence_type,
    Null_pointer_error
};


struct SEQUENCE_EXCEPTION : public std::exception {
    ERRORS error;
    const char* what() const throw() {
        switch (error) {
            case ERRORS::Index_Out_of_range:
                return "Index is out of range!";

            case ERRORS::Null_pointer_error:
                return "nullptr error!";

            case ERRORS::Sequence_is_empty:
                return "this Sequence is empty!";

            case ERRORS::Invalid_sequence_type:
                return "Invalid sequence type!";

            case ERRORS::Memory_allocation_error:
                return "Memory_allocation_error!";

            default:
                return "Unknown error";
        }
    }
};


