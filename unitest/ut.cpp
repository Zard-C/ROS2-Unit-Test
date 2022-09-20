#include "demo.hpp"
#include <gtest/gtest.h> 


TEST(demo_test, test1)
{
    EXPECT_EQ(smaller(0, 1), 0); 
    EXPECT_EQ(isOdd(1), true); 
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}