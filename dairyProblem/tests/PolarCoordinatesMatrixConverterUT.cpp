#include <gmock/gmock.h>
#include <dataConverter/PolarCoordinatesMatrixConverter.h>
#include <dataReader/CvrpRawData.h>
#include <iostream>

using namespace Vrp;

class PolarCoordinatesMatrixConverterTest : public testing::Test
{
public:
};

TEST_F(PolarCoordinatesMatrixConverterTest, ThrowsExceptionWhenDataSizeIsSmallerThanTwo)
{

    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 1.0, 1.0});

    ASSERT_ANY_THROW(PolarCoordinatesMatrixConverter { l_rawData });

    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 2.0, 2.0});
    ASSERT_NO_THROW(PolarCoordinatesMatrixConverter { l_rawData });
}

TEST_F(PolarCoordinatesMatrixConverterTest, ConvertReturnsTwoCoordinatesForTwoNodes)
{

    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 1.0, 1.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 2.0, 2.0});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };


        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 1.4142135);
        ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, 0.78539819);
}

TEST_F(PolarCoordinatesMatrixConverterTest, ConvertReturnsFiveCoordinateForFiveNodes)
{

    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 1.0, 1.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 2.0, 2.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {3, 3.0, 4.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {4, 4.0, 6.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {5, 5.0, 8.0});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };


    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 1.4142135);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, 0.78539819);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[2].index, 3);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[2].distance, 3.6055512);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[2].angle, 0.98279375);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[3].index, 4);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[3].distance, 5.8309517);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[3].angle, 1.0303768);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[4].index, 5);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[4].distance, 8.0622578);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[4].angle, 1.0516502);
}

TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesBelowAndToTheLeftFromDepot)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 4.0, 4.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 2.0, 1.0});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 3.6055512);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, -2.1587989);
}

TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesBelowAndToTheRightFromDepot)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 17.0, 11.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 20.0, 5.2});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 6.5299311);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, -1.0934509);
}

TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesUpAndToTheLeftFromDepot)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 17.0, 11.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 3.2, 54.2});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 45.350636);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, 1.8799952);
}

TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesUpAndToTheRightFromDepot)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 17.0, 11.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 3.2, 2.2});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 16.367041);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, -2.5739262);
}


TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesOnXAxis)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 17.0, 25.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 17.0, 200.2});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 175.2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, 1.5707964);
}

TEST_F(PolarCoordinatesMatrixConverterTest, CanConvertForNodesOnYAxis)
{
    std::shared_ptr<CvrpRawData> l_rawData = std::make_shared<CvrpRawData>();
    l_rawData->appendToCoordinates(Vrp2dCoordinate {1, 25.0, 17.0});
    l_rawData->appendToCoordinates(Vrp2dCoordinate {2, 200.2, 17.0});

    PolarCoordinatesMatrixConverter l_polarCoordinates { l_rawData };

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].index, 1);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].distance, 0.0);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[0].angle, 0.0);

    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].index, 2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].distance, 175.2);
    ASSERT_FLOAT_EQ(l_polarCoordinates.convert()[1].angle, 0);
}
