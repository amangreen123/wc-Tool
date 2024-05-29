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
	int numOfWords = 0;
	std::string line;

	while (std::getline(f, line)) {
		
		std::stringstream linestream(line);
		std::string word;

		while (linestream >> word) { // Read word by word
			++numOfWords;
		}
	}

	return numOfWords;
}


int main(int argc, char* argv[]) {

	std::string lines{};
	std::ifstream myFile{ "test.txt" };


	if (!myFile) {
		std::cerr << "Can't open File\n";
		return 1;
	}


		int byteCount = countNumberofBytes(myFile);
		int lineCount = countNumberofLines(myFile);
		int wordCount = countNumberOfWords(myFile);


		std::cout << "Number of bytes: " << byteCount << std::endl;
		std::cout << "Number of lines: " << lineCount << std::endl;
		std::cout << "Number of words: " << wordCount << std::endl;
	
	
		//Bytes number 342190
		//lines number 7145
		//word number 58164

	myFile.close();

	return 0;
}

	


