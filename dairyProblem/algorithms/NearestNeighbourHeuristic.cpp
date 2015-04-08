#include "NearestNeighbourHeuristic.h"

NearestNeighbourHeuristic::NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix)
    : m_distanceMatrix(p_distanceMatrix)
{
}

QList<quint64> NearestNeighbourHeuristic::compute()
{
    QList<quint64> l_path;
    QList<bool> l_visitedNodes;
    initializeVisitedNodesList(l_visitedNodes);


    quint64 l_truckLoad = 0;

   while(l_visitedNodes.contains(false))
    {
       quint64 l_actNode = 1;
       qreal l_distance = 0.0;
        while(true)
        {
            qDebug() << "ActNode" << l_actNode;
            quint64 l_pickedNode = pickNearestUnvisitedNode(l_actNode, l_visitedNodes, l_truckLoad);
            if(l_pickedNode == 0) break;
            l_distance += m_distanceMatrix->getDistanceBetweenNodes(l_pickedNode, l_actNode);
            l_actNode = l_pickedNode;
        }
        qDebug() << "DISTANCE:" << l_distance;
    }
    return l_path;
}

quint64 NearestNeighbourHeuristic::pickNearestUnvisitedNode(const quint64 p_node, QList<bool> &p_visitedNodes, quint64 &p_truckLoad)
{
    QList<qreal> l_nodeNeighbors = m_distanceMatrix->distanceData()[p_node];

    qreal l_nearestDistance = qInf();
    quint64 l_nearestNode = 0;
    for (quint64 l_neighborNode = 1;
         l_neighborNode < static_cast<quint64>(l_nodeNeighbors.size()) && p_visitedNodes.contains(false);
         ++l_neighborNode)
    {
        //Debug() << "Distance:" << l_nodeNeighbors[l_neighborNode] <<"for node:" << l_neighborNode;
        if (l_neighborNode == p_node || p_visitedNodes[l_neighborNode])
        {
            continue;
        }

        if (l_nodeNeighbors[l_neighborNode] < l_nearestDistance)
        {
            l_nearestDistance = l_nodeNeighbors[l_neighborNode];
            l_nearestNode = l_neighborNode;
        }
    }
    qDebug() << "Picked demand" << m_distanceMatrix->demands()[l_nearestNode-1].demand << "for node" << l_nearestNode;
    if (m_distanceMatrix->demands()[l_nearestNode-1].demand + p_truckLoad > m_distanceMatrix->capacity())
    {
        return 0;
    }
    else
    {
        p_truckLoad += m_distanceMatrix->demands()[l_nearestNode].demand;
        p_visitedNodes[l_nearestNode] = true;
        return l_nearestNode;
    }
}

void NearestNeighbourHeuristic::initializeVisitedNodesList(QList<bool> &p_visitedNodes)
{
    for (quint64 i = 0; i <= m_distanceMatrix->dimension(); ++i)
    {
        p_visitedNodes.append(false);
    }
    p_visitedNodes[1] = true;
    p_visitedNodes[0] = true;
}
