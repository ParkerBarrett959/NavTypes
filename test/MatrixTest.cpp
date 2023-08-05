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

// Test Constructor - Invalid Columns
TEST(Constructor, InvalidCols) {
    // Throw Exception
    EXPECT_THROW({
        try {
            Matrix m(2, -3);
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Row/column size must be greater than zero", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// Test Equality Operator
TEST(EqualityOperator, SetValue) {
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

// Test Equality Operator - Different Sized Matrix Exception
TEST(EqualityOperator, DifferentSizes) {
    // Throw Exception
    Matrix m1(3, 2, 1.0);
    Matrix m2(2, 3);
    EXPECT_THROW({
        try {
            m2 = m1;;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrices must be same size", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// Test Index Operator Exceptions
TEST(IndexOperator, Exceptions) {
    // Initialize Matrix
    Matrix m(2,3);

    // Throw Exception - Negative Row Index
    EXPECT_THROW({
        try {
            double i = m(-2, 3);
        } catch (const std::invalid_argument& e1) {
            EXPECT_STREQ("Invalid Row/Column Specification", e1.what());
            throw;
        }
    }, std::invalid_argument);

    // Throw Exception - Row Index Outside Bounds
    EXPECT_THROW({
        try {
            double i = m(2, 2);
        } catch (const std::invalid_argument& e2) {
            EXPECT_STREQ("Invalid Row/Column Specification", e2.what());
            throw;
        }
    }, std::invalid_argument);

    // Throw Exception - Negative Column Index
    EXPECT_THROW({
        try {
            double i = m(1, -3);
        } catch (const std::invalid_argument& e3) {
            EXPECT_STREQ("Invalid Row/Column Specification", e3.what());
            throw;
        }
    }, std::invalid_argument);

    // Throw Exception - Column Index Outside Bounds
    EXPECT_THROW({
        try {
            double i = m(1, 3);
        } catch (const std::invalid_argument& e4) {
            EXPECT_STREQ("Invalid Row/Column Specification", e4.what());
            throw;
        }
    }, std::invalid_argument);
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

// Test Matrix Addition - Different Sized Rows
TEST(Addition, DifferentSizedRows) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(1, 3);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 + m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrices must be same size", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// Test Matrix Addition - Different Sized Columns
TEST(Addition, DifferentSizedCols) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(2, 2);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 + m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrices must be same size", e.what());
            throw;
        }
    }, std::invalid_argument);
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

// Test Matrix Subtraction - Different Sized Rows
TEST(Subtraction, DifferentSizedRows) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(1, 3);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 - m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrices must be same size", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// Test Matrix Subtraction - Different Sized Columns
TEST(Subtraction, DifferentSizedCols) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(2, 2);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 - m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrices must be same size", e.what());
            throw;
        }
    }, std::invalid_argument);
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

// Test Matrix Multiplication - Wrong Size Case 1
TEST(Multiplication, WrongSizeCase1) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(2, 2);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 * m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrix sizes are not compatible", e.what());
            throw;
        }
    }, std::invalid_argument);
}

// Test Matrix Multiplication - Wrong Size Case 2
TEST(Multiplication, WrongSizeCase2) {
    // Throw Exception
    Matrix m1(2, 3);
    Matrix m2(3, 3);
    EXPECT_THROW({
        try {
            Matrix m3 = m1 * m2;
        } catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Matrix sizes are not compatible", e.what());
            throw;
        }
    }, std::invalid_argument);
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

// Test Matrix Determinant - Zero Matrix
TEST(Determinant, Zero) {
    // Construct Matrices
    Matrix m(0, 0);

    // Compute Determinant
    double d = m.determinant(m);

    // Assertions
    ASSERT_EQ(d, 1.0);
}

// Test Matrix Determinant - 1D Matrix
TEST(Determinant, OneD) {
    // Construct Matrices
    Matrix m(1, 1);
    m(0, 0) = 2.0;

    // Compute Determinant
    double d = m.determinant(m);

    // Assertions
    ASSERT_EQ(d, 2.0);
}

// Test Matrix Determinant - 2D Matrix
TEST(Determinant, TwoD) {
    // Construct Matrices
    Matrix m(2, 2);
    m(0, 0) = 3.0;
    m(0, 1) = 8.0;
    m(1, 0) = 4.0;
    m(1, 1) = 6.0;

    // Compute Determinant
    double d = m.determinant(m);

    // Assertions
    ASSERT_EQ(d, -14.0);
}

// Test Matrix Determinant - 3D Matrix
TEST(Determinant, ThreeD) {
    // Construct Matrices
    Matrix m(3, 3);
    m(0, 0) = 6.0;
    m(0, 1) = 1.0;
    m(0, 2) = 1.0;
    m(1, 0) = 4.0;
    m(1, 1) = -2.0;
    m(1, 2) = 5.0;
    m(2, 0) = 2.0;
    m(2, 1) = 8.0;
    m(2, 2) = 7.0;

    // Compute Determinant
    double d = m.determinant(m);

    // Assertions
    ASSERT_EQ(d, -306.0);
}

// Test Matrix Inversion
/*TEST(Inversion, InvertMatrix) {
    // Construct Matrix
    Matrix m(3, 3);
    m(0, 0) = 1.0;
    m(0, 1) = 2.0;
    m(0, 2) = 3.0;
    m(1, 0) = 4.0;
    m(1, 1) = 5.0;
    m(1, 2) = 6.0;
    m(2, 0) = 7.0;
    m(2, 1) = 8.0;
    m(2, 2) = 9.0;
    
    // Invert Matrix
    Matrix mInv = m.inverse();

    // Value Assertions
    EXPECT_EQ(mInv.rows(), 3);
    EXPECT_EQ(mInv.cols(), 3);
    EXPECT_EQ(mInv(0, 0), -2.6666666667);
    EXPECT_EQ(mInv(0, 1),  2.6666666667);
    EXPECT_EQ(mInv(0, 2), -1.0);
    EXPECT_EQ(mInv(1, 0),  3.3333333333);
    EXPECT_EQ(mInv(1, 1), -4.3333333333);
    EXPECT_EQ(mInv(1, 2),  2.0);
    EXPECT_EQ(mInv(2, 0), -1.0);
    EXPECT_EQ(mInv(2, 1),  2.0);
    EXPECT_EQ(mInv(2, 2),  1.0);
}*/
