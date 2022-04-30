// Parrot.cpp : Defines the entry point for the application.
//

#include "./lib/Parrot.hpp"

int main (int argc, char* argv[]) {
	std::cout << "Parrot\n";
	Parrot::Log logFile;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			std::cout << argv[i] << ", ";
			if ((std::strcmp(argv[i], "-l") == 0) && (i + 1 < argc)) {
				std::cout << "log init : " << argv[i + 1] << ", " << i+1 <<"\n";
				logFile.init(argv[++i]);
			}else if (std::strcmp(argv[i], "-s") == 0) {
				std::cout << "parrot src :: \n";
				for (++i; i < argc; i++) {
					std::cout << argv[i] << "\n";
				}
			}
		}
	}
	return 0;
}
