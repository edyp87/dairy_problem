#include "vrpfilereader.h"
#include <QDebug>
#include <QStringList>
#include <stdexcept>

VrpFileReader::VrpFileReader(const QString p_filename)
    : m_file(p_filename)
{
    serializeFileToDataClass();
}

void VrpFileReader::serializeFileToDataClass()
{
    while (not m_file.atEnd())
    {
        processNextLine();
    }
}

void VrpFileReader::processNextLine()
{
    QString l_line = m_file.readLine();

    if (l_line.isNull())
    {
        qDebug() << "END OF FILE reached.";
        return;
    }

    QStringList l_wordList = splitLine(l_line);
    removeWhiteSpaces(l_wordList);

    if (l_wordList.isEmpty())
    {
        qDebug() << "Skipped empty line";
        return;
    }

    processLine(l_wordList, l_line);
}

void VrpFileReader::removeWhiteSpaces(QStringList &l_wordList)
{
    l_wordList.replaceInStrings(QRegExp("\\s*"), "");
}

void VrpFileReader::processLine(QStringList l_wordList, QString l_line)
{
    switch (Utils::findEnumForKeyword(l_wordList[0]))
    {
        case Utils::e_keywords::NAME:
            readName(l_wordList);
            break;
        case Utils::e_keywords::COMMENT:
            readComment(l_line);
            break;
        case Utils::e_keywords::TYPE:
            readVrpType(l_wordList);
            break;
         case Utils::e_keywords::DIMENSION:
            readDimension(l_wordList);
            break;
         case Utils::e_keywords::EDGE_WEIGHT_TYPE:
            readEdgesType(l_wordList);
            break;
         case Utils::e_keywords::CAPACITY:
            readCapacity(l_wordList);
            break;
         case Utils::e_keywords::NODE_COORD_SECTION:
            readCoordinates();
            break;
         case Utils::e_keywords::DEMAND_SECTION:
            readDemands();
            break;
         case Utils::e_keywords::DEPOT_SECTION:
            readDepots();
            break;
         case Utils::e_keywords::END:
            break;
         default:
            throw std::runtime_error(std::string("Unimplemented token!"));
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
    quint32 l_dimension = m_data.dimension();

    while (l_dimension--)
    {
        QString l_line = m_file.readLine();
        auto l_list = l_line.split(" ");
        l_list.removeAll("");
        m_data.appendToDemands({l_list[0].toUInt(), l_list[1].toUInt()});
        qDebug() << "READER: Demand set: " <<  m_data.demands().last();
    }
}

void VrpFileReader::readDepots()
{
    QString l_line = m_file.readLine();
    bool l_isDepotSet = false;

    while (l_line.toInt() != -1)
    {
        m_data.setDepot(l_line.toUInt());
        l_isDepotSet = true;
        l_line = m_file.readLine();
    }

    if (not l_isDepotSet)
    {
        throw std::runtime_error(std::string("No depot in input file!"));
    }
}

void VrpFileReader::readCapacity(QStringList l_wordList)
{
    m_data.setCapacity(l_wordList[1].toInt());
    qDebug() << "READER: Capacity set: " << m_data.capacity();
}

void VrpFileReader::readEdgesType(QStringList l_wordList)
{
    if (l_wordList[1] != "EUC_2D")
    {
        throw std::runtime_error(std::string("Edge weight type unsupported!"));
    }
    m_data.setEdgeWeightType(l_wordList[1]);
    qDebug() << "READER: Type of edge weight set: " << m_data.edgeWeightType();
}

void VrpFileReader::readDimension(QStringList l_wordList)
{
    m_data.setDimension(l_wordList[1].toInt());
    qDebug() << "READER: Dimension set: " << m_data.dimension();
}

void VrpFileReader::readVrpType(QStringList l_wordList)
{
    if (l_wordList[1] != "CVRP")
    {
        throw std::runtime_error(std::string("VRP Type unsupported!"));
    }
    m_data.setType(l_wordList[1]);
    qDebug() << "READER: Type set: " << m_data.type();
}

void VrpFileReader::readComment(QString l_line)
{
    m_data.setComment(l_line);
    qDebug() << "READER: Comment set: " << m_data.comment();
}

void VrpFileReader::readName(QStringList l_wordList)
{
    m_data.setName(l_wordList[1]);
    qDebug() << "READER: Name set: " << m_data.name();
}

QStringList VrpFileReader::splitLine(QString p_line)
{
    return p_line.split(CvrpFile::s_descriptionSplitter);
}

CvrpData VrpFileReader::getData()
{
    return m_data;
}
