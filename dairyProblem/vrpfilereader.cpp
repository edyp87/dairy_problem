#include "vrpfilereader.h"
#include <QDebug>
#include <QStringList>
#include <stdexcept>

VrpFileReader::VrpFileReader(const QString &p_filename)
    : m_file(p_filename)
{
    //showFile();
    while (not m_file.atEnd())
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
    //qDebug() << l_wordList[0];
    switch (Utils::findEnumForKeyword(l_wordList[0]))
    {
        case Utils::e_keywords::NAME:
            m_data.setName(l_wordList[1]);
            qDebug() << "READER: Name set: " << m_data.name();
            break;
        case Utils::e_keywords::COMMENT:
            m_data.setComment(l_line.split(CvrpFile::s_descriptionSplitter).join(':'));
            qDebug() << "READER: Comment set: " << m_data.comment();
            break;
        case Utils::e_keywords::TYPE:
            if (l_wordList[1] != "CVRP")
            {
                throw std::runtime_error(std::string("VRP Type unsupported!"));
            }
            m_data.setType(l_wordList[1]);
            qDebug() << "READER: Type set: " << m_data.type();
            break;
         case Utils::e_keywords::DIMENSION:
            m_data.setDimension(l_wordList[1].toInt());
            qDebug() << "READER: Dimension set: " << m_data.dimension();
            break;
         case Utils::e_keywords::EDGE_WEIGHT_TYPE:
            if (l_wordList[1] != "EUC_2D")
            {
                throw std::runtime_error(std::string("Edge weight type unsupported!"));
            }
            m_data.setEdgeWeightType(l_wordList[1]);
            qDebug() << "READER: Type of edge weight set: " << m_data.edgeWeightType();
            break;
         case Utils::e_keywords::CAPACITY:
            m_data.setCapacity(l_wordList[1].toInt());
            qDebug() << "READER: Capacity set: " << m_data.capacity();
            break;
         case Utils::e_keywords::NODE_COORD_SECTION:
            readCoordinates();
         case Utils::e_keywords::DEMAND_SECTION:
            readDemands();
        default:
            break;
            //qDebug() << "ERROR!";
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

void VrpFileReader::readCoordinates()
{
    quint32 l_dimension = m_data.dimension();

    while (l_dimension--)
    {
        QString l_line = m_file.readLine();
        auto l_list = l_line.split(" ");
        l_list.removeAll("");
        m_data.appendToCoordinates({l_list[0].toUInt(), l_list[1].toFloat(), l_list[2].toFloat()});
        qDebug() << "READER: Node set: " <<  m_data.nodeCoordinates().last();


    }
}

void VrpFileReader::readDemands()
{

}
