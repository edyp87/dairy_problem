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
    return 0.0;
}

QList<QList<quint64> > SweepingAlgorithm::createSubroutes()
{
    QList<QList<quint64>> l_subroutes;
    quint64 l_nextIndex = 0;

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

void SweepingAlgorithm::sortByDistanceFromDepot(QList<quint64> p_subroute)
{
    auto l_comparator = [this](){};
    qSort(p_subroute.begin(), p_subroute.end());
}

void SweepingAlgorithm::assertThatSorted()
{
    qreal l_last = 0.0;
    for (auto & l_coordinate :m_polarData->polarCoordinates())
    {
        if (l_coordinate.angle < l_last)
        {
             throw std::runtime_error("Input coordinates are not sorted!");
        }
        l_last = l_coordinate.angle;
    }
}

qreal SweepingAlgorithm::computeDistance(const QList<quint64> p_path)
{
    for (const quint64 p_node : p_path)
    {

    }
    return 0.0;
}

