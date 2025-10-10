include_directories(include)

add_executable(
  04_json_validator
  04_json_validator.cc
)

target_link_libraries(
  04_json_validator
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(04_json_validator)