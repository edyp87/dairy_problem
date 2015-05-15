#include "PolarCoordinatesMatrixConverter.h"
#include <dataConverter/CvrpDistanceMatrixData.h>
#include <dataReader/CvrpRawData.h>
#include <QtCore/QtMath>
#include <cmath>

namespace Vrp
{

PolarCoordinatesMatrixConverter::PolarCoordinatesMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData)
    : m_rawData(p_rawData)
{
    if (m_rawData->nodeCoordinates().size() < s_minDimmension)
    {
        throw std::runtime_error(std::string("Problem dimmension to small!"));
    }
}

std::shared_ptr<PolarMatrixData> PolarCoordinatesMatrixConverter::convert()
{
    std::shared_ptr<PolarMatrixData> l_polarData = std::make_shared<PolarMatrixData>(m_rawData->dimension());

    l_polarData->setCapacity(m_rawData->capacity());
    l_polarData->setComment(m_rawData->comment());
    l_polarData->setDemands(m_rawData->demands());
    l_polarData->setDepot(m_rawData->depot());
    l_polarData->setDimension(m_rawData->dimension());
    l_polarData->setEdgeWeightType(m_rawData->edgeWeightType());
    l_polarData->setName(m_rawData->name());
    l_polarData->setType(m_rawData->type());
    l_polarData->setDistanceData(convertPositionsToDistances());
    l_polarData->setPolarCoordinates(convertCenteredCoordinatesToPolar(centerRawCoordinates()));
    return l_polarData;
}

std::shared_ptr<PolarMatrixData> PolarCoordinatesMatrixConverter::convertAndSortByAngle()
{
    auto l_comparator = [](const PolarCoordinate & l_left, const PolarCoordinate & l_right)
        {
            return l_left.angle < l_right.angle;
        };

    std::shared_ptr<PolarMatrixData> l_polarCoordinates = convert();
    qSort(l_polarCoordinates->polarCoordinates().begin(), l_polarCoordinates->polarCoordinates().end(), l_comparator);

    return l_polarCoordinates;
}

QList<PolarCoordinate> PolarCoordinatesMatrixConverter::convertCenteredCoordinatesToPolar(
        const QList<Vrp2dCoordinate> l_centeredRawCoordinates)
{
    QList<PolarCoordinate> l_polarCoordinates;

    for (const Vrp2dCoordinate & l_centeredCoordinate : l_centeredRawCoordinates)
    {
        if (l_centeredCoordinate.index == l_centeredRawCoordinates[findIndexOfDepot()].index)
        {
            l_polarCoordinates.append(PolarCoordinate { l_centeredCoordinate.index, 0, 0});
        }
        else
        {
            l_polarCoordinates.append(PolarCoordinate { l_centeredCoordinate.index,
                                     computeDistance(l_centeredRawCoordinates[findIndexOfDepot()], l_centeredCoordinate),
                                     computeAngle(l_centeredCoordinate.x , l_centeredCoordinate.y)});
        }
    }

    return l_polarCoordinates;
}

QList<Vrp2dCoordinate> PolarCoordinatesMatrixConverter::centerRawCoordinates()
{
    auto l_rawCoordinates = m_rawData->nodeCoordinates();
    QList<Vrp2dCoordinate> l_centeredRawCoordinates;

    for (Vrp2dCoordinate & l_coordinate : l_rawCoordinates)
    {
        l_centeredRawCoordinates.
            append(Vrp2dCoordinate { l_coordinate.index,
                                     l_coordinate.x - l_rawCoordinates[findIndexOfDepot()].x,
                                     l_coordinate.y - l_rawCoordinates[findIndexOfDepot()].y});
    }

    return l_centeredRawCoordinates;
}

qreal PolarCoordinatesMatrixConverter::computeAngle(qreal l_x, qreal l_y)
{
    return qAtan2(l_y , l_x);
}

quint64 PolarCoordinatesMatrixConverter::findIndexOfDepot()
{
    for (quint64 l_idx = 0; l_idx < quint64(m_rawData->nodeCoordinates().size()); ++l_idx)
    {
        if (m_rawData->nodeCoordinates()[l_idx].index == m_rawData->depot())
        {
            return l_idx;
        }
    }
    throw std::runtime_error(std::string("Cannot find depot!"));
}

Utilities::SquareMatrix PolarCoordinatesMatrixConverter::convertPositionsToDistances()
{
    Utilities::SquareMatrix l_matrix(m_rawData->dimension());

    auto l_nodesCoordinates = m_rawData->nodeCoordinates();

    for (Vrp2dCoordinate & l_node : l_nodesCoordinates)
    {
        for (Vrp2dCoordinate & l_otherNode : l_nodesCoordinates)
        {
            l_matrix[l_node.index][l_otherNode.index] = computeDistance(l_node, l_otherNode);
            //qDebug() << "Distance node:" << l_node.index << "," << l_otherNode.index << "--" << l_matrix[l_node.index][l_otherNode.index];
        }
    }
    return l_matrix;
}

qreal PolarCoordinatesMatrixConverter::computeDistance(Vrp2dCoordinate p_firstNode, Vrp2dCoordinate p_secondNode)
{
    return qSqrt(qPow(p_firstNode.x - p_secondNode.x, 2.0) + qPow(p_firstNode.y - p_secondNode.y, 2.0));
}

} // namespace Vrp
