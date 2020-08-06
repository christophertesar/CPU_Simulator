#include "pipeline.h"

pipeline::pipeline(){

	this->mem = memory();
	
	this->rf = registerFile();
}

pipeline::pipeline(std::string fn){
	this->mem = memory();
	std::cout << "initialized mem" << std::endl;
	filename = fn;
	mem.read_instructions(fn);
	
	this->rf = registerFile();
	
	this->rb = reorderBuffer();
	
	this->iq = IQueue();
	
	this->ex = execute();
	
}

pipeline::~pipeline(){
	
}

void pipeline::fetch(){

	instruction j = mem.instruction_decode(mem.get_instruction(rf.get_pc())); //get instruction from unsigned int
	rf.increment_pc();
	rb.rob.push(j);         //push instructions into rb and iq
	iq.iqueue.push(j);
	iq.push_id_num();  
	
}

void pipeline::exe(){
	
	instruction i = iq.iqueue.front(); //dispatch
	iq.iqueue.pop();
									   //read
	
	if(i.get_type() == "R"){//R

	}
	else if(i.get_type() == "I"){//I
		ex.executeI(i,rf);
	}
	else if(i.get_type() == "J"){//J

	}
	else if(i.get_type() == "P"){//P

	}
	else
		std::cout << "Error at execute() read." << std::endl;
	
	
}

void pipeline::commit(){

}
