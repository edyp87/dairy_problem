#pragma once

#include <QString>

namespace Vrp
{

class ICvrpFile
{
public:
    virtual QString readLine() const = 0;
    virtual bool atEnd() const = 0;
};

} // namespace Vrp
