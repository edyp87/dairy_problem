#pragma once

#include <QtGlobal>
#include <QList>
#include <stdexcept>

namespace Utilities
{

class SquareMatrix
{
public:
    explicit SquareMatrix(quint64 p_size)
        : m_size(p_size)
    {
        initializeMatrixWithZeroes();
    }

    QList<qreal> & operator[](quint64 n)
    {
        if (n > m_size)
        {
            throw std::runtime_error(std::string("Size to big!"));
        }
        return m_matrix[n];
    }

    quint64 size()
    {
        return m_size;
    }

private:
    void initializeMatrixWithZeroes()
    {
        for(quint64 i = 0; i < m_size; ++i)
        {
            m_matrix.append(QList<qreal>());
            for(quint64 j = 0; j < m_size; ++j)
            {
                m_matrix[i].append(0);
            }
        }
    }

    QList<QList<qreal>> m_matrix;
    quint64 m_size;
};

} // namespace Utilities
