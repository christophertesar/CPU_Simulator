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

std::list<std::string> operation;
std::list<std::string> src1;
std::list<std::string> src2;
std::list<std::string> dest;
std::list<std::string> immediate;
std::list<bool> valid1;
std::list<bool> valid2;
std::list<int> rob_id_iq;

/*
std::list<std::string>::iterator operationit;
std::list<std::string>::iterator src1it;
std::list<std::string>::iterator src2it;
std::list<std::string>::iterator destit;
std::list<std::string>::iterator immediateit;
std::list<bool>::iterator valid1it;
std::list<bool>::iterator valid2it;
std::list<int>::iterator rob_id_iqit;
*/

private:

int iqq;

};

#endif
