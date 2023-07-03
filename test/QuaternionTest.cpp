// QuaternionTest.hpp
//
// @Author: Parker Barrett
// @Description: Quaternion class test file.
//

// NavTypes Includes
#include "Quaternion.hpp"

// External Includes
#include "gtest/gtest.h"

// Test Constructor
TEST(Constructor, Standard) {
    // Construct Quaternion
    Quaternion q(1.0, 2.0, 3.0, 4.0);

    // Assertions
    EXPECT_EQ(q.getQ0(), 1.0);
    EXPECT_EQ(q.getQ1(), 2.0);
    EXPECT_EQ(q.getQ2(), 3.0);
    EXPECT_EQ(q.getQ3(), 4.0);
}

// Test Default Constructor
TEST(Constructor, Default) {
    // Construct Quaternion
    Quaternion q;

    // Assertions
    EXPECT_EQ(q.getQ0(), 0.0);
    EXPECT_EQ(q.getQ1(), 0.0);
    EXPECT_EQ(q.getQ2(), 0.0);
    EXPECT_EQ(q.getQ3(), 1.0);
}
