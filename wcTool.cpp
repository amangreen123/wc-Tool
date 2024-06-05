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
	std::string lines{};
	char current_char;

	while (true) {

		if (f.peek() == -1)
			break;
		current_char = f.get();

		if (current_char != '\n')
			++numberOfCharacters;
	}

	return numberOfCharacters;

	/*while (f.get(current_char)) {

		if (current_char == EOF) {
			break;
		}
		numberOfCharacters++;
		
	}

		return numberOfCharacters;*/

	/*while (std::getline(f, lines)) {	
		numberOfCharacters += lines.length();

		return numberOfCharacters;
		
		gets 69
	}*/


	/*f.seekg(0, std::ios_base::end);
	std::ios_base::streampos end_pos = f.tellg();
	gets -1
	return end_pos;*/


}


int main(int argc, char* argv[]) {

	std::string lines{};
	std::ifstream myFile{ "test.txt" };


	if (!myFile) {
		std::cerr << "Can't open File\n";
		return 1;
	}




		//int byteCount = countNumberofBytes(myFile);
		//int lineCount = countNumberofLines(myFile);
		//int wordCount = countNumberOfWords(myFile);
		int charCount = countNumberOfCharacters(myFile);


		//std::cout << "Number of bytes: " << byteCount << std::endl;
		//std::cout << "Number of lines: " << lineCount << std::endl;
		//std::cout << "Number of words: " << wordCount << std::endl;
		std::cout << "Number of characters" << charCount << std::endl;
	
	
		//Bytes number 342190
		//lines number 7145
		//word number 58164

	myFile.close();

	return 0;
}

	


