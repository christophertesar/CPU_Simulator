#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <iostream>
#include <string>
#include "helperFunctions.h"
#include "memory.h"
#include "instruction.h"

class pipeline{

public:
	
	pipeline();
	pipeline(std::string);
	~pipeline();
	memory mem;

private:
	std::string filename;
	
};

#endif
