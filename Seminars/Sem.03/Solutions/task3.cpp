#include <iostream>
#include <fstream>

void replaceInFile(char ch, char ch2, fstream& file) {
	char currentSymbol;
	while (!file.eof())
	{
		char currentSymbol = file.get();
		if (currentSybmol != ch) {
			continue;
		}
		file.seekp(-1, std::ios::cur);
		file.put(ch2);
		file.flush();
	}
}

int main()
{
	std::fstream file("treasureTrail.txt", std::ios::in | std::ios::out);
	
	if(!file.is_open()) {
		std::cout << "Error while opening the file!" << std::endl;
		return 1;
	}
	
	replaceInFile('a', 'X', file);
	return 0;
}
