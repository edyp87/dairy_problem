#include "CvrpData.h"

namespace Vrp
{

CvrpData::CvrpData()
{
}

QString CvrpData::name() const
{
    return m_name;
}


void CvrpData::setName(const QString p_name)
{
    m_name = p_name;
}
QString CvrpData::comment() const
{
    return m_comment;
}

void CvrpData::setComment(const QString comment)
{
    m_comment = comment;
}
QString CvrpData::type() const
{
    return m_type;
}

void CvrpData::setType(const QString type)
{
    m_type = type;
}
quint32 CvrpData::dimension() const
{
    return m_dimension;
}

void CvrpData::setDimension(const quint32 dimension)
{
    m_dimension = dimension;
}
QString CvrpData::edgeWeightType() const
{
    return m_edgeWeightType;
}

void CvrpData::setEdgeWeightType(const QString edgeWeightType)
{
    m_edgeWeightType = edgeWeightType;
}
quint32 CvrpData::capacity() const
{
    return m_capacity;
}

void CvrpData::setCapacity(const quint32 capacity)
{
    m_capacity = capacity;
}
QList<Vrp2dCoordinate> CvrpData::nodeCoordinates() const
{
    return m_nodeCoordinates;
}

void CvrpData::setNodeCoordinates(const QList<Vrp2dCoordinate> nodeCoordinates)
{
    m_nodeCoordinates = nodeCoordinates;
}

void CvrpData::appendToCoordinates(const Vrp2dCoordinate p_node)
{
    m_nodeCoordinates.append(p_node);
}
QList<CvrpDemand> CvrpData::demands() const
{
    return m_demands;
}

void CvrpData::setDemands(const QList<CvrpDemand> demands)
{
    m_demands = demands;
}

void CvrpData::appendToDemands(const CvrpDemand p_demand)
{
    m_demands.append(p_demand);
}
quint32 CvrpData::depot() const
{
    return m_depot;
}

void CvrpData::setDepot(const quint32 depot)
{
    m_depot = depot;
}

} // namespace Vrp
