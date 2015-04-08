#ifndef NEARESTNEIGHBOURHEURISTIC_H
#define NEARESTNEIGHBOURHEURISTIC_H

#include <dataCoverter/CvrpDistanceMatrixData.h>
#include <memory>
#include <QList>

class NearestNeighbourHeuristic
{
public:
    explicit NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix);
    QList<quint64> compute();
private:
    quint64 pickNearestUnvisitedNode(const quint64 p_node, QList<bool> &p_visitedNodes, quint64 &p_truckLoad);
    void initializeVisitedNodesList(QList<bool> &p_visitedNodes);

    Vrp::SharedCvrpDistanceMatrix m_distanceMatrix;
};

#endif // NEARESTNEIGHBOURHEURISTIC_H
