#include<utilities/Matrix.h>
#include <gmock/gmock.h>

class MatrixTest : public testing::Test
{

};

TEST_F(MatrixTest, CanBeCreated)
{
    const quint64 l_matrixSize { 3 };

    Utilities::SquareMatrix l_matrix { l_matrixSize };
}

TEST_F(MatrixTest, SizeCanBeObtained)
{
    const quint64 l_matrixSize { 3 };

    Utilities::SquareMatrix l_matrix { l_matrixSize };

    ASSERT_EQ(l_matrixSize, l_matrix.size());
}

TEST_F(MatrixTest, IsInitializedWithZeroes)
{
    const quint64 l_matrixSize { 3 };

    Utilities::SquareMatrix l_matrix { l_matrixSize };

    for (quint64 i = 0; i < l_matrixSize; ++i)
    {
        for (quint64 j = 0; j < l_matrixSize; ++j)
        {
            ASSERT_EQ(l_matrix[i][j], 0);
        }
    }
}

TEST_F(MatrixTest, CanBeFilled)
{
    const quint64 l_matrixSize { 3 };

    Utilities::SquareMatrix l_matrix { l_matrixSize };

    for (quint64 i = 0; i < l_matrixSize; ++i)
    {
        for (quint64 j = 0; j < l_matrixSize; ++j)
        {
            l_matrix[i][j] = i*j;
            ASSERT_EQ(l_matrix[i][j], i*j);
        }
    }
}

