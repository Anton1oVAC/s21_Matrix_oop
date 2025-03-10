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

// создать матрицу переносом другой
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->allocate_matrix();
  this->copy_matrix_value(other);

  other.rows_ = 0;
  other.cols_ = 0;
}


// ######## Диструктор
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

// Детерминант матрицы
double S21Matrix::determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("matrix don't square");
  }
  double result = 0;
  int size = rows_;

  if (size == 1) {
    result = matrix_[0][0];
  } else if (size == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    double temp_deterinant = 0;

    for (int i = 0; i < size; i++) {
      S21Matrix temp_matrix = this->minor_matrix(i, 0);
      temp_deterinant = temp_matrix.determinant();

      if (i % 2 == 0) {
        result += matrix_[i][0] * temp_deterinant;
      } else {
        result -= matrix_[i][0] * temp_deterinant;
      }
      temp_deterinant = 0;
    }
  }
  return result;
}

// Аглебраическое дополнение матрицы
S21Matrix S21Matrix::calc_complements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("matrix don't square");
  }
  S21Matrix result(rows_, cols_);
  int size = rows_;

  if (size == 1) {
    result.matrix_[0][0] = matrix_[0][0];
  } else if (size == 2) {
    result.matrix_[0][0] = matrix_[1][1];
    result.matrix_[0][1] = matrix_[1][0] * -1;
    result.matrix_[1][0] = matrix_[0][1] * -1;
    result.matrix_[1][1] = matrix_[0][0];
  } else {
    double minor = 0;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        S21Matrix temp_matrix = this->minor_matrix(i, j);
        minor = temp_matrix.determinant();

        int extent = i + j;
        if (extent % 2 == 0) {
          result.matrix_[i][j] = minor;
        } else {
          result.matrix_[i][j] = minor * -1;
        }
        minor = 0;
      }
    }
  }
  return result;
}

// обратная матрица
S21Matrix S21Matrix::inverse_matrix() {
  double determinant = this->determinant();
  if (determinant == 0) {
    throw std::invalid_argument("incorrect det");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = 1;

  } else {
    result = calc_complements().transpose();
    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        result(i, j) *= (1 / determinant);
      }
    }
  }
  return result;
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

// Складывает другую матрицу с текущей
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


// Accessor (Геттеры)

int S21Matrix::get_rows() const { return rows_; }

int S21Matrix::get_cols() const { return cols_; }


// Mutator (Сеттеры)

void S21Matrix::set_rows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("Error: rows matrix is ​​less than one");
  }
  S21Matrix temp(rows, cols_);
  if (rows > rows_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    for (int n = rows_; n < rows; n++) {
      for (int m = 0; m < cols_; m++) {
        temp.matrix_[n][m] = 0;
      }
    }
  } else {
    for (int k = 0; k < rows; k++) {
      for (int l = 0; l < cols_; l++) {
        temp.matrix_[k][l] = matrix_[k][l];
      }
    }
  }
  *this = temp;
}

void S21Matrix::set_cols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("Error: cols matrix is ​​less than one");
  }
  S21Matrix temp(rows_, cols);
  if (cols > rows_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    for (int n = 0; n < rows_; n++) {
      for (int m = cols_; m < cols; m++) {
        temp.matrix_[n][m] = 0;
      }
    }
  } else {
    for (int k = 0; k < rows_; k++) {
      for (int l = 0; l < cols; l++) {
        temp.matrix_[k][l] = matrix_[k][l];
      }
    }
  }
  *this = temp;
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

// Проверяет равны ли матрицы
bool S21Matrix::matrix_size_eq(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    return true;
  }
  return false;
}

// Запоняет маленькую матрицу на основе указаных индектов строки и столбца
S21Matrix S21Matrix::minor_matrix(int row, int col) {
  S21Matrix result(rows_ - 1, cols_ - 1);

  int res_i = 0, res_j = 0;
  for (int i = 0; i < rows_ || res_i < rows_ - 1; i++) {
    if (i == row) continue;

    for (int j = 0; j < cols_ || res_j < (cols_ - 1); j++) {
      if (j == col) continue;

      result.matrix_[res_i][res_j++] = matrix_[i][j];
    }
    res_i++;
    res_j = 0;
  }
  return result;
}

// Освобождение памяти
void S21Matrix::remove_matrix() {
  if (matrix_) {
    delete[] matrix_[0];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}
