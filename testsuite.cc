
#include <iostream>

#include "vectorconst.hh"

#include <gtest/gtest.h>


class VectorConstTestFixture : public testing::Test
{
protected:

    virtual void SetUp()
    {
        intVector.push_back( 1 );
        intVector.push_back( 2 );
        intVector.push_back( 3 );
    }

    virtual void TearDown()
    {
        intVector.clear();
    }

    std::vector< int > intVector;
};

TEST_F( VectorConstTestFixture, Constructor )
{
    vectorconst< int > constIntVector( intVector );
}

TEST_F( VectorConstTestFixture, At )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.at( 2 ), intVector.at( 2 ) );
}

TEST_F( VectorConstTestFixture, indexOperator )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector[ 1 ], intVector[ 1 ] );
}

TEST_F( VectorConstTestFixture, front )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.front(), intVector.front() );
}

TEST_F( VectorConstTestFixture, back )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.back(), intVector.back() );
}

TEST_F( VectorConstTestFixture, size )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.size(), intVector.size() );
}

TEST_F( VectorConstTestFixture, max_size )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.max_size(), intVector.max_size() );
}

TEST_F( VectorConstTestFixture, empty )
{
    vectorconst< int > constIntVector( intVector );

    EXPECT_EQ( constIntVector.empty(), intVector.empty() );
}

// Copied from gtest/src/gtest_main.cc
GTEST_API_ int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


