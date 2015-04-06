#pragma once

namespace Vrp
{

class CvrpData;

class IDataReader
{
public:
    virtual void readData() = 0;
    virtual CvrpData getData() const = 0;
};

} // namespace Vrp
