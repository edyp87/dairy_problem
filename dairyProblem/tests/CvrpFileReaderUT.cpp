#include<dataReader/CvrpFilereader.h>
#include <Mocks/CvrpFileMock.h>
#include <gmock/gmock.h>

class CvrpFileReaderTest : public testing::Test
{

};

TEST_F(CvrpFileReaderTest, CanBeCreated)
{
    const QString l_filePath = "../../dairyProblem/data/A-n32-k5.vrp";

    std::shared_ptr<Vrp::ICvrpFile> l_cvrpFle { new Vrp::CvrpFile(l_filePath) };

    ASSERT_NO_THROW(Vrp::CvrpFileReader { l_cvrpFle });
}

TEST_F(CvrpFileReaderTest, MockCanBeInjected)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    EXPECT_CALL(*l_cvrpFle, atEnd()).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader { l_cvrpFle };
}

TEST_F(CvrpFileReaderTest, NameCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("NAME : A-n32-k5"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->name(), "A-n32-k5");
}

TEST_F(CvrpFileReaderTest, CommentCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("COMMENT : example"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->comment(), "COMMENT : example");
}

TEST_F(CvrpFileReaderTest, VrpTypeCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("TYPE : CVRP"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->type(), "CVRP");
}

TEST_F(CvrpFileReaderTest, DimensionCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("DIMENSION : 32"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->dimension(), 32);
}

TEST_F(CvrpFileReaderTest, CoordinatesCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("DIMENSION : 32"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("NODE_COORD_SECTION"));
    EXPECT_CALL(*l_cvrpFle, readLine()).Times(32).InSequence(l_sequence).WillRepeatedly(testing::Return("1 2 3"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader { l_cvrpFle };
}

TEST_F(CvrpFileReaderTest, DemandsCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("DIMENSION : 32"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("DEMAND_SECTION"));
    EXPECT_CALL(*l_cvrpFle, readLine()).Times(32).InSequence(l_sequence).WillRepeatedly(testing::Return("1 2"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader { l_cvrpFle };
}

TEST_F(CvrpFileReaderTest, EdgeWeightTypeCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("EDGE_WEIGHT_TYPE : EUC_2D"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->edgeWeightType(), "EUC_2D");
}

TEST_F(CvrpFileReaderTest, CapacityCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("CAPACITY : 100"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->capacity(), 100);
}

TEST_F(CvrpFileReaderTest, DepotCanBeRead)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("DEPOT_SECTION"));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("1"));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("-1"));
    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(true));

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };
    ASSERT_EQ(l_cvrpFileReader.getData()->depot(), 1);
}

TEST_F(CvrpFileReaderTest, WillThrowErrorIfUnimplementedTokenAppeared)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("EDGE_WEIGHT_FORMAT"));

    ASSERT_ANY_THROW(Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle });
}

TEST_F(CvrpFileReaderTest, WillThrowErrorIfUndefinedTokenAppeared)
{
    std::shared_ptr<CvrpFileMock> l_cvrpFle { new CvrpFileMock };

    ::testing::Sequence l_sequence;


    EXPECT_CALL(*l_cvrpFle, atEnd()).InSequence(l_sequence).WillOnce(testing::Return(false));
    EXPECT_CALL(*l_cvrpFle, readLine()).InSequence(l_sequence).WillOnce(testing::Return("UNDEFINED_TOKEN"));

    ASSERT_ANY_THROW(Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle });
}

TEST_F(CvrpFileReaderTest, DataIsReadedCorrectlyFromExistingFile)
{
    const QString l_filePath = "../../dairyProblem/data/A-n32-k5.vrp";

    std::shared_ptr<Vrp::ICvrpFile> l_cvrpFle { new Vrp::CvrpFile(l_filePath) };

    Vrp::CvrpFileReader l_cvrpFileReader { l_cvrpFle };

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
