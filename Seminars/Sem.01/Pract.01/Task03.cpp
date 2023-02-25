#include <iostream>
int**  createMatrix(size_t row, size_t col);
void inputArr(int** arr, size_t row, size_t col);
void printArr(int** arr, size_t row, size_t col);
int** transponeMatrix(int** arr, size_t row, size_t col);
void freeMemory(int** arr, size_t row);
int main()
{
    int row, col;
    std::cin >> row >> col;
    int** matrix = createMatrix(row, col);
    inputArr(matrix, row, col);
    int** transponedMatrix = transponeMatrix(matrix, row, col);
    printArr(transponedMatrix, col, row);
    freeMemory(matrix, row);
    freeMemory(transponedMatrix, col);

    return 0;
}

int** createMatrix(size_t row, size_t col)
{
    int** matrix = new int*[row];
    for (size_t i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }
    return matrix;
}

void inputArr(int** arr, size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            std::cin >> arr[i][j];
        }
    }   
}

void printArr(int** arr, size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            std::cout << arr[i][j] << " ";
        } 
    }
}

int** transponeMatrix(int** arr, size_t row, size_t col)
{
    int** transponedMatrix = createMatrix(col, row);
    for(size_t i = 0; i < col; i++)
    {
        for(size_t j = 0; j < row; j++)
        {
            transponedMatrix[i][j] = arr[j][i];
        }
    }
    return transponedMatrix;
}

void freeMemory(int** arr, size_t row)
{
    for(size_t i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}