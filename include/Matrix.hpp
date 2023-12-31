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
	    throw std::invalid_argument("Row/column size must be greater than zero");
        }

        // Set Matrix Size and Values
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

    /* @getElements
     * @Description: Return Matrix elements as vector.
     * @Inputs:
     * @Outputs:
     *     m_: Matrix elements
     */
    std::vector<std::vector<double>> getElements() { return m_; };

    /* @()
     * @Description: Return value of array given (row,col) index.
     * @Inputs:
     *     row: Row index
     *     col: Column index
     * @Outputs:
     *     m_[row][col]: Value of matrix at row/column index
     */
    double& operator()(int row, int col) {
        if ((row < 0) || (row > n_rows_-1) || (col < 0) || (col > n_cols_-1)) {
           throw std::invalid_argument("Invalid Row/Column Specification");
	}
	return m_[row][col];
    };

    /* @=
     * @Description: Matrix assignment operator.
     * @Inputs:
     *     mIn: Input matrix
     * @Outputs:
     */
    void operator=(Matrix mIn) {
	// Verify Matrices are Same Size
	if ((mIn.rows() != n_rows_) || (mIn.cols() != n_cols_)) {
            throw std::invalid_argument("Matrices must be same size");
	}
	    
	// Loop over Elements and Set Value
	for (int i = 0; i < n_rows_; i++) {
	    for (int j = 0; j < n_cols_; j++) {
                m_[i][j] = mIn(i,j);
	    }
	}
    };

    /* @<<
     * @Description: Matrix assignment operator.
     * @Inputs:
     *     vals: Input matrix, left to right, top to bottom
     * @Outputs:
     */
    void operator<<(std::vector<double> vals) {
        // Verify Matrices are Same Size
        if (vals.size() != n_rows_*n_cols_) {
            throw std::invalid_argument("Matrices must be same size");
        }

        // Loop over Elements and Set Value
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                m_[i][j] = vals[(i*n_cols_)+j];
            }
        }
    };

    /* @==
     * @Description: Matrix equality operator.
     * @Inputs:
     *     mIn: Input matrix
     * @Outputs:
     */
    bool operator==(Matrix mIn) {
        // Verify Matrices are Same Size
        if ((mIn.rows() != n_rows_) || (mIn.cols() != n_cols_)) {
            throw std::invalid_argument("Matrices must be same size");
        }

        // Loop over Elements and Verify Equal
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                if (m_[i][j] != mIn(i,j)) {
                    return false;
		}
            }
        }
	return true;
    };

    /* @!=
     * @Description: Matrix inequality operator.
     * @Inputs:
     *     mIn: Input matrix
     * @Outputs:
     */
    bool operator!=(Matrix mIn) {
        // Verify Matrices are Same Size
        if ((mIn.rows() != n_rows_) || (mIn.cols() != n_cols_)) {
            throw std::invalid_argument("Matrices must be same size");
        }

        // Loop over Elements and Verify No Equal
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                if (m_[i][j] != mIn(i,j)) {
                    return true;
                }
            }
        }
        return false;
    };

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
        // Verify Matrices are Same Size
        if ((mIn.rows() != n_rows_) || (mIn.cols() != n_cols_)) {
            throw std::invalid_argument("Matrices must be same size");
        }
	    
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
        // Verify Matrices are Same Size
        if ((mIn.rows() != n_rows_) || (mIn.cols() != n_cols_)) {
            throw std::invalid_argument("Matrices must be same size");
        }
	    
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
        // Verify Matrices Can be Multiplied
        if ((mIn.rows() != n_cols_) || (mIn.cols() != n_rows_)) {
            throw std::invalid_argument("Matrix sizes are not compatible");
        }
	    
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

    /* @/
     * @Description: Matrix scalar division operator.
     * @Inputs:
     *     val: Value to divide each element of matrix
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix operator/(double val) {
        // Set Output Matrix
        Matrix mOut(n_rows_, n_cols_);

        // Loop over Elements and Divide by Scalar
        for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                mOut(i,j) = m_[i][j] / val;
            }
        }
        return mOut;
    };

    /* @transpose
     * @Description: Matrix transpose.
     * @Inputs:
     * @Outputs:
     *     mOut: Output Matrix
     */
    Matrix transpose() {
        // Set Output Matrix
        Matrix mOut(n_cols_, n_rows_);

        // Loop over Elements and Set Output
        for (int i = 0; i < n_cols_; i++) {
            for (int j = 0; j < n_rows_; j++) {
                mOut(i,j) = m_[j][i];
            }
        }
        return mOut;
    };

    /* @inverse
     * @Description: Get matrix inverse
     * @Inputs:
     * @Outputs:
     *     mInv: Matrix inverse result
     */
    Matrix inverse() {
        // Verify Matrix is Square
        if (n_cols_ != n_rows_) {
            throw std::invalid_argument("Matrix must be square for inverse");
        }

        // Calculate Determinant
	double det = determinant();
	if (std::abs(det) <= 1.0e-12) {
            throw std::runtime_error("Matrix is nearly singular. Unable to invert");
        }

	// Get Adjoint
	Matrix adj = getCofactor();
        adj = adj.transpose();

        // Calculate Inverse
	Matrix mInv = adj / det;
	return mInv;
    }

    /* @determinant
     * @Description: Get Matrix determinant
     * @Inputs:
     * @Outputs:
     *     det: Matrix determinant
     */
    double determinant() {
        // Get Matrix Dimensions
	int dim = n_rows_;

	// 0-Dimensional Case
	if (dim == 0) {
            return 1;
	}

	// 1-Dimensional Case
        if (dim == 1) {
            return m_[0][0];
        }

        // Initialize Values
	double d = 0.0;
	int sign = 1;

	// Loop over Elements
	for (int i = 0; i < dim; i++) {
            // Assemble Submatrix
	    Matrix subM(dim-1, dim-1);
	    for (int m = 1; m < dim; m++) {
	        int z = 0;
                for (int n = 0; n < dim; n++) {
                    if (n != i) {
                        subM(m-1, z) = m_[m][n];
			z++;
		    }
	        }	
	    }

	    // Make Recursive Call
            d = d + sign * m_[0][i] * subM.determinant();
	    sign = -sign;
	}
        return d;
    };

  private:

    /* @getCofactor
     * @Description: Get Matrix Cofactor
     * @Inputs:
     * @Outputs:
     *     mOut: Output Cofactor Matrix
     */
    Matrix getCofactor() {
        // Initialize Matrices
	Matrix mOut(n_rows_, n_cols_);
	Matrix subM(n_rows_-1, n_cols_-1);

	// Loop over Elements of Matrix
	for (int i = 0; i < n_rows_; i++) {
            for (int j = 0; j < n_cols_; j++) {
                int p = 0;
		for (int x = 0; x < n_rows_; x++) {
                    if (x == i) {
                        continue;
		    }
		    int q = 0;
		    for (int y = 0; y < n_rows_; y++) {
                        if (y == j) {
                            continue;
			}
			subM(p, q) = m_[x][y];
			q++;
		    }
		    p++;
		}
		mOut(i, j) = std::pow(-1, i+j) * subM.determinant();
	    }
	}
	return mOut;
    };

    // Matrix Class Members
    int n_rows_ = 0;
    int n_cols_ = 0;
    std::vector<std::vector<double>> m_;
};
