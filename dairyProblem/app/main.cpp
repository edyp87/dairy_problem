
#include <dataConverter/PolarCoordinatesMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>
#include <algorithms/TabuAlgorithm.h>
#include <algorithms/SweepingAlgorithm.h>
#include <algorithms/SimulatedAnnealing.h>
#include <iostream>
#include <stdlib.h>
#include <QDirIterator>
#include <QTime>

void perform(QString filepath)
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>(filepath);
    Vrp::PolarCoordinatesMatrixConverter l_polarConv(Vrp::CvrpFileReader(l_file).getData());
    auto m_polarData = l_polarConv.convertAndSortByAngle();
    SweepingAlgorithm l_algorithm(m_polarData);


    auto l_optimalValue = m_polarData->comment().split(" ").last();
    l_optimalValue = l_optimalValue.left(l_optimalValue.size()-1);

    auto l_optimalReal = atof(l_optimalValue.toStdString().c_str());
    std::cout << l_optimalReal / l_algorithm.compute().distance << " ";
}

int main()
{
    QStringList nameFilter("*.vrp");
    QDir directory("../../dairyProblem/data");
    QStringList txtFilesAndDirectories = directory.entryList(nameFilter);

    for(QString file : txtFilesAndDirectories)
    {
        std::cout << file.toStdString() << " ";
        const clock_t begin_time = clock();
        perform("../../dairyProblem/data/" +file);
        std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << std::endl;
    }
}
