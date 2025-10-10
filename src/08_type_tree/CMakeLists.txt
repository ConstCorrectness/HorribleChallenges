include_directories(include)

add_executable(
  08_type_tree
  08_type_tree.cc
)

target_link_libraries(
  08_type_tree
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(08_type_tree)