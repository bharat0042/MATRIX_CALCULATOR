#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

namespace mx
{
    using Matrix = std::vector<std::vector<double>>;

    class MatrixNd
    {
    private:
        int m_Row;
        int m_Col;
        Matrix m_Mat;
    public:
        MatrixNd(int pRow = 0, int pCol = 0, Matrix pMat = {{}});
        int getRows() const;
        int getCols() const;
        std::vector<double> operator[](int index) const;
    };

    MatrixNd add(const MatrixNd& a, const MatrixNd& b);
}
#endif // MATRIX_H
