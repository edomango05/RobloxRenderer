#include "../includes/matrix.h"


Matrix::Matrix(int rows_, int columns_)
{
    rows = rows_;
    columns = columns_;
    malloc();
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < columns_; ++j)
        {
            table[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] table[i];
    }
    delete[] table;
}

void Matrix::malloc()
{
    table = new double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        table[i] = new double[columns];
    }
}

Matrix& Matrix::operator+=(const Matrix& operand){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            table[i][j] += operand.table[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& operand){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            table[i][j] -= operand.table[i][j];
        }
    }
    return *this;
}

Matrix operator-(const Matrix &operand1, const Matrix &operand2)
{
    Matrix result(operand1);
    return result-=operand2;
}

Matrix operator+(const Matrix &operand1, const Matrix &operand2)
{
    Matrix result(operand1);
    return result+=operand2;
}
