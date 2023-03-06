#include <iostream>
#include <fstream>

const unsigned int BUFF_SIZE = 512;
const unsigned int MAX_NUM_OF_PROPERTIES = 50;

int loadSource(const char SOURCE_FILE_NAME[], char pairs[MAX_NUM_OF_PROPERTIES][BUFF_SIZE])
{
    std::ifstream readFile(SOURCE_FILE_NAME);

    if (!readFile.is_open())
    {
        return -1;
    }

    int idx = 0;

    while (!readFile.eof())
    {
        char line[BUFF_SIZE] = {'\0'};
        int i = 0;

        readFile.getline(line, BUFF_SIZE);

        while (line[i] != '\0')
        {
            pairs[idx][i] = line[i];
            ++i;
        }
        idx++;
    }

    readFile.close();
    return 0;
}

void fillPropertyValue(std::ofstream &file, const char property[], const char pairs[MAX_NUM_OF_PROPERTIES][BUFF_SIZE])
{
    for (int i = 0; i < MAX_NUM_OF_PROPERTIES; ++i)
    {
        int j = 0;
        while (pairs[i][j] == property[j])
        {
            ++j;
        }
        if (pairs[i][j] == ' ')
        {
            ++j;

            while (pairs[i][j] != '\0')
            {
                file << pairs[i][j];
                ++j;
            }
        }
    }
}

void parseLine(std::ofstream &file, const char line[], const char pairs[MAX_NUM_OF_PROPERTIES][BUFF_SIZE])
{
    char property[BUFF_SIZE] = {'\0'};

    int idx = 0;

    while (line[idx] != '\0' && idx < BUFF_SIZE)
    {
        if (line[idx] == '{')
        {
            ++idx;
            int i = 0;
            while (line[idx] != '}')
            {
                property[i] = line[idx];
                ++i;
                ++idx;
            }
            fillPropertyValue(file, property, pairs);
        }
        else
        {
            file << line[idx];
        }

        ++idx;
    }
}

int fillTemplate(const char TEMPLATE_FILE_NAME[], const char pairs[MAX_NUM_OF_PROPERTIES][BUFF_SIZE], const char OUTPUT_FILE_NAME[])
{
    std::ifstream readFile(TEMPLATE_FILE_NAME);
    std::ofstream writeNewFile(OUTPUT_FILE_NAME);

    if (!readFile.is_open() || !writeNewFile.is_open())
    {
        return -1;
    }

    while (!readFile.eof())
    {
        char line[BUFF_SIZE] = {'\0'};

        readFile.getline(line, BUFF_SIZE);
        parseLine(writeNewFile, line, pairs);
        writeNewFile << std::endl;
    }

    readFile.close();
    writeNewFile.close();

    return 0;
}

int main()
{

    const char TEMPLATE_FILE_NAME[] = "templateFile.txt";
    const char SOURCE_FILE_NAME[] = "sourceFile.txt";
    const char OUTPUT_FILE_NAME[] = "user1.txt";

    char pairs[MAX_NUM_OF_PROPERTIES][BUFF_SIZE] = {'\0'};

    if (loadSource(SOURCE_FILE_NAME, pairs) != 0)
    {
        return 1;
    };

    if (fillTemplate(TEMPLATE_FILE_NAME, pairs, OUTPUT_FILE_NAME) != 0)
    {
        return 1;
    };

    return 0;
}