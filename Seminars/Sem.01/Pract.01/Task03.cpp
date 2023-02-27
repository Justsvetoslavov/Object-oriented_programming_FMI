#include <iostream>
using namespace std;

void CreateMatrix(int**&, int, int);
void ReadMatrix(int**&, int&, int&);
void CopyMatrix(int**, int, int, int**&);
void TransposeMatrix(int**&, int&, int&);
void DeleteMatrix(int**&, int, int);
void PrintMatrix(int**, int, int);
void SwapValues(int&, int&);

int main() {
	int n, m;
	int** matrix = nullptr;
	ReadMatrix(matrix, n, m);
	TransposeMatrix(matrix, n, m);
	PrintMatrix(matrix, n, m);
	DeleteMatrix(matrix, n, m);
}

void CreateMatrix(int**& matrix, int n, int m) {
	matrix = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
}

void ReadMatrix(int**& matrix, int& n, int& m) {
	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;
	CreateMatrix(matrix, n, m);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void CopyMatrix(int** matrix, int n, int m, int**& matrixCopy) {
	CreateMatrix(matrixCopy, n, m);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			matrixCopy[i][j] = matrix[i][j];
		}
	}
}

void SwapValues(int& n, int &m) {
	int temp = n;
	n = m;
	m = temp;
}

void DeleteMatrix(int**& matrix, int n, int m) {
	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void TransposeMatrix(int**& matrix, int& n, int& m) {
	int** transposedMatrix = nullptr;
	SwapValues(n, m);
	CreateMatrix(transposedMatrix, n, m);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			transposedMatrix[i][j] = matrix[j][i];
		}
	}
	DeleteMatrix(matrix, m, n);
	matrix = transposedMatrix;
}

void PrintMatrix(int** matrix, int n, int m) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}