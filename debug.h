#ifndef DEBUG_H
#define DEBUG_H


#include <string>
#include <iostream>

class debug{

public:

debug();
~debug();
debug(const debug&);

void debug_fetch();
void debug_iq();
void debug_execute();
void debug_commit();
void inst2bin(unsigned int);


private:

int deb = 0;




};

#endif
