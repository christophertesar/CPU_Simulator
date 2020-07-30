#include "memory.h"

memory::memory(){
	pc = 0;
	instruction.reserve(20);
}

memory::memory(std::string filename){
	pc = 0;
	memory::read_instructions(filename);
	std::cout << "memory overloaded constructor called" << std::endl;
}

memory::~memory(){
	std::cout << "memory destructor called" << std::endl;
}

memory::memory(const memory &a){

}

void memory::read_instructions(std::string filename){

	std::ifstream file;
	file.open(filename,std::ifstream::in);
	std::string inst;
	
	std::string temp;
	std::string line;
	
	if(!file.is_open()){
		std::cout << "Cannot open file." << std::endl;
		return;
	}

	while(std::getline(file,line,',')){ //Reads entire file
		std::stringstream ss(line);
		std::getline(ss, inst, ',');

		instruction.push_back(std::stoul(inst)); //storing variables
	}
	file.close(); //finished
	
	for(unsigned int c:instruction)
		std::cout << c << std::endl;
}

void memory::instruction_decode(unsigned int inst){
	//instruction = new instruction;
	//std::cout << inst << std::endl;
	if((inst & 0xC0000000) == 0xC0000000){ //110000000... bitmask
		std::cout << "P" << std::endl;
	}
	else if((inst & 0x80000000) == 0x80000000){
		std::cout << "J" << std::endl;
	}
	else if((inst & 0x40000000) == 0x40000000){
		std::cout << "I" << std::endl;
	}
	else if((inst & 0xC0000000) == 0x00000000){
		std::cout << "R" << std::endl;
	}
	else
		std::cout << "Other" << std::endl;
}

unsigned int memory::get_instruction(int location){
	inst_ptr = instruction.begin() + location;
	return *inst_ptr;
	
}

void memory::disp_instructions(){
	for(unsigned int c:instruction)
		std::cout << c << std::endl;
}













