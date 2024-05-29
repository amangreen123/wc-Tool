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
	std::ifstream myFile{ "test.txt" };
	std::vector<std::string> words;
	std::string input;

	if (!myFile) {
		std::cerr << "Can't open File\n";
		return 1;
	}

	std::string strInput{};
	while (std::getline(myFile, strInput)) {

		myFile.seekg(0, std::ios::end);
		int byteSize = myFile.tellg();

		std::cout << "Size of the file is" << byteSize << " ";
	}		

	return 0;


}

	/*myfile.open("test.txt");

	if (!myfile) {
		std::cout << "Unable to open file";
		exit(1);
	}

	if (myfile.is_open()) {
		
		while (std::getline(myfile, line)) {
			  myfile.seekg(0);
			  int byte_Size = myfile.tellg();
			  std::cout << byte_Size << '\n';
		}

		myfile.close();
	}

	else {
		std::cout << "Unable to open file";
	}*/


