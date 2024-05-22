#include <cstdlib>
#include<fstream>
#include<iostream>
#include <string>
#include <vector>



int main() {

	std::string line;
	std::ifstream myfile;
	std::vector<std::string> words;


	myfile.open("test.txt");

	if (!myfile) {
		std::cout << "Unable to open file";
		exit(1);
	}

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			words.push_back(line);
			std::cout << line << '\n';
		}
		myfile.close();
	}

	else {
		std::cout << "Unable to open file";
	}

}