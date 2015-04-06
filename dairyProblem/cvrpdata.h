#ifndef CVRPDATA_H
#define CVRPDATA_H

#include <QString>
#include <QList>
#include <vrp2dcoordinate.h>
#include <vrpdemand.h>

class CvrpData
{
public:
    CvrpData();
    QString name() const;
    void setName(const QString p_name);
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

    QList<Vrp2dCoordinate> nodeCoordinates() const;
    void setNodeCoordinates(const QList<Vrp2dCoordinate> nodeCoordinates);
    void appendToCoordinates(const Vrp2dCoordinate p_node);

    QList<VrpDemand> demands() const;
    void setDemands(const QList<VrpDemand> demands);
    void appendToDemands(const VrpDemand p_demand);

    quint32 depot() const;
    void setDepot(const quint32 depot);

private:
    QString m_name;
    QString m_comment;
    QString m_type;
    quint32 m_dimension;
    QString m_edgeWeightType;
    quint32 m_capacity;
    quint32 m_depot;
    QList<Vrp2dCoordinate> m_nodeCoordinates;
    QList<VrpDemand> m_demands;
};

#endif // CVRPDATA_H
