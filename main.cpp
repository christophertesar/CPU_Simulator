#include <iostream>
#include "pipeline.h"

int main(){

std::string filename;
std::cout << "Please enter file name to run. Type \"exit\" to exit" << std::endl;
std::cin >> filename;
filename = filename + ".csv";

while(filename != "exit.csv"){
	
	pipeline pipe(filename);


	while(pipe.isValid()){

		pipe.fetch();
		pipe.exe();
		pipe.commit();
	}
	
	std::cout << "Please enter file name to run. Type \"exit\" to exit" << std::endl;
	std::cin >> filename;
	filename = filename + ".csv";
	
}

return 0;

}
