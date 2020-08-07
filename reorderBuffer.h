#ifndef REORDERBUFFER_H
#define REORDERBUFFER_H

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "helperFunctions.h"
#include "instruction.h"

class reorderBuffer{

public:

reorderBuffer();
~reorderBuffer();
reorderBuffer(const reorderBuffer&);
//reorderBuffer operator=(const reorderBuffer&){return 0;}

std::list<instruction> rob;
std::list<bool> valid1;
std::list<bool> valid2;
std::list<int> rob_id;

private:

int robert;

};

#endif
