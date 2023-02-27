void createMatrix(int**& matrix, size_t rows, size_t cols)
{
    matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}
int** inputMatrix(int** matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}
void deleteMatrix(int** matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void printMatrix(int** matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std:: cout << std::endl;
    }
}
int** transMatrix(int** matrix, size_t rows, size_t cols)
{
    size_t transCols = rows;
    size_t transRows = cols;
    int** transMatrix = createMatrix(transRows, transCols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            transMatrix[j][i] = matrix[i][j];
        }
    }
    return transMatrix;
}
int main()
{
    size_t rows, cols, transRows, transCols;
    std::cin >> rows >> cols;
    transCols = rows;
    transRows = cols;
    int** matrix;
    createMatrix(matrix, rows, cols);
    matrix = inputMatrix(matrix, rows, cols);
    int** newMatrix = transMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    std::cout << std::endl;
    transMatrix(matrix, rows, cols);
    printMatrix(transMatrix(matrix, rows, cols), transRows, transCols);
    deleteMatrix(matrix, rows, cols);
    deleteMatrix(newMatrix, rows, cols);
}