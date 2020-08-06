#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <iostream>
#include <string>
#include "helperFunctions.h"

class registerFile{

public:
	registerFile();
	registerFile(const registerFile&);
	
	int read_r0();
	int read_r1();
	int read_r3();
	int read_r4();
	int read_r5();
	int read_r6();
	int read_r7();
	int read_r8();
	int read_r9();
	int read_r10();
	int read_r11();
	int read_r12();
	int read_r13();
	int read_r14();
	int read_r15();
	
	int get_pc();
	
	void write_r1(int);
	void write_r3(int);
	void write_r4(int);
	void write_r5(int);
	void write_r6(int);
	void write_r7(int);
	void write_r8(int);
	void write_r9(int);
	void write_r10(int);
	void write_r11(int);
	void write_r12(int);
	void write_r13(int);
	void write_r14(int);
	void write_r15(int);
	
	void increment_pc();
	
	void write_reg(std::string,int);
	int read_reg(std::string);
	

private:
	int r0 = 0;  //constant register of value 0;
	int r2;      //can only be written to by p type instructions
	
	int r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15;
	int pc = 0;
};

#endif
