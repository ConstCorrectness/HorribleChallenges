include_directories(include)

add_executable(
  11_byte_pair_encoding
  11_byte_pair_encoding.cc
)

target_link_libraries(
  11_byte_pair_encoding
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(11_byte_pair_encoding)