#include "vrpfilereader.h"
#include <QDebug>
#include <QStringList>

VrpFileReader::VrpFileReader(const QString &p_filename)
    : m_file(p_filename)
{
    //showFile();
    processNextLine();
}

void VrpFileReader::processNextLine()
{
    QString l_line = m_file.readLine();

    if (l_line.isNull())
    {
        qDebug() << "END OF FILE reached.";
        return;
    }

    QStringList l_wordList = l_line.split(CvrpFile::s_descriptionSplitter);
    l_wordList.replaceInStrings(QRegExp("\\s*"), "");

    if (l_wordList.isEmpty())
    {
        qDebug() << "Skipped empty line";
        return;
    }
    qDebug() << l_wordList[0];
    switch (Utils::findEnumForKeyword(l_wordList[0]))
    {
        case Utils::e_keywords::NAME:
            m_data.setName(l_wordList[1]);
            //qDebug() << "Data set: " << m_data.getName();
            break;
        default:
            qDebug() << "ERROR!";
    }
}

void VrpFileReader::showFile()
{
    QString l_line = m_file.readLine();

    while (not l_line.isNull())
    {
        qDebug() << l_line;
        l_line = m_file.readLine();
    }
}
