#include <iostream>
#include <vrpfilereader.h>
#include <QDirIterator>

QList<VrpFileReader> g_fileList;

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

                VrpFileReader(info.filePath());
            }
            if (info.isDir())
            {
                //scan again
            }
        }
    }
    return 0;
}
