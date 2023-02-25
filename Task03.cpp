#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int** create_matrix(int size1, int size2) {
    int** matrix = new int*[size1];
    for (size_t i = 0; i < size1; i++)
        matrix[i] = new int[size2];
    return matrix;
}

void fill_matrix(int** matrix, int size1, int size2) {
    for (size_t i = 0; i < size1; i++)
        for (size_t j = 0; j < size2; j++)
            matrix[i][j] = i * size2 + j + 1;
}

int** transpon_matrix(int** matrix, int size1, int size2) {
    int** tran_matrix = create_matrix(size2, size1);
    for (size_t i = 0; i < size1; i++)
        for (size_t j = 0; j < size2; j++)
            tran_matrix[j][i] = matrix[i][j];
    return tran_matrix;
}

void delete_matrix(int** matrix, int size) {
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void read_matrix(int** matrix, int size1, int size2) {
    for (size_t i = 0; i < size1; i++) {
        for (size_t j = 0; j < size2; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int** matrix = create_matrix(n, m);
    fill_matrix(matrix, n, m);
    read_matrix(matrix, n, m);
    matrix = transpon_matrix(matrix, n, m);
    read_matrix(matrix, m, n);
    delete_matrix(matrix, m);
}