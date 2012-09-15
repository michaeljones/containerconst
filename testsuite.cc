
#include <iostream>

#include "vectorconst.hh"

#include <gtest/gtest.h>


class Data { int a; };

class VectorConstTestFixture : public testing::Test
{
protected:

    virtual void SetUp()
    {
        intVector.push_back( 1 );
        intVector.push_back( 2 );
        intVector.push_back( 3 );

        dataVector.push_back( new Data );
        dataVector.push_back( new Data );
        dataVector.push_back( new Data );
        dataVector.push_back( new Data );
    }

    virtual void TearDown()
    {
        intVector.clear();

        for ( size_t i=0; i<dataVector.size(); ++i )
        {
            delete dataVector[i];
        }

        dataVector.clear();
    }

    std::vector< int > intVector;
    std::vector< Data* > dataVector;
};

TEST_F( VectorConstTestFixture, Constructor )
{
    vectorconst< int > constIntVector( intVector );

    vectorconst< Data* > constDataVector( dataVector );

    const Data * bob = constDataVector[ 0 ];
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

TEST_F( VectorConstTestFixture, iterator )
{
    vectorconst< int > constIntVector( intVector );

    vectorconst< int >::const_iterator constIt = constIntVector.begin();
    vectorconst< int >::const_iterator constEnd = constIntVector.end();

    std::vector< int >::iterator it = intVector.begin();
    std::vector< int >::iterator end = intVector.end();

    for ( ; it != end; ++it, ++constIt )
    {
        EXPECT_EQ( *it, *constIt );
    }
}

// Copied from gtest/src/gtest_main.cc
GTEST_API_ int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


