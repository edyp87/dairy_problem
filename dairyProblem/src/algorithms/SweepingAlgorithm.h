#pragma once

#include <dataConverter/PolarMatrixData.h>
#include <memory>

class SweepingAlgorithm
{
public:
    SweepingAlgorithm(Vrp::SharedPolarMatrix p_polarData);
    QList<quint64> compute();
    qreal getDistance();

private:
    QList<QList<quint64>> createSubroutes();

    Vrp::SharedPolarMatrix m_polarData;
};
