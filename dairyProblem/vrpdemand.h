#ifndef VRPDEMAND_H
#define VRPDEMAND_H

#include <QtGlobal>
#include <QTextStream>
#include <QDebug>

namespace Vrp
{

struct VrpDemand
{
    quint32 index, demand;
};

QDebug operator<<(QDebug cout, const VrpDemand& p_node);

} // namespace Vrp

#endif // VRPDEMAND_H
