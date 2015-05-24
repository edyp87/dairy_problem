#include "LambdaInterchange.h"

LambdaInterchange::LambdaInterchange(Vrp::SharedPolarMatrix p_polarData)
    : m_polarData(p_polarData)
{
}

QList<DairyPath> LambdaInterchange::generateNeigborhood(const DairyPath p_path)
{
    QList<QList<quint64>> l_subroutesList = extractListOfSubroutes(p_path.path);

    QList<DairyPath> l_result {};



    for (int i = 0; i < l_subroutesList.size()-1; ++i)
    {
        findAllSwapsForInterThisRoute(i, l_subroutesList, l_result);
    }
    for (int i = 0; i < l_subroutesList.size(); ++i)
    {
        findAllInsertionsForInterThisRoute(i, l_subroutesList, l_result);
    }

    return l_result;
}

void LambdaInterchange::findAllSwapsForInterThisRoute(const quint64 p_sublist, const QList<QList<quint64> > p_subroutesList, QList<DairyPath> &p_reulst)
{
    for (int i = p_sublist+1; i < p_subroutesList.size(); ++i)
    {
        findAllSwapsBetweenTwoRoutes(p_sublist, i, p_subroutesList, p_reulst);
    }
}

void LambdaInterchange::findAllInsertionsForInterThisRoute(const quint64 p_sublist, const QList<QList<quint64> > p_subroutesList, QList<DairyPath> &p_reulst)
{
    for (int i = 0; i < p_subroutesList.size(); ++i)
    {
        if (static_cast<quint64>(i) != p_sublist && p_subroutesList[p_sublist].size() != 1)
        {
            findAllInsertionsBetweenTwoRoutes(p_sublist, i, p_subroutesList, p_reulst);
        }
    }
}

void LambdaInterchange::findAllSwapsBetweenTwoRoutes(const quint64 p_firstSublist,
                                                     const quint64 p_secondSublist,
                                                     QList<QList<quint64> > p_subroutesList,
                                                     QList<DairyPath> &p_result)
{
    for (int i = 0; i < p_subroutesList[p_firstSublist].size(); ++i)
    {
        for (int j = 0; j < p_subroutesList[p_secondSublist].size(); ++j)
        {
            std::swap(p_subroutesList[p_firstSublist][i], p_subroutesList[p_secondSublist][j]);
            auto l_flattedList = flatNestedList(p_subroutesList);
            p_result.append({l_flattedList, computeDistance(l_flattedList)});
            std::swap(p_subroutesList[p_firstSublist][i], p_subroutesList[p_secondSublist][j]);
        }
    }
}

void LambdaInterchange::findAllInsertionsBetweenTwoRoutes(const quint64 p_firstSublist, const quint64 p_secondSublist, QList<QList<quint64> > p_subroutesList, QList<DairyPath> &p_result)
{
    for (int i = 0; i < p_subroutesList[p_firstSublist].size(); ++i)
    {
        qreal l_bestDistance = std::numeric_limits<qreal>::max();
        QList<quint64> l_insertionCandidate {};

        for (int j = 0; j < p_subroutesList[p_secondSublist].size(); ++j)
        {
            p_subroutesList[p_secondSublist].insert(j, p_subroutesList[p_firstSublist][i]);
            p_subroutesList[p_firstSublist].removeAt(i);
            auto l_flattedList = flatNestedList(p_subroutesList);
            auto l_newDistance = computeDistance(l_flattedList);

            if (l_newDistance < l_bestDistance)
            {
                l_bestDistance = l_newDistance;
                l_insertionCandidate = l_flattedList;
            }

            p_subroutesList[p_firstSublist].insert(i, p_subroutesList[p_secondSublist][j]);
            p_subroutesList[p_secondSublist].removeAt(j);
        }

        if (not l_insertionCandidate.empty())
            p_result.append({l_insertionCandidate, l_bestDistance});

    }
}

qreal LambdaInterchange::computeDistance(const QList<quint64> p_path)
{
    auto l_lastNode = m_polarData->depot();
    qreal l_distance = 0.0f;
    for (const auto l_currentNode : p_path)
    {
        l_distance += m_polarData->distanceData()[l_lastNode][l_currentNode];
        l_lastNode = l_currentNode;
    }
    return l_distance;
}

QList<quint64> LambdaInterchange::flatNestedList(const QList<QList<quint64> > p_subroutesList)
{
    QList<quint64> l_result;

    for (const QList<quint64> & l_list : p_subroutesList)
    {
        l_result.append(m_polarData->depot());
        for (quint64 l_index : l_list)
        {
            l_result.append(l_index);
        }
    }

    l_result.append(m_polarData->depot());
    return l_result;
}

QList<QList<quint64>> LambdaInterchange::extractListOfSubroutes(const QList<quint64> p_route)
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
