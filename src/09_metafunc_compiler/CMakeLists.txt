include_directories(include)

add_executable(
  09_metafunc_compiler
  09_metafunc_compiler.cc
)

target_link_libraries(
  09_metafunc_compiler
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(09_metafunc_compiler)