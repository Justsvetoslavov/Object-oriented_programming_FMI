#include <iostream>

void validationColsRows(int& x) {
    while (x <= 0) {
        std::cout << "Dimensions should be higher than zero!\nTry again: ";
        std::cin >> x;
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void fillMatrix(int**& matrix, int rows, int cols) {
    std::cout << "Input matrix elements.\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

int** transpose(int**& matrix, int rows, int cols) {
    int** transposedMatrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        transposedMatrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
}

void printMatrix(int**& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int**& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];

    delete[] matrix;
}

void task3() {
    int N, M;
    std::cout << "Input N: ";
    std::cin >> N;
    validationColsRows(N);
    std::cout << "Input M: ";
    std::cin >> M;
    validationColsRows(M);

    int** matrix = createMatrix(N, M);
    fillMatrix(matrix, N, M);

    int** transMatrix = transpose(matrix, M, N);
    printMatrix(transMatrix, M, N);

    freeMatrix(matrix, N, M);
    freeMatrix(transMatrix, M, N);
}

int main() {
    task3();
    return 0;
}