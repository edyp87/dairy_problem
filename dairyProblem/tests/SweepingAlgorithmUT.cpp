
#include <gmock/gmock.h>
#include <algorithms/SweepingAlgorithm.h>

class SweepingAlgorithmTest : public testing::Test
{
public:
};

TEST_F(SweepingAlgorithmTest, ReturnsSimpleRoadWhenOnlyTwoNodesExist)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(2);

    l_polarData->setDepot(1);

    l_polarData->setDimension(2);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 1});

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path, QList<quint64> ({1, 2, 1}));
}

TEST_F(SweepingAlgorithmTest, DepotsAreAppendedAtTheBeginningAndEndOfResult)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(2);

    l_polarData->setDepot(1);

    l_polarData->setDimension(2);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 1});

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path.first(), l_polarData->depot());
    ASSERT_EQ(l_algorithm.compute().path.last(), l_polarData->depot());
}

TEST_F(SweepingAlgorithmTest, DepotsAreAppendedAtTheBeginningAndEndOfResultEvenIfDepotHasBiggerAngle)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(2);

    l_polarData->setDepot(1);

    l_polarData->setDimension(2);
    l_polarData->polarCoordinates().append({2, 2.0, -2.0});
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 1});

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path.first(), l_polarData->depot());
    ASSERT_EQ(l_algorithm.compute().path.last(), l_polarData->depot());
}

TEST_F(SweepingAlgorithmTest, DividesRouteIntoSubroutes)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(4);

    l_polarData->setDepot(1);

    l_polarData->setDimension(4);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 4.0, 0.1});
    l_polarData->polarCoordinates().append({3, 3.0, 0.5});
    l_polarData->polarCoordinates().append({4, 3.0, 1.1});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 2});
    l_polarData->demands().append({3, 1});
    l_polarData->demands().append({4, 1});

    l_polarData->setCapacity(2);

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path, QList<quint64> ({1, 2, 1, 3, 4, 1}));
}

TEST_F(SweepingAlgorithmTest, CreatesRouteAccordingToDepot)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(4);

    l_polarData->setDepot(3);

    l_polarData->setDimension(4);
    l_polarData->polarCoordinates().append({3, 0.0, 0.0});
    l_polarData->polarCoordinates().append({1, 3.4, 0.2});
    l_polarData->polarCoordinates().append({2, 4.0, 0.3});
    l_polarData->polarCoordinates().append({4, 3.0, 1.1});

    l_polarData->demands().append({1, 1});
    l_polarData->demands().append({2, 1});
    l_polarData->demands().append({3, 0});
    l_polarData->demands().append({4, 2});

    l_polarData->setCapacity(2);

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path, QList<quint64> ({ 3, 1, 2, 3, 4, 3 }));
}

TEST_F(SweepingAlgorithmTest, ComputesDistancesCorrectly)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(4);

    l_polarData->setDepot(1);

    l_polarData->setDimension(4);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 4.0, 0.1});
    l_polarData->polarCoordinates().append({3, 3.0, 0.5});
    l_polarData->polarCoordinates().append({4, 3.0, 1.1});

    l_polarData->distanceData()[1][2] = l_polarData->distanceData()[2][1] = 4.0;
    l_polarData->distanceData()[1][3] = l_polarData->distanceData()[3][1] = 3.0;
    l_polarData->distanceData()[3][4] = l_polarData->distanceData()[4][3] = 0.34;
    l_polarData->distanceData()[1][4] = l_polarData->distanceData()[4][1] = 3.0;

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 2});
    l_polarData->demands().append({3, 1});
    l_polarData->demands().append({4, 1});

    l_polarData->setCapacity(2);

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_FLOAT_EQ(l_algorithm.compute().distance, 14.34);
    ASSERT_FLOAT_EQ(l_algorithm.getDistance(), 14.34);
}







///////////////////////////////////////////////////

#include <dataConverter/PolarCoordinatesMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>

TEST_F(SweepingAlgorithmTest, BigTestOnRealData)
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>("../../dairyProblem/data/A-n32-k5.vrp");
    Vrp::PolarCoordinatesMatrixConverter l_polarConv(Vrp::CvrpFileReader(l_file).getData());
    SweepingAlgorithm l_algorithm(l_polarConv.convertAndSortByAngle());

    DairyPath l_result;
    l_result.distance = 1383.4856;
    l_result.path = {1, 30, 16, 28, 23, 10, 25, 19, 9, 15, 1,
                     12, 5, 29, 24, 7, 4, 3, 27, 1, 14, 8, 18,
                     20, 31, 32, 1, 17, 22, 2, 13, 21, 1, 26, 6, 11, 1};

    ASSERT_EQ(l_algorithm.compute().path, l_result.path);

    ASSERT_FLOAT_EQ(l_algorithm.getDistance(), l_result.distance);
}
