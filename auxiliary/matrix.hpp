//
// Created by pyo on 2020-05-24.
//

#ifndef ALGORITHM_STUDY_MATRIX_HPP
#define ALGORITHM_STUDY_MATRIX_HPP

#include <iostream>
#include <random_number_generator.hpp>

using namespace std;

template <typename T>
class Matrix {
public:
    Matrix() = default;

    Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        arr = new T*[rows];
        for (int r = 0; r < rows; r++) {
            arr[r] = new T[cols];
        }
        fill_zero();
    }

    Matrix(const Matrix& rhs) : rows(rhs.getRowSize()), cols(rhs.getColSize()){
        arr = new T*[rows];
        for (int r = 0; r < rows; r++) {
            arr[r] = new T[cols];
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                arr[r][c] = rhs[r][c];
            }
        }
    }

    Matrix(Matrix&& rhs) noexcept {
        cols = rhs.getColSize();
        rows = rhs.getRowSize();

        arr = rhs.arr;
        rhs.arr = nullptr;
    }

    ~Matrix() {
        if (arr != nullptr) {
            for (int r = 0; r < rows; r++) {
                delete[] arr[r];
            }
        }
    }

    void fill_zero() {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                arr[r][c] = 0;
            }
        }
    }

    void fill_rn(int ll, int ul) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                arr[r][c] = get_random_number(ll, ul);
            }
        }
    }

    operator T**() const { return arr; }

    Matrix& operator=(const Matrix& rhs) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                arr[r][c] = rhs[r][c];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& rhs) {
        Matrix ret(rhs.rows, rhs.cols);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                ret[r][c] = (*this)[r][c] + rhs[r][c];
            }
        }
        return std::move(ret);
    }

    Matrix operator-(const Matrix& rhs) {
        Matrix ret(rhs.rows, rhs.cols);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                ret[r][c] = (*this)[r][c] - rhs[r][c];
            }
        }
        return std::move(ret);
    }

    int getRowSize() const { return rows; }

    int getColSize() const { return cols; }

    void resize(int new_rows, int new_cols) {
        if (arr != nullptr) {
            for (int r = 0; r < rows; r++) {
                delete[] arr[r];
            }
            delete[] arr;
        }

        rows = new_rows;
        cols = new_cols;

        arr = new T*[rows];
        for (int r = 0; r < rows; r++) {
            arr[r] = new T[cols];
        }
    }

    Matrix split(int sr, int sc, int n) {
        Matrix ret(n, n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                ret[r][c] = arr[sr + r][sc + c];
            }
        }
        return ret;
    }

    void partial_fill(int sr, int sc, Matrix p) {
        for (int r = 0; r < p.getRowSize(); r++) {
            for (int c = 0; c < p.getColSize(); c++) {
                arr[sr + r][sc + c] = p[r][c];
            }
        }
    }

    void print() const {
        for (int r = 0; r < rows; r++) {
            cout << "| ";
            for (int c = 0; c < cols; c++) {
                cout << setw(3) << arr[r][c] << " ";
            }
            cout << " |";
            cout << endl;
        }
    }
private:
    T** arr{nullptr};
    int rows{0};
    int cols{0};
};

#endif //ALGORITHM_STUDY_MATRIX_HPP
