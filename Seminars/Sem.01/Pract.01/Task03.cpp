#include <iostream>

int** InitializeMatrix(const int rows, const int cols)
{
	int** matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	return matrix;
}

void FillMatrix(int** matrix, const int rows, const int cols)
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

int** TransposeMatrix(const int** matrix, const int rows, const int cols)
{
	int** transposedMatrix = InitializeMatrix(cols, rows);
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			transposedMatrix[j][i] =  matrix[i][j];
		}
	}
    
	return transposedMatrix;
}

void PrintMatrix(const int** matrix, const int rows, const int cols)
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void DeleteMatrix(int** matrix, const int rows)
{
	for (size_t i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	int** matrix = InitializeMatrix(rows, cols);
	FillMatrix(matrix, rows, cols);
	PrintMatrix(matrix, rows, cols);

	int** transposedMatrix = TransposeMatrix(matrix, rows, cols);
	PrintMatrix(transposedMatrix, cols, rows);

	DeleteMatrix(matrix, rows);
	DeleteMatrix(transposedMatrix, cols);
}