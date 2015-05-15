
#include <dataConverter/PolarCoordinatesMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>

int main()
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>("../../dairyProblem/data/A-n32-k5.vrp");
    Vrp::PolarCoordinatesMatrixConverter l_polarConv(Vrp::CvrpFileReader(l_file).getData());
   // SweepingAlgorithm l_algorithm(l_polarConv.convertAndSortByAngle());

    QList<PolarCoordinate> asd = l_polarConv.convert()->polarCoordinates();
    for ( int i =0 ; i < asd.size(); i++)
    {
        qDebug() << "index " << asd[i].index << " angle " <<asd[i].angle ;
    }
}
