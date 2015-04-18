#pragma once

#include <QTextStream>
#include <QFile>
#include <memory>

#include <dataReader/CvrpFile.h>
#include <dataReader/CvrpRawData.h>
#include <dataReader/IDataReader.h>
#include <memory>

/*
 * This reader is implemented only for CVRP problems with two dimension.
 */

namespace Vrp
{

class CvrpFileReader : public IDataReader
{
public:
    explicit CvrpFileReader(std::shared_ptr<ICvrpFile> p_cvrpFile);

    void readData() override;
    std::shared_ptr<CvrpRawData> getData() const override;

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

    std::shared_ptr<ICvrpFile> m_file;
    std::shared_ptr<CvrpRawData> m_data;
};

} // namespace Vrp
