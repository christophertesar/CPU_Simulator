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
	int read_r2();
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
	
	bool read_v0(){return true;}
	bool read_v1();
	bool read_v2();
	bool read_v3();
	bool read_v4();
	bool read_v5();
	bool read_v6();
	bool read_v7();
	bool read_v8();
	bool read_v9();
	bool read_v10();
	bool read_v11();
	bool read_v12();	
	bool read_v13();
	bool read_v14();
	bool read_v15();
	
	void write_v1(bool);
	void write_v2(bool);
	void write_v3(bool);
	void write_v4(bool);
	void write_v5(bool);
	void write_v6(bool);
	void write_v7(bool);
	void write_v8(bool);
	void write_v9(bool);
	void write_v10(bool);
	void write_v11(bool);
	void write_v12(bool);	
	void write_v13(bool);
	void write_v14(bool);
	void write_v15(bool);
	
	int get_pc();
	
	void write_r1(int);
	void write_r2(int);
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
	void write_pc(int);
	
	void write_reg(std::string,int);
	int read_reg(std::string);
	void write_v(std::string, bool);
	bool read_v(std::string);
	

private:
	int r0 = 0;  //constant register of value 0;
	int r2 = 0;      //can only be written to by p type instructions
	
	int r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15;
	int pc = 0;
	
	bool v0 = true,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15;
};

#endif
