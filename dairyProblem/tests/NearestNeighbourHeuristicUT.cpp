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

TEST_F(NearestNeighbourHeuristicTest, ThrowsExceptionWhenMatrixSizeIsSmallerThanThree)
{
    const quint64 l_matrixSize { 1 };

    Vrp::SharedCvrpDistanceMatrix l_distanceDataWithOneElem
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);
    Vrp::SharedCvrpDistanceMatrix l_distanceDataWithTwoElems
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize+1);
    Vrp::SharedCvrpDistanceMatrix l_distanceDataWithThreeElems
        = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize+2);

    ASSERT_ANY_THROW(NearestNeighbourHeuristic { l_distanceDataWithOneElem });
    ASSERT_ANY_THROW(NearestNeighbourHeuristic { l_distanceDataWithTwoElems });
    ASSERT_NO_THROW (NearestNeighbourHeuristic { l_distanceDataWithThreeElems });
}
