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
    Matrix m;

    // Size Assertions
    EXPECT_EQ(m.rows(), 0);
    EXPECT_EQ(m.cols(), 0);
}

// Test Constructor - No Value Args
TEST(Constructor, NoValueArgs) {
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

// Test Scalar Add
TEST(Addition, Scalar) {
    // Construct Initial Matrix
    Matrix m(2, 3, 1.5);

    // Add Scalar
    m = m + 0.25;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.75);
    EXPECT_EQ(m(0, 1), 1.75);
    EXPECT_EQ(m(0, 2), 1.75);
    EXPECT_EQ(m(1, 0), 1.75);
    EXPECT_EQ(m(1, 1), 1.75);
    EXPECT_EQ(m(1, 2), 1.75);
}

// Test Matrix Add
TEST(Addition, Matrix) {
    // Construct Initial Matrices
    Matrix m(2, 3, 1.5);
    Matrix m2(2, 3, 0.25);

    // Add Scalar
    m = m + m2;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.75);
    EXPECT_EQ(m(0, 1), 1.75);
    EXPECT_EQ(m(0, 2), 1.75);
    EXPECT_EQ(m(1, 0), 1.75);
    EXPECT_EQ(m(1, 1), 1.75);
    EXPECT_EQ(m(1, 2), 1.75);
}
