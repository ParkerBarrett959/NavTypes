// DirectionCosinesMatrixTest.hpp
//
// @Author: Parker Barrett
// @Description: DCM class test file.
//

// NavTypes Includes
#include "DirectionCosinesMatrix.hpp"

// External Includes
#include "gtest/gtest.h"

// Test Constructor
TEST(Constructor, Constructor) {
    // Construct Direction Cosines Matrix
    DirectionCosinesMatrix R;

    // Size Assertions
    EXPECT_EQ(R.rows(), 3);
    EXPECT_EQ(R.cols(), 3);
}
