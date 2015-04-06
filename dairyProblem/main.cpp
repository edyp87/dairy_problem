#include <iostream>
#include <dataReader/cvrpfilereader.h>
#include <QDirIterator>
#include <QCryptographicHash>

QList<Vrp::CvrpData> g_dataList;

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
    showProgress();
    return 0;
}
