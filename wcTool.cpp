#include <cstdlib>
#include<fstream>
#include<iostream>
#include <string>
#include <vector>
#include <sstream>




int countNumberofBytes(std::ifstream& f) {
	
	std::string lines{};

	while (std::getline(f, lines)) {

		f.seekg(0, std::ios::end);
		int byteSize = f.tellg();

		return byteSize;
	}

}

int countNumberofLines(std::ifstream& f) {

	std::string lines{};
	int numberOfLines = 0;

	while (std::getline(f, lines)) {
		numberOfLines++;
	}

	return numberOfLines;

}

int countNumberOfWords(std::ifstream& f) {
	int numberOfWords = 0;
	std::string line;

	while (std::getline(f, line)) {
		
		std::stringstream linestream(line);
		std::string word;

		while (linestream >> word) { // Read word by word
			++numberOfWords;
		}
	}

	return numberOfWords;
}

int countNumberOfCharacters(std::ifstream& f) {	
	
	int numberOfCharacters = 0;
	char current_char = '\0';

	while (f.get(current_char)) {

		if (current_char != '\n')
		++numberOfCharacters;
	}
		return numberOfCharacters;

}

bool checkValidInput(std::string input) {
	// Check if the input is valid  -c, -l and -w are valid inputs

	if (input == "-c" || input == "-l" || input == "-w" || input == "-m") {
		return true;
	}
	else {
		return false;
	}
}


//argc = argument count always equal 1 each command line argument the user provides will cause argc to increase by 1
//argv = where the actual argument values are stored 

int main(int argc, char* argv[]) {
    
	std::string lines{};
    std::ifstream myFile{ "test.txt" };
	std::string input{};

	if (argc != 3) {
		std::cerr << "Invalid number of arguments\n";
		return 1;
	}
	
	std::cout << "There are " << argc << " arguments:\n";

	// Loop through each argument and print its number and value
	for (int count{ 0 }; count < argc; ++count)
	{
		std::cout << count << ' ' << argv[count] << '\n';
	}


	if (!myFile.is_open()) {
		std::cerr << "File not found\n";
		return 1;
	}

	std::cout << "Enter the option you want to use: -c, -l, -w, -m\n";
	std::cin >> input;

	if (!checkValidInput(input)) {
		std::cout << "Invalid input\n";
		return 1;
		}

	if (input == "-c") {
		std::cout << argv[1] << " " << input << " " << countNumberofBytes(myFile) << " " << argv[2] << '\n';
	}
	else if (input == "-l") {
		std::cout << argv[1] << " " << input << " " << countNumberofLines(myFile) << " " << argv[2] << '\n';
	}
	else if (input == "-w") {
	    std::cout << argv[1] << " " << input << " " << countNumberOfWords(myFile) << " " << argv[2] << '\n';
	}
	else if (input == "-m") {
		std::cout << argv[1] << " " << input << " " << countNumberOfCharacters(myFile) << " " << argv[2] << '\n';
	}
	else if (input == argv[2]) {
		std::cout << countNumberofBytes(myFile) << " " << countNumberofLines(myFile) << " " << countNumberOfWords(myFile) << " " << countNumberOfCharacters(myFile) << '\n';
	}

	else {
		std::cout << "Invalid input\n";
		return 1;
	}

    myFile.close();
    
	return 0;
}

	


