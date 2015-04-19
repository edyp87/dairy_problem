#include <gmock/gmock.h>
#include <algorithms/NearestNeighbourHeuristic.h>

class NearestNeighbourHeuristicTest : public testing::Test
{
};

TEST_F(NearestNeighbourHeuristicTest, NearestNeighbourHeuristicAlgorithmCanBeCreated)
{
    const quint64 l_matrixSize { 3 };

    Vrp::SharedCvrpDistanceMatrix l_distanceData
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);
    NearestNeighbourHeuristic l_algo { l_distanceData };
}

TEST_F(NearestNeighbourHeuristicTest, ThrowsExceptionWhenMatrixSizeIsSmallerThanTwo)
{
    const quint64 l_matrixSize { 1 };

    Vrp::SharedCvrpDistanceMatrix l_distanceDataWithOneElem
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);
    Vrp::SharedCvrpDistanceMatrix l_distanceDataWithTwoElems
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize+1);

    ASSERT_ANY_THROW(NearestNeighbourHeuristic { l_distanceDataWithOneElem });
    ASSERT_NO_THROW(NearestNeighbourHeuristic { l_distanceDataWithTwoElems });
}

TEST_F(NearestNeighbourHeuristicTest, ReturnsSimpleRoadWhenOnlyTwoNodesExist)
{
    const quint64 l_matrixSize { 2 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setCapacity(999);
    l_simpleData->setDimension(2);
    l_simpleData->distanceData()[1][2] = 3;
    l_simpleData->distanceData()[2][1] = 3;


    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 1}));
}

TEST_F(NearestNeighbourHeuristicTest, SelectsEdgeWithSmallestWeightDuringEachMove)
{
    const quint64 l_matrixSize { 3 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setCapacity(999);
    l_simpleData->setDimension(3);
    l_simpleData->distanceData()[1][2] = 3;
    l_simpleData->distanceData()[2][1] = 3;
    l_simpleData->distanceData()[1][3] = 4;
    l_simpleData->distanceData()[3][1] = 4;
    l_simpleData->distanceData()[2][3] = 5;
    l_simpleData->distanceData()[3][2] = 5;


    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 3, 1}));
}
