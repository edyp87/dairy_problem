#pragma once

namespace Vrp
{

class CvrpRawData;

class IDataReader
{
public:
    virtual void readData() = 0;
    virtual std::shared_ptr<CvrpRawData> getData() const = 0;
};

} // namespace Vrp
