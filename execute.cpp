#include "execute.h"

execute::execute(){

}

execute::~execute(){

}

void execute::executeR(instruction& i, registerFile& rf){
	
}

void execute::executeI(instruction& i, registerFile& rf){
	execute_op(i,rf);
}

void execute::executeJ(instruction& i, registerFile& rf){

}

void execute::executeP(instruction& i, registerFile& rf){

}	

void execute::execute_op(instruction& i,registerFile& rf){
	
	if(i.get_opcode() == "add"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) + std::stoi(i.get_immediate());
			std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
		}
	}
	
	else if(i.get_opcode() == "sub"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) - std::stoi(i.get_immediate());
			std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
		}
	}
	
	else if(i.get_opcode() == "mult"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) * std::stoi(i.get_immediate());
			std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
		}
	}
	
	else if(i.get_opcode() == "div"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) / std::stoi(i.get_immediate());
			std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
		}
	}
	
	else if(i.get_opcode() == "mod"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) % std::stoi(i.get_immediate());
			std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
		}
	}
	
	else if(i.get_opcode() == "bne"){
	
	}
	
	else if(i.get_opcode() == "beq"){
	
	}
	
	else if(i.get_opcode() == "mov"){
	
	}
	
	else if(i.get_opcode() == "mov print"){
	
	}
	
	else
		std::cout << "Error at execute_op" << std::endl;
}
