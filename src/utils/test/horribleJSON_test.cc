#include <type_traits>


#include "horribleJSON.hpp"
#include <gtest/gtest.h>


TEST(JSON, is_space_literals) {
  using namespace horrible::utils;

  EXPECT_EQ(is_space(' '), true);
  EXPECT_EQ(is_space(L' '), true);
  EXPECT_EQ(is_space(u8' '), true);
  EXPECT_EQ(is_space(u' '), true);
  EXPECT_EQ(is_space(U' '), true);

  EXPECT_EQ(is_space(static_cast<char>(0x20)), true);
  EXPECT_EQ(is_space(U'\x20'), true);
  EXPECT_EQ(is_space(U'\x20'), true);
  EXPECT_EQ(is_space(u8'a'), false);

}