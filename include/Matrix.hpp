// Matrix.hpp
//
// @Author: Parker Barrett
// @Description: header only class implementation of matrix class.
//

// Include Headers
#pragma once
#include <cmath>
#include <iostream>
#include <vector>

// Matrix Class
class Matrix {
  public:
    /* @Matrix
     * @Description: Matrix class constructor which sets values of
     * matrix elements.
     * @Inputs:
     *     n_rows: Number of matrix rows
     *     n_cols: Number of matrix columns
     *     init_val: Initial value for matrix elements
     * @Outputs:
     */
    Matrix(int n_rows = 0, int n_cols = 0, double init_val = 0.0) {
        // Verify Input Dimensions are Valid
        if (n_rows < 0 || n_cols < 0) {
            return;
        }

        // Set Matriz Size and Values
        n_rows_ = n_rows;
        n_cols_ = n_cols;
        m_.resize(n_rows);
        for (int i = 0; i < m_.size(); i++) {
            m_[i].resize(n_cols, init_val);
        }
    };

    /* @cols
     * @Description: Return number of matrix columns.
     * @Inputs:
     * @Outputs:
     *     n_cols_: Number of matrix columns
     */
    int cols() { return n_cols_; };

    /* @rows
     * @Description: Return number of matrix rows.
     * @Inputs:
     * @Outputs:
     *     n_rows_: Number of matrix rows
     */
    int rows() { return n_rows_; };

    /* @()
     * @Description: Return value of array given (row,col) index.
     * @Inputs:
     *     row: Row index
     *     col: Column index
     * @Outputs:
     *     m_[row][col]: Value of matrix at row/column index
     */
    double& operator()(int row, int col) { return m_[row][col]; };

    /* @+
     * @Description: Matrix scalar addition operator.
     * @Inputs:
     *     val: Value to add to each element of matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator+(double val) {
	// Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

	// Loop over Elements and Add Scalar
	for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] + val;
	    }
	}
	return mOut;
    };

    /* @+
     * @Description: Matrix addition operator.
     * @Inputs:
     *     mIn: Matrix to add to existing matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator+(Matrix mIn) {
        // Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

        // Loop over Elements and Add Matrix Elements
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] + mIn(i,j);
            }
        }
        return mOut;
    };

    /* @-
     * @Description: Matrix scalar subtraction operator.
     * @Inputs:
     *     val: Value to subtract from each element of matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator-(double val) {
        // Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

        // Loop over Elements and Subtract Scalar
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] - val;
            }
        }
        return mOut;
    };

    /* @-
     * @Description: Matrix subtraction operator.
     * @Inputs:
     *     mIn: Matrix to subtract from existing matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator-(Matrix mIn) {
        // Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

        // Loop over Elements and Subtract Matrix Elements
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] - mIn(i,j);
            }
        }
        return mOut;
    };

    /* @*
     * @Description: Matrix scalar multiplication operator.
     * @Inputs:
     *     val: Value to multiply each element of matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator*(double val) {
        // Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

        // Loop over Elements and Multiply Scalar
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] * val;
            }
        }
        return mOut;
    };

    /* @*
     * @Description: Matrix multiplication operator.
     * @Inputs:
     *     mIn: Matrix to multiply existing matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator*(Matrix mIn) {
        // Set Output Matrix
        Matrix mOut(n_rows_, mIn.cols());

        // Loop over Elements and Perform Column-Row  Multiplication
	double temp = 0.0;
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < mIn.cols(); j++) {
		temp = 0.0;
		for (int k = 0; k < n_cols_; k++) {
                    temp += m_[i][k] * mIn(k,j);
		}
                mOut(i,j) = temp;
            }
        }
        return mOut;
    };

    // TODO: Scalar Divide, Transpose, Inverse

  private:
    // Matrix Class Members
    int n_rows_ = 0;
    int n_cols_ = 0;
    std::vector<std::vector<double>> m_;
};
