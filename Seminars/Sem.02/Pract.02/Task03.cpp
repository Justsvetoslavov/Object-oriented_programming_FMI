#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 256;
char ifpath[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\inFile.txt";
char ofpath[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\outFile.txt";

void createReport(void)
{
	ifstream streamReader(ifpath);
	ofstream streamWriter(ofpath);

	char temp, elements[4][MAX_SIZE];

	for (short i = 0, index = 0; i < 4; ++i)
		streamReader.getline(elements[i], 256);

	streamWriter << "Dear, " << elements[0] << " " << elements[1] << ".\n" << '\n' << elements[2] << '\n' << '\n' << "Sincirely,\n" << elements[3];

	streamReader.close();
	streamWriter.close();
}

int main()
{
	createReport();

	return 0;
}
