#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char* VALUES_FILE = "../values.txt";
const char* PLACEHOLDER_FILE = "../placeholder.txt";
const char* RESULTS_FILE = "../results.txt";

const int max_line_length = 1024;
const int values_count = 4;

void getValuesFromFile(ifstream &valuesFile, char values[][max_line_length]) {
    char type[max_line_length];
    while (!valuesFile.eof()) {
        valuesFile >> type;
        valuesFile.ignore(1, ' ');
        if (strcmp(type, "title") == 0) {
            valuesFile.getline(values[0], max_line_length);
        } else if (strcmp(type, "recipient_name") == 0) {
            valuesFile.getline(values[1], max_line_length);
        } else if (strcmp(type, "message") == 0) {
            valuesFile.getline(values[2], max_line_length);
        } else if (strcmp(type, "sender_name") == 0) {
            valuesFile.getline(values[3], max_line_length);
        } else {
            cout << "Unknown type: " << type << endl;
            cout << "Please check the file" << endl;
        }
    }
}

void replaceWordInString(char *line, const char *word, const char *value) {
    char *pos = strstr(line, word);
    if (pos != NULL) {
        int index = pos - line;
        int length = strlen(line);
        int wordLength = strlen(word);
        int valueLength = strlen(value);
        int newLength = length - wordLength + valueLength;
        char *newLine = new char[newLength + 1];
        for (int i = 0; i < index; i++) {
            newLine[i] = line[i];
        }
        for (int i = 0; i < valueLength; i++) {
            newLine[index + i] = value[i];
        }
        for (int i = index + wordLength; i < length; i++) {
            newLine[i - wordLength + valueLength] = line[i];
        }
        newLine[newLength] = '\0';
        strcpy(line, newLine);
        delete[] newLine;
    }
}

void writeToFile(ifstream &placeholderFile, ofstream &resultsFile, const char values[][max_line_length]) {
    char line[max_line_length];
    while (!placeholderFile.eof()) {
        placeholderFile.getline(line, max_line_length);
        replaceWordInString(line, "{title}", values[0]);
        replaceWordInString(line, "{recipient_name}", values[1]);
        replaceWordInString(line, "{message}", values[2]);
        replaceWordInString(line, "{sender_name}", values[3]);
        resultsFile << line << endl;
    }
}

int main() {
    char values[values_count][max_line_length];
    ifstream valuesFile(VALUES_FILE);
    if (!valuesFile.is_open()) {
        cout << "Values is not open" << endl;
        return -1;
    }
    getValuesFromFile(valuesFile, values);
    valuesFile.close();

    ofstream resultsFile(RESULTS_FILE);
    if (!resultsFile.is_open()) {
        cout << "Results is not open" << endl;
        return -1;
    }

    ifstream placeholderFile(PLACEHOLDER_FILE);
    if (!placeholderFile.is_open()) {
        cout << "Placeholder is not open" << endl;
        return -1;
    }

    writeToFile(placeholderFile, resultsFile, values);

    placeholderFile.close();
    resultsFile.close();

    return 0;
}
