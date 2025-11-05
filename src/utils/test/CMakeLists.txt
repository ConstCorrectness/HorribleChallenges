enable_testing()

find_package(GTest CONFIG REQUIRED)  # or FetchContent if you prefer
add_executable(horribleutils_tests
  horribleutils_test.cc
  horribleJSON_test.cc
)
target_link_libraries(horribleutils_tests PRIVATE
  horribleutils
  GTest::gtest_main
)
target_compile_features(horribleutils_tests PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(horribleutils_tests)