#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdexcept>

template<typename T>
class Matrix
{
    T **m_matrix;
    size_t m_sizeX;
    size_t m_sizeY;
    bool m_xTop = true;

    void CopyFrom(const Matrix &copy);
    void Free();

public:
    Matrix();
    Matrix(size_t x, size_t y);

    Matrix(const Matrix &copy);
    Matrix &operator=(const Matrix &mat);
    ~Matrix();

    size_t GetWidth() const;
    size_t GetHeight() const;

    void SetAt(size_t x, size_t y, const T &element);
    const T &GetAt(size_t x, size_t y) const;

    void Transpose();
};
template<typename T>
size_t Matrix<T>::GetHeight() const
{
    return m_xTop ? m_sizeY : m_sizeX;
}
template<typename T>
size_t Matrix<T>::GetWidth() const
{
    return m_xTop ? m_sizeX : m_sizeY;
}
template<typename T>
Matrix<T>::Matrix()
        :Matrix(2, 2)
{

}
template<typename T>
Matrix<T>::Matrix(size_t x, size_t y)
{
    m_sizeX = x;
    m_sizeY = y;
    m_xTop = true;

    m_matrix = new T *[x];
    for (int i = 0; i < x; ++i)
    {
        m_matrix[i] = new T[y];
        for (int j = 0; j < y; ++j)
        {
            m_matrix[i][j] = T();
        }
    }
}
template<typename T>
void Matrix<T>::CopyFrom(const Matrix &copy)
{
    m_sizeX = copy.m_sizeY;
    m_sizeY = copy.m_sizeY;

    m_matrix = new T *[copy.m_sizeX];
    for (int i = 0; i < copy.m_sizeX; ++i)
    {
        m_matrix[i] = new T[copy.m_sizeY];
        for (int j = 0; j < copy.m_sizeY; ++j)
        {
            m_matrix[i][j] = copy[i][j];
        }
    }
}
template<typename T>
void Matrix<T>::Free()
{
    for (int i = 0; i < GetWidth(); ++i)
        delete[] m_matrix[i];

    delete[] m_matrix;

    m_matrix = nullptr;
}
template<typename T>
Matrix<T>::Matrix(const Matrix &copy)
{
    CopyFrom(copy);
}
template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        Free();
        CopyFrom(mat);
    }
    return *this;
}
template<typename T>
Matrix<T>::~Matrix()
{
    Free();
}
template<typename T>
void Matrix<T>::SetAt(size_t x, size_t y, const T &element)
{
    if (x >= GetWidth() || y >= GetHeight())
        throw std::length_error("Invalid coordinates!");

    m_matrix[x][y] = element;
}
template<typename T>
const T &Matrix<T>::GetAt(size_t x, size_t y) const
{
    if (x >= GetWidth() || y >= GetHeight())
        throw std::length_error("Invalid coordinates!");

    return m_matrix[x][y];
}
template<typename T>
void Matrix<T>::Transpose()
{
    m_xTop = !m_xTop;
    T **temp = new T *[m_sizeY];
    for (int i = 0; i < m_sizeY; ++i)
    {
        temp[i] = new T[m_sizeX];
        for (int j = 0; j < m_sizeX; ++j)
        {
            temp[i][j] = m_matrix[j][i];
        }
    }

    Free();

    m_matrix = temp;
}

#endif
