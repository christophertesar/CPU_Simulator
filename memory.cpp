#include "memory.h"

memory::memory(){

	instruct.reserve(20);
}

memory::memory(std::string filename){
	pc = 0;
	//memory::read_instructions(filename);
	std::cout << "memory overloaded constructor called" << std::endl;
}

memory::~memory(){

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
	
	//for(unsigned int c:instruct)
	//	std::cout << c << std::endl;
}

instruction memory::instruction_decode(unsigned int inst){
	
	instruction i;
	//---------------------------------------------------------------
	if((inst & 0xC0000000) == 0xC0000000){ //110000000... bitmask
		//std::cout << "P" << std::endl;
		i.set_type("P");
		
		if ((inst & 0x3C000000) == 0x00000000){
			//std::cout << "add" << std::endl;
			i.set_opcode("add");
		}
		else if((inst & 0x3C000000) == 0x04000000){
			//std::cout << "sub" << std::endl;
			i.set_opcode("sub");
		}
		else if((inst & 0x3C000000) == 0x08000000){
			//std::cout << "mult" << std::endl;
			i.set_opcode("mult");
		}
		else if((inst & 0x3C000000) == 0x0C000000){
			//std::cout << "div" << std::endl;
			i.set_opcode("div");
		}
		else if((inst & 0x3C000000) == 0x10000000){
			//std::cout << "mod" << std::endl;
			i.set_opcode("mod");
		}
		else if((inst & 0x3C000000) == 0x14000000){
			//std::cout << "beq" << std::endl;
			i.set_opcode("beq");
		}
		else if((inst & 0x3C000000) == 0x18000000){
			//std::cout << "bne" << std::endl;
			i.set_opcode("bne");
		}
		else if((inst & 0x3C000000) == 0x1C000000){
			//std::cout << "mov" << std::endl;
			i.set_opcode("mov");
		}
		else if((inst & 0x3C000000) == 0x20000000){
			//std::cout << "mov print" << std::endl;
			i.set_opcode("mov print");
		}
		else
			std::cout << "Error at instruction decode P" << std::endl;
		
		unsigned int dest = find_dest1(inst);
		set_destination(dest,i);
		i.set_src1("-1");
		i.set_src2("-1");
		
			
	}
	//---------------------------------------------------------------
	else if((inst & 0xC0000000) == 0x80000000){ //10
		//std::cout << "J" << std::endl;
		i.set_type("J");
		
		unsigned int address = find_address(inst);
		set_address(address,i);
		i.set_src1("-1");
		i.set_src2("-1");
		i.set_opcode("-1");
		i.set_dest("-1");
	}
	//---------------------------------------------------------------
	else if((inst & 0x40000000) == 0x40000000){ //01
		//std::cout << "I" << std::endl;
		i.set_type("I");
		
		if ((inst & 0x3C000000) == 0x00000000){
			//std::cout << "add" << std::endl;
			i.set_opcode("add");
		}
		else if((inst & 0x3C000000) == 0x0C000000){
			//std::cout << "div" << std::endl;
			i.set_opcode("div");
		}
		else if((inst & 0x3C000000) == 0x04000000){
			//std::cout << "sub" << std::endl;
			i.set_opcode("sub");
		}
		else if((inst & 0x3C000000) == 0x18000000){
			//std::cout << "bne" << std::endl;
			i.set_opcode("bne");
		}
		else if((inst & 0x3C000000) == 0x08000000){
			//std::cout << "mult" << std::endl;
			i.set_opcode("mult");
		}
		else if((inst & 0x3C000000) == 0x10000000){
			//std::cout << "mod" << std::endl;
			i.set_opcode("mod");
		}
		else if((inst & 0x3C000000) == 0x14000000){
			//std::cout << "beq" << std::endl;
			i.set_opcode("beq");
		}
		else if((inst & 0x3C000000) == 0x1C000000){
			//std::cout << "mov" << std::endl;
			i.set_opcode("mov");
		}
		else if((inst & 0x3C000000) == 0x20000000){
			//std::cout << "mov print" << std::endl;
			i.set_opcode("mov print");
		}
		else
			std::cout << "Error at instruction decode I" << std::endl;
		
		unsigned int dest = find_dest1(inst);
		unsigned int src1 = find_dest2(inst);
		unsigned int imm = find_immediate(inst);
		set_dest(dest,src1,i);
		set_immediate(imm,i);
		i.set_src2("-1");
		
	}

	else{
		//std::cout << "R" << std::endl;
		i.set_type("R");
		if((inst & 0x3C000000) == 0x20000000){
			//std::cout << "mov print" << std::endl;
			i.set_opcode("mov print");
		}
		else if ((inst & 0x3C000000) == 0x00000000){
			//std::cout << "add" << std::endl;
			i.set_opcode("add");
		}
		else if((inst & 0x3C000000) == 0x04000000){
			//std::cout << "sub" << std::endl;
			i.set_opcode("sub");
		}
		else if((inst & 0x3C000000) == 0x08000000){
			//std::cout << "mult" << std::endl;
			i.set_opcode("mult");
		}
		else if((inst & 0x3C000000) == 0x0C000000){
			//std::cout << "div" << std::endl;
			i.set_opcode("div");
		}
		else if((inst & 0x3C000000) == 0x10000000){
			//std::cout << "mod" << std::endl;
			i.set_opcode("mod");
		}
		else if((inst & 0x3C000000) == 0x14000000){
			//std::cout << "beq" << std::endl;
			i.set_opcode("beq");
		}
		else if((inst & 0x3C000000) == 0x18000000){
			//std::cout << "bne" << std::endl;
			i.set_opcode("bne");
		}
		else if((inst & 0x3C000000) == 0x1C000000){
			//std::cout << "mov" << std::endl;
			i.set_opcode("mov");
		}

		else
			std::cout << "Error at instruction decode R" << std::endl;
		
		unsigned int dest = find_dest1(inst);
		unsigned int src1 = find_dest2(inst);
		unsigned int src2 = find_src2(inst);

		set_dest(dest,src1,i);
		set_src2(src2,i);
		i.set_immediate("-1");
		
		}
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

unsigned int memory::find_dest1(unsigned int inst){

	inst = inst & 0x03E00000; //extracts values at 0x03E0...
	inst = inst >> 21;		  //bitshift to get reg value
	return inst;
}

unsigned int memory::find_dest2(unsigned int inst){
	inst = inst & 0x001F0000; 
	inst = inst >> 16;
	return inst;
}

unsigned int memory::find_immediate(unsigned int inst){

	inst = inst & 0x0000FFFF;
	return inst;

}

unsigned int memory::find_src2(unsigned int inst){
	
	inst = inst & 0x00007800;
	inst = inst >> 11;
	return inst;
}

unsigned int memory::find_address(unsigned int inst){

	inst = inst & 0x3FFFFFFF;
	return inst;
}


void memory::set_dest(unsigned int dest, unsigned int src1, instruction &i){
	
	i.set_dest(std::to_string(dest));
	i.set_src1(std::to_string(src1));

}

void memory::set_immediate(unsigned int imm, instruction &i){
	
	i.set_immediate(std::to_string(imm));

}

void memory::set_src2(unsigned int src2, instruction &i){

	i.set_src2(std::to_string(src2));

}

void memory::set_destination(unsigned int dest, instruction &i){
	
	i.set_dest(std::to_string(dest));

}

void memory::set_address(unsigned int address, instruction &i){

	i.set_address(std::to_string(address));
	
}

int memory::get_inst_size(){
	return instruct.size();
}








































































