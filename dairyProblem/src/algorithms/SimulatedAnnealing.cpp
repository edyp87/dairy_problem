#include "SimulatedAnnealing.h"
#include <QTime>
#include <QtMath>
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData), m_initialSolution(p_polarData), m_neighbourhoodGenerator(p_polarData)
{
    qsrand(QTime::currentTime().msec());
}

DairyPath SimulatedAnnealing::compute()
{
    DairyPath l_currentSolution = m_initialSolution.compute();

    int iterations = 0;

    while (m_temperature > m_epsilon)
    {
        iterations++;
        DairyPath l_randomNeigh = getRandomNeighbour(l_currentSolution);

        qreal l_deltaDistance = l_randomNeigh.distance - l_currentSolution.distance;

        if (l_deltaDistance < 0)
        {
            l_currentSolution = l_randomNeigh;
        }
        else
        {
            qreal l_randomTrial = (qrand() % 100) / 100.0;
            if (l_randomTrial < qExp(-l_deltaDistance / m_temperature))
            {
               // qDebug() << "ACCEPTED " << l_randomTrial << " < " << qExp(-l_deltaDistance / m_temperature);
                l_currentSolution = l_randomNeigh;
            }
        }

        m_temperature *= s_alphaTemp;


      //  std::cout << "distance " << l_currentSolution.distance << std::endl;
    }
    return l_currentSolution;

}

DairyPath SimulatedAnnealing::getRandomNeighbour(const DairyPath p_currentSolution)
{
    QList<DairyPath> l_candidateNeighborhood = m_neighbourhoodGenerator.generateNeigborhood(p_currentSolution);
    int l_randomNeighIndex {};
    do
    {
        l_randomNeighIndex = qrand() % l_candidateNeighborhood.size();
    }
    while(not isSolutionValid(l_candidateNeighborhood[l_randomNeighIndex]));

    return l_candidateNeighborhood[l_randomNeighIndex];

}

bool SimulatedAnnealing::isSolutionValid(DairyPath p_solutionCandidate)
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

quint64 SimulatedAnnealing::getDemandForIndex(quint64 p_nodeIndex)
{
    return m_polarData->demands()[p_nodeIndex-1].demand;
}

