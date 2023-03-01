//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225
#include <iostream>

void inputMatrix(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}
void printMatrix(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}
int** transposeMatrix(int** matrix, int** transposedMatrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    return transposedMatrix;
}
void deleteMatrix(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int main()
{
    int rows;
    std::cout << "Enter the number of the rows: ";
    std::cin >> rows;
    int cols;
    std::cout << "Enter the number of the cols: ";
    std::cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    std::cout << "Enter the elements of the matrix: ";
    inputMatrix(matrix, rows, cols);
    std::cout << std::endl << "The original matrix is: " << std::endl;
    printMatrix(matrix, rows, cols);

    int** transposedMatrix = new int* [cols];
    for (int i = 0; i < cols; ++i)
    {
        transposedMatrix[i] = new int[rows];
    }
    transposedMatrix = transposeMatrix(matrix, transposedMatrix, rows, cols);
    std::cout << std::endl << "The transposed matrix is: " << std::endl;
    printMatrix(transposedMatrix, cols, rows);

    deleteMatrix(matrix, rows, cols);
    deleteMatrix(transposedMatrix, cols, rows);

    return 0;
}
