#include <iostream>
#include "pipeline.h"

int main(){

pipeline pipe("factorial.csv");
//pipe.mem.disp_instructions();
pipe.mem.instruction_decode(pipe.mem.get_instruction(0));
//pipe.mem.read_instructions("factorial.csv");

}
