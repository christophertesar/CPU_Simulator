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
	
	v1 = true;
	v3 = true;
	v4 = true;
	v5 = true;
	v6 = true;
	v7 = true;
	v8 = true;
	v9 = true;
	v10 = true;
	v11 = true;
	v12 = true;
	v13 = true;
	v14 = true;
	v15 = true;
}

int registerFile::read_r0(){
	return r0;
}

int registerFile::read_r1(){
	return r1;
}

int registerFile::read_r2(){
	return r2;
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

void registerFile::write_r2(int n){
	r2 = n;
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

void registerFile::write_pc(int n){
	pc = n;
}

void registerFile::write_reg(std::string s, int n){
	if(s == "1"){
		write_r1(n);
	}
	else if(s == "2"){
		write_r2(n);
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
	else if(s == "0"){
		std::cout << "Cannot write to reg 0." << std::endl;
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
	else if(s == "2"){
		return read_r2();
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


bool registerFile::read_v1(){
	return v1;
}

bool registerFile::read_v2(){
	return v2;
}

bool registerFile::read_v3(){
	return v3;
}

bool registerFile::read_v4(){
	return v4;
}
	
bool registerFile::read_v5(){
	return v5;
}	

bool registerFile::read_v6(){
	return v6;
}

bool registerFile::read_v7(){
	return v7;
}	

bool registerFile::read_v8(){
	return v8;
}
	
bool registerFile::read_v9(){
	return v9;
}
	
bool registerFile::read_v10(){
	return v10;
}

bool registerFile::read_v11(){
	return v11;
}

bool registerFile::read_v12(){
	return v12;
}
	
bool registerFile::read_v13(){
	return v13;
}
	
bool registerFile::read_v14(){
	return v14;
}	

bool registerFile::read_v15(){
	return v15;
}



void registerFile::write_v1(bool n){
	v1 = n;
}

void registerFile::write_v2(bool n){
	v2 = n;
}

void registerFile::write_v3(bool n){
	v3 = n;
}

void registerFile::write_v4(bool n){
	v4 = n;
}
	
void registerFile::write_v5(bool n){
	v5 = n;
}	

void registerFile::write_v6(bool n){
	v6 = n;
}

void registerFile::write_v7(bool n){
	v7 = n;
}	

void registerFile::write_v8(bool n){
	v8 = n;
}
	
void registerFile::write_v9(bool n){
	v9 = n;
}
	
void registerFile::write_v10(bool n){
	v10 = n;
}

void registerFile::write_v11(bool n){
	v11 = n;
}

void registerFile::write_v12(bool n){
	v12 = n;
}
	
void registerFile::write_v13(bool n){
	v13 = n;
}
	
void registerFile::write_v14(bool n){
	v14 = n;
}	

void registerFile::write_v15(bool n){
	v15 = n;
}

bool registerFile::read_v(std::string s){
	if(s == "0"){
		return read_v0();
	}
	else if(s == "1"){
		return read_v1();
	}
	else if(s == "2"){
		return read_v2();
	}
	else if(s == "3"){
		return read_v3();
	}
	else if(s == "4"){
		return read_v4();
	}
	else if(s == "5"){
		return read_v5();
	}
	else if(s == "6"){
		return read_v6();
	}
	else if(s == "7"){
		return read_v7();
	}
	else if(s == "8"){
		return read_v8();
	}
	else if(s == "9"){
		return read_v9();
	}
	else if(s == "10"){
		return read_v10();
	}
	else if(s == "11"){
		return read_v11();
	}
	else if(s == "12"){
		return read_v12();
	}
	else if(s == "13"){
		return read_v13();
	}
	else if(s == "14"){
		return read_v14();
	}
	else if(s == "15"){
		return read_v15();
	}
	else
		return -1;
}

void registerFile::write_v(std::string s, bool n){
	if(s == "1"){
		write_v1(n);
	}
	else if(s == "2"){
		write_v2(n);
	}
	else if(s == "3"){
		write_v3(n);
	}
	else if(s == "4"){
		write_v4(n);
	}
	else if(s == "5"){
		write_v5(n);
	}
	else if(s == "6"){
		write_v6(n);
	}
	else if(s == "7"){
		write_v7(n);
	}
	else if(s == "8"){
		write_v8(n);
	}
	else if(s == "9"){
		write_v9(n);
	}
	else if(s == "10"){
		write_v10(n);
	}
	else if(s == "11"){
		write_v11(n);
	}
	else if(s == "12"){
		write_v12(n);
	}
	else if(s == "13"){
		write_v13(n);
	}
	else if(s == "14"){
		write_v14(n);
	}
	else if(s == "15"){
		write_v15(n);
	}
	else if(s == "0"){
		std::cout << "Cannot write to reg 0." << std::endl;
	}
	else
		std::cout << "Cannot write to valid bit." << std::endl;
}

registerFile::registerFile(const registerFile &a){

}














	
