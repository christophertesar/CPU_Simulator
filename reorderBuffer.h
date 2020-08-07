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
std::list<bool> valid_bit;
std::list<int> rob_id;

void increment_rob();
void increment_rob_next();

int get_robval();
int get_robnext();

private:

int robval = 0;
int robnext = 0;

};

#endif
