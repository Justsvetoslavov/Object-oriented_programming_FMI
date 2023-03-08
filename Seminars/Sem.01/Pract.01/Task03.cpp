#include <iostream>
#include <iomanip>
using std:: cin;
using std:: cout;

int main()
{
    size_t N, M;
    cout << "N = ";
    cin >> N;
    cout << "M = ";
    cin >> M;
    int** matrix = new int*[N];
    
    for(int i = 0; i<N; ++i)
    {
        matrix[i] = new int[M];
    }

    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<M; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Original matrix: \n";

    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<M; ++j)
        {
            cout << matrix[i][j] << std::setw(3);
        }

        cout << '\n';
    }

    cout << "Transposed matrix:\n";

    for(int i = 0; i<M; ++i)
    {
        for(int j = 0; j<N; ++j)
        {
            cout << matrix[j][i] << std::setw(3);
        }
        cout << '\n';
    }

    delete[] matrix;

}