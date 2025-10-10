include_directories(include)

add_executable(
  06_nn_params
  06_nn_params.cc
)

target_link_libraries(
  06_nn_params
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(06_nn_params)