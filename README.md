# CPU_Simulator
This program simulates a simple CPU with basic instructions. The CPU executes 4 types of instructions, R, I ,J and P type instructions. These instructions are stored in
a unsigned int (32 bit) format in a csv.

R Type instructions (Bit 31 and 30 == "00") consist of an opcode, a destination register, operand 1 and operand 2.
I Type instructions (Bit 31 and 30 == "01") consist of an opcode, a destination register, operand 1 and immediate value.
J Type instructions (Bit 31 and 30 == "10") only consists of an address to jump to. The address is loaded into the program counter.
P Type instructions (Bit 31 and 30 == "11") consists of an opcode (which is not used.), a destination of register 2. User is prompted with an input and is stored in register 2.

