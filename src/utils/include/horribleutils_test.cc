#include <type_traits>


#include "horribleutils.hpp"
#include <gtest/gtest.h>


TEST(UTILS, typelist) {
  using namespace horrible::utils;

  using SignedIntegrals = Typelist<signed char, signed short, signed int, signed long, signed long long>;
  static_assert(std::is_same_v<front_t<SignedIntegrals>, front_t<Typelist<signed char>>>, "ERROR: front_t");
}
