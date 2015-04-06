#include "DistanceMatrixConverter.h"
#include <dataCoverter/CvrpDistanceMatrixData.h>

DistanceMatrixConverter::DistanceMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData)
    : m_rawData(p_rawData)
{
}

std::shared_ptr<ICvrpGraphData> DistanceMatrixConverter::convert()
{
    std::shared_ptr<CvrpDistanceMatrixData> l_distanceMatrix = std::make_shared<CvrpDistanceMatrixData>();

    return l_distanceMatrix;
}
