#pragma once

#include <utilities/DairyPath.h>
#include <dataConverter/PolarMatrixData.h>
#include <algorithms/SweepingAlgorithm.h>

class LambdaInterchange
{
public:
    LambdaInterchange(Vrp::SharedPolarMatrix p_polarData);
    QList<DairyPath> generateNeigborhood(const DairyPath p_path);

private:
    void findAllSwapsForInterThisRoute(
            const quint64 p_sublist,
            const QList<QList<quint64> > p_subroutesList,
            QList<DairyPath> &p_reulst);
    void findAllInsertionsForInterThisRoute(
            const quint64 p_sublist,
            const QList<QList<quint64> > p_subroutesList,
            QList<DairyPath> &p_reulst);
    void findAllSwapsBetweenTwoRoutes(
            const quint64 p_firstSublist,
            const quint64 p_secondSublist,
            QList<QList<quint64> > p_subroutesList,
            QList<DairyPath> &p_result);
    void findAllInsertionsBetweenTwoRoutes(
            const quint64 p_firstSublist,
            const quint64 p_secondSublist,
            QList<QList<quint64> > p_subroutesList,
            QList<DairyPath> &p_result);
    DairyPath findBestNeighbor(const DairyPath p_solution);


    QList<QList<quint64>> extractListOfSubroutes(const QList<quint64> p_route);
    qreal computeDistance(const QList<quint64> p_path);
    QList<quint64> flatNestedList(QList<QList<quint64> > p_subroutesList);

    Vrp::SharedPolarMatrix m_polarData;
};

