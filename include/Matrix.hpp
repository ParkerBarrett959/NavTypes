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
    Matrix(int n_rows, int n_cols, double init_val = 0.0) {
        // Verify Input Dimensions are Valid
        if (n_rows < 1 || n_cols < 1) {
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
    double operator()(int row, int col) { return m_[row][col]; };

  private:
    // Matrix Class Members
    int n_rows_ = 0;
    int n_cols_ = 0;
    std::vector<std::vector<double>> m_;
};
