#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void inputMatrix(int** matrix, const int rows, const int columns) {
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            cout << "Enter a number: ";
            cin >> matrix[i][j];
        }
    }
}

int** transposeMatrix(int** matrix, const int rows, const int columns) {
    int** transposedMatrix = new int*[columns];

    for (int i = 0; i < columns; i++) {
        transposedMatrix[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    return transposedMatrix;
}

void printMatrix(int** matrix, const int rows, const int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {

    int n, m;

    cout << "Enter rows count: ";
    cin >> n;
    cout << "Enter columns count: ";
    cin >> m;

    int** matrix = new int*[n];

    inputMatrix(matrix, n, m);

    int** transposedMatrix = transposeMatrix(matrix, n, m);

    cout << "Original matrix: " << endl;
    printMatrix(matrix, n, m);

    cout << "Transposed matrix: " << endl;
    printMatrix(transposedMatrix, m, n);

    deleteMatrix(matrix, n);
    deleteMatrix(matrix, m);

    return 0;
}