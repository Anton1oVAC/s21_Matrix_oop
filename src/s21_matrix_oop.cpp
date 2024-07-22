#include "s21_matrix_oop.h"

// ########### Конструкторы

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

// ############ Методы
// Проверяет матрицы на равенство
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

// Складывает две матрицы поэментно, если у них одинаковые размеры
void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (this->matrix_size_eq(other)) {
    for (int i = 0; i < rows_ * cols_; i++) {
      matrix_[0][i] = matrix_[0][i] + other.matrix_[0][i];
    }
  } else {
    throw std::invalid_argument("matrix of different sizes");
  }
}

// вычитает из текущей матрицы другую
void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (this->matrix_size_eq(other)) {
    for (int i = 0; i < rows_ * cols_; i++) {
      matrix_[0][i] = matrix_[0][i] - other.matrix_[0][i];
    }
  } else {
    throw std::invalid_argument("matrix of different sizes");
  }
}

//  Умножение матрицы на число
void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[0][i] = matrix_[0][i] * num;
  }
}

// Умножение матрицы на матрицу
void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (rows_ != other.cols_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix is ​​not equal to the "
        "number of rows of the second matrix");
  }
  S21Matrix result = S21Matrix(this->rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      double sum = 0;
      for (int k = 0; k < cols_; k++) {
        sum += matrix_[i][k] * other.matrix_[k][j];
      }
      result.matrix_[i][j] = sum;
    }
  }
  *this = result;
}

// Транспонирование матрицы
S21Matrix S21Matrix::transpose() {
  S21Matrix transpose_matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      transpose_matrix.matrix_[j][i] = matrix_[i][j];
    }
  }
  return transpose_matrix;
}


// ###########  Перегрузка операторов

// присвоение матрице значений другой матрицы
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->remove_matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->allocate_matrix();
  this->copy_matrix_value(other);
  return *this;
}

// Проверяет, равны ли две матрицы
bool S21Matrix::operator==(const S21Matrix& other) {
  return this->equal_matrix(other);
}

// Доступ к элементу по индексу
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= rows_ * cols_) {
    throw std::out_of_range("index outside the matrix");
  }
  return matrix_[i][j];
}

// Складывает другую матрицу с текущей.
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->sum_matrix(other);
  return *this;
}

// Возвращает результат суммы двух матриц
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.sum_matrix(other);
  return result;
}

// Вычитает другую матрицу с текущей
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->sub_matrix(other);
  return *this;
}

// Возвращает результат разности двух матриц
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.sub_matrix(other);
  return result;
}

// Умножение матрицы на число
S21Matrix& S21Matrix::operator*=(const double num) {
  this->mul_number(num);
  return *this;
}

// Умножения исходной матрицы на заданное число
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result = S21Matrix(*this);
  result.mul_number(num);
  return result;
}

// Умножение другую матрицы с текущей матрицей
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->mul_matrix(other);
  return *this;
}

// Возвращает результат умножения матрицы на матрицу
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = S21Matrix(*this);
  result.mul_matrix(other);
  return result;
}

// ############ Доп методы

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
