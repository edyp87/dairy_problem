
#include <gmock/gmock.h>
#include <algorithms/SweepingAlgorithm.h>

class SweepingAlgorithmTest : public testing::Test
{
public:
};

TEST_F(SweepingAlgorithmTest, SweepingAlgorithmAlgorithmCanBeCreated)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(2);
    SweepingAlgorithm l_algorithm { l_polarData };
}

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
