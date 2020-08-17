#include "pipeline.h"
#define DEBUG

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

	this->except = exception();

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
	//iq.rob_id_iq.push_back(rb.get_robnext());
	rb.increment_rob_next();
	
	iq.iqueue.push(j);			 //iqueue handling
	
	iq.src1.push_back(j.get_src1());
	iq.src2.push_back(j.get_src2());
	iq.operation.push_back(j.get_opcode());
	iq.dest.push_back(j.get_dest());
	iq.immediate.push_back(j.get_immediate());
	
}

void pipeline::exe(){

	#ifdef DEBUG
	
	std::list<std::string>::iterator operationit = iq.operation.begin();
	std::list<std::string>::iterator src1it = iq.src1.begin();
	std::list<std::string>::iterator src2it = iq.src2.begin();
	std::list<std::string>::iterator destit = iq.dest.begin();
	std::list<std::string>::iterator immediateit = iq.immediate.begin();
	std::list<bool>::iterator valid1it = iq.valid1.begin();
	std::list<bool>::iterator valid2it = iq.valid2.begin();
	std::list<int>::iterator rob_id_iqit = iq.rob_id_iq.begin();
	
	std::cout << "--------Instruction Queue------------\n";
	std::cout << std::setw(6) <<"Dest"<< std::setw(6) << "V" << std::setw(6) << "Src1" << std::setw(6) << "V" << std::setw(6) << "Src2" << std::setw(10) << "Immediate" << std::endl;
	std::cout << std::setw(6) << *destit << std::setw(6) << "1" << std::setw(6) << *src1it << std::setw(6) << "1" << std::setw(6) << *src2it << std::setw(10) << *immediateit << std::endl;
	
	#endif

	#ifdef DEBUG
	std::cout << "---------Execute----------\n";
	#endif
	instruction i = iq.iqueue.front(); //dispatch
									   //read
	#ifdef DEBUG
	std::list<int>::iterator ro = rb.rob_id.begin();
	std::cout << "INST: " << *ro << "): Ready to be executed" << std::endl;
	#endif
	
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
	iq.src1.pop_front();
	iq.src2.pop_front();
	iq.dest.pop_front();
	iq.immediate.pop_front();
	iq.operation.pop_front();
	
}

void pipeline::commit(){
	std::list<bool>::iterator it = rb.valid_bit.begin();
	std::list<int>::iterator it2 = rb.rob_id.begin();
	
	if(rb.get_robval() != *it2){
		std::cout << "ROB value invalid. Terminating program" << std::endl;
		setValid();
	}
	
	if((*it == true) && (rb.get_robval() == *it2)){
	
		#ifdef DEBUG
		std::cout << "---------Commit-----------\n";
		std::list<int>::iterator robit = rb.rob_id.begin();
		std::cout << "ROB ID " << *robit << " Committed.\n\n\n\n" << std::endl;
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
