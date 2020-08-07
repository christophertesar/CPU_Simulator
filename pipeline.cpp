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

	this->rb = reorderBuffer();
	
	this->iq = IQueue();

	this->ex = execute();

}

pipeline::~pipeline(){
	
}

void pipeline::fetch(){

	instruction j = mem.instruction_decode(mem.get_instruction(rf.get_pc())); //get instruction from unsigned int
	
	#ifdef DEBUG
	std::cout << "---------Fetch-----------\n";
	unsigned int k = mem.get_instruction(rf.get_pc());
	std::cout << "b ";
	for(unsigned int i = 2147483648; i > 0; i /= 2){   
			if ((k & i) != 0){
				std::cout << '1'; 
			}
			else{
				std::cout << '0';
			}
	}
	std::cout << "\n";
	
	#endif
	
	rf.increment_pc();           //pc increment
	
	rb.rob.push_back(j);         //push instructions into rb and iq
	rb.valid_bit.push_back(false);
	rb.rob_id.push_back(rb.get_robnext());
	rb.increment_rob_next();
	
	iq.iqueue.push(j);			 //iqueue handling
	iq.push_id_num();  
	
}

void pipeline::exe(){
	#ifdef DEBUG
	std::cout << "---------Execute----------\n";
	#endif
	instruction i = iq.iqueue.front(); //dispatch
									   //read
	
	if(i.get_type() == "R"){//R
		ex.executeR(i,rf);
	}
	else if(i.get_type() == "I"){//I
		ex.executeI(i,rf);
	}
	else if(i.get_type() == "J"){//J
		ex.executeJ(i,rf);
	}
	else if(i.get_type() == "P"){//P
		ex.executeP(i,rf);
	}
	else
		std::cout << "Error at execute() read." << std::endl;
	#ifdef DEBUG 
	std::cout << "Executed." << std::endl;
	#endif
	
	std::list<bool>::iterator it = rb.valid_bit.begin();
	*it = true;
	
	#ifdef DEBUG
	std::list<int>::iterator robit = rb.rob_id.begin();
	std::cout << "ROB ID " << *robit << " marked" << std::endl;
	#endif
	iq.iqueue.pop();
	
}

void pipeline::commit(){
	std::list<bool>::iterator it = rb.valid_bit.begin();
	std::list<int>::iterator it2 = rb.rob_id.begin();
	
	if((*it == true) && (rb.get_robval() == *it2)){
	
		#ifdef DEBUG
		std::cout << "---------Commit-----------\n";
		std::list<int>::iterator robit = rb.rob_id.begin();
		std::cout << "ROB ID " << *robit << " Committed.\n\n" << std::endl;
		#endif
		
		rb.rob.pop_front();
		rb.rob_id.pop_front();
		rb.valid_bit.pop_front();
		rb.increment_rob();
	}
	else
		std::cout << "ROB Fail" << std::endl;
	
	#ifdef DEBUG
	
	#endif
	
	if(rf.get_pc() + 1 > mem.get_inst_size()){
		setValid();
	}
	
	
}

bool pipeline::isValid(){
	return valid;
}

void pipeline::setValid(){
	valid = false;
}
