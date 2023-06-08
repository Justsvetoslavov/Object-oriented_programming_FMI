#include <iostream>
#include "Matrix.hpp"

int main()
{
    Matrix<int> matrix(8, 5);
    matrix.SetAt(7, 4, 15222);
    matrix.Transpose();

    size_t width = matrix.GetWidth();
    size_t height = matrix.GetHeight();

    for (int y = 0; y < matrix.GetHeight(); ++y)
    {
        for (int x = 0; x < matrix.GetWidth(); ++x)
        {
            std::cout << matrix.GetAt(x, y) << ", ";
        }

        std::cout << std::endl;
    }

    return 0;
}
