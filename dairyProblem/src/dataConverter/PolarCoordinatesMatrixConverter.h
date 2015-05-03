#pragma once

#include <dataConverter/IDataCoverter.h>
#include <utilities/Matrix.h>
#include <dataConverter/PolarCoordinate.hpp>
#include <dataReader/Vrp2dCoordinate.h>

namespace Vrp
{

class CvrpRawData;

class PolarCoordinatesMatrixConverter
{
public:
    explicit PolarCoordinatesMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData);

    QList<PolarCoordinate> convert();
    QList<PolarCoordinate> convertAndSortByAngle();

private:
    QList<Vrp2dCoordinate> centerRawCoordinates();
    QList<PolarCoordinate> convertCenteredCoordinatesToPolar(const QList<Vrp2dCoordinate> l_centeredRawCoordinates);
    qreal computeDistance(Vrp2dCoordinate p_firstNode, Vrp2dCoordinate p_secondNode);
    qreal computeAngle(qreal l_x, qreal l_y);
    quint64 findIndexOfDepot();

    std::shared_ptr<CvrpRawData> m_rawData;
    static const quint8 s_minDimmension = 2;
};

} // namespace Vrp
