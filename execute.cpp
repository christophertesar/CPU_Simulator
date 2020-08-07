#include "execute.h"

execute::execute(){

}

execute::~execute(){

}

void execute::executeR(instruction& i, registerFile& rf){
	execute_op(i,rf);
}

void execute::executeI(instruction& i, registerFile& rf){
	execute_op(i,rf);
}

void execute::executeJ(instruction& i, registerFile& rf){
	int pcval = std::stoi(i.get_address());
	rf.write_pc(pcval);
}

void execute::executeP(instruction& i, registerFile& rf){
	int input;
	std::cout << "Enter Input:";
	std::cin >> input;
	rf.write_reg(i.get_dest(),input);
}	

void execute::execute_op(instruction& i,registerFile& rf){
	
	if(i.get_opcode() == "add"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) + std::stoi(i.get_immediate());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
		else if(i.get_type() == "R"){
			int result = rf.read_reg(i.get_src1()) + rf.read_reg(i.get_src2());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "sub"){
		if(i.get_type() == "I"){
			
			int result = rf.read_reg(i.get_src1()) - std::stoi(i.get_immediate());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
		else if(i.get_type() == "R"){
			
			int result = (rf.read_reg(i.get_src1())) - (rf.read_reg(i.get_src2()));
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "mult"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) * std::stoi(i.get_immediate());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
		else if(i.get_type() == "R"){
			int result = rf.read_reg(i.get_src1()) * rf.read_reg(i.get_src2());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "div"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) / std::stoi(i.get_immediate());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
		else if(i.get_type() == "R"){
			int result = (rf.read_reg(i.get_src1())) / (rf.read_reg(i.get_src2()));
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "mod"){
		if(i.get_type() == "I"){
			int result = rf.read_reg(i.get_src1()) % std::stoi(i.get_immediate());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
		else if(i.get_type() == "R"){
			int result = rf.read_reg(i.get_src1()) % rf.read_reg(i.get_src2());
			//std::cout << result << std::endl;
			rf.write_reg(i.get_dest(),result);
			
			#ifdef DEBUG
			std::cout << "Writing " << result << " to R" << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "bne"){
		if(i.get_type() == "I"){
			if(rf.read_reg(i.get_dest()) != rf.read_reg(i.get_src1())){
				rf.write_pc(std::stoi(i.get_immediate()));
			
				#ifdef DEBUG
				std::cout << "Writing " << std::stoi(i.get_immediate()) << " to PC" << std::endl;
				#endif
			}
			else{
				#ifdef DEBUG
				std::cout << "Incrementing PC" << std::endl;
				#endif
				//rf.increment_pc();
			}
		}
	}
	
	else if(i.get_opcode() == "beq"){
		if(i.get_type() == "I"){
			if(rf.read_reg(i.get_dest()) == rf.read_reg(i.get_src1())){
				rf.write_pc(std::stoi(i.get_immediate()));
				
				#ifdef DEBUG
				std::cout << "Writing " << std::stoi(i.get_immediate()) << " to PC" << std::endl;
				#endif
			}
			else{
				#ifdef DEBUG
				std::cout << "Incrementing PC" << std::endl;
				#endif
				//rf.increment_pc();
			}
		}
	}
	
	else if(i.get_opcode() == "mov"){
		if(i.get_type() == "R"){
			rf.write_reg(i.get_dest(),rf.read_reg(i.get_src1()));
			
			#ifdef DEBUG
			std::cout << "Moving " << rf.read_reg(i.get_src1()) << " to " << i.get_dest() << std::endl;
			#endif
		}
	}
	
	else if(i.get_opcode() == "mov print"){
		if(i.get_type() == "R"){
			//rf.write_reg(i.get_dest(),std::stoi(i.get_src1()));
			std::cout << "Your answer is: " << rf.read_reg(i.get_dest()) << std::endl;
		}
	}
	
	else
		std::cout << "Error at execute_op" << std::endl;
}
