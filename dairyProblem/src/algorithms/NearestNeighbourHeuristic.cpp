#include "NearestNeighbourHeuristic.h"
#include <iostream>
NearestNeighbourHeuristic::NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix)
    : m_distanceMatrix(p_distanceMatrix), m_truckLoad(0)
{
    if (m_distanceMatrix->distanceData().size() < s_minDimmension)
    {
        throw std::runtime_error(std::string("Problem dimmension to small!"));
    }
}

QList<quint64> NearestNeighbourHeuristic::compute()
{
    m_road.clear();

    m_road.append(m_distanceMatrix->depot());

    while (not allNodesAreVisited())
    {
        appendNextNode();
    }

    m_road.append(m_distanceMatrix->depot());

    return m_road;
}

void NearestNeighbourHeuristic::appendNextNode()
{
    m_road.append(findNearestNodeToLastVisited());
}

quint64 NearestNeighbourHeuristic::findNearestNodeToLastVisited()
{
    quint64 l_nearestNode = m_road.last();
    qreal   l_distanceToNearestNode = std::numeric_limits<qreal>::max();


    for (quint64 l_pickedNode = 1; l_pickedNode <= m_distanceMatrix->dimension(); ++l_pickedNode)
    {
        selectNodeIfNearerAndNotOverloadTruck(l_pickedNode, l_nearestNode, l_distanceToNearestNode);
    }

    if (l_nearestNode == m_road.last())
    {
        unloadTruck();
        return m_distanceMatrix->depot();
    }
    m_truckLoad += m_distanceMatrix->demands()[l_nearestNode-1].demand;

    return l_nearestNode;
}

void NearestNeighbourHeuristic::selectNodeIfNearerAndNotOverloadTruck
    (quint64 &p_pickedNode, quint64 &p_nearestNode, qreal &p_distanceToNearestNode)
{
    if (m_distanceMatrix->distanceData()[m_road.last()][p_pickedNode] < p_distanceToNearestNode
        && not m_road.contains(p_pickedNode)
        && m_distanceMatrix->demands()[p_pickedNode-1].demand + m_truckLoad <= m_distanceMatrix->capacity())
    {
        p_distanceToNearestNode = m_distanceMatrix->distanceData()[m_road.last()][p_pickedNode];
        p_nearestNode = p_pickedNode;
    }
}

bool NearestNeighbourHeuristic::allNodesAreVisited()
{
    for (quint64 i = 1; i <= m_distanceMatrix->dimension(); ++i)
    {
        if (not m_road.contains(i))
        {
            return false;
        }
    }

    return true;
}

void NearestNeighbourHeuristic::unloadTruck()
{
    m_truckLoad = 0;
}

