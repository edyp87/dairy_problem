#pragma once

#include <QtGlobal>

class ICvrpGraphData
{
public:
    virtual qreal getDistanceBetweenNodes(quint64, quint64) = 0;
};
