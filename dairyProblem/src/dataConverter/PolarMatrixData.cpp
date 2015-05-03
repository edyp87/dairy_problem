#include "PolarMatrixData.h"

namespace Vrp
{

PolarMatrixData::PolarMatrixData()
{
}

QString PolarMatrixData::name() const
{
    return m_name;
}

void PolarMatrixData::setName(const QString &name)
{
    m_name = name;
}

QString PolarMatrixData::comment() const
{
    return m_comment;
}

void PolarMatrixData::setComment(const QString &comment)
{
    m_comment = comment;
}

QString PolarMatrixData::type() const
{
    return m_type;
}

void PolarMatrixData::setType(const QString &type)
{
    m_type = type;
}

quint32 PolarMatrixData::dimension() const
{
    return m_dimension;
}

void PolarMatrixData::setDimension(const quint32 &dimension)
{
    m_dimension = dimension;
}

QString PolarMatrixData::edgeWeightType() const
{
    return m_edgeWeightType;
}

void PolarMatrixData::setEdgeWeightType(const QString &edgeWeightType)
{
    m_edgeWeightType = edgeWeightType;
}

quint32 PolarMatrixData::capacity() const
{
    return m_capacity;
}

void PolarMatrixData::setCapacity(const quint32 &capacity)
{
    m_capacity = capacity;
}

quint32 PolarMatrixData::depot() const
{
    return m_depot;
}

void PolarMatrixData::setDepot(const quint32 &depot)
{
    m_depot = depot;
}

QList<Vrp2dCoordinate> PolarMatrixData::nodeCoordinates() const
{
    return m_nodeCoordinates;
}

void PolarMatrixData::setNodeCoordinates(const QList<Vrp2dCoordinate> &nodeCoordinates)
{
    m_nodeCoordinates = nodeCoordinates;
}

QList<CvrpDemand> PolarMatrixData::demands() const
{
    return m_demands;
}

void PolarMatrixData::setDemands(const QList<CvrpDemand> &demands)
{
    m_demands = demands;
}

QList<PolarCoordinate> &PolarMatrixData::polarCoordinates()
{
    return m_polarCoordinates;
}

void PolarMatrixData::setPolarCoordinates(const QList<PolarCoordinate> &polarCoordinates)
{
    m_polarCoordinates = polarCoordinates;
}

} // namespace Vrp
