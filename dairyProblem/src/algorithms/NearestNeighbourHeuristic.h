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
    qreal getDistance();

private:
    void incrementCounters(quint64 l_nearestNode);
    void returnToDepot();
    quint64 pickNextNode();
    quint64 findNearestNodeToLastVisited();
    void appendNextNode();
    bool areAllNodesVisited();
    void unloadTruck();
    void resetState();
    void selectNodeIfNearerAndNotOverloadTruck(quint64 &p_pickedNode, quint64 &p_nearestNode, qreal &p_distanceToNearestNode);
    bool isNodeGoodCandidateForNextNode(const quint64 p_pickedNode, const qreal p_distanceToNearestNode);
    bool hasNewNodeBeenPicked(const quint64 p_nearestNode);


    Vrp::SharedCvrpDistanceMatrix m_distanceMatrix;
    QList<quint64> m_road;
    quint64 m_truckLoad;
    qreal m_distance;
    quint64 m_numOfVisitedNodes;
    static const quint8 s_minDimmension = 2;
};

#endif // NEARESTNEIGHBOURHEURISTIC_H
