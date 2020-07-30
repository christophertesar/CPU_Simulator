#include "pipeline.h"

pipeline::pipeline(){
	
}

pipeline::pipeline(std::string fn){
	filename = fn;
	mem.read_instructions(fn);
}

pipeline::~pipeline(){
	
}
