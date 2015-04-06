#pragma once

#include <dataCoverter/IDataCoverter.h>

class CvrpRawData;

class DistanceMatrixConverter : public IDataConverter
{
public:
    DistanceMatrixConverter(std::shared_ptr<CvrpRawData> p_rawData);

    std::shared_ptr<ICvrpGraphData> convert();

private:
    std::shared_ptr<CvrpRawData> m_rawData;
};
