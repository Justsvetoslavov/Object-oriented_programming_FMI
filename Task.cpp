#include <iostream>
#include <fstream>
#include <sstream>

const int MAX_SIZE_CHAR = 128;
const int BUFF_SIZE = 1028;

enum class Category {
    OKN,
    M,
    PM,
    PR,
    Other
};

enum class TypeExam {
    Exam,
    CourseProject,
    Test
};

struct Discipline {
    int id = 0;
    char name[MAX_SIZE_CHAR] = "";
    Category category {(Category)4};
    int numCredits = 0;
    TypeExam type{(TypeExam)0};
};

struct System {
    int size;
    Discipline *disciplines;
    ~System() {
        delete[] disciplines;
    }
};

int sizeSystem(std::fstream &file) {
    size_t currPos = file.tellg();
    file.seekg(std::ios::beg);
    char buff[BUFF_SIZE];
    int res = 0;
    while (!file.eof()) {
        file.getline(buff, BUFF_SIZE);
        res++;
    }
    file.clear();
    file.seekg(currPos);
    return res - 1;
}

System initSys(const int size) {
    System res{size};
    res.disciplines = new Discipline[size];
    return res;
}

void replace(char text[]) {
    int i = -1;
    while (text[++i]) {
        if (text[i] == ',')
            text[i] = ' ';
    }
}

Discipline readRow(char row[]) {
    Discipline res;
    replace(row);
    int enum_int;
    std::stringstream ss(row);
    ss >> res.id;
    ss >> res.name;
    ss >> enum_int;
    res.category = (Category)enum_int;
    ss >> res.numCredits;
    ss >> enum_int;
    res.type = (TypeExam)enum_int;
    return res;
}

bool strEqual(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] && str2[i]) {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    if (i == 0 || str1[i] || str2[i])
        return false;
    return true;
}

int sizeChar(const char text[]) {
    int res = -1;
    while(text[++res]);
    return res;
}

bool checkFileType(const char path[]) {
    int sizePath = sizeChar(path);
    if (path[sizePath - 1] == 'v' && path[sizePath - 2] == 's' && path[sizePath - 3] == 'c' && path[sizePath - 4] == '.')  {
        return true;
    }
    return false;
}

bool checkFile(std::fstream& file, const char path[]) {
    size_t curr_pos = file.tellg();
    file.seekg(0, std::ios::beg);
    char checker[MAX_SIZE_CHAR + 1];
    if (checkFileType(path)) {
        file.getline(checker, MAX_SIZE_CHAR, ',');
        if (strEqual(checker, "ID")) {
            file.getline(checker, MAX_SIZE_CHAR, ',');
            if (strEqual(checker, "Name")) {
                file.getline(checker, MAX_SIZE_CHAR, ',');
                if (strEqual(checker, "Category")) {
                    file.getline(checker, MAX_SIZE_CHAR, ',');
                    if (strEqual(checker, "Credits")) {
                        file.getline(checker, MAX_SIZE_CHAR);
                        if (strEqual(checker, "Type")) {
                            file.clear();
                            file.seekg(curr_pos);
                            return true;
                        }
                    }
                }
            }
        }
    }
    file.clear();
    file.seekg(curr_pos);
    return false;
}

System readSysFromFile(std::fstream &file) {
    size_t currPos = file.tellg();
    file.seekg(std::ios::beg);
    System res = initSys(sizeSystem(file));
    char buff[BUFF_SIZE];
    int pos = 0;
    file.getline(buff, BUFF_SIZE);
    while (!file.eof()) {
        file.getline(buff, BUFF_SIZE);
        res.disciplines[pos++] = readRow(buff);
    }
    file.clear();
    file.seekg(currPos);
    return res;
}

void writeDiscipline(std::fstream &file, const Discipline &discipline) {
    file << std::endl << discipline.id << ','
         << discipline.name << ','
         << (int) discipline.category << ','
         << discipline.numCredits << ','
         << (int) discipline.type;
}

void writeSystemToFile(std::fstream &file, const System &sys, const int mode = 0, const int delete_id = 0) {
    file << "ID,Name,Category,Credits,Type";
    if (mode == 0)
        for (int i = 0; i < sys.size; ++i)
            writeDiscipline(file, sys.disciplines[i]);
    else
        for (int i = 0; i < sys.size; ++i) {
            if (sys.disciplines[i].id == delete_id)
                continue;
            writeDiscipline(file, sys.disciplines[i]);
        }
}

int is_existId(const int id, const System &system) {
    for (int i = 0; i < system.size; ++i)
        if (id == system.disciplines[i].id)
            return i;
    return -1;
}

void editDiscipline(Discipline &discipline) {
    int ans;
    std::cout << "It's ID exist\n";
    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::cin.getline(discipline.name, MAX_SIZE_CHAR);
    std::cout << "Enter new category: ";
    std::cin >> ans;
    discipline.category = (Category)ans;
    std::cout << "Enter new number of credits: ";
    std::cin >> discipline.numCredits;
    std::cout << "Enter new type of exam: ";
    std::cin >> ans;
    discipline.type = (TypeExam)ans;
}

void addNewDisciplene(std::fstream &file) {
    file.seekp(std::ios::end);
    int ans;
    char answer[MAX_SIZE_CHAR + 1];
    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::cin.getline(answer, MAX_SIZE_CHAR);
    file << ',' << answer;
    std::cout << "Enter category: ";
    std::cin >> ans;
    file << ',' << ans;
    std::cout << "Enter number of credits: ";
    std::cin >> ans;
    file << ',' << ans;
    std::cout << "Enter type of exam: ";
    std::cin >> ans;
    file << ',' << ans;
}

int addDiscipline(System &system, std::fstream &file) {
    int id, pos;
    std::cout << "Enter ID\n\\> ";
    std::cin >> id;
    pos = is_existId(id, system);
    if (pos != -1) {
        editDiscipline(system.disciplines[pos]);
        return 1;
    }
    else {
        file << std::endl << id;
        addNewDisciplene(file);
        return 2;
    }
}

char* categoryToChar(const Category category) {
    switch (category) {
        case Category::M:
            return "M";
            break;
        case Category::OKN:
            return "OKN";
            break;
        case Category::PM:
            return "PM";
            break;
        case Category::PR:
            return "PR";
            break;
        case Category::Other:
            return "Other";
            break;
    }
}

char* typeToChar(const TypeExam type) {
    switch (type) {
        case TypeExam::CourseProject:
            return "Course Project";
            break;
        case TypeExam::Exam:
            return "Exam";
            break;
        case TypeExam::Test:
            return "Test";
            break;
    }
}

void readDiscipline(const Discipline &discipline) {
    std::cout << "ID: " << discipline.id << std::endl;
    std::cout << "Name: " << discipline.name << std::endl;
    std::cout << "Category: " << categoryToChar(discipline.category) << std::endl;
    std::cout << "Credits: " << discipline.numCredits << std::endl;
    std::cout << "Type: " << typeToChar(discipline.type) << std::endl;
}

void readById(const System &system, const int id) {
    int pos = is_existId(id, system);
    if (pos == -1)
        std::cout << "Error" << std::endl;
    else
        readDiscipline(system.disciplines[pos]);
}

void readByCategory(const System &system, const Category category) {
    for (int i = 0; i < system.size; ++i)
        if (system.disciplines[i].category == category)
            readDiscipline(system.disciplines[i]);
}

void readByCredits(const System &system, const int max, const int min) {
    for (int i = 0; i < system.size; ++i)
        if (system.disciplines[i].numCredits >= min && system.disciplines[i].numCredits <= max)
            readDiscipline(system.disciplines[i]);
}

int main () {
    char path[MAX_SIZE_CHAR + 1], anotherPath[MAX_SIZE_CHAR + 1];
    std::cout << "Hi, please enter database path: ";
    std::cin.getline(path, MAX_SIZE_CHAR);
    std::fstream file(path, std::ios::in), anotherFile;
    if (!checkFile(file, path)) {
        std::cout << "Error";
        return 0;
    }
    std::cout << "Path accepted\n";
    file.close();
    int ans, mode, id, category, max, min;
    while (true) {
        std::cout << "What do yoy want do?\n"
         << "1. Save data to anther CSV-file\n"
         << "2. Get data from CSV-file\n"
         << "3. Add discipline\n"
         << "4. Delete discipline\n"
         << "5. Read discipline by id\n"
         << "6. Read disciplines by category\n"
         << "7. Read disciplines by credits\n"
         << "8. Exit\n";
        std::cin >> ans;
        std::cin.ignore();
        if (ans == 1) {
            std::cout << "Enter path for another CSV-file: ";
            std::cin.getline(anotherPath, MAX_SIZE_CHAR);
            if (!checkFileType(anotherPath))
                std::cout << "Error\n";
            else {
                anotherFile.open(anotherPath, std::ios::out);
                file.open(path, std::ios::in);
                writeSystemToFile(anotherFile, readSysFromFile(file));
                file.close();
                anotherFile.close();
            }
        }
        else if (ans == 2) {
            std::cout << "Enter path for another CSV-file: ";
            std::cin.getline(anotherPath, MAX_SIZE_CHAR);
            anotherFile.open(anotherPath, std::ios::in);
            if (!checkFile(anotherFile, anotherPath))
                std::cout << "Error\n";
            else {
                file.open(path, std::ios::out);
                writeSystemToFile(file, readSysFromFile(anotherFile));
                file.close();
            }
            anotherFile.close();
        }
        else if (ans == 3) {
            file.open(path, std::ios::in | std::ios::out | std::ios::app);
            System system = readSysFromFile(file);
            mode = addDiscipline(system, file);
            file.close();
            if (mode == 1) {
                file.open(path, std::ios::out);
                writeSystemToFile(file, system);
                file.close();
            }
        }
        else if (ans == 4) {
            std::cout << "Enter ID: ";
            std::cin >> id;
            file.open(path, std::ios::in);
            System system = readSysFromFile(file);
            file.close();
            file.open(path, std::ios::out);
            writeSystemToFile(file, system, 1, id);
            file.close();
        }
        else if (ans == 5) {
            std::cout << "Enter ID: ";
            std::cin >> id;
            file.open(path, std::ios::in);
            readById(readSysFromFile(file), id);
            file.close();
        }
        else if (ans == 6) {
            std::cout << "Enter category: ";
            std::cin >> category;
            file.open(path, std::ios::in);
            readByCategory(readSysFromFile(file), (Category) category);
            file.close();
        }
        else if (ans == 7) {
            std::cout << "Enter min credits: ";
            std::cin >> min;
            std::cout << "Enter max credits: ";
            std::cin >> max;
            file.open(path, std::ios::in);
            readByCredits(readSysFromFile(file), max, min);
            file.close();
        }
        else if (ans == 8)
            break;
    }
}