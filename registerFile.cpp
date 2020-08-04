#include "registerFile.h"

registerFile::registerFile(){
	
}

int registerFile::read_r1(){
	return r1;
}

int registerFile::read_r3(){
	return r3;
}

int registerFile::read_r4(){
	return r4;
}
	
int registerFile::read_r5(){
	return r5;
}	

int registerFile::read_r6(){
	return r6;
}

int registerFile::read_r7(){
	return r7;
}	

int registerFile::read_r8(){
	return r8;
}
	
int registerFile::read_r9(){
	return r9;
}
	
int registerFile::read_r10(){
	return r10;
}

int registerFile::read_r11(){
	return r11;
}

int registerFile::read_r12(){
	return r12;
}
	
int registerFile::read_r13(){
	return r13;
}
	
int registerFile::read_r14(){
	return r14;
}	

int registerFile::read_r15(){
	return r15;
}
		
void registerFile::write_r1(int n){
	r1 = n;
}
		
void registerFile::write_r3(int n){
	r3 = n;
}
	
void registerFile::write_r4(int n){
	r4 = n;
}
	
void registerFile::write_r5(int n){
	r5 = n;
}
		
void registerFile::write_r6(int n){
	r6 = n;
}
		
void registerFile::write_r7(int n){
	r7 = n;
}
		
void registerFile::write_r8(int n){
	r8 = n;
}
		
void registerFile::write_r9(int n){
	r9 = n;
}
	
void registerFile::write_r10(int n){
	r10 = n;
}
	
void registerFile::write_r11(int n){
	r11 = n;
}
	
void registerFile::write_r12(int n){
	r12 = n;
}

void registerFile::write_r13(int n){
	r13 = n;
}
		
void registerFile::write_r14(int n){
	r14 = n;
}
		
void registerFile::write_r15(int n){
	r15 = n;
}	

int registerFile::get_pc(){
	return pc;
}

registerFile::registerFile(const registerFile &a){

}














	
