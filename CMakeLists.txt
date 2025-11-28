cmake_minimum_required(VERSION 3.21)

project(HorribleChallenges
	VERSION 1.0.0.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# Googletest v1.17.0
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Google Benchmark (current stable tag as of late 2025; bump when needed)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.0
)

# Avoid building benchmark's own tests
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
# If you're on Linux and don't have gperftools, let it use stdc++fs etc.
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(benchmark)

if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
	find_package(Threads REQUIRED)
endif()












include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/utils/include)

add_subdirectory(src/01_type_list)
add_subdirectory(src/02_expr_eval)
add_subdirectory(src/03_pattern_match)
add_subdirectory(src/04_json_validator)
add_subdirectory(src/05_lambda_calc)
add_subdirectory(src/06_nn_params)
add_subdirectory(src/07_type_query)
add_subdirectory(src/08_type_tree)
add_subdirectory(src/09_metafunc_compiler)
add_subdirectory(src/10_reflection_system)


add_subdirectory(src/utils)

add_subdirectory(benchmarks)


# ---------------------------------------------------------
# Aggregate library for all HorribleChallenges source code
# ---------------------------------------------------------
file(GLOB_RECURSE HC_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

add_library(HorribleChallenges STATIC ${HC_SOURCES})
target_include_directories(HorribleChallenges PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_features(HorribleChallenges PUBLIC cxx_std_23)

add_subdirectory(tests)
