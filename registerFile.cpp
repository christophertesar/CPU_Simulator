#include "registerFile.h"

registerFile::registerFile(){
	r1 = 0;
	r3 = 0;
	r4 = 0;
	r5 = 0;
	r6 = 0;
	r7 = 0;
	r8 = 0;
	r9 = 0;
	r10 = 0;
	r11 = 0;
	r12 = 0;
	r13 = 0;
	r14 = 0;
	r15 = 0;
}

int registerFile::read_r0(){
	return r0;
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

void registerFile::increment_pc(){
	pc++;
}

void registerFile::write_reg(std::string s, int n){
	if(s == "1"){
		write_r1(n);
	}
	else if(s == "3"){
		write_r3(n);
	}
	else if(s == "4"){
		write_r4(n);
	}
	else if(s == "5"){
		write_r5(n);
	}
	else if(s == "6"){
		write_r6(n);
	}
	else if(s == "7"){
		write_r7(n);
	}
	else if(s == "8"){
		write_r8(n);
	}
	else if(s == "9"){
		write_r9(n);
	}
	else if(s == "10"){
		write_r10(n);
	}
	else if(s == "11"){
		write_r11(n);
	}
	else if(s == "12"){
		write_r12(n);
	}
	else if(s == "13"){
		write_r13(n);
	}
	else if(s == "14"){
		write_r14(n);
	}
	else if(s == "15"){
		write_r15(n);
	}
	else
		std::cout << "Cannot write to reg." << std::endl;
}

int registerFile::read_reg(std::string s){
	if(s == "0"){
		return read_r0();
	}
	else if(s == "1"){
		return read_r1();
	}
	else if(s == "3"){
		return read_r3();
	}
	else if(s == "4"){
		return read_r4();
	}
	else if(s == "5"){
		return read_r5();
	}
	else if(s == "6"){
		return read_r6();
	}
	else if(s == "7"){
		return read_r7();
	}
	else if(s == "8"){
		return read_r8();
	}
	else if(s == "9"){
		return read_r9();
	}
	else if(s == "10"){
		return read_r10();
	}
	else if(s == "11"){
		return read_r11();
	}
	else if(s == "12"){
		return read_r12();
	}
	else if(s == "13"){
		return read_r13();
	}
	else if(s == "14"){
		return read_r14();
	}
	else if(s == "15"){
		return read_r15();
	}
	else
		return -1;
}

registerFile::registerFile(const registerFile &a){

}














	
