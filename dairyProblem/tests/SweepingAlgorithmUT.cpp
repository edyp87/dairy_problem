
#include <gmock/gmock.h>
#include <algorithms/SweepingAlgorithm.h>

class SweepingAlgorithmTest : public testing::Test
{
public:
};

TEST_F(SweepingAlgorithmTest, SweepingAlgorithmAlgorithmCanBeCreated)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>();
    SweepingAlgorithm l_algorithm { l_polarData };
}

TEST_F(SweepingAlgorithmTest, ReturnsSimpleRoadWhenOnlyTwoNodesExist)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>();

    l_polarData->setDepot(1);

    l_polarData->setDimension(2);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 1});

    SweepingAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 1}));
}
