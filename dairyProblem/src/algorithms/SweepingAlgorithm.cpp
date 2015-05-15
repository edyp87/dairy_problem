#include "SweepingAlgorithm.h"
#include <dataReader/CvrpDemand.h>
#include <iostream>

SweepingAlgorithm::SweepingAlgorithm(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData)
{
    assertThatSorted();
}

DairyPath SweepingAlgorithm::compute()
{
    const auto l_path = flatNestedList(createSubroutes());
    return { l_path, computeDistance(l_path)};
}

qreal SweepingAlgorithm::getDistance()
{
    const auto l_path = flatNestedList(createSubroutes());
    return computeDistance(l_path);
}

QList<QList<quint64> > SweepingAlgorithm::createSubroutes()
{
    QList<QList<quint64>> l_subroutes;
    quint64 l_nextIndex = 0;

    moveDepotAtTheBeginning();

    while (l_nextIndex < m_polarData->dimension())
    {
        QList<quint64> l_subroute = createSubroute(l_nextIndex);
        if (l_subroute.empty())
        {
            return l_subroutes;
        }
        l_subroutes.append(l_subroute);
    }

    return l_subroutes;
}

QList<quint64> SweepingAlgorithm::createSubroute(quint64 &p_nextIndex)
{
    quint64 l_truckCapacity = m_polarData->capacity();

    QList<quint64> l_subroute;
    while(p_nextIndex < m_polarData->dimension()
          && l_truckCapacity >= getDemandForIndex(m_polarData->polarCoordinates()[p_nextIndex].index))
    {
        l_subroute.append(m_polarData->polarCoordinates()[p_nextIndex].index);
        l_truckCapacity -= getDemandForIndex(m_polarData->polarCoordinates()[p_nextIndex].index);
        ++p_nextIndex;
    }

    l_subroute.append(m_polarData->depot());
    return l_subroute;

}

quint64 SweepingAlgorithm::getDemandForIndex(quint64 p_nodeIndex)
{
    for (Vrp::CvrpDemand & l_demand : m_polarData->demands())
    {
        if (l_demand.index == p_nodeIndex)
        {
            return l_demand.demand;
        }
    }

    throw std::runtime_error((QString("Demand for index %1 not found!").arg(p_nodeIndex)).toStdString());
}

QList<quint64> SweepingAlgorithm::flatNestedList(QList<QList<quint64> > p_subroutesList)
{
    QList<quint64> l_result;

    for (QList<quint64> & l_list : p_subroutesList)
    {
        for (quint64 l_index : l_list)
        {
            l_result.append(l_index);
        }
    }

    return l_result;
}

void SweepingAlgorithm::assertThatSorted()
{
    qreal l_last = m_polarData->polarCoordinates()[0].angle;
    for (auto & l_coordinate : m_polarData->polarCoordinates())
    {
        if (l_coordinate.angle < l_last)
        {

             throw std::runtime_error(
                        (QString("Input coordinates are not sorted! %1 < %2").arg(l_coordinate.angle).arg(l_last)).toStdString());
        }
        l_last = l_coordinate.angle;
    }
}

qreal SweepingAlgorithm::computeDistance(const QList<quint64> p_path)
{
    auto l_lastNode = m_polarData->depot();
    qreal l_distance = 0.0f;
    for (const auto l_currentNode : p_path)
    {
        l_distance += m_polarData->distanceData()[l_lastNode][l_currentNode];
        l_lastNode = l_currentNode;
    }
    return l_distance;
}

void SweepingAlgorithm::moveDepotAtTheBeginning()
{
    int l_depotPosition = 0;
    for (int i = 0; i < m_polarData->polarCoordinates().size(); ++i)
    {
        if (m_polarData->polarCoordinates()[i].index == m_polarData->depot())
        {
            l_depotPosition = i;
            break;
        }
    }

    for (quint64 i = l_depotPosition; i > 0; --i)
    {
        std::swap(m_polarData->polarCoordinates()[i], m_polarData->polarCoordinates()[i-1]);
    }
}

