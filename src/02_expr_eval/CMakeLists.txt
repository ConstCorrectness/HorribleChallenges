include_directories(include)

add_executable(
  02_expr_eval
  02_expr_eval.cc
)

target_link_libraries(
  02_expr_eval
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(02_expr_eval)