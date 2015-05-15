#pragma once

#include <dataConverter/PolarMatrixData.h>
#include <memory>
#include <utilities/DairyPath.h>

class SweepingAlgorithm
{
public:
    SweepingAlgorithm(Vrp::SharedPolarMatrix p_polarData);
    DairyPath compute();
    qreal getDistance();

private:
    QList<QList<quint64>> createSubroutes();
    QList<quint64> createSubroute(quint64 &p_nextIndex);
    quint64 getDemandForIndex(quint64 p_nodeIndex);
    QList<quint64> flatNestedList(QList<QList<quint64>> p_subroutesList);
    void sortByDistanceFromDepot(QList<quint64> p_subroute);
    void assertThatSorted();
    qreal computeDistance(const QList<quint64> p_path);

    Vrp::SharedPolarMatrix m_polarData;
};
