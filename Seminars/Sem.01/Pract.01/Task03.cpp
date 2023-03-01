#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int** createMatrix(const int rows, const int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int** matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int** transposeMatrix(const int* const* matrix, const int rows, const int cols) {
    int** transposedMatrix = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    return transposedMatrix;
}

void printMatrix(const int* const* matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void free(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int N, M;
    cin >> N >> M;
    int** matrix = createMatrix(N, M);
    cout << "Enter the matrix: ";
    inputMatrix(matrix, N, M);
    int** transpostedMatrix = transposeMatrix(matrix, N, M);
    printMatrix(transpostedMatrix, M, N);
    free(matrix, N);
    free(transpostedMatrix, M);
}