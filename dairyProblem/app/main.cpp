#include <iostream>
#include <dataReader/CvrpFilereader.h>
#include <QDirIterator>
#include <QCryptographicHash>
#include <memory>
#include <dataConverter/DistanceMatrixConverter.h>
#include <dataConverter/CvrpDistanceMatrixData.h>
#include <algorithms/NearestNeighbourHeuristic.h>

QList<std::shared_ptr<Vrp::CvrpRawData>> g_dataList;

void showProgress()
{
    QDir dir("../dairyProblem/data");
    if (dir.exists())
    {
        foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::AllDirs ))
        {
            if (info.isFile())
            {
                qDebug() << info.filePath();

                g_dataList.append(Vrp::CvrpFileReader(info.filePath()).getData());
                Vrp::DistanceMatrixConverter matrixConv(g_dataList.last());
                matrixConv.convert();
            }
            if (info.isDir())
            {
                //scan again
            }
        }
    }
}

int main()
{
    //showProgress();
    Vrp::DistanceMatrixConverter l_distanceMatrixConv(Vrp::CvrpFileReader("../dairyProblem/data/A-n32-k5.vrp").getData());
    NearestNeighbourHeuristic l_heuristic(std::dynamic_pointer_cast<Vrp::CvrpDistanceMatrixData>(l_distanceMatrixConv.convert()));
  //  l_heuristic.compute();
    return 0;
}
