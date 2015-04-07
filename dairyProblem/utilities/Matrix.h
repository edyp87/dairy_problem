#pragma once

#include <QtGlobal>
#include <QList>

namespace Utilities
{

class SquareMatrix
{
public:
    explicit SquareMatrix(quint64 p_size)
        : m_size(p_size)
    {
        // i know, bad piece of code
        for(quint64 i = 0; i <= m_size; ++i)
        {
            m_matrix.append(QList<qreal>());
            for(quint64 j = 0; j <= m_size; ++j)
            {
                m_matrix[i].append(0);
            }
        }
    }

    QList<qreal> & operator[](quint64 n)
    {
        if (n > m_size)
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
