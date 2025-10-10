include_directories(include)

add_executable(
  07_type_query
  07_type_query.cc
)

target_link_libraries(
  07_type_query
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(07_type_query)