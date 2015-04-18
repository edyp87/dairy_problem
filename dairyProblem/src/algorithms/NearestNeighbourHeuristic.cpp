#include "NearestNeighbourHeuristic.h"

NearestNeighbourHeuristic::NearestNeighbourHeuristic(Vrp::SharedCvrpDistanceMatrix p_distanceMatrix)
    : m_distanceMatrix(p_distanceMatrix)
{
    if (m_distanceMatrix->distanceData().size() < s_minDimmension)
    {
        throw std::runtime_error(std::string("Problem dimmension to small!"));
    }
}
