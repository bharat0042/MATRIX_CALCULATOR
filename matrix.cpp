#include "matrix.h"

mx::MatrixNd::MatrixNd(){}

void mx::MatrixNd::setA(int pRows, int pCols, Matrix pA)
{
    arma::mat temp(pRows, pCols, arma::fill::zeros);
    for(int i = 0; i < pRows; i++)
    {
        for(int j = 0; j < pCols; j++)
        {
            temp(i, j) = pA[i][j];
        }
    }
    m_a = temp;
}

void mx::MatrixNd::setB(int pRows, int pCols, Matrix pB)
{
    arma::mat temp(pRows, pCols, arma::fill::zeros);
    for(int i = 0; i < pRows; i++)
    {
        for(int j = 0; j < pCols; j++)
        {
            temp(i, j) = pB[i][j];
        }
    }
    m_b = temp;
}

arma::mat mx::MatrixNd::getA()
{
    return m_a;
}

arma::mat mx::MatrixNd::getB()
{
    return m_b;
}

arma::mat mx::MatrixNd::addMat()
{
    return (m_a + m_b);
}

arma::mat mx::MatrixNd::subMat()
{
    return (m_a - m_b);
}

arma::mat mx::MatrixNd::mulMat()
{
    return (m_a * m_b);
}

double mx::MatrixNd::matDet(bool isA)
{
    if(isA)
    {
        return arma::det(m_a);
    }
    return arma::det(m_b);
}

bool mx::MatrixNd::invMat(bool isA, arma::mat& inv)
{
    if(isA)
    {
        if(matDet(true) == 0)
        {
            return false;
        }
        inv = arma::inv(m_a);
        return true;
    }
    else
    {
        if(matDet(false) == 0)
        {
            return false;
        }
        inv = arma::inv(m_b);
        return true;
    }
}

arma::mat mx::MatrixNd::tpose(bool isA)
{
    if(isA)
    {
        return m_a.t();
    }
    return m_b.t();
}

arma::mat mx::MatrixNd::sq(bool isA)
{
    if(isA)
    {
        return arma::square(m_a);
    }
    return arma::square(m_b);
}

double mx::MatrixNd::accuA()
{
    return arma::accu(m_a);
}
