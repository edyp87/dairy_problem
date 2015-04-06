#ifndef VRPDEMAND_H
#define VRPDEMAND_H

#include <QtGlobal>
#include <QTextStream>
#include <QDebug>

namespace Vrp
{

struct CvrpDemand
{
    quint32 index, demand;
};

QDebug operator<<(QDebug cout, const CvrpDemand& p_node);

} // namespace Vrp

#endif // VRPDEMAND_H
