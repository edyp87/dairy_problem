#pragma once

#include <QTextStream>
#include <QFile>
#include <memory>

#include <dataReader/cvrpfile.h>
#include <dataReader/cvrpdata.h>
#include <dataReader/IDataReader.h>

/*
 * This reader is implemented only for CVRP problems with two dimension.
 */

namespace Vrp
{

class CvrpFileReader : public IDataReader
{
public:
    explicit CvrpFileReader(const QString p_filename);

    void readData() override;
    CvrpData getData() const override;

private:
    void processNextLine();
    void showFile();
    void processLine(QStringList l_wordList, QString l_line);
    void removeWhiteSpaces(QStringList &l_wordList);
    void readCoordinates();
    void readDemands();
    void readDepots();
    void readCapacity(QStringList l_wordList);
    void readEdgesType(QStringList l_wordList);
    void readDimension(QStringList l_wordList);
    void readVrpType(QStringList l_wordList);
    void readComment(QString l_line);
    void readName(QStringList l_wordList);
    QStringList splitLine(QString p_line);

    CvrpFile m_file;
    CvrpData m_data;
};

} // namespace Vrp
