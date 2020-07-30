#ifndef MEMORY_H
#define MEMORY_H

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
	void instruction_decode(unsigned int);
	unsigned int get_instruction(int);
	void disp_instructions();

private:
	std::vector<unsigned int> instruction;
	std::vector<unsigned int>::iterator inst_ptr;
	int pc;
	
};


#endif
