#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char* valuesFile = "values.txt";
const char* placeholderFile = "placeholder.txt";
const char* resultsFile = "results.txt";

void getValuesFromFile(ifstream &file, char values[][1024]) {
    char type[1024];
    while (!file.eof()) {
        file >> type;
        file.ignore(1, ' ');
        if (strcmp(type, "title") == 0) {
            file.getline(values[0], 1024);
        } else if (strcmp(type, "recipient_name") == 0) {
            file.getline(values[1], 1024);
        } else if (strcmp(type, "message") == 0) {
            file.getline(values[2], 1024);
        } else if (strcmp(type, "sender_name") == 0) {
            file.getline(values[3], 1024);
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

void writeToFile(ifstream &placeholder, ofstream &result, const char values[][1024]) {
    char line[1024];
    while (!placeholder.eof()) {
        placeholder.getline(line, 1024);
        replaceWordInString(line, "{title}", values[0]);
        replaceWordInString(line, "{recipient_name}", values[1]);
        replaceWordInString(line, "{message}", values[2]);
        replaceWordInString(line, "{sender_name}", values[3]);
        result << line << endl;
    }
}

int main() {
    char values[4][1024];
    ifstream file(valuesFile);
    if (!file.is_open()) {
        cout << "Values is not open" << endl;
        return -1;
    }
    getValuesFromFile(file, values);
    file.close();

    ofstream result(resultsFile);
    if (!result.is_open()) {
        cout << "Results is not open" << endl;
        return -1;
    }
    
    ifstream placeholder(placeholderFile);
    if (!placeholder.is_open()) {
        cout << "Placeholder is not open" << endl;
        return -1;
    }
    
    writeToFile(placeholder, result, values);
    placeholder.close();
    result.close();
    
    return 0;
}
