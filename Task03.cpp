#include <iostream>
#include <fstream>
#include <cassert>

const int MAX_SIZE_STR = 1024;
const char PATH_WORDS[] = "words.txt";
const char PATH_RESULT[] = "result.txt";
const char PATH_PATTERN[] = "pattern.txt";

struct PlaceHolder {
    char key[MAX_SIZE_STR];
    char text[MAX_SIZE_STR];
};

PlaceHolder getPlaceHolder(std::fstream &file) {
    PlaceHolder placeHolder;
    file.getline(placeHolder.key, MAX_SIZE_STR, ' ');
    file.getline(placeHolder.text, MAX_SIZE_STR);
    return placeHolder;
}

int sizePlaceHolders(std::fstream &file) {
    char buff[MAX_SIZE_STR * 2];
    int res = 0;
    size_t curr_pos = file.tellg();
    file.seekg(std::ios::beg);
    while (!file.eof()) {
        file.getline(buff, MAX_SIZE_STR * 2);
        res++;
    }
    file.seekg(curr_pos);
    file.clear();
    return res;
}

PlaceHolder* getArrayPlaceHolder(std::fstream &file, const int size) {
    PlaceHolder* arr = new PlaceHolder[size];
    int pos = 0;
    while (!file.eof()) {
        arr[pos++] = getPlaceHolder(file);
    }
    file.seekg(std::ios::beg);
    file.clear();
    return arr;
}

bool strEqueal(const char text1[], const char text2[]) {
    int i = 0;
    while (text1[i] || text2[i]) {
        if (text1[i] != text2[i])
            return false;
        i++;
    }
    return true;
}

void put_words(std::fstream &file, const PlaceHolder arr[], const int size_arr) {
    std::fstream nFile(PATH_RESULT, std::ios::out);
    char reader;
    char buff[MAX_SIZE_STR];
    while (file.get(reader)) {
        if (reader == '{') {
            file.getline(buff, MAX_SIZE_STR, '}');
            for (int i = 0; i < size_arr; ++i)
                if (strEqueal(buff, arr[i].key))
                    nFile << arr[i].text;
            continue;
        }
        nFile << reader;
    }
    nFile.close();
}

int main() {
    std::fstream file(PATH_WORDS, std::ios::in);
    int size = sizePlaceHolders(file);
    PlaceHolder *placeHolders = getArrayPlaceHolder(file, size);
    file.close();
    file.open(PATH_PATTERN, std::ios::in);
    put_words(file, placeHolders, size);
    file.close();
}
