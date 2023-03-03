#include <iostream>

void createMatrix(int**& matrix, int rows, int cols)
{
    matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}
void initializeMatrix(int**& matrix, int rows, int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void transposeMatrix(int** matrix, int**& matrixT, int rows, int cols)
{
    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            matrixT[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    int n, m;
    std::cout << "Enter size of matrix: ";
    std::cin >> n >> m;

    int** matrix;
    createMatrix(matrix, n, m);
    initializeMatrix(matrix, n, m);
    std::cout << "Start matrix:\n";
    printMatrix(matrix, n, m);
    std::cout << "\nTransposed matrix:\n";

    int** matrixT;
    createMatrix(matrixT, m, n);
    transposeMatrix(matrix, matrixT, n, m);
    printMatrix(matrixT, m, n);

    deleteMatrix(matrix, n);
    deleteMatrix(matrixT, m);

    return 0;
}