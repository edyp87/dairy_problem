#include "cvrpdata.h"

CvrpData::CvrpData()
{
}

QString CvrpData::getName()
{
    return m_name;
}

QString CvrpData::setName(QString p_name)
{
    m_name = p_name;
}
