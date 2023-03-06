#include <iostream>
#include <fstream>

namespace PATHS {

    const char MESSAGE_PATH[] =
            "C:\\Users\\nikol\\Documents\\"
            "GitHub\\Object-oriented_programming_FMI_2023\\"
            "Seminars\\Sem.02\\Pract.02\\"
            "message.txt";

    const char PLACEHOLDERS_PATH[] =
            "C:\\Users\\nikol\\Documents\\"
            "GitHub\\Object-oriented_programming_FMI_2023\\"
            "Seminars\\Sem.02\\Pract.02\\"
            "placeholders.txt";

    const char MESSAGE_RESULT_PATH[] =
            "C:\\Users\\nikol\\Documents\\"
            "GitHub\\Object-oriented_programming_FMI_2023\\"
            "Seminars\\Sem.02\\Pract.02\\"
            "message_result.txt";

}

using namespace PATHS;

char* shiftLeft(char str[],const int size){

    for(int i = 0; i < size;i++){
        str[i] = str[i+1];
    }
    return str;
}
char* getActualTextByPlaceholder(const char* placeholder,std::ifstream& placeholders){

    char line[255];
    char* actualText = new char[16];

    bool flag= false;
    int c = 0;

    while(placeholders.getline(line, sizeof line,'\n')){

        for(int i = 0;line[i] != '\0';i++){

            if(line[i] == ' ')flag = true;

            if(flag){
                actualText[c++] = line[i];
            }
            else if(line[i] != placeholder[i])break;

        }

        if(flag){
            actualText[c] = '\0';
            actualText = shiftLeft(actualText,c);
            return actualText;
        }

    }

    return actualText;
}
bool replacePlaceholders(std::ifstream& message, std::ofstream& message_result,std::ifstream& placeholders){

    char line[255];
    char* placeholder = new char[16];
    int c = 0;
    bool flag = false;


    while(message.getline(line, sizeof line,'\n')){

        for(int i = 0 ; line[i] != '\0' ; i++){

            if(line[i] == '{') flag = true;

            if(flag)
                placeholder[c++] = line[i];
            else
                message_result << line[i];

            if(line[i] == '}'){

                placeholder[c-1] = '\0';
                placeholder = shiftLeft(placeholder,c);
                message_result<<getActualTextByPlaceholder(placeholder,placeholders);

                c = 0;
                flag = false;
            }
        }

        if(!message.eof())message_result<<'\n';
    }

    message.close();
    placeholders.close();
    message_result.close();

    return true;

}

int main(){

    std::ifstream message(MESSAGE_PATH);
    std::ifstream placeholders(PLACEHOLDERS_PATH);
    std::ofstream message_result (MESSAGE_RESULT_PATH,std::ios::trunc);

    message_result.close();
    message_result.open(MESSAGE_RESULT_PATH,std::ios::app);

    //
    replacePlaceholders(message,message_result,placeholders);
    //

    return 0;
}




