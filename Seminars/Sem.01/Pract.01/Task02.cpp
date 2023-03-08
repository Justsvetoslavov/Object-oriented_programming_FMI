#include <iostream>
using std:: cin;
using std:: cout;

int main()
{
    unsigned int N;
    cout << "Number of numbers: ";
    cin >> N;
    int* arr = new int [N];
    cout << "Numbers: ";
    
    for(int i = 0; i<N; i++)
    {
        cin >> arr[i];
    }

    char symbol;
    cout << "Symbol: ";
    cin >> symbol;
    int br = 0;

    for(int i = 0; i< N; i++)
    {
        if(symbol<arr[i])
        {
            br++;
        }
    }

    delete[] arr;

    cout << "Numbers with bigger ASCII code: " << br << '\n';
}