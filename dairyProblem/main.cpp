#include <iostream>
#include <dataReader/CvrpFilereader.h>
#include <QDirIterator>
#include <QCryptographicHash>
#include <memory>
#include <dataCoverter/DistanceMatrixConverter.h>

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

    auto data = Vrp::CvrpFileReader("../dairyProblem/data/A-n32-k5.vrp").getData();

    Vrp::DistanceMatrixConverter matrixConv(data);
    auto distanceMatrixData = matrixConv.convert();


    return 0;
}
