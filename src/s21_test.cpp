#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

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

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}