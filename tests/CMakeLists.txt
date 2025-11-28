cmake_minimum_required(VERSION 3.21)
project(HorribleChallenges_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest target is already available via FetchContent from top-level CMake
# We'll use gtest_main for main() boilerplate
find_package(GTest REQUIRED)

# Test executable
add_executable(horrible_tests
    01_type_list/test_type_list.cc
    02_expr_eval/test_expr_eval.cc
    03_pattern_match/test_pattern_match.cc
    04_json_validator/test_json_validator.cc
    05_lambda_calc/test_lambda_calc.cc
    06_nn_params/test_nn_params.cc
    07_type_query/test_type_query.cc
    08_type_tree/test_type_tree.cc
    09_metafunc_compiler/test_metafunc_compiler.cc
    10_reflection_system/test_reflection_system.cc
    11_byte_pair_encoding/test_bpe.cc
)

# Include directories so tests can see src headers
target_include_directories(horrible_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/utils/include
)

# Link GoogleTest
target_link_libraries(horrible_tests
    PRIVATE
        GTest::gtest_main
)

# Register tests with CTest
enable_testing()
add_test(NAME HorribleTests COMMAND horrible_tests)
