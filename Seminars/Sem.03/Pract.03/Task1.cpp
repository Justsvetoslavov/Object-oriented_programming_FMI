#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream, std::ios;

const int MAX_GROUP_SIZE = 1024;
const int NAME_LENGTH = 16;
const int NUMBER_LENGTH = 5;
const char* FILE_NAME = "data.csv";

enum HairColor {
    BROWN, 
    BLACK, 
    BLONDE, 
    RED, 
    WHITE, 
    OTHER
};

struct Student {
    char firstName[NAME_LENGTH + 1];
    char secondName[NAME_LENGTH + 1];
    char facultyNumber[NUMBER_LENGTH + 1];
    double grade;
    HairColor hairColor;

    char* getHairColor() {
        switch (hairColor) {
            case 0: 
              return "BROWN";
            case 1: 
              return "BLACK";
            case 2:
              return "BLONDE";
            case 3:
              return "RED";
            case 4: 
              return "WHITE";
        }
        return "OTHER";
    }
};

struct Group {
    Student students[MAX_GROUP_SIZE];
    int size = 0;

    void addStudent(Student& student) {
        students[size++] = student;
    }

    void printGroup() {
        cout << "Group: " << endl;
        for (int i = 0; i < size; i++) {
            Student current = students[i];
            cout << current.firstName << " " << current.secondName << " " << current.facultyNumber << " " << current.grade << " " << current.getHairColor() << endl;
        }
    }
};

bool areEquals(char* str1, char* str2) {
    if (*str1 == '\0' && *str2 == '\0') {
        return true;
    } else if (*str1 != *str2) {
        return false;
    } else {
        return areEquals(++str1, ++str2);
    }
}

HairColor stringToColor(char* str) {
    if (areEquals(str, "BROWN")) {
        return BROWN;
    } else if (areEquals(str, "BLACK")) {
        return BLACK;
    } else if (areEquals(str, "BLONDE")) {
        return BLONDE;
    } else if (areEquals(str, "RED")) {
        return RED;
    } else if (areEquals(str, "WHITE")) {
        return WHITE;
    }

    return OTHER;
}

void saveGroupToFile(ofstream& file, Group& group) {
    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    for (int i = 0; i < group.size; i++) {
        Student current = group.students[i];

        if (i != 0) {
            file << endl;
        }
        
        file << current.firstName << "," << current.secondName << "," << current.facultyNumber << "," 
             << current.grade << "," << current.getHairColor();
    }
}

void readGroupFromFile(ifstream& file, Group& group) {
    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    while (!file.eof()) {
        char hair[7];

        Student student;
        file.getline(student.firstName, 1024, ',');
        file.getline(student.secondName, 1024, ',');
        file.getline(student.facultyNumber, 1024, ',');
        file >> student.grade;
        file.getline(hair, 2, ',');
        file.getline(hair, 7, '\n');

        student.hairColor = stringToColor(hair);

        group.addStudent(student);
    }
}
 
int main() {

    Student s1 = {"First", "F", "11111", 5.2, BLACK};
    Student s2 = {"Second", "S", "22222", 5.5, BLONDE};
    Student s3 = {"Third", "T", "33333", 4.7, BLONDE};

    Group group;
    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);

    ofstream fileO(FILE_NAME, ios::app);
    
    saveGroupToFile(fileO, group);
    
    fileO.close();

    Group group2;

    ifstream fileI(FILE_NAME);

    readGroupFromFile(fileI, group2);

    fileI.close();

    group2.printGroup();

    return 0;
}