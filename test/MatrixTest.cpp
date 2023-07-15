// MatrixTest.hpp
//
// @Author: Parker Barrett
// @Description: Matrix class test file.
//

// NavTypes Includes
#include "Matrix.hpp"

// External Includes
#include "gtest/gtest.h"

// Test Constructor - No Args
TEST(Constructor, NoArgs) {
    // Construct Matrix
    Matrix m(2, 3);

    // Size Assertions
    EXPECT_EQ(m.rows(), 2);
    EXPECT_EQ(m.cols(), 3);

    // Value Assertions
    EXPECT_EQ(m(0, 0), 0.0);
    EXPECT_EQ(m(0, 1), 0.0);
    EXPECT_EQ(m(0, 2), 0.0);
    EXPECT_EQ(m(1, 0), 0.0);
    EXPECT_EQ(m(1, 1), 0.0);
    EXPECT_EQ(m(1, 2), 0.0);
}

// Test Constructor - Args
TEST(Constructor, Args) {
    // Construct Matrix
    Matrix m(2, 3, 1.5);

    // Size Assertions
    EXPECT_EQ(m.rows(), 2);
    EXPECT_EQ(m.cols(), 3);

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.5);
    EXPECT_EQ(m(0, 1), 1.5);
    EXPECT_EQ(m(0, 2), 1.5);
    EXPECT_EQ(m(1, 0), 1.5);
    EXPECT_EQ(m(1, 1), 1.5);
    EXPECT_EQ(m(1, 2), 1.5);
}
