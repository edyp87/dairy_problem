#include "DistanceMatrixConverter.h"
#include <dataCoverter/CvrpDistanceMatrixData.h>
#include <dataReader/CvrpRawData.h>
#include <QtCore/QtMath>

namespace Vrp
{

DistanceMatrixConverter::DistanceMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData)
    : m_rawData(p_rawData)
{
}

std::shared_ptr<ICvrpGraphData> DistanceMatrixConverter::convert()
{
    std::shared_ptr<CvrpDistanceMatrixData> l_distanceMatrix
            = std::make_shared<CvrpDistanceMatrixData>(m_rawData->dimension());

    l_distanceMatrix->setCapacity(m_rawData->capacity());
    l_distanceMatrix->setComment(m_rawData->comment());
    l_distanceMatrix->setDemands(m_rawData->demands());
    l_distanceMatrix->setDepot(m_rawData->depot());
    l_distanceMatrix->setDimension(m_rawData->dimension());
    l_distanceMatrix->setEdgeWeightType(m_rawData->edgeWeightType());
    l_distanceMatrix->setName(m_rawData->name());
    l_distanceMatrix->setType(m_rawData->type());

    l_distanceMatrix->setDistanceData(convertPositionsToDistances());
    return l_distanceMatrix;
}

Utilities::SquareMatrix DistanceMatrixConverter::convertPositionsToDistances()
{
    Utilities::SquareMatrix l_matrix(m_rawData->dimension());

    auto l_nodesCoordinates = m_rawData->nodeCoordinates();

    for (Vrp2dCoordinate & l_node : l_nodesCoordinates)
    {
        for (Vrp2dCoordinate & l_otherNode : l_nodesCoordinates)
        {
            l_matrix[l_node.index][l_otherNode.index] = computeDistance(l_node, l_otherNode);
        }
    }
    return l_matrix;
}

qreal DistanceMatrixConverter::computeDistance(Vrp2dCoordinate p_firstNode, Vrp2dCoordinate p_secondNode)
{
    return qSqrt(qPow(p_firstNode.x - p_secondNode.x, 2.0) + qPow(p_firstNode.y - p_secondNode.y, 2.0));
}

}
