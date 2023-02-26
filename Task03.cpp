#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int** create_matrix(int row, int col) {
    int** matrix = new int*[row];
    for (size_t i = 0; i < row; i++)
        matrix[i] = new int[col];
    return matrix;
}

void fill_matrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> matrix[i][j];
}

int** transpon_matrix(const int* const* matrix, int row, int col) {
    int** tran_matrix = create_matrix(col, row);
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            tran_matrix[j][i] = matrix[i][j];
    return tran_matrix;
}

void delete_matrix(int** matrix, int row) {
    for (size_t i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void read_matrix(const int* const* matrix, int row, int col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int **matrix = create_matrix(n, m);
    fill_matrix(matrix, n ,m);
    read_matrix(matrix, n, m);
    matrix = transpon_matrix(matrix, n, m);
    read_matrix(matrix, m, n);
    delete_matrix(matrix, m);
}
