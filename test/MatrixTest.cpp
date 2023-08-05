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

// Test Constructor - Invalid Rows
TEST(Constructor, InvalidRows) {
    // Throw Exception
    EXPECT_THROW({
	try {
            Matrix m(-2, 3);
	} catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Row/column size must be greater than zero", e.what());
	    throw;
	}
    }, std::invalid_argument);
}

// Test Equality Operator
TEST(Operator, Equality) {
    // Construct Matrix
    Matrix m(2, 3, 1.5);

    // Set New Matrix Equal
    Matrix mNew = m;

    // Value Assertions
    EXPECT_EQ(mNew(0, 0), 1.5);
    EXPECT_EQ(mNew(0, 1), 1.5);
    EXPECT_EQ(mNew(0, 2), 1.5);
    EXPECT_EQ(mNew(1, 0), 1.5);
    EXPECT_EQ(mNew(1, 1), 1.5);
    EXPECT_EQ(mNew(1, 2), 1.5);
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

    // Add Matrix
    m = m + m2;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.75);
    EXPECT_EQ(m(0, 1), 1.75);
    EXPECT_EQ(m(0, 2), 1.75);
    EXPECT_EQ(m(1, 0), 1.75);
    EXPECT_EQ(m(1, 1), 1.75);
    EXPECT_EQ(m(1, 2), 1.75);
}

// Test Scalar Subtraction
TEST(Subtraction, Scalar) {
    // Construct Initial Matrix
    Matrix m(2, 3, 1.5);

    // Subtract Scalar
    m = m - 0.25;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.25);
    EXPECT_EQ(m(0, 1), 1.25);
    EXPECT_EQ(m(0, 2), 1.25);
    EXPECT_EQ(m(1, 0), 1.25);
    EXPECT_EQ(m(1, 1), 1.25);
    EXPECT_EQ(m(1, 2), 1.25);
}

// Test Matrix Subtraction
TEST(Subtraction, Matrix) {
    // Construct Initial Matrices
    Matrix m(2, 3, 1.5);
    Matrix m2(2, 3, 0.25);

    // Subtract Matrices
    m = m - m2;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 1.25);
    EXPECT_EQ(m(0, 1), 1.25);
    EXPECT_EQ(m(0, 2), 1.25);
    EXPECT_EQ(m(1, 0), 1.25);
    EXPECT_EQ(m(1, 1), 1.25);
    EXPECT_EQ(m(1, 2), 1.25);
}

// Test Scalar Multiplication
TEST(Multiplication, Scalar) {
    // Construct Initial Matrix
    Matrix m(2, 3, 1.5);

    // Multiply Scalar
    m = m * 0.5;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 0.75);
    EXPECT_EQ(m(0, 1), 0.75);
    EXPECT_EQ(m(0, 2), 0.75);
    EXPECT_EQ(m(1, 0), 0.75);
    EXPECT_EQ(m(1, 1), 0.75);
    EXPECT_EQ(m(1, 2), 0.75);
}

// Test Matrix Multiplication
TEST(Multiplication, Matrix) {
    // Construct Initial Matrices
    Matrix m(2, 3, 1.5);
    Matrix m2(3, 2, 2.0);

    // Multiply Matrices
    Matrix m3(2, 2);
    m3 = m * m2;

    // Value Assertions
    EXPECT_EQ(m3(0, 0), 9.0);
    EXPECT_EQ(m3(0, 1), 9.0);
    EXPECT_EQ(m3(1, 0), 9.0);
    EXPECT_EQ(m3(1, 1), 9.0);
    EXPECT_EQ(m3.rows(), 2);
    EXPECT_EQ(m3.cols(), 2);
}

// Test Scalar Division
TEST(Division, Scalar) {
    // Construct Initial Matrix
    Matrix m(2, 3, 1.5);

    // Divide Scalar
    m = m / 2.0;

    // Value Assertions
    EXPECT_EQ(m(0, 0), 0.75);
    EXPECT_EQ(m(0, 1), 0.75);
    EXPECT_EQ(m(0, 2), 0.75);
    EXPECT_EQ(m(1, 0), 0.75);
    EXPECT_EQ(m(1, 1), 0.75);
    EXPECT_EQ(m(1, 2), 0.75);
}

// Test Matrix Transpose
TEST(Transpose, Transpose) {
    // Construct Initial Matrix
    Matrix m(2,3);
    m(0,0) = 1;
    m(0,1) = 2;
    m(0,2) = 3;
    m(1,0) = 4;
    m(1,1) = 5;
    m(1,2) = 6;

    // Transpose Matrix
    Matrix mOut = m.transpose();

    // Value Assertions
    EXPECT_EQ(mOut.rows(), 3);
    EXPECT_EQ(mOut.cols(), 2);
    EXPECT_EQ(mOut(0, 0), 1);
    EXPECT_EQ(mOut(0, 1), 4);
    EXPECT_EQ(mOut(1, 0), 2);
    EXPECT_EQ(mOut(1, 1), 5);
    EXPECT_EQ(mOut(2, 0), 3);
    EXPECT_EQ(mOut(2, 1), 6);
}
