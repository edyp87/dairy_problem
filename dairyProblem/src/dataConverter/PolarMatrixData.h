#pragma once
#include <QString>
#include <dataReader/Vrp2dCoordinate.h>
#include <dataConverter/PolarCoordinate.hpp>
#include <dataReader/CvrpDemand.h>
#include <memory>

namespace Vrp
{

class PolarMatrixData
{
public:
    PolarMatrixData();

    QString name() const;
    void setName(const QString &name);
    QString comment() const;
    void setComment(const QString &comment);
    QString type() const;
    void setType(const QString &type);
    quint32 dimension() const;
    void setDimension(const quint32 &dimension);
    QString edgeWeightType() const;
    void setEdgeWeightType(const QString &edgeWeightType);
    quint32 capacity() const;
    void setCapacity(const quint32 &capacity);
    quint32 depot() const;
    void setDepot(const quint32 &depot);
    QList<Vrp2dCoordinate> nodeCoordinates() const;
    void setNodeCoordinates(const QList<Vrp2dCoordinate> &nodeCoordinates);
    QList<CvrpDemand> demands() const;
    void setDemands(const QList<CvrpDemand> &demands);
    QList<PolarCoordinate> &polarCoordinates();
    void setPolarCoordinates(const QList<PolarCoordinate> &polarCoordinates);

private:
    QString m_name;
    QString m_comment;
    QString m_type;
    quint32 m_dimension;
    QString m_edgeWeightType;
    quint32 m_capacity;
    quint32 m_depot;
    QList<Vrp2dCoordinate> m_nodeCoordinates;
    QList<PolarCoordinate> m_polarCoordinates;
    QList<CvrpDemand> m_demands;
};

using SharedPolarMatrix = std::shared_ptr<Vrp::PolarMatrixData>;

} // namespace Vrp
