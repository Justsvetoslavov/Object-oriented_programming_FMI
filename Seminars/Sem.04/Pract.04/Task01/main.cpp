#include <iostream>
#include <fstream>
#include "teacher.hpp"

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;

const char *FILE_NAME = "teacher.txt";

int main() {

    Teacher teacher("Ivan", 30, 10);
    ofstream out(FILE_NAME, std::ios::binary);
    out.write((char *) &teacher, sizeof(Teacher));
    out.close();

    Teacher teacher2;
    ifstream in(FILE_NAME, std::ios::binary);
    in.read((char *) &teacher2, sizeof(Teacher));
    in.close();

    cout << teacher2.getName() << endl;
    cout << teacher2.getAge() << endl;
    cout << teacher2.getWorkYears() << endl;

    return 0;
}
