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
	mem.instruction_decode(mem.get_instruction(rf.get_pc()));
}

void pipeline::execute(){

}

void pipeline::commit(){

}
