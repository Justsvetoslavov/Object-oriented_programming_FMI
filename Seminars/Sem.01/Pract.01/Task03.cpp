#include <iostream>
#include <iomanip>

void printMatrixTransposed(const int** arr, const int rows, const int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            std::cout << std::setw(2);
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void freeSpace(int** arr, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    int** arr = new int*[N];

    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
        for (int j = 0; j < M; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "\nTransposed:\n\n";
    printMatrixTransposed((const int**) arr, N, M);
    freeSpace(arr, N);
}
