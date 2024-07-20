#include "s21_matrix_oop.h"

#include <gtest/gtest.h>

TEST(Test_1__equal_matrix, Int_matrix) {
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

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}