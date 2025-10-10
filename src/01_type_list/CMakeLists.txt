include_directories(include)

add_executable(
  01_type_list
  01_type_list.cc
)

target_link_libraries(
  01_type_list
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(01_type_list)