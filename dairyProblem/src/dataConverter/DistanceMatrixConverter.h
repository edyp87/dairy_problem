#pragma once

#include <dataConverter/IDataCoverter.h>
#include <utilities/Matrix.h>
#include <dataReader/Vrp2dCoordinate.h>

namespace Vrp
{

class CvrpRawData;

class DistanceMatrixConverter : public IDataConverter
{
public:
    explicit DistanceMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData);

    std::shared_ptr<ICvrpGraphData> convert() override;

private:
    Utilities::SquareMatrix convertPositionsToDistances();
    qreal computeDistance(Vrp2dCoordinate p_firstNode, Vrp2dCoordinate p_secondNode);

    std::shared_ptr<CvrpRawData> m_rawData;
};

} // namespace Vrp
