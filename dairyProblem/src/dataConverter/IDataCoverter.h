#pragma once

#include <memory>
#include <dataConverter/ICvrpGraphData.h>

class IDataConverter
{
public:
    virtual std::shared_ptr<ICvrpGraphData> convert() = 0;
};
