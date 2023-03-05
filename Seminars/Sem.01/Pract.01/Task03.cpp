// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int** createMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;
}
void fillMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}
}
void deleteMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
int** transMatrix(int** matrix, int rows, int cols) {
	int** matrix2 = createMatrix(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix2[j][i] = matrix[i][j];
		}
	}
	return matrix2;
}
int main()
{
	int rows, cols;
	cin >> rows >> cols;
	int** matrix = createMatrix(rows, cols);
	fillMatrix(matrix, rows, cols);
	matrix = transMatrix(matrix, rows, cols);
	rows = rows - cols;
	cols = cols + rows;
	rows = cols - rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
	deleteMatrix(matrix, rows, cols);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
