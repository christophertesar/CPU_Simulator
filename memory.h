#ifndef MEMORY_H
#define MEMORY_H
#define FECTCH_WIDTH 1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "instruction.h"

class memory{

public:
	memory();
	~memory();
	memory(std::string);
	memory(const memory&);
	void read_instructions(std::string);
	instruction instruction_decode(unsigned int);
	unsigned int get_instruction(int);
	void disp_instructions();
	
	unsigned int find_dest1(unsigned int);
	unsigned int find_dest2(unsigned int);
	unsigned int find_immediate(unsigned int);
	unsigned int find_src2(unsigned int);
	unsigned int find_address(unsigned int);
	void set_dest(unsigned int,unsigned int,instruction&);
	void set_immediate(unsigned int, instruction&);
	void set_src2(unsigned int, instruction&);
	void set_destination(unsigned int, instruction&);
	void set_address(unsigned int, instruction&);
	void set_instruction(unsigned int, instruction&);
	int get_inst_size();
	

private:
	
	std::vector<unsigned int>::iterator inst_ptr;
	std::vector<unsigned int> instruct;
	
	
	int pc;
	
};


#endif
