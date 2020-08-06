#include <iostream>
#include "pipeline.h"

int main(){
std::string filename;
std::cout << "Please enter file name to run." << std::endl;
std::cin >> filename;
filename = filename + ".csv";
pipeline pipe(filename);

for(int i = 0; i < 100; i++){
	pipe.fetch();
	pipe.exe();
	pipe.commit();
}

return 0;

}
