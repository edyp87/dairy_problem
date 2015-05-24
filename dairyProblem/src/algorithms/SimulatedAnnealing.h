# pragma once

#include <utilities/DairyPath.h>
#include <dataConverter/PolarMatrixData.h>
#include <algorithms/SweepingAlgorithm.h>
#include "algorithms/LambdaInterchange.h"

class SimulatedAnnealing
{
public:
    SimulatedAnnealing(Vrp::SharedPolarMatrix p_polarData);
    DairyPath compute();

private:
    DairyPath getRandomNeighbour(const DairyPath p_currentSolution);
    bool isSolutionValid(DairyPath p_solutionCandidate);
    quint64 getDemandForIndex(quint64 p_nodeIndex);

    QList<QPair<QPair<quint32, quint32>, qreal> > sortDistances();

    Vrp::SharedPolarMatrix m_polarData;
    SweepingAlgorithm m_initialSolution;
    LambdaInterchange m_neighbourhoodGenerator;
    qreal m_temperature = 5000.0;
    qreal m_epsilon = 0.001;
    QList<QPair<quint32, quint32>> m_listOfClosest;

    static constexpr qreal s_alphaTemp = 0.99;
};
