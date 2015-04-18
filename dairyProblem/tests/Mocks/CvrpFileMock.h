#pragma once

#include <gmock/gmock.h>
#include <dataReader/ICvrpFile.h>

class CvrpFileMock : public Vrp::ICvrpFile
{
public:
    MOCK_CONST_METHOD0(readLine, QString());
    MOCK_CONST_METHOD0(atEnd, bool());
};

