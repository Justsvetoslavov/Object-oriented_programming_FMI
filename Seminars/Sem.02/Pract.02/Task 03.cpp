#include <iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;


const int Max_Size = 1024;
int char_array_length(const char* arr)
{
	int len = 0;
	while (arr[len] != '\0' && len < Max_Size)
	{
		len++;
	}
	return len;
}

void replace(char* line, const char* placeholder, const char* value) {
	int placeholder_length = char_array_length(placeholder);
	int value_length = char_array_length(value);
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == placeholder[0]) {
			bool match_found = true;
			for (int j = 0; j < placeholder_length; j++) {
				if (line[i + j] != placeholder[j]) {
					match_found = false;
					break;
				}
			}
			if (match_found) {
				// Did this in order to shift the remaining characters to the right
				for (int k = char_array_length(line); k >= i + placeholder_length; k--) {
					line[k + value_length - placeholder_length] = line[k];
				}
				
				for (int k = 0; k < value_length; k++) {
					line[i + k] = value[k];
				}
				
				i += value_length - placeholder_length;
			}
		}
	}
}


void fromOneFileToAnother(const char *name1,const char*name2, const char* title, const char* recipient_name, const char* message, const char* sender_name) {

	std::ifstream inputfile(name1);
	if (!inputfile.is_open())
	{
		cout << "ERROR!";

		return;
	}


	std::ofstream outputfile(name2);
	if (!outputfile.is_open())
	{
		cout << "ERROR!";

		return;
	}
	char line[Max_Size];
	while (inputfile.getline(line, Max_Size)) {
		replace(line, "{title}", title);
		replace(line, "{recipient_name}", recipient_name);
		replace(line, "{message}", message);
		replace(line, "{sender_name}", sender_name);
		outputfile << line << endl;

	}
	inputfile.close();
	outputfile.close();

	cout << "Done!" << endl;


}
int main() {
	const char* input_file_name = "input.txt";
	const char* output_file_name = "output.txt";
	const char* title = "Veliki";
	const char* recipient_name = "Pop Armeniya";
	const char* message = "Iskam da se oplacha!!!";
	const char* sender_name = "FMI-student";

	fromOneFileToAnother(input_file_name, output_file_name, title, recipient_name, message, sender_name);


}







