

#include <gmock/gmock.h>
#include <algorithms/TabuAlgorithm.h>

class TabuAlgorithmTest : public testing::Test
{
public:
};

//TEST_F(TabuAlgorithmTest, CanBeCreated)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(2);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(2);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

//    l_polarData->distanceData()[1][2] = 1;
//    l_polarData->distanceData()[2][1] = 1;


//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 1});

//    TabuAlgorithm l_algorithm { l_polarData };
//    ASSERT_EQ(l_algorithm.compute().path, QList<quint64> ({1, 2, 1}));
//}

//TEST_F(TabuAlgorithmTest, extracting)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(2);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(2);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 1});

//    TabuAlgorithm l_algorithm { l_polarData };
//    ASSERT_EQ(l_algorithm.extractListOfSubroutes({1,2,3,1,2,1,5,6,7,1}), QList<QList<quint64>> ({{2,3},{2},{5,6,7}}));
//}

///////////////////////////////////////////////////

#include <dataConverter/PolarCoordinatesMatrixConverter.h>
#include <dataReader/CvrpFilereader.h>

TEST_F(TabuAlgorithmTest, BigTestOnRealData)
{
    std::shared_ptr<Vrp::CvrpFile> l_file = std::make_shared<Vrp::CvrpFile>("../../dairyProblem/data/A-n69-k9.vrp");
    Vrp::PolarCoordinatesMatrixConverter l_polarConv(Vrp::CvrpFileReader(l_file).getData());
    TabuAlgorithm l_algorithm(l_polarConv.convertAndSortByAngle());

    DairyPath l_result;
    l_result.distance = 1281.9614;
    l_result.path = {1, 30, 16, 28, 23, 10, 25, 19, 9, 15, 1,
                     12, 5, 29, 24, 7, 4, 3, 27, 1, 14, 8, 18,
                     20, 31, 32, 1, 17, 22, 2, 13, 21, 1, 26, 6, 11, 1};

    //ASSERT_EQ(l_algorithm.compute().path, l_result.path);
ASSERT_FLOAT_EQ(l_algorithm.compute().distance, l_result.distance);
    //ASSERT_FLOAT_EQ(l_algorithm.getDistance(), l_result.distance);
}
