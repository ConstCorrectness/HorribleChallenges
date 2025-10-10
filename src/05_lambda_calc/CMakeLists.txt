include_directories(include)

add_executable(
  05_lambda_calc
  05_lambda_calc.cc
)

target_link_libraries(
  05_lambda_calc
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(05_lambda_calc)