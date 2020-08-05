#include "instruction.h"

instruction::instruction(){
	//std::cout << "instruction constructor called" << std::endl;
}

instruction::~instruction(){
	//std::cout << "insturction destructor called" << std::endl;
}

void instruction::set_opcode(std::string s){
	opcode = s;
}

void instruction::set_src1(std::string s){
	src1 = s;
}

void instruction::set_src2(std::string s){
	src2 = s;
}

void instruction::set_dest(std::string s){
	dest = s;
}

void instruction::set_immediate(std::string s){
	immediate = s;
}

void instruction::set_address(std::string s){
	address = s;
}

std::string instruction::get_opcode(){
	return opcode;
}

std::string instruction::get_src1(){
	return src1;
}
std::string instruction::get_src2(){
	return src2;
}
std::string instruction::get_dest(){
	return dest;
}
std::string instruction::get_immediate(){
	return immediate;
}
std::string instruction::get_address(){
	return address;
}
	
