#include "matrix.h"

mx::MatrixNd::MatrixNd(int pRow, int pCol, Matrix pMat) :
    m_Row(pRow),
    m_Col(pCol)
{
    m_Mat = pMat;
}

int mx::MatrixNd::getRows() const
{
    return m_Row;
}

int mx::MatrixNd::getCols() const
{
    return m_Col;
}

std::vector<double> mx::MatrixNd::operator[](int index) const
{
    return m_Mat[index];
}

mx::MatrixNd mx::add(const mx::MatrixNd& a, const mx::MatrixNd& b)
{
    if(a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        mx::Matrix mat(0, std::vector<double>(0));
        mx::MatrixNd res(0, 0, mat);
        return res;
    }
    mx::Matrix fin(a.getRows(), std::vector<double>(a.getCols()));
    for(int i = 0 ; i < a.getRows(); i++)
    {
        for(int j = 0; j < a.getCols(); j++)
        {
            fin[i][j] = a[i][j] + b[i][j];
        }
    }
    mx::MatrixNd finRes(a.getRows(), a.getCols(), fin);
    return finRes;
}
