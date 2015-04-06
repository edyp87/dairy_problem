#ifndef CVRPDATA_H
#define CVRPDATA_H

#include <QString>

class CvrpData
{
public:
    CvrpData();
    QString getName();
    QString setName(QString p_name);
private:
    QString m_name;
};

#endif // CVRPDATA_H
