#ifndef NEARESTNEIGHBOURHEURISTIC_H
#define NEARESTNEIGHBOURHEURISTIC_H

#include <dataConverter/CvrpDistanceMatrixData.h>
#include <memory>
#include <QList>

class NearestNeighbourHeuristic
{
public:
    explicit NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix);
private:
    Vrp::SharedCvrpDistanceMatrix m_distanceMatrix;
    static const quint8 s_minDimmension = 3;
};

#endif // NEARESTNEIGHBOURHEURISTIC_H
