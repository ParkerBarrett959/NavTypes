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

    /* @*
     * @Description: Quaternion multiplication operator.
     * @Inputs:
     *     q: Input quaternion - perform right multiplication on current class
     * @Outputs:
     *     multiply(q): Performs private member multiply function on current class members
     */
    Quaternion operator*(Quaternion q) { return multiply(q); };

  private:
    /* @multiply
     * @Description: Quaternion multiplication function.
     * @Inputs:
     *     q: Input quaternion
     * @Outputs:
     *     qOut: Output quaternion result - qOut = q_ * q
     */
    Quaternion multiply(Quaternion q) {
        // Get Input Quaternion Elements
        double q0In = q.getQ0();
        double q1In = q.getQ1();
        double q2In = q.getQ2();
        double q3In = q.getQ3();

        // Perform Multiplication
        double q0 = q0_ * q0In - q1_ * q1In - q2_ * q2In - q3_ * q3In;
        double q1 = q0_ * q1In + q1_ * q0In + q2_ * q3In - q3_ * q2In;
        double q2 = q0_ * q2In - q1_ * q3In + q2_ * q0In + q3_ * q1In;
        double q3 = q0_ * q3In + q1_ * q2In - q2_ * q1In + q3_ * q0In;

        // Set Quaternion Outputs and Return
        Quaternion qOut(q0, q1, q2, q3);
        return qOut;
    };

    // Quaternion Elements
    double q0_, q1_, q2_, q3_;
};
