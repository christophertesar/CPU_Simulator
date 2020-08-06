#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>


class instruction{

public:
	instruction();
	~instruction();
	
	void set_type(std::string);
	void set_opcode(std::string);
	void set_src1(std::string);
	void set_src2(std::string);
	void set_dest(std::string);
	void set_immediate(std::string);
	void set_address(std::string);
	
	std::string get_type();
	std::string get_opcode();
	std::string get_src1();
	std::string get_src2();
	std::string get_dest();
	std::string get_immediate();
	std::string get_address();
	
	

private:
	std::string type;
	std::string opcode;
	std::string src1;
	std::string src2;
	std::string dest;
	std::string immediate;
	std::string address;

};

#endif
