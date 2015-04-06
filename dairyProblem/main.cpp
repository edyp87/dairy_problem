#include <iostream>
#include <vrpfilereader.h>
#include <QDirIterator>

QList<CvrpData> g_dataList;

int main()
{
    QDir dir("../dairyProblem/data");
    if (dir.exists())
    {
        foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::AllDirs ))
        {
            if (info.isFile())
            {
                qDebug() << info.filePath();

                g_dataList.append(VrpFileReader(info.filePath()).getData());
            }
            if (info.isDir())
            {
                //scan again
            }
        }
    }
    return 0;
}
