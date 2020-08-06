#include <iostream>
#include <string>
#include <queue>
#include "instruction.h"
#include "registerFile.h"
#include "helperFunctions.h"

class execute{

public:

execute();
~execute();
execute(const execute&);

void executeR(instruction&, registerFile&);
void executeI(instruction&, registerFile&);
void executeJ(instruction&, registerFile&);
void executeP(instruction&, registerFile&);	

void execute_op(instruction&, registerFile&);

private:



};
