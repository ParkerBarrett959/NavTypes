// Quaternion.hpp
//
// @Author: Parker Barrett
// @Description: header only class implementation of quaternion class.
//

// Include Headers
#pragma once
#include <cmath>
#include <iostream>

// Quaternion Class
class Quaternion {
  public:
    /* @Quaternion
     * @Description: Quaternion class constructor which sets values of
     * quaternion elements.
     * @Inputs:
     *     q0: Scalar quaternion element
     *     q1: First vector quaternion element
     *     q2: Second vector quaternion element
     *     q3: Third vector quaternion element
     * @Outputs:
     */
    Quaternion(double q0, double q1, double q2, double q3) : q0_(q0), q1_(q1), q2_(q2), q3_(q3){};

    /* @Quaternion
     * @Description: Quaternion class default constructor.
     * @Inputs:
     * @Outputs:
     */
    Quaternion() : q0_(0.0), q1_(0.0), q2_(0.0), q3_(1.0){};

    /* @getQ0
     * @Description: Returns scalar element of quaternion.
     * @Inputs:
     * @Outputs:
     *     q0_: Scalar element of quaternion
     */
    double getQ0() { return q0_; };

    /* @getQ1
     * @Description: Returns first vector element of quaternion.
     * @Inputs:
     * @Outputs:
     *     q1_: First vector element of quaternion
     */
    double getQ1() { return q1_; };

    /* @getQ2
     * @Description: Returns second vector element of quaternion.
     * @Inputs:
     * @Outputs:
     *     q2_: Second vector element of quaternion
     */
    double getQ2() { return q2_; };

    /* @getQ3
     * @Description: Returns third vector element of quaternion.
     * @Inputs:
     * @Outputs:
     *     q3_: Third vector element of quaternion
     */
    double getQ3() { return q3_; };

  private:
    // Quaternion Elements
    double q0_, q1_, q2_, q3_;
};
