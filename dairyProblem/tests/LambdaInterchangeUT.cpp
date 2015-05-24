

#include <gmock/gmock.h>
#include <algorithms/LambdaInterchange.h>

class LambdaInterchangeTest : public testing::Test
{
public:
};

//TEST_F(LambdaInterchangeTest, DISABLED_CanBeCreated)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(2);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(2);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 1});

//    LambdaInterchange l_lambdaInterchange{ l_polarData };
//    DairyPath l_inputPath = {QList<quint64>({1,2,3,1}), 0.0f};
//    ASSERT_EQ(l_lambdaInterchange.findBestNeighbor(l_inputPath).path, QList<quint64> ({}));
//}

//TEST_F(LambdaInterchangeTest, extractListOfSubroutes)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(2);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(2);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 1});

//    LambdaInterchange l_lambdaInterchange{ l_polarData };
//    QList<quint64> l_inputPath {1,2,3,1,5,6,1};
//    ASSERT_EQ(l_lambdaInterchange.extractListOfSubroutes(l_inputPath), QList<QList<quint64>> ({{2,3},{5,6}}));
//}

//TEST_F(LambdaInterchangeTest, computeDistance)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(4);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(4);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 4.0, 0.1});
//    l_polarData->polarCoordinates().append({3, 3.0, 0.5});
//    l_polarData->polarCoordinates().append({4, 3.0, 1.1});

//    l_polarData->distanceData()[1][2] = l_polarData->distanceData()[2][1] = 4.0;
//    l_polarData->distanceData()[1][3] = l_polarData->distanceData()[3][1] = 3.0;
//    l_polarData->distanceData()[2][3] = l_polarData->distanceData()[3][2] = 3.1;
//    l_polarData->distanceData()[3][4] = l_polarData->distanceData()[4][3] = 0.34;
//    l_polarData->distanceData()[1][4] = l_polarData->distanceData()[4][1] = 3.0;

//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 2});
//    l_polarData->demands().append({3, 1});
//    l_polarData->demands().append({4, 1});

//    l_polarData->setCapacity(2);

//    LambdaInterchange l_lambdaInterchange{ l_polarData };
//    QList<quint64> l_inputPath {2,3,4};
//    ASSERT_EQ(l_lambdaInterchange.computeDistance(l_inputPath), 3.44);
//}

//TEST_F(LambdaInterchangeTest, findBestSwapBetweenTwoRoutes)
//{
//    Vrp::SharedPolarMatrix l_polarData
//        = std::make_shared<Vrp::PolarMatrixData>(4);

//    l_polarData->setDepot(1);

//    l_polarData->setDimension(4);
//    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
//    l_polarData->polarCoordinates().append({2, 4.0, 0.1});
//    l_polarData->polarCoordinates().append({3, 3.0, 0.5});
//    l_polarData->polarCoordinates().append({4, 3.0, 1.1});

//    l_polarData->distanceData()[1][2] = l_polarData->distanceData()[2][1] = 4.0;
//    l_polarData->distanceData()[1][3] = l_polarData->distanceData()[3][1] = 3.0;
//    l_polarData->distanceData()[1][4] = l_polarData->distanceData()[4][1] = 12.2;
//    l_polarData->distanceData()[2][3] = l_polarData->distanceData()[3][2] = 4.1;
//    l_polarData->distanceData()[2][4] = l_polarData->distanceData()[4][2] = 21.01;
//    l_polarData->distanceData()[3][4] = l_polarData->distanceData()[4][3] = 0.34;

//    l_polarData->demands().append({1, 0});
//    l_polarData->demands().append({2, 2});
//    l_polarData->demands().append({3, 1});
//    l_polarData->demands().append({4, 1});

//    l_polarData->setCapacity(2);

//    LambdaInterchange l_lambdaInterchange{ l_polarData };
//    QList<quint64> l_firstRoute {3,2};
//    QList<quint64> l_secondRoute {1,4};
//    QList<QList<quint64>> l_route {l_firstRoute, l_secondRoute};
//    l_lambdaInterchange.findBestSwapBetweenTwoRoutes(0, 1, l_route);
//    ASSERT_EQ(l_route, QList<QList<quint64>>({{1,2}, {3,4}}));
//}

TEST_F(LambdaInterchangeTest, findBestNeighbor)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(4);

    l_polarData->setDepot(1);

    l_polarData->setDimension(4);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 4.0, 0.1});
    l_polarData->polarCoordinates().append({3, 3.0, 0.5});
    l_polarData->polarCoordinates().append({4, 3.0, 1.1});


    l_polarData->distanceData()[1][2] = l_polarData->distanceData()[2][1] = 4.1;
    l_polarData->distanceData()[1][3] = l_polarData->distanceData()[3][1] = 3.1;
    l_polarData->distanceData()[1][4] = l_polarData->distanceData()[4][1] = 3.3;
    l_polarData->distanceData()[2][3] = l_polarData->distanceData()[3][2] = 3.4;
    l_polarData->distanceData()[2][4] = l_polarData->distanceData()[4][2] = 3.5;
    l_polarData->distanceData()[3][4] = l_polarData->distanceData()[4][3] = 0.34;

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 2});
    l_polarData->demands().append({3, 1});
    l_polarData->demands().append({4, 1});

    l_polarData->setCapacity(2);

    LambdaInterchange l_lambdaInterchange{ l_polarData };

    DairyPath l_route {{1,3,2,1,4,1}, 0.0f};
    //l_lambdaInterchange.generateNeigborhood(l_route);
    ASSERT_EQ(l_lambdaInterchange.generateNeigborhood(l_route).first().path, QList<quint64>({1,4,2,1,3,1}));
   // ASSERT_EQ(l_lambdaInterchange.generateNeigborhood(l_route).last().path, QList<quint64>({1,3,4,1,2,1}));
    ASSERT_FLOAT_EQ(l_lambdaInterchange.generateNeigborhood(l_route).first().distance, 17.1f);
   //ASSERT_FLOAT_EQ(l_lambdaInterchange.generateNeigborhood(l_route).last().distance, 14.94f);

}
