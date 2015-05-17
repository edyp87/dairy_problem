# pragma once

#include <utilities/DairyPath.h>
#include <dataConverter/PolarMatrixData.h>
#include <algorithms/SweepingAlgorithm.h>

class TabuAlgorithm
{
public:
    TabuAlgorithm(Vrp::SharedPolarMatrix p_polarData);
    DairyPath compute();

private:
    void reduceTabuListSize(QList<DairyPath> l_tabu);
    void updateBestSolution(DairyPath l_bestCandidate, DairyPath l_bestSolution);
    DairyPath findBestCandidate(QList<DairyPath> l_tabu, DairyPath l_currentSolution);
    bool stoppingCondition();
    QList<DairyPath> solutionNeighborhood(DairyPath);

    Vrp::SharedPolarMatrix m_polarData;
    SweepingAlgorithm m_initialSolution;
    static const qint32 s_tabuListSize = 10;
};
