#include <iostream>
#include <fstream>
#include <string>



int main() {

	std::string line;
	std::ofstream myfile;

	myfile.open("example.txt");

	if (myfile.is_open()) {

		std::cout << "Enter text. To end, type 'end'." << std::endl;

	}
}