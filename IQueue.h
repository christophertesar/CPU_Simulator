#ifndef IQUEUE_H
#define IQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include "helperFunctions.h"
#include "instruction.h"

class IQueue{

public:

IQueue();
~IQueue();

std::queue<instruction> iqueue;
std::vector<int> id;

void push_id_num();

private:


};

#endif
