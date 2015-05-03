#include "SweepingAlgorithm.h"

SweepingAlgorithm::SweepingAlgorithm(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData)
{
}

QList<quint64> SweepingAlgorithm::compute()
{
    return {1, 2, 1};
}

qreal SweepingAlgorithm::getDistance()
{
    return 0.0;
}

QList<QList<quint64> > SweepingAlgorithm::createSubroutes()
{
    return QList<QList<quint64>>();
}
