#include <iostream>
#include <fstream>

using namespace std;

const char* FILE_PATH = "C:\\Users\\grade\\Desktop\\result.txt";

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c,
        product = a * b * c;

    ofstream streamWriter(FILE_PATH);
    streamWriter << sum << '\n' << product;
    streamWriter.close();

    ifstream streamReader(FILE_PATH);

    streamReader >> sum >> product;
    streamReader.close();

    int diff = sum - product;

    cout << diff;

    return 0;
}
