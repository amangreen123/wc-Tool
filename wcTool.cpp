#include <cstdlib>
#include<fstream>
#include<iostream>
#include <string>
#include <vector>
#include <regex>



//bool isValidInput(const std::string& input) {
//
//	std::regex inputRegex("^(-[clwm]+)$");
//
//	if (!std::regex_match(input, inputRegex)) {
//		std::cout << "Error: Invalid input format. Expected format: -c, -l, -w, or -m" << std::endl;
//		return false;
//	}
//
//	return true;
//
//}

int main(int argc, char* argv[]) {

	std::string line;
	std::ifstream myfile;
	std::vector<std::string> words;
	std::string input;

	myfile.open("test.txt");

	if (!myfile) {
		std::cout << "Unable to open file";
		exit(1);
	}

	if (myfile.is_open()) {
		
		while (getline(myfile, line)) {
				/*words.push_back(line);
				int byte_Size = myfile.tellg();
				std::cout << byte_Size;*/
			
		}
		myfile.close();
	}

	else {
		std::cout << "Unable to open file";
	}

}