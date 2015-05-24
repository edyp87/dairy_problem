#include "TabuAlgorithm.h"

TabuAlgorithm::TabuAlgorithm(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData), m_initialSolution(p_polarData), m_neighbourhoodGenerator(p_polarData)
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
  //  qDebug() << l_bestSolution.path;

    return l_bestSolution;
}

void TabuAlgorithm::reduceTabuListSize(QList<DairyPath> &l_tabu)
{
   // qDebug() << "DUPA";
    if (l_tabu.size() > s_tabuListSize)
    {
     //   qDebug() << "Removed " << l_tabu.first().path;
        l_tabu.removeFirst();
    }
}

void TabuAlgorithm::updateBestSolution(DairyPath &l_bestCandidate, DairyPath &l_bestSolution)
{
    ++m_bestSolutionUpdates;
    if (l_bestCandidate.distance < l_bestSolution.distance)
    {
        m_bestSolutionUpdates = 0;
        l_bestSolution = l_bestCandidate;
    }
}

DairyPath TabuAlgorithm::findBestCandidate(const QList<DairyPath> p_tabu, DairyPath &p_currentSolution)
{
    DairyPath l_bestCandidate {{}, std::numeric_limits<qreal>::max()};
    QList<DairyPath> l_candidateNeighborhood = m_neighbourhoodGenerator.generateNeigborhood(p_currentSolution);//solutionNeighborhood(p_currentSolution);

    if (l_candidateNeighborhood.empty()) // only one route exists so nothing to be done
    {
        return l_bestCandidate;
    }

    for (const DairyPath &l_candidate : l_candidateNeighborhood)
    {
        if (not p_tabu.contains(l_candidate) && isSolutionValid(l_candidate) && l_candidate.distance < l_bestCandidate.distance)
        {
            l_bestCandidate = l_candidate;
        }
    }

    p_currentSolution = l_bestCandidate;

    return l_bestCandidate;
}

bool TabuAlgorithm::stoppingCondition()
{
    return m_bestSolutionUpdates == s_maxBestSolutionSleeping;
}

QList<DairyPath> TabuAlgorithm::solutionNeighborhood(DairyPath p_centerSolution)
{
    QList<QList<quint64>> l_listOfSubroutes = extractListOfSubroutes(p_centerSolution.path);
    // STUB
    return {};
}

bool TabuAlgorithm::isSolutionValid(DairyPath p_solutionCandidate)
{
    quint64 l_computedCapacity {};

    for (int i = 1; i < p_solutionCandidate.path.size(); ++i)
    {
        if (p_solutionCandidate.path[i] == m_polarData->depot())
        {
            l_computedCapacity = 0;
        }
        else
        {
            l_computedCapacity += getDemandForIndex(p_solutionCandidate.path[i]);
            if (l_computedCapacity > m_polarData->capacity())
            {
                return false;
            }
        }
    }
    return true;
}

QList<QList<quint64>> TabuAlgorithm::extractListOfSubroutes(const QList<quint64> p_route)
{
    QList<QList<quint64>> l_result;
    for (int i = 0; i != p_route.size()-1; ++i)
    {
        if (p_route[i] == m_polarData->depot())
        {
            l_result.append(QList<quint64>());
            continue;
        }
        l_result.last().append(p_route[i]);
    }
    return l_result;
}

quint64 TabuAlgorithm::getDemandForIndex(quint64 p_nodeIndex)
{
//    for (Vrp::CvrpDemand & l_demand : m_polarData->demands())
//    {
//        if (l_demand.index == p_nodeIndex)
//        {
//            return l_demand.demand;
//        }
//    }

//    throw std::runtime_error((QString("Demand for index %1 not found!").arg(p_nodeIndex)).toStdString());
    return m_polarData->demands()[p_nodeIndex-1].demand;
}
