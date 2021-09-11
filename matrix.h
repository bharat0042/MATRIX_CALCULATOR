#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <armadillo>

namespace mx
{
    using Matrix = std::vector<std::vector<double>>;

    class MatrixNd
    {
    private:
        arma::mat m_a;
        arma::mat m_b;
    public:
        MatrixNd();
        void setA(int pRows, int pCols, Matrix pA);
        void setB(int pRows, int pCols, Matrix pB);
        arma::mat getA();
        arma::mat getB();
        arma::mat addMat();
        arma::mat subMat();
        arma::mat mulMat();
        double matDet(bool isA);
        bool invMat(bool isA, arma::mat& inv);
        arma::mat tpose(bool isA);
        arma::mat sq(bool isA);
        double accuA();
    };
}
#endif // MATRIX_H
