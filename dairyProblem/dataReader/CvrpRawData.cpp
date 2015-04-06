#include "CvrpRawData.h"

namespace Vrp
{

CvrpRawData::CvrpRawData()
{
}

QString CvrpRawData::name() const
{
    return m_name;
}


void CvrpRawData::setName(const QString p_name)
{
    m_name = p_name;
}
QString CvrpRawData::comment() const
{
    return m_comment;
}

void CvrpRawData::setComment(const QString comment)
{
    m_comment = comment;
}
QString CvrpRawData::type() const
{
    return m_type;
}

void CvrpRawData::setType(const QString type)
{
    m_type = type;
}
quint32 CvrpRawData::dimension() const
{
    return m_dimension;
}

void CvrpRawData::setDimension(const quint32 dimension)
{
    m_dimension = dimension;
}
QString CvrpRawData::edgeWeightType() const
{
    return m_edgeWeightType;
}

void CvrpRawData::setEdgeWeightType(const QString edgeWeightType)
{
    m_edgeWeightType = edgeWeightType;
}
quint32 CvrpRawData::capacity() const
{
    return m_capacity;
}

void CvrpRawData::setCapacity(const quint32 capacity)
{
    m_capacity = capacity;
}
QList<Vrp2dCoordinate> CvrpRawData::nodeCoordinates() const
{
    return m_nodeCoordinates;
}

void CvrpRawData::setNodeCoordinates(const QList<Vrp2dCoordinate> nodeCoordinates)
{
    m_nodeCoordinates = nodeCoordinates;
}

void CvrpRawData::appendToCoordinates(const Vrp2dCoordinate p_node)
{
    m_nodeCoordinates.append(p_node);
}
QList<CvrpDemand> CvrpRawData::demands() const
{
    return m_demands;
}

void CvrpRawData::setDemands(const QList<CvrpDemand> demands)
{
    m_demands = demands;
}

void CvrpRawData::appendToDemands(const CvrpDemand p_demand)
{
    m_demands.append(p_demand);
}
quint32 CvrpRawData::depot() const
{
    return m_depot;
}

void CvrpRawData::setDepot(const quint32 depot)
{
    m_depot = depot;
}

} // namespace Vrp
