#include<dataReader/CvrpFilereader.h>
#include <gmock/gmock.h>

class CvrpFileReaderTest : public testing::Test
{

};

TEST_F(CvrpFileReaderTest, CanBeCreated)
{
    const QString l_filePath = "../../dairyProblem/data/A-n32-k5.vrp";

    ASSERT_NO_THROW(Vrp::CvrpFileReader { l_filePath });
}

TEST_F(CvrpFileReaderTest, ThrowsExceptionWhenFileNotFound)
{
    const QString l_filePath = "../../dairyProblem/data/dummy.vrp";

    ASSERT_ANY_THROW(Vrp::CvrpFileReader { l_filePath });
}

TEST_F(CvrpFileReaderTest, DataIsReadedCorrectly)
{
    const QString l_filePath = "../../dairyProblem/data/A-n32-k5.vrp";

    Vrp::CvrpFileReader l_cvrpFileReader { l_filePath };

    l_cvrpFileReader.readData();

    std::shared_ptr<Vrp::CvrpRawData> l_cvrpRawData = l_cvrpFileReader.getData();

    ASSERT_EQ(l_cvrpRawData->name(), "A-n32-k5");
    ASSERT_EQ(l_cvrpRawData->comment(), "COMMENT : (Augerat et al, Min no of trucks: 5, Optimal value: 784)");
    ASSERT_EQ(l_cvrpRawData->type(), "CVRP");
    ASSERT_EQ(l_cvrpRawData->dimension(), 32);
    ASSERT_EQ(l_cvrpRawData->edgeWeightType(), "EUC_2D");
    ASSERT_EQ(l_cvrpRawData->capacity(), 100);
    ASSERT_EQ(l_cvrpRawData->nodeCoordinates().size(), l_cvrpRawData->dimension());

    ASSERT_EQ(l_cvrpRawData->nodeCoordinates()[0].index, 1);
    ASSERT_EQ(l_cvrpRawData->nodeCoordinates()[0].x, 82);
    ASSERT_EQ(l_cvrpRawData->nodeCoordinates()[0].y, 76);

    ASSERT_EQ(l_cvrpRawData->nodeCoordinates().last().index, 32);
    ASSERT_EQ(l_cvrpRawData->nodeCoordinates().last().x, 98);
    ASSERT_EQ(l_cvrpRawData->nodeCoordinates().last().y, 5);

    ASSERT_EQ(l_cvrpRawData->demands()[0].index, 1);
    ASSERT_EQ(l_cvrpRawData->demands()[0].demand, 0);

    ASSERT_EQ(l_cvrpRawData->demands().last().index, 32);
    ASSERT_EQ(l_cvrpRawData->demands().last().demand, 9);

    ASSERT_EQ(l_cvrpRawData->depot(), 1);

}
