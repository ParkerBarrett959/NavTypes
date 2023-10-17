// DirectionCosinesMatrix.hpp
//
// @Author: Parker Barrett
// @Description: header only class implementation of dcm class.
//

// Include Headers
#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "Matrix.hpp"

// Direction Cosines Matrix Class
class DirectionCosinesMatrix : public Matrix {
  public:
    /* @DirectionCosinesMatrix
     * @Description: DCM class constructor which sets values of
     * matrix elements.
     * @Inputs:
     * @Outputs:
     */
    DirectionCosinesMatrix() : Matrix(3, 3, 0) {};

  private:

};
