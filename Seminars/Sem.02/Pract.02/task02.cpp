#include <iostream>
#include <fstream>

int lengthOfChar(const char* arr){

    int length =0;
    while (arr[length]!= '\0'){
        length++;
    }
    return length;
}

long lengthOfFile(const char*name){

    std::ifstream inputStream(name);
    long length=0;
    for(int i=0;!inputStream.eof();i++){
        char arr[1024];
        inputStream.getline(arr,1024);
        length+= lengthOfChar(arr);
    }
    return  length;

}
int main(){

    std::cout<< lengthOfChar("test.txt");

    return 0;
}