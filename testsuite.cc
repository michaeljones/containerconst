
#include <iostream>

#include "vectorconst.hh"

#include <gtest/gtest.h>


struct Data
{
    Data( int a_ ) : a( a_ ) {}

    int a;
};

class VectorConstTestFixture : public testing::Test
{
protected:

    virtual void SetUp()
    {
        dataVector.push_back( new Data( 1 ) );
        dataVector.push_back( new Data( 2 ) );
        dataVector.push_back( new Data( 3 ) );
        dataVector.push_back( new Data( 4 ) );
    }

    virtual void TearDown()
    {
        for ( size_t i=0; i<dataVector.size(); ++i )
        {
            delete dataVector[i];
        }

        dataVector.clear();
    }

    std::vector< Data* > dataVector;
};

TEST_F( VectorConstTestFixture, Constructor )
{
    vectorconst< Data > constDataVector( dataVector );
}

TEST_F( VectorConstTestFixture, At )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.at( 2 ), dataVector.at( 2 ) );
}

TEST_F( VectorConstTestFixture, indexOperator )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector[ 1 ], dataVector[ 1 ] );
}

TEST_F( VectorConstTestFixture, front )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.front(), dataVector.front() );
}

TEST_F( VectorConstTestFixture, back )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.back(), dataVector.back() );
}

TEST_F( VectorConstTestFixture, size )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.size(), dataVector.size() );
}

TEST_F( VectorConstTestFixture, max_size )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.max_size(), dataVector.max_size() );
}

TEST_F( VectorConstTestFixture, empty )
{
    vectorconst< Data > constIntVector( dataVector );

    EXPECT_EQ( constIntVector.empty(), dataVector.empty() );
}

TEST_F( VectorConstTestFixture, iterator )
{
    /*
    {
        vectorconst< Data > constDataVector( dataVector );

        vectorconst< Data >::const_iterator constIt = constDataVector.begin();
        vectorconst< Data >::const_iterator constEnd = constDataVector.end();

        std::vector< Data* >::iterator it = dataVector.begin();
        std::vector< Data* >::iterator end = dataVector.end();

        for ( ; it != end; ++it, ++constIt )
        {
            (*constIt)->a = 0;
            EXPECT_EQ( *it, *constIt );
        }
    }
    */
}

// Copied from gtest/src/gtest_main.cc
GTEST_API_ int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


