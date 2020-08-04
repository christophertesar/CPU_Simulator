#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>
//#include "memory.h"

class instruction{

public:
	instruction();
	~instruction();
	void set_opcode(std::string);
	void set_src1(std::string);
	void set_src2(std::string);
	void set_dest(std::string);
	void set_immediate(std::string);
	void set_address(std::string);

private:
	std::string opcode;
	std::string src1;
	std::string src2;
	std::string dest;
	std::string immediate;
	std::string address;

};

#endif
