#ifndef NEARESTNEIGHBOURHEURISTIC_H
#define NEARESTNEIGHBOURHEURISTIC_H

#include <dataConverter/CvrpDistanceMatrixData.h>
#include <memory>
#include <QList>

class NearestNeighbourHeuristic
{
public:
    explicit NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix);
    QList<quint64> compute();
    void selectNodeIfNearer(quint64 &l_pickedNode, quint64 &l_nearestNode, qreal &l_minDistance);
private:
    void appendNextNode();
    quint64 findNearestNodeToLastVisited();
    bool allNodesAreVisited();

    Vrp::SharedCvrpDistanceMatrix m_distanceMatrix;
    QList<quint64> m_road;
    static const quint8 s_minDimmension = 2;
};

#endif // NEARESTNEIGHBOURHEURISTIC_H
