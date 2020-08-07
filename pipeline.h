#ifndef PIPELINE_H
#define PIPELINE_H
#define ISSUE_WIDTH 1

#include <vector>
#include <iostream>
#include <string>
#include "helperFunctions.h"
#include "memory.h"
#include "instruction.h"
#include "registerFile.h"
#include "reorderBuffer.h"
#include "IQueue.h"
#include "execute.h"

class pipeline{

public:
	
	pipeline();
	pipeline(std::string);
	~pipeline();
	
	memory mem;
	registerFile rf;
	reorderBuffer rb;
	IQueue iq;
	execute ex;
	
	void fetch();
	void exe();
	void commit();
	
	bool isValid();
	void setValid();

private:

	std::string filename;
	bool valid = true;
};

#endif
