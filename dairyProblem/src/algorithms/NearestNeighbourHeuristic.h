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
private:
    void selectNodeIfNearerAndNotOverloadTruck(quint64 &p_pickedNode, quint64 &p_nearestNode, qreal &p_distanceToNearestNode);
    void unloadTruck();
    void appendNextNode();
    quint64 findNearestNodeToLastVisited();
    bool allNodesAreVisited();

    Vrp::SharedCvrpDistanceMatrix m_distanceMatrix;
    QList<quint64> m_road;
    quint64 m_truckLoad;
    static const quint8 s_minDimmension = 2;
};

#endif // NEARESTNEIGHBOURHEURISTIC_H
