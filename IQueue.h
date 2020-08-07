#ifndef IQUEUE_H
#define IQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "helperFunctions.h"
#include "instruction.h"

class IQueue{

public:

IQueue();
~IQueue();
IQueue(const IQueue&);

std::queue<instruction> iqueue;

std::list<bool> valid;

void push_id_num();

private:

int iqq;

};

#endif
