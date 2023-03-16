#include <iostream>
#include <fstream>

long linesCounter(std::ifstream& ifs){

    long counter =0;

    while (! ifs.eof()){

        char buff[256];
        ifs.getline(buff,256);
        counter++;
    }
    return counter;
}

int main(){

    return 0;
}