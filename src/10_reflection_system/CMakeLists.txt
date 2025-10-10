include_directories(include)

add_executable(
  10_reflection_system
  10_reflection_system.cc
)

target_link_libraries(
  10_reflection_system
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(10_reflection_system)