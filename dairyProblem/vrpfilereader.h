#ifndef VRPFILEREADER_H
#define VRPFILEREADER_H

#include <QTextStream>
#include <QFile>
#include <memory>

#include <cvrpfile.h>
#include <cvrpdata.h>

/*
 * This reader is implemented only for CVRP problems with two dimension.
 */

namespace Vrp
{

class VrpFileReader
{
public:
    explicit VrpFileReader(const QString p_filename);
    CvrpData getData();

private:
    void serializeFileToDataClass();
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

#endif // VRPFILEREADER_H
