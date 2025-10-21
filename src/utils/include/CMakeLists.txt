add_executable(
  horribleutils
  horribleutils_test.cc
)

target_link_libraries(
  horribleutils
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(horribleutils)