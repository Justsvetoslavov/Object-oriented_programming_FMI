#include <iostream>
#include <fstream>

const unsigned int MAX_SIZE_ELEMENTS = 25;

struct Pair
{
    int a = 0;
    int b = 0;
};

struct Relation
{
    int size = 0;
    Pair elements[MAX_SIZE_ELEMENTS];
};

void initPair(Pair &pair)
{
    std::cout << "Initialize pair (a, b): ";
    std::cin >> pair.a >> pair.b;
    std::cout << std::endl;
}

void addPairToRelation(const Pair &pair, Relation &relation)
{
    if (relation.size > MAX_SIZE_ELEMENTS - 1)
    {
        return;
    }

    relation.elements[relation.size++] = pair;
}

int writeRelationToFile(const char FILE_NAME[], const Relation &relation, const char DELIM, const char RELATION_NAME[])
{
    std::ofstream readFile(FILE_NAME);

    if (!readFile.is_open())
    {
        return 1;
    }

    readFile << RELATION_NAME << std::endl;

    for (int i = 0; i < relation.size; ++i)
    {
        readFile << relation.elements[i].a << DELIM << relation.elements[i].b << std::endl;
    }

    readFile.close();

    return 0;
}

bool compStr(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        ++i;
    }
    return true;
}

Pair parseLine(const char line[], const char DELIM, const unsigned int BUFFER_SIZE)
{
    Pair pair;

    int idx = 0;

    while (line[idx] != DELIM && idx < BUFFER_SIZE)
    {
        pair.a = 10 * (int)pair.a + line[idx] - '0';
        ++idx;
    }

    ++idx;

    while (line[idx] != '\0')
    {
        pair.b = 10 * (int)pair.b + line[idx] - '0';
        ++idx;
    }

    return pair;
}

Relation readRelationFromFile(const char FILE_NAME[], const unsigned int BUFFER_SIZE, const char RELATION_NAME[], const char DELIM)
{
    Relation relation;

    std::ifstream readFile(FILE_NAME);

    if (!readFile.is_open())
    {
        return {0, {'\0'}};
    }

    int idx = 0;

    bool readingPairs = false;

    while (!readFile.eof())
    {

        char line[BUFFER_SIZE] = {'\0'};

        readFile.getline(line, BUFFER_SIZE);

        if (compStr(line, RELATION_NAME) && !readingPairs)
        {
            readingPairs = true;
            continue;
        }

        // This check ensures that if the file has multiple Relations in it, we stop reading when we encounter another one.
        // Currently we store only one Relation in the file, so this check is not necessary
        if (compStr(line, RELATION_NAME) && readingPairs)
        {
            break;
        }

        relation.elements[relation.size++] = parseLine(line, DELIM, BUFFER_SIZE);
    }
    readFile.close();
    return relation;
}

int main()
{

    const char FILE_NAME[] = "relation.txt";
    const unsigned int BUFFER_SIZE = 512;
    const char DELIM = '|';
    const char RELATION_NAME[] = "Relation";

    Pair pair1;
    Pair pair2;

    Relation relation;

    initPair(pair1);
    initPair(pair2);

    addPairToRelation(pair1, relation);
    addPairToRelation(pair2, relation);

    if (writeRelationToFile(FILE_NAME, relation, DELIM, RELATION_NAME) != 0)
    {
        return 1;
    };

    Relation fileRelation;
    fileRelation = readRelationFromFile(FILE_NAME, BUFFER_SIZE, RELATION_NAME, DELIM);

    return 0;
}

/* sample input:
 16 32
 72 423

*/