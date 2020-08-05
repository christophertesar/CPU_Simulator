#include "pipeline.h"

pipeline::pipeline(){

	this->mem = memory();
	
	this->rf = registerFile();
}

pipeline::pipeline(std::string fn){
	this->mem = memory();
	filename = fn;
	mem.read_instructions(fn);
	
	this->rf = registerFile();
	
}

pipeline::~pipeline(){
	
}

void pipeline::fetch(){
	instruction j = mem.instruction_decode(mem.get_instruction(rf.get_pc()));
	
	std::cout << j.get_dest() << std::endl;
	std::cout << j.get_src1() << std::endl;
	std::cout << j.get_immediate() << std::endl;
	
}

void pipeline::execute(){

}

void pipeline::commit(){

}
