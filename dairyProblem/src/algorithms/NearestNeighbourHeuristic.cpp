#include "NearestNeighbourHeuristic.h"
#include <iostream>
NearestNeighbourHeuristic::NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix)
    : m_distanceMatrix(p_distanceMatrix), m_truckLoad(0), m_distance(0.0), m_numOfVisitedNodes(0)
{
    if (m_distanceMatrix->distanceData().size() < s_minDimmension)
    {
        throw std::runtime_error(std::string("Problem dimmension to small!"));
    }
}

QList<quint64> NearestNeighbourHeuristic::compute()
{
    resetState();

    m_road.append(m_distanceMatrix->depot());

    while (not areAllNodesVisited())
    {
        appendNextNode();
    }

    m_road.append(m_distanceMatrix->depot());

    return m_road;
}

void NearestNeighbourHeuristic::appendNextNode()
{
    m_road.append(pickNextNode());
}

quint64 NearestNeighbourHeuristic::pickNextNode()
{
    quint64 l_nearestNode = findNearestNodeToLastVisited();

    if (not hasNewNodeBeenPicked(l_nearestNode))
    {
        returnToDepot();
        unloadTruck();
        return m_distanceMatrix->depot();
    }
    else
    {
        incrementCounters(l_nearestNode);
        return l_nearestNode;
    }
}

quint64 NearestNeighbourHeuristic::findNearestNodeToLastVisited()
{
    quint64 l_nearestNode = m_road.last();
    qreal   l_distanceToNearestNode = std::numeric_limits<qreal>::max();


    for (quint64 l_pickedNode = 1; l_pickedNode <= m_distanceMatrix->dimension(); ++l_pickedNode)
    {
        selectNodeIfNearerAndNotOverloadTruck(l_pickedNode, l_nearestNode, l_distanceToNearestNode);
    }

    return l_nearestNode;
}


void NearestNeighbourHeuristic::selectNodeIfNearerAndNotOverloadTruck(quint64 &p_pickedNode, quint64 &p_nearestNode, qreal &p_distanceToNearestNode)
{
    if (isNodeGoodCandidateForNextNode(p_pickedNode, p_distanceToNearestNode))
    {
        p_distanceToNearestNode = m_distanceMatrix->distanceData()[m_road.last()][p_pickedNode];
        p_nearestNode = p_pickedNode;
    }
}

qreal NearestNeighbourHeuristic::getDistance()
{
    compute();
    return m_distance;
}

void NearestNeighbourHeuristic::unloadTruck()
{
    m_truckLoad = 0;
}

bool NearestNeighbourHeuristic::areAllNodesVisited()
{
    return m_numOfVisitedNodes == m_distanceMatrix->dimension()-1 ? true : false;
}

void NearestNeighbourHeuristic::resetState()
{
    unloadTruck();
    m_road.clear();
    m_distance = 0;
    m_numOfVisitedNodes = 0;
}

bool NearestNeighbourHeuristic::isNodeGoodCandidateForNextNode(const quint64 p_pickedNode, const qreal p_distanceToNearestNode)
{
    return m_distanceMatrix->distanceData()[m_road.last()][p_pickedNode] < p_distanceToNearestNode
            && not m_road.contains(p_pickedNode)
            && m_distanceMatrix->demands()[p_pickedNode-1].demand + m_truckLoad <= m_distanceMatrix->capacity();
}

bool NearestNeighbourHeuristic::hasNewNodeBeenPicked(const quint64 p_nearestNode)
{
    return p_nearestNode != m_road.last();
}

void NearestNeighbourHeuristic::incrementCounters(quint64 l_nearestNode)
{
    m_truckLoad += m_distanceMatrix->demands()[l_nearestNode-1].demand;
    m_distance += m_distanceMatrix->distanceData()[m_road.last()][l_nearestNode];
    m_numOfVisitedNodes += 1;
}

void NearestNeighbourHeuristic::returnToDepot()
{
    m_distance += m_distanceMatrix->distanceData()[m_road.last()][m_distanceMatrix->depot()];
}
