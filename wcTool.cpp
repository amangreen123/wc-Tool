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
	std::string input;
	std::string lines{};
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


int main(int argc, char* argv[]) {
    std::string lines{};
    std::ifstream myFile{ "test.txt" };
    std::cout << argv[0] << std::endl;

    
	char option = std::string(argv[1])[1];


    if (argc == 2 && std::cin.peek()) {

		if (!checkValidInput(std::string(argv[1])))
		{
			std::cerr << "Usage: " << argv[0] << " <-l | -w | -c | -m> <filename>" << std::endl;
			return 1;
		}
       
		switch (option) {
        case 'c':
            std::cout << "Bytes number " << countNumberofBytes(myFile) << std::endl;
            break;
        case 'l':
            std::cout << "lines number " << countNumberofLines(myFile) << std::endl;
            break;
        case 'w':
            std::cout << "word number " << countNumberOfWords(myFile) << std::endl;
            break;
        case 'm':
            std::cout << "character " << countNumberOfCharacters(myFile) << std::endl;
            break;
        default:
            std::cerr << "Invalid input\n";
            return 1;
        }
    }
    if (argc == 1) {
        std::cerr << "No input provided\n";
        return 1;
    }
    if (argc > 2) {
        std::cerr << "Too many arguments\n";
        return 1;
    }
    if (!checkValidInput(argv[1])) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    if (!myFile) {
        std::cerr << "Can't open File\n";
        return 1;
    }



    myFile.close();
    return 0;
}

	


