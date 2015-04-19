#include <gmock/gmock.h>
#include <algorithms/NearestNeighbourHeuristic.h>

class NearestNeighbourHeuristicTest : public testing::Test
{
public:
    void createSimpleMatrixWithTwoNodes(Vrp::SharedCvrpDistanceMatrix &p_simpleData)
    {
        p_simpleData->setDimension(2);
        p_simpleData->distanceData()[1][2] = 3;
        p_simpleData->distanceData()[2][1] = 3;

        p_simpleData->demands().append({1, 0});
        p_simpleData->demands().append({2, 1});
    }

    void createSimpleMatrixWithThreeNodes(Vrp::SharedCvrpDistanceMatrix &p_simpleData)
    {
        p_simpleData->setDimension(3);
        p_simpleData->distanceData()[1][2] = 3;
        p_simpleData->distanceData()[2][1] = 3;
        p_simpleData->distanceData()[1][3] = 4;
        p_simpleData->distanceData()[3][1] = 4;
        p_simpleData->distanceData()[2][3] = 5;
        p_simpleData->distanceData()[3][2] = 5;

        p_simpleData->demands().append({1, 0});
        p_simpleData->demands().append({2, 1});
        p_simpleData->demands().append({3, 1});
    }

    void createSimpleMatrixWithFourNodes(Vrp::SharedCvrpDistanceMatrix &p_simpleData)
    {
        p_simpleData->setDimension(4);
        p_simpleData->distanceData()[1][2] = 3;
        p_simpleData->distanceData()[2][1] = 3;
        p_simpleData->distanceData()[1][3] = 8;
        p_simpleData->distanceData()[3][1] = 8;
        p_simpleData->distanceData()[2][3] = 4;
        p_simpleData->distanceData()[3][2] = 4;

        p_simpleData->distanceData()[1][4] = 6;
        p_simpleData->distanceData()[4][1] = 6;
        p_simpleData->distanceData()[2][4] = 7;
        p_simpleData->distanceData()[4][2] = 7;
        p_simpleData->distanceData()[3][4] = 5;
        p_simpleData->distanceData()[4][3] = 5;

        p_simpleData->demands().append({1, 0});
        p_simpleData->demands().append({2, 1});
        p_simpleData->demands().append({3, 1});
        p_simpleData->demands().append({4, 1});
    }
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

    l_simpleData->setDepot(1);
    l_simpleData->setCapacity(999);
    createSimpleMatrixWithTwoNodes(l_simpleData);

    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 1}));
}

TEST_F(NearestNeighbourHeuristicTest, DepotsAreAppendedAtTheBeginningAndEndOfResult)
{
    const quint64 l_matrixSize { 2 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setDepot(1);
    l_simpleData->setCapacity(999);
    createSimpleMatrixWithTwoNodes(l_simpleData);

    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute().first(), l_simpleData->depot());
    ASSERT_EQ(l_algorithm.compute().last(), l_simpleData->depot());
}


TEST_F(NearestNeighbourHeuristicTest, SelectsEdgeWithSmallestWeightDuringEachMove)
{
    const quint64 l_matrixSize { 3 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setDepot(1);
    l_simpleData->setCapacity(999);
    createSimpleMatrixWithThreeNodes(l_simpleData);

    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 3, 1}));
}

TEST_F(NearestNeighbourHeuristicTest, StartsWithConfiguredDepot)
{
    const quint64 l_matrixSize { 3 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setDepot(1);
    l_simpleData->setCapacity(999);
    createSimpleMatrixWithThreeNodes(l_simpleData);

    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 3, 1}));
    l_simpleData->setDepot(2);
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({2, 1, 3, 2}));
}

TEST_F(NearestNeighbourHeuristicTest, ComeBackToDepotIfTruckIsOverloaded)
{
    const quint64 l_matrixSize { 4 };

    Vrp::SharedCvrpDistanceMatrix l_simpleData = std::make_shared<Vrp::CvrpDistanceMatrixData>(l_matrixSize);

    l_simpleData->setDepot(1);
    l_simpleData->setCapacity(2);
    createSimpleMatrixWithFourNodes(l_simpleData);

    NearestNeighbourHeuristic l_algorithm { l_simpleData };
    ASSERT_EQ(l_algorithm.compute(), QList<quint64> ({1, 2, 3, 1, 4, 1}));
}





///////////////////////////////////////////////////

#include <dataConverter/DistanceMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>

TEST_F(NearestNeighbourHeuristicTest, BigTestOnRealData)
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>("../../dairyProblem/data/A-n32-k5.vrp");
    Vrp::DistanceMatrixConverter l_distanceMatrixConv(Vrp::CvrpFileReader(l_file).getData());
    NearestNeighbourHeuristic l_algorithm(std::dynamic_pointer_cast<Vrp::CvrpDistanceMatrixData>(l_distanceMatrixConv.convert()));

    ASSERT_EQ(l_algorithm.compute(), QList<quint64>
        ({1, 31, 27, 17, 13, 2, 8, 15, 30, 23, 19, 1, 25, 28,
          21, 6, 26, 11, 9, 1, 14, 22, 32, 20, 18, 4, 24, 1,
          7, 3, 29, 5, 12, 10, 1, 16, 1}));

    ASSERT_FLOAT_EQ(l_algorithm.getDistance(), 1064.6561);
}
