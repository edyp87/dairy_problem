#ifndef CVRPFILE_H
#define CVRPFILE_H

#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <memory>

namespace Utils
{

enum class e_keywords
{
    NAME,
    TYPE,
    COMMENT,
    DIMENSION,
    CAPACITY,
    EDGE_WEIGHT_TYPE,
    EDGE_WEIGHT_FORMAT,
    EDGE_DATA_FORMAT,
    NODE_COORD_TYPE,
    DISPLAY_DATA_TYPE,
    NODE_COORD_SECTION,
    DEPOT_SECTION,
    DEMAND_SECTION,
    EDGE_DATA_SECTION,
    FIXED_EDGE_SECTION,
    DISPLAY_DATA_SECTION,
    TOUR_SECTION,
    EDGE_WEIGHT_SECTION,
    END,
    UNDEFINED
};

static QStringList keywordStringList {
    "NAME",
    "TYPE",
    "COMMENT",
    "DIMENSION",
    "CAPACITY",
    "EDGE_WEIGHT_TYPE",
    "EDGE_WEIGHT_FORMAT",
    "EDGE_DATA_FORMAT",
    "NODE_COORD_TYPE",
    "DISPLAY_DATA_TYPE",
    "NODE_COORD_SECTION",
    "DEPOT_SECTION",
    "DEMAND_SECTION",
    "EDGE_DATA_SECTION",
    "FIXED_EDGE_SECTION",
    "DISPLAY_DATA_SECTION",
    "TOUR_SECTION",
    "EDGE_WEIGHT_SECTION",
    "EOF",
    "UNDEFINED"
};

Utils::e_keywords findEnumForKeyword(QString p_keyword);

} // namespace Utils

class CvrpFile
{
public:

    CvrpFile(const QString &p_filename);

    QString readLine()
    {
        return m_cvrpRawFileStream->readLine();
    }

    bool atEnd()
    {
        return m_cvrpRawFileStream->atEnd();
    }

    static QString s_descriptionSplitter;



private:
    void loadCvrpFile();





    QFile m_cvrpRawFile;
    std::unique_ptr<QTextStream> m_cvrpRawFileStream;
};

#endif // CVRPFILE_H
