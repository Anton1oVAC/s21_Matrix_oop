#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// ################# ТЕСТЫ МЕТОДОВ
// EQUAL_MATRIX
TEST(test_1_equal_matrix, int_matrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 3;
  m3(0, 1) = 2;
  m3(1, 0) = 2;
  m3(1, 1) = 3;
  EXPECT_TRUE(m1.equal_matrix(m2));
  EXPECT_FALSE(m1.equal_matrix(m3));
}

TEST(test_1_equal_matrix, double_matrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2.009;
  m2(0, 1) = 2.001;
  m2(1, 0) = 1.999;
  m2(1, 1) = 2.00;
  EXPECT_FALSE(m1.equal_matrix(m2));
}

TEST(test_1_equal_matrix, operator) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2.009;
  m2(0, 1) = 2.001;
  m2(1, 0) = 1.999;
  m2(1, 1) = 2.00;

  m3(0, 0) = 2;
  m3(0, 1) = 2;
  m3(1, 0) = 2;
  m3(1, 1) = 2;
  EXPECT_FALSE(m1 == m2);
  EXPECT_TRUE(m1 == m3);
}

// SUM_MATRIX
TEST(test_2_sum_matrix, square_matrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;
  m1.sum_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}

TEST(test_2_sum_matrix, different_matrix) {
  S21Matrix m1(2, 4);
  S21Matrix m2(2, 4);
  S21Matrix m3(2, 4);
  m1(0, 1) = 2;
  m1(0, 0) = 2;
  m1(0, 2) = 2;
  m1(0, 3) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;
  m1(1, 2) = 2;
  m1(1, 3) = 2;

  m2(0, 0) = 2.009;
  m2(0, 1) = 2;
  m2(0, 2) = 2;
  m2(0, 3) = 2;
  m2(1, 0) = 0.007;
  m2(1, 1) = 2;
  m2(1, 2) = 2;
  m2(1, 3) = -1000;

  m3(0, 0) = 4.009;
  m3(0, 1) = 4;
  m3(0, 2) = 4;
  m3(0, 3) = 4;
  m3(1, 0) = 2.007;
  m3(1, 1) = 4;
  m3(1, 2) = 4;
  m3(1, 3) = -998;

  m1.sum_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}

TEST(test_2_sum_matrix, operator_sum_one) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;
  m1 += m2;
  EXPECT_TRUE(m1 == m3);
}

TEST(test_2_sum_matrix, operator_sum_two) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  S21Matrix m4(2, 2);

  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;

  m4 = m1 + m2;
  EXPECT_TRUE(m4 == m3);
}

TEST(test_2_sum_matrix, exception) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 4);
  EXPECT_THROW(m1.sum_matrix(m2), std::invalid_argument);
}

// SUB_MATRIX
TEST(test_3_sub_matrix, square_matrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;
  m3.sub_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}
TEST(test_3_sub_matrix, different_matrix) {
  S21Matrix m1(2, 4);
  S21Matrix m2(2, 4);
  S21Matrix m3(2, 4);
  m1(0, 1) = 2;
  m1(0, 0) = 2;
  m1(0, 2) = 2;
  m1(0, 3) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;
  m1(1, 2) = 2;
  m1(1, 3) = 2;

  m2(0, 0) = 2.009;
  m2(0, 1) = 2;
  m2(0, 2) = 2;
  m2(0, 3) = 2;
  m2(1, 0) = 0.007;
  m2(1, 1) = 2;
  m2(1, 2) = 2;
  m2(1, 3) = -1000;

  m3(0, 0) = 4.009;
  m3(0, 1) = 4;
  m3(0, 2) = 4;
  m3(0, 3) = 4;
  m3(1, 0) = 2.007;
  m3(1, 1) = 4;
  m3(1, 2) = 4;
  m3(1, 3) = -998;

  m3.sub_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}
TEST(test_3_sub_matrix, operator_sub_one) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;
  m3 -= m2;
  EXPECT_TRUE(m1 == m3);
}
TEST(test_3_sub_matrix, operator_sub_two) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  S21Matrix m4(2, 2);

  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2;
  m2(0, 1) = 2;
  m2(1, 0) = 2;
  m2(1, 1) = 2;

  m3(0, 0) = 4;
  m3(0, 1) = 4;
  m3(1, 0) = 4;
  m3(1, 1) = 4;

  m4 = m3 - m2;
  EXPECT_TRUE(m4 == m1);
}
TEST(test_3_sub_matrix, exception) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 4);
  EXPECT_THROW(m1.sub_matrix(m2), std::invalid_argument);
}


// MUL_NUMBER
TEST(test_4_mul_number, square_matrix_and_number) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  m2(0, 0) = 2000;
  m2(0, 1) = 2000;
  m2(1, 0) = 2000;
  m2(1, 1) = 2000;

  m1.mul_number(1000);
  EXPECT_TRUE(m1 == m2);
}

TEST(test_4_mul_number, rectangular_matrix_and_double){
  S21Matrix m1(2, 4);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }

  S21Matrix m2(2, 4);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m2(0, i) = (i + 1) * 0.3;
  }

  m1.mul_number(0.3);
  EXPECT_TRUE(m1 == m2);
}

TEST(test_4_mul_number, operator_one){
  S21Matrix m1(2, 4);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }

  S21Matrix m2(2, 4);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m2(0, i) = (i + 1) * 0.3;
  }

  m1 *= 0.3;
  EXPECT_TRUE(m1 == m2);
}

TEST(test_4_mul_number, operator_two){
  S21Matrix m1(2, 4);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }

  S21Matrix m2(2, 4);
  for (int i = 0; i < (m2.get_rows() * m2.get_cols()); i++) {
    m2(0, i) = (i + 1) * 0.3;
  }

  S21Matrix m3(2, 4);
  m3 = m1 * 0.3;
  EXPECT_TRUE(m3 == m2);
}


// MUL_MATRIX
TEST(test_5_mul_matrix, square_matrix){
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
    m2(0, i) = i + 1;
  }

  m3(0, 0) = 7;
  m3(0, 1) = 10;
  m3(1, 0) = 15;
  m3(1, 1) = 22;
  m1.mul_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}

TEST(test_5_mul_matrix, rectangular_matrix) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 3);
  S21Matrix m3(3, 3);
  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 4;

  m3(0, 0) = 9;
  m3(0, 1) = 11;
  m3(0, 2) = 17;
  m3(1, 0) = 12;
  m3(1, 1) = 13;
  m3(1, 2) = 22;
  m3(2, 0) = 15;
  m3(2, 1) = 15;
  m3(2, 2) = 27;
  m1.mul_matrix(m2);
  EXPECT_TRUE(m1 == m3);
}

TEST(test_5_mul_matrix, operator_one) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 3);
  S21Matrix m3(3, 3);
  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 4;

  m3(0, 0) = 9;
  m3(0, 1) = 11;
  m3(0, 2) = 17;
  m3(1, 0) = 12;
  m3(1, 1) = 13;
  m3(1, 2) = 22;
  m3(2, 0) = 15;
  m3(2, 1) = 15;
  m3(2, 2) = 27;

  m1 *= m2;
  EXPECT_TRUE(m1 == m3);
}

TEST(test_5_mul_matrix, operator_two) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 3);
  S21Matrix m3(3, 3);
  S21Matrix m4(3, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 4;

  m3(0, 0) = 9;
  m3(0, 1) = 11;
  m3(0, 2) = 17;
  m3(1, 0) = 12;
  m3(1, 1) = 13;
  m3(1, 2) = 22;
  m3(2, 0) = 15;
  m3(2, 1) = 15;
  m3(2, 2) = 27;

  m4 = m1 * m2;
  EXPECT_TRUE(m3 == m4);
}

TEST(test_5_mul_matrix, exception) {
  S21Matrix m1(2, 4);
  S21Matrix m2(2, 4);
  EXPECT_THROW(m1.mul_matrix(m2), std::invalid_argument);
}

// TRANSPOSE
TEST(test_6_transpose, square_matrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }

  m2(0, 0) = 1;
  m2(0, 1) = 3;
  m2(1, 0) = 2;
  m2(1, 1) = 4;
  m3 = m1.transpose();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_6_transpose, rectangular_matrix) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 3);
  S21Matrix m3(2, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(0, 2) = 3;
  m2(1, 0) = 4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;

  m3 = m1.transpose();
  EXPECT_TRUE(m2 == m3);
}

// DETERMINANT
TEST(test_7_determinant, one_elemetn) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 10;
  EXPECT_EQ(10, m1.determinant());
}

TEST(test_7_determinant, matrix_size_two) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;
  EXPECT_EQ(-2, m1.determinant());
}

TEST(test_7_determinant, big_matrix){
  S21Matrix m1(3, 3);
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  EXPECT_EQ(0, m1.determinant());
}

TEST(test_7_determinant, exception) {
  S21Matrix m1(3, 6);
  EXPECT_THROW(m1.determinant(), std::invalid_argument);
}

// CALC_COMPLEMENTS
TEST(test_8_calc_complements, one_element) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);
  S21Matrix m3(1, 1);
  m1(0, 0) = 1;
  m2(0, 0) = 1;

  m3 = m1.calc_complements();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_8_calc_complements, matrix_size_two) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;

  m2(0, 0) = 5;
  m2(0, 1) = -2;
  m2(1, 0) = -4;
  m2(1, 1) = 1;

  m3 = m1.calc_complements();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_8_calc_complements, big_matrix) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  S21Matrix m3(3, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 0;
  m1(1, 1) = 4;
  m1(1, 2) = 2;
  m1(2, 0) = 5;
  m1(2, 1) = 2;
  m1(2, 2) = 1;

  m2(0, 0) = 0;
  m2(0, 1) = 10;
  m2(0, 2) = -20;
  m2(1, 0) = 4;
  m2(1, 1) = -14;
  m2(1, 2) = 8;
  m2(2, 0) = -8;
  m2(2, 1) = -2;
  m2(2, 2) = 4;

  m3 = m1.calc_complements();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_8_calc_complements, exception) {
  S21Matrix m1(2, 4);
  EXPECT_THROW(m1.calc_complements(), std::invalid_argument);
}

// INVERSE_MATRIX
TEST(test_10_inverse_matrix, one_element) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);
  S21Matrix m3(1, 1);

  m1(0, 0) = 21;
  m2(0, 0) = 1;
  m3 = m1.inverse_matrix();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_10_inverse_matrix, matrix_size_two) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  S21Matrix m3(3, 3);

  m1(0, 0) = 2;
  m1(0, 1) = 5;
  m1(0, 2) = 7;
  m1(1, 0) = 6;
  m1(1, 1) = 3;
  m1(1, 2) = 4;
  m1(2, 0) = 5;
  m1(2, 1) = -2;
  m1(2, 2) = -3;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = -38;
  m2(1, 1) = 41;
  m2(1, 2) = -34;
  m2(2, 0) = 27;
  m2(2, 1) = -29;
  m2(2, 2) = 24;

  m3 = m1.inverse_matrix();
  EXPECT_TRUE(m2 == m3);
}

TEST(test_10_inverse_matrix, exception_one) {
  S21Matrix m1(3, 13);
  EXPECT_THROW(m1.inverse_matrix(), std::invalid_argument);
}

TEST(test_10_inverse_matrix, exception_two) {
  S21Matrix m1;
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  EXPECT_THROW(m1.inverse_matrix(), std::invalid_argument);
}

// ############ Тест Сеттеров
// SET_ROWS
TEST(test_11_set_rows, increase) {
  S21Matrix m1;
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  m1.set_rows(6);
  EXPECT_TRUE(6 == m1.get_rows());
  EXPECT_TRUE(0 == m1(5, 2));
}

TEST(test_11_set_rows, decrease) {
  S21Matrix m1;
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  m1.set_rows(1);
  EXPECT_TRUE(1 == m1.get_rows());
  EXPECT_EQ(3, m1(0, 2));
}

TEST(test_11_set_rows, exception) {
  S21Matrix m1;
  EXPECT_THROW(m1.set_rows(0), std::invalid_argument);
}


// SET_COLS
TEST(test_12_set_cols, increase) {
  S21Matrix m1;
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  m1.set_cols(6);
  EXPECT_TRUE(6 == m1.get_cols());
  EXPECT_TRUE(0 == m1(2, 5));
}

TEST(test_12_set_cols, decrease) {
  S21Matrix m1;
  for (int i = 0; i < (m1.get_rows() * m1.get_cols()); i++) {
    m1(0, i) = i + 1;
  }
  m1.set_cols(1);
  EXPECT_TRUE(1 == m1.get_cols());
  EXPECT_EQ(7, m1(2, 0));
}

TEST(test_12_set_cols, exception) {
  S21Matrix m1;
  EXPECT_THROW(m1.set_cols(-6), std::invalid_argument);
}


// ###########  Тест конструкторов
TEST(test_13_constructors, no_parametrs) {
  S21Matrix m1;
  EXPECT_EQ(3, m1.get_rows());
  EXPECT_EQ(3, m1.get_cols());
}

TEST(test_13_constructors, with_parametrs) {
  S21Matrix m1(6, 9);
  EXPECT_EQ(6, m1.get_rows());
  EXPECT_EQ(9, m1.get_cols());
}

TEST(test_13_constructors, copy) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  S21Matrix m2(m1);
  EXPECT_EQ(1, m1 == m2);
  EXPECT_EQ(2, m1(1, 1));
}

TEST(test_13_constructors, move) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  S21Matrix m2(std::move(m1));
  EXPECT_EQ(0, m1.get_rows());
  EXPECT_EQ(0, m1.get_cols());
  EXPECT_THROW(m1(0, 0), std::out_of_range);
  EXPECT_EQ(2, m2.get_rows());
  EXPECT_EQ(2, m2.get_cols());
  EXPECT_EQ(2, m2(1, 1));
}

TEST(test_13_constructors, operator) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 2;
  m1(0, 1) = 2;
  m1(1, 0) = 2;
  m1(1, 1) = 2;

  S21Matrix m2 = m1;
  EXPECT_EQ(1, m1 == m2);
}

TEST(test_13_constructors, exception) {
  EXPECT_THROW(S21Matrix matrix(0, -9), std::invalid_argument);
}



int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}