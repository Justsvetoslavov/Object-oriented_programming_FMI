#include<iostream>
#include<fstream>



int lengOfFile(const char* fileName) {

	std::ifstream in("text.txt");
	if (!in.is_open())
	{
		return -1;
	}
	
	in.seekg(0, std::ios::end);
	int lenght = in.tellg();
	in.close();
	return lenght;
}



int main()
{

	std::cout << lengOfFile("text.txt");

	return 0;
}