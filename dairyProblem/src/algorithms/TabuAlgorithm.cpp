#include "TabuAlgorithm.h"

TabuAlgorithm::TabuAlgorithm(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData), m_initialSolution(p_polarData)
{

}

DairyPath TabuAlgorithm::compute()
{
    DairyPath l_currentSolution = m_initialSolution.compute();
    DairyPath l_bestSolution = l_currentSolution;

    QList<DairyPath> l_tabu {};

    while (not stoppingCondition())
    {
        DairyPath l_bestCandidate = findBestCandidate(l_tabu, l_currentSolution);

        updateBestSolution(l_bestCandidate, l_bestSolution);

        l_tabu.push_back(l_bestCandidate);

        reduceTabuListSize(l_tabu);

    }

    return l_bestSolution;
}

void TabuAlgorithm::reduceTabuListSize(QList<DairyPath> l_tabu)
{
    if (l_tabu.size() > s_tabuListSize)
    {
        l_tabu.removeFirst();
    }
}

void TabuAlgorithm::updateBestSolution(DairyPath l_bestCandidate, DairyPath l_bestSolution)
{
    if (l_bestCandidate.distance < l_bestSolution.distance)
    {
        l_bestSolution = l_bestCandidate;
    }
}

DairyPath TabuAlgorithm::findBestCandidate(QList<DairyPath> l_tabu, DairyPath l_currentSolution)
{
    DairyPath l_bestCandidate {{}, std::numeric_limits<qreal>::max()};
    QList<DairyPath> l_candidateNeighborhood = solutionNeighborhood(l_currentSolution);

    for (const DairyPath &l_candidate : l_candidateNeighborhood)
    {
        if (not l_tabu.contains(l_candidate) && l_candidate.distance < l_bestCandidate.distance)
        {
            l_bestCandidate = l_candidate;
        }
    }

    l_currentSolution = l_bestCandidate;

    return l_bestCandidate;
}

bool TabuAlgorithm::stoppingCondition()
{
    return true;
}

QList<DairyPath> TabuAlgorithm::solutionNeighborhood(DairyPath)
{
    // STUB
    return {};
}
