#include "memory.h"

memory::memory(){
	pc = 0;
	instruct.reserve(20);
	//memory::read_instructions("inst_mem.csv");
}

memory::memory(std::string filename){
	pc = 0;
	//memory::read_instructions(filename);
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

		instruct.push_back(std::stoul(inst)); //storing variables
	}
	file.close(); //finished
	
	for(unsigned int c:instruct)
		std::cout << c << std::endl;
}

instruction memory::instruction_decode(unsigned int inst){
	
	instruction i;
	
	if((inst & 0xC0000000) == 0xC0000000){ //110000000... bitmask
		std::cout << "P" << std::endl;
	}
	
	else if((inst & 0x80000000) == 0x80000000){ //10
		std::cout << "J" << std::endl;
	}
	
	else if((inst & 0x40000000) == 0x40000000){ //01
		std::cout << "I" << std::endl;
		
		if ((inst & 0x3C000000) == 0x00000000){
			std::cout << "add" << std::endl;
		}
		else if((inst & 0x04000000) == 0x04000000){
			std::cout << "sub" << std::endl;
		}
		else if((inst & 0x08000000) == 0x08000000){
			std::cout << "mult" << std::endl;
		}
		else if((inst & 0x0C000000) == 0x0C000000){
			std::cout << "divide" << std::endl;
		}
		else if((inst & 0x10000000) == 0x10000000){
			std::cout << "modulo" << std::endl;
		}
		else if((inst & 0x14000000) == 0x14000000){
			std::cout << "beq" << std::endl;
		}
		else if((inst & 0x18000000) == 0x18000000){
			std::cout << "bne" << std::endl;
		}
		else if((inst & 0x1C000000) == 0x1C000000){
			std::cout << "mov" << std::endl;
		}
		else if((inst & 0x20000000) == 0x20000000){
			std::cout << "mov print" << std::endl;
		}
		else
			std::cout << "fail" << std::endl;
	}
	//else if((inst & 0xC0000000) == 0xC0000000){ //00
		
	//}
	else
		std::cout << "R" << std::endl;
	
	return i;
}

unsigned int memory::get_instruction(int location){
	inst_ptr = instruct.begin() + location;
	return *inst_ptr;
	
}

void memory::disp_instructions(){
	for(unsigned int c:instruct)
		std::cout << c << std::endl;
}













