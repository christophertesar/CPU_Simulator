#include "exception.h"

exception::exception(){

}

exception::~exception(){

}

exception::exception(const exception &i){

}

void exception::invalid_program(){
	std::cout << "Invalid Program." << std::endl;
}

void exception::invalid_user_in(){
	std::cout << "Invalid input." << std::endl;
}

