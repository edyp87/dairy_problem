#include "NearestNeighbourHeuristic.h"
#include <iostream>
NearestNeighbourHeuristic::NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix)
    : m_distanceMatrix(p_distanceMatrix)
{
    if (m_distanceMatrix->distanceData().size() < s_minDimmension)
    {
        throw std::runtime_error(std::string("Problem dimmension to small!"));
    }
}

QList<quint64> NearestNeighbourHeuristic::compute()
{
    m_road.clear();

    m_road.append(1);

    while (not allNodesAreVisited())
    {
        appendNextNode();
    }

    m_road.append(1);

    return m_road;
}

void NearestNeighbourHeuristic::appendNextNode()
{


    m_road.append(findNearestNodeToLastVisited());
}

void NearestNeighbourHeuristic::selectNodeIfNearer(quint64 &l_pickedNode, quint64 &l_nearestNode, qreal &l_minDistance)
{
    if (m_distanceMatrix->distanceData()[m_road.last()][l_pickedNode] < l_minDistance
        && not m_road.contains(l_pickedNode))
    {
        l_minDistance = m_distanceMatrix->distanceData()[m_road.last()][l_pickedNode];
        l_nearestNode = l_pickedNode;
    }
}

quint64 NearestNeighbourHeuristic::findNearestNodeToLastVisited()
{
    quint64 l_nearestNode = m_road.last();
    qreal   l_minDistance = std::numeric_limits<qreal>::max();

    for (quint64 l_pickedNode = 1; l_pickedNode <= m_distanceMatrix->dimension(); ++l_pickedNode)
    {
        selectNodeIfNearer(l_pickedNode, l_nearestNode, l_minDistance);
    }

    return l_nearestNode;
}

bool NearestNeighbourHeuristic::allNodesAreVisited()
{
    return static_cast<quint32>(m_road.size()) == m_distanceMatrix->dimension();
}



