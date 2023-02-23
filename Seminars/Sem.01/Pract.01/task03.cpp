#include <iostream>

using namespace std;

int **createMatrix(const int rows, const int cols) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int **matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter the element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

int **transposeMatrix(int **matrix, const int rows, const int cols) {
    int **transposedMatrix = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    return transposedMatrix;
}

void printMatrix(int **matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int **matrix, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    int **matrix = createMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);
    
    cout << "The matrix is:" << endl;
    printMatrix(matrix, rows, cols);
    
    int **transposedMatrix = transposeMatrix(matrix, rows, cols);
    cout << "The transposed matrix is:" << endl;
    printMatrix(transposedMatrix, cols, rows);
    
    deleteMatrix(matrix, rows);
    deleteMatrix(transposedMatrix, cols);
    return 0;
}
