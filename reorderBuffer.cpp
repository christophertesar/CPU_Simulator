#include "reorderBuffer.h"

reorderBuffer::reorderBuffer(){

}

reorderBuffer::~reorderBuffer(){

}

reorderBuffer::reorderBuffer(const reorderBuffer &a){

}

void reorderBuffer::increment_rob(){
	robval++;
}

void reorderBuffer::increment_rob_next(){
	robnext++;
}

int reorderBuffer::get_robnext(){
	return robnext;
}

int reorderBuffer::get_robval(){
	return robval;
}
