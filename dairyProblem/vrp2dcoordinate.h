#pragma once

#include <QtGlobal>
#include <QTextStream>
#include <QDebug>

namespace Vrp
{

struct Vrp2dCoordinate
{
    quint32 index;
    qreal x, y;
};

QDebug operator<<(QDebug cout, const Vrp2dCoordinate& p_node);

} // namespace Vrp

