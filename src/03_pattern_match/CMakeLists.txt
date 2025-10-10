include_directories(include)

add_executable(
  03_pattern_match
  03_pattern_match.cc
)

target_link_libraries(
  03_pattern_match
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(03_pattern_match)