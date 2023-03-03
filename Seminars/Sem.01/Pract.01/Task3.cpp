#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void inputMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter a number: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int** matrix, int** transposedMatrix, int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

void printMatrix(int** matrix, int rows, int columns) {
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

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    inputMatrix(matrix, n, m);

    int** transposedMatrix = new int*[m];

    for (int i = 0; i < m; i++) {
        transposedMatrix[i] = new int[n];
    }

    transposeMatrix(matrix, transposedMatrix, n, m);



    cout << "Original matrix: " << endl;
    printMatrix(matrix, n, m);

    cout << "Transposed matrix: " << endl;
    printMatrix(transposedMatrix, m, n);

    deleteMatrix(matrix, n);
    deleteMatrix(transposedMatrix, m);

    return 0;
}