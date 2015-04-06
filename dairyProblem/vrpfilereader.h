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

class VrpFileReader
{
public:
    VrpFileReader(const QString &p_filename);
private:
    void processNextLine();
    void showFile();
    void readCoordinates();
    void readDemands();

    CvrpFile m_file;
    CvrpData m_data;
};

#endif // VRPFILEREADER_H
