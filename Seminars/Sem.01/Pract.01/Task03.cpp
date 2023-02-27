#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1

//Да се напише програма, която прочита от конзолата матрица с размер NxM и я отпечатва трансонирана.

int** creatematrix(const int rows, const  int cols) {

	int** matrix = new  int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];

	}
	return matrix;
}
void inputmatrix(int** matrix, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}
void printmatrix(int** matrix, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << matrix[i][j];
		}
		cout << endl;
	}
}

void freematrix(int** matrix, const int rows) {
	for (int i = 0; i < rows; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

int** transposedmatrix(int** matrix, const int rows, const int cols) {
	int line = cols;
	int columns = rows;

	int** tranposed = creatematrix(columns, rows);

	for (int j = 0; j < line; j++) {
		for (int g = 0; g < columns; g++) {
			tranposed[j][g] = matrix[g][j];
		}
	}
	return tranposed;

}


int main() {

	int rows;
	int cols;
	cin >> rows >> cols;

	int** matrix = creatematrix(rows, cols);

	inputmatrix(matrix, rows, cols);

	cout << "the matrix is:";
	printmatrix(matrix, rows, cols);
	int** transposed = transposedmatrix(matrix, rows, cols);
	cout << "transposed";
	printmatrix(transposed, cols, rows);

	freematrix(matrix, rows);
	freematrix(transposed, cols);
}