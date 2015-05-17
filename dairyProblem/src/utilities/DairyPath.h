#pragma once

#include <QList>

struct DairyPath
{
    QList<quint64> path;
    qreal distance;
};

inline bool operator==(const DairyPath &p_left,  const DairyPath &p_right)
{
    return p_left.distance == p_right.distance && p_left.path == p_right.path;
}

inline bool operator!=(const DairyPath &p_left,  const DairyPath &p_right)
{
    return not (p_left == p_right);
}
