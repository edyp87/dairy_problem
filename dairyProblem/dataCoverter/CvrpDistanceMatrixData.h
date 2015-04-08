#pragma once

#include <dataCoverter/ICvrpGraphData.h>
#include <QString>
#include <dataReader/CvrpDemand.h>
#include <dataReader/Vrp2dCoordinate.h>
#include <utilities/Matrix.h>
#include <memory>

namespace Vrp
{

class CvrpDistanceMatrixData : public ICvrpGraphData
{
public:
    explicit CvrpDistanceMatrixData(const quint64 p_size);
    QString name() const;
    void setName(const QString name);
    QString comment() const;
    void setComment(const QString comment);
    QString type() const;
    void setType(const QString type);
    quint32 dimension() const;
    void setDimension(const quint32 dimension);
    QString edgeWeightType() const;
    void setEdgeWeightType(const QString edgeWeightType);
    quint32 capacity() const;
    void setCapacity(const quint32 capacity);
    quint32 depot() const;
    void setDepot(const quint32 depot);
    QList<Vrp2dCoordinate> nodeCoordinates() const;
    void setNodeCoordinates(const QList<Vrp2dCoordinate> nodeCoordinates);
    QList<CvrpDemand> demands() const;
    void setDemands(const QList<CvrpDemand> demands);
    Utilities::SquareMatrix distanceData() const;
    void setDistanceData(const Utilities::SquareMatrix distanceData);
    qreal getDistanceBetweenNodes(quint64 p_firstIndex, quint64 p_secondIndex);

private:
    QString m_name;
    QString m_comment;
    QString m_type;
    quint32 m_dimension;
    QString m_edgeWeightType;
    quint32 m_capacity;
    quint32 m_depot;
    QList<Vrp2dCoordinate> m_nodeCoordinates;
    Utilities::SquareMatrix m_distanceData;
    QList<CvrpDemand> m_demands;
};

using SharedCvrpDistanceMatrix = std::shared_ptr<Vrp::CvrpDistanceMatrixData>;

QDebug &operator<<(QDebug &cout, const CvrpDistanceMatrixData& p_distanceMatrix);

} // namespace Vrp
