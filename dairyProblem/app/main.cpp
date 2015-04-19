#include <dataConverter/DistanceMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>
#include <algorithms/NearestNeighbourHeuristic.h>

int main()
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>("../dairyProblem/data/A-n32-k5.vrp");
    Vrp::DistanceMatrixConverter l_distanceMatrixConv(Vrp::CvrpFileReader(l_file).getData());
    NearestNeighbourHeuristic l_heuristic(std::dynamic_pointer_cast<Vrp::CvrpDistanceMatrixData>(l_distanceMatrixConv.convert()));

    qDebug() << l_heuristic.compute();
    return 0;
}
