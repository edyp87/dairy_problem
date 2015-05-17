

#include <gmock/gmock.h>
#include <algorithms/TabuAlgorithm.h>

class TabuAlgorithmTest : public testing::Test
{
public:
};

TEST_F(TabuAlgorithmTest, CanBeCreated)
{
    Vrp::SharedPolarMatrix l_polarData
        = std::make_shared<Vrp::PolarMatrixData>(2);

    l_polarData->setDepot(1);

    l_polarData->setDimension(2);
    l_polarData->polarCoordinates().append({1, 0.0, 0.0});
    l_polarData->polarCoordinates().append({2, 1.0, 1.0});

    l_polarData->demands().append({1, 0});
    l_polarData->demands().append({2, 1});

    TabuAlgorithm l_algorithm { l_polarData };
    ASSERT_EQ(l_algorithm.compute().path, QList<quint64> ({1, 2, 1}));
}
