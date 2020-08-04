#include <iostream>
#include "pipeline.h"

int main(){
std::string filename;
std::cout << "Please enter file name to run." << std::endl;
std::cin >> filename;
filename = filename + ".csv";
pipeline pipe("inst_mem.csv");

pipe.fetch();


}
