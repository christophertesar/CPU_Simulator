#ifndef REORDERBUFFER_H
#define REORDERBUFFER_H

#include <iostream>
#include <string>
#include <queue>
#include "helperFunctions.h"
#include "instruction.h"

class reorderBuffer{

public:

reorderBuffer();
~reorderBuffer();
reorderBuffer(const reorderBuffer&);

std::queue<instruction> rob;
std::queue<bool> valid1;
std::queue<bool> valid2;
std::queue<int> rob_id;

private:



};

#endif
