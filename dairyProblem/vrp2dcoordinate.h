#ifndef VRP2DCOORDINATE_H
#define VRP2DCOORDINATE_H

#include <QtGlobal>
#include <QTextStream>
#include <QDebug>

struct Vrp2dCoordinate
{
    quint32 index;
    qreal x, y;
};

QTextStream& operator<<(QTextStream& cout, const Vrp2dCoordinate& p_node);
QDebug operator<<(QDebug cout, const Vrp2dCoordinate& p_node);

#endif // VRP2DCOORDINATE_H
