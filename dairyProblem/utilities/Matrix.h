#pragma once

#include <QtGlobal>
#include <QList>

namespace Utilities
{

class SquareMatrix
{
public:
    explicit SquareMatrix(quint32 p_size)
        : m_size(p_size)
    {}

    QList<qreal> & operator[](quint64 n)
    {
        if (n >= m_size)
        {
            throw std::runtime_error(std::string("Size to big!"));
        }
        return m_matrix[n];
    }

private:
    QList<QList<qreal>> m_matrix;
    quint64 m_size;
};

} // namespace Utilities
