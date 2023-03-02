#include <iostream>
#include <fstream>
#include <cassert>

const int MAX_TITLE_SIZE = 50;
const int MAX_NAME_SIZE = 60;
const int MAX_TEXT_SIZE = 1000;
const char PATH[] = "result_message.txt";

struct Info{
    char title[MAX_TITLE_SIZE];
    char recipient_name[MAX_NAME_SIZE];
    char message[MAX_TEXT_SIZE];
    char sender_name[MAX_NAME_SIZE];
};

Info get_info_from_file(const char path[]) {
    std::fstream file(path, std::ios::in);
    assert(file.is_open());
    Info res{};
    char rotator;
    int line = 0;
    while (file >> std::noskipws >> rotator) {
        if (rotator == ' ') {
            switch (line) {
                case 0:
                    file.getline(res.title, MAX_TITLE_SIZE);
                    break;
                case 1:
                    file.getline(res.recipient_name, MAX_NAME_SIZE);
                    break;
                case 2:
                    file.getline(res.message, MAX_TEXT_SIZE);
                    break;
                case 3:
                    file.getline(res.sender_name, MAX_NAME_SIZE);
                    break;
                default:
                    break;
            }
            line++;
        }
    }
    file.close();
    return res;
}

void put_words(const char path[], const Info& info) {
    std::fstream file(path, std::ios::in);
    assert(file.is_open());
    std::fstream new_file(PATH, std::ios::out);
    char rotator;
    int time = 0;
    while (file >> std::noskipws >> rotator) {
        if (rotator == '{') {
            switch (time) {
                case 0:
                    new_file << info.title;
                    break;
                case 1:
                    new_file << info.recipient_name;
                    break;
                case 2:
                    new_file << info.message;
                    break;
                case 3:
                    new_file << info.sender_name;
                    break;
                default:
                    break;
            }
            time++;
            while (file >> rotator)
                if (rotator == '}')
                    break;
            continue;
        }
        new_file << rotator;
    }
    file.close();
    new_file.close();
}

int main() {
    put_words("example1.1.txt", get_info_from_file("example1.txt"));
}
