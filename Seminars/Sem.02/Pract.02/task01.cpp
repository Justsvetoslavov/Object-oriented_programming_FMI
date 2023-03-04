#include <iostream>
#include <fstream>

int main(){
    int num1=0,num2=0,num3=0;
    std::cin>>num1>>num2>>num3;

    int sum=0,product =0;
    sum = num1+num2+num3;
    product = num1*num2*num3;


    std::ifstream file("results.txt",std::ios::app);

    file>>sum>>product;

    file.close();
    return 0;
}