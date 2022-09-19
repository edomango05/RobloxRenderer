#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix(int rows_, int columns_);
    ~Matrix();
    Matrix &operator+=(const Matrix &operand);
    Matrix &operator-=(const Matrix &operand);
    void malloc();

protected:
    int rows, columns;
    double **table;
};
 
struct CFrame : public Matrix
{
    CFrame(double x, double y, double z, double R00 , double R01,double R02, double R10, double R11, double R12,double R20,double R21,double R22) : Matrix(4,4)
    {
        table[0][0] = R00;
        table[0][1] = R01;
        table[0][2] = R02;
        table[0][3] = x;

        table[1][0] = R10;
        table[1][1] = R11;
        table[1][2] = R12;
        table[1][3] = y;

        table[2][0] = R20;
        table[2][1] = R21;
        table[2][2] = R22;
        table[2][3] = z;

        table[3][0] = 0;
        table[3][1] = 0;
        table[3][2] = 0;
        table[3][3] = 1;
    }
};

struct Vector : public Matrix
{
    Vector(double x, double y, double z) : Matrix(1,3)
    {
        table[0][0] = x;
        table[0][1] = y;
        table[0][2] = z;
    }
    Vector(double x, double y) : Matrix(1,2)
    {
        table[0][0] = x;
        table[0][1] = y;
    }
};

#endif