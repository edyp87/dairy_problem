#include "CvrpDistanceMatrixData.h"

namespace Vrp
{

CvrpDistanceMatrixData::CvrpDistanceMatrixData(const quint64 p_size)
    : m_distanceData(p_size)
{
}
QList<CvrpDemand> &CvrpDistanceMatrixData::demands()
{
    return m_demands;
}

void CvrpDistanceMatrixData::setDemands(const QList<CvrpDemand> demands)
{
    m_demands = demands;
}
Utilities::SquareMatrix CvrpDistanceMatrixData::distanceData() const
{
    return m_distanceData;
}

void CvrpDistanceMatrixData::setDistanceData(const Utilities::SquareMatrix distanceData)
{
    m_distanceData = distanceData;
}

QList<Vrp2dCoordinate> CvrpDistanceMatrixData::nodeCoordinates() const
{
    return m_nodeCoordinates;
}

void CvrpDistanceMatrixData::setNodeCoordinates(const QList<Vrp2dCoordinate> nodeCoordinates)
{
    m_nodeCoordinates = nodeCoordinates;
}

quint32 CvrpDistanceMatrixData::depot() const
{
    return m_depot;
}

void CvrpDistanceMatrixData::setDepot(const quint32 depot)
{
    m_depot = depot;
}

quint32 CvrpDistanceMatrixData::capacity() const
{
    return m_capacity;
}

void CvrpDistanceMatrixData::setCapacity(const quint32 capacity)
{
    m_capacity = capacity;
}

QString CvrpDistanceMatrixData::edgeWeightType() const
{
    return m_edgeWeightType;
}

void CvrpDistanceMatrixData::setEdgeWeightType(const QString edgeWeightType)
{
    m_edgeWeightType = edgeWeightType;
}

quint32 CvrpDistanceMatrixData::dimension() const
{
    return m_dimension;
}

void CvrpDistanceMatrixData::setDimension(const quint32 dimension)
{
    m_dimension = dimension;
}

QString CvrpDistanceMatrixData::type() const
{
    return m_type;
}

void CvrpDistanceMatrixData::setType(const QString type)
{
    m_type = type;
}

QString CvrpDistanceMatrixData::comment() const
{
    return m_comment;
}

void CvrpDistanceMatrixData::setComment(const QString comment)
{
    m_comment = comment;
}

QString CvrpDistanceMatrixData::name() const
{
    return m_name;
}

void CvrpDistanceMatrixData::setName(const QString name)
{
    m_name = name;
}

qreal CvrpDistanceMatrixData::getDistanceBetweenNodes(quint64 p_firstIndex, quint64 p_secondIndex)
{
    return m_distanceData[p_firstIndex][p_secondIndex];
}

QDebug &operator<<(QDebug &cout, const CvrpDistanceMatrixData &p_distanceMatrix)
{
    for (quint64 i = 0; i < p_distanceMatrix.dimension(); ++i)
    {
        cout << p_distanceMatrix.distanceData()[i];
    }
    return cout;
}

} // namespace Vrp
