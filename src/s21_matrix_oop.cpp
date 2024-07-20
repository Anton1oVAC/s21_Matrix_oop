#include "s21_matrix_oop.h"

// Конструкторы

// Инициализирует матрицу размером 3x3.
S21Matrix::S21Matrix() : S21Matrix(3, 3){};

// Создает матрицу с указанным количеством строк и столбцов.
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Error matrix!");
  }
  this->allocate_matrix();
}

// Копирует значения из другого объекта матрицы.
S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->allocate_matrix();
  this->copy_matrix_value(other);
}

// Освобождает динамически выделенную память.
S21Matrix::~S21Matrix() {
  delete[] matrix_[0];
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
}

// Методы

bool S21Matrix::equal_matrix(const S21Matrix& other) {
  bool result = false;
  if (this->matrix_size_eq(other)) {
    result = true;
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabsl(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
          result = false;
        }
      }
    }
  }
  return result;
}


// Перегрузка операторов

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->equal_matrix(other);
}

// Доступ к элементу по индексу
double& S21Matrix::operator()(int i, int j){
    if (i < 0 || j < 0 || i >= rows_ || j >= rows_ * cols_){
        throw std::out_of_range("index outside the matrix");
    }
    return matrix_[i][j];
}


// Доп методы

// Выделяет память под матрицу
void S21Matrix::allocate_matrix() {
  matrix_ = new double*[rows_];
  matrix_[0] = new double[rows_ * cols_];
  for (int i = 1; i < rows_; i++) {
    matrix_[i] = matrix_[i - 1] + cols_;
  }
}

// Копирует значения из другой матрицы
void S21Matrix::copy_matrix_value(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

bool S21Matrix::matrix_size_eq(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    return true;
  }
  return false;
}

// Освобождение памяти
void S21Matrix::remove_matrix() {
  if (matrix_) {
    delete[] matrix_[0];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}
