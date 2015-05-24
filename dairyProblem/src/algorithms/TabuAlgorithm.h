# pragma once

#include <utilities/DairyPath.h>
#include <dataConverter/PolarMatrixData.h>
#include <algorithms/SweepingAlgorithm.h>
#include "algorithms/LambdaInterchange.h"

class TabuAlgorithm
{
public:
    TabuAlgorithm(Vrp::SharedPolarMatrix p_polarData);
    DairyPath compute();
    QList<QList<quint64>> extractListOfSubroutes(const QList<quint64> p_route);

private:
    void reduceTabuListSize(QList<DairyPath> &l_tabu);
    void updateBestSolution(DairyPath &l_bestCandidate, DairyPath &l_bestSolution);
    DairyPath findBestCandidate(const QList<DairyPath> p_tabu, DairyPath &p_currentSolution);
    bool stoppingCondition();
    QList<DairyPath> solutionNeighborhood(DairyPath p_centerSolution);
    bool isSolutionValid(DairyPath p_solutionCandidate);
    quint64 getDemandForIndex(quint64 p_nodeIndex);

    Vrp::SharedPolarMatrix m_polarData;
    SweepingAlgorithm m_initialSolution;
    LambdaInterchange m_neighbourhoodGenerator;
    quint32 m_bestSolutionUpdates = 0;
    static const qint32 s_maxBestSolutionSleeping = 10;
    static const qint32 s_tabuListSize = 100;
};
