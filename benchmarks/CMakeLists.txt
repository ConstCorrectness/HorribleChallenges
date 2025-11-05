# benchmarks/CMakeLists.txt

add_executable(is_space_bench is_space_bench.cc)
target_link_libraries(is_space_bench PRIVATE benchmark::benchmark)
target_compile_features(is_space_bench PRIVATE cxx_std_20)
target_include_directories(is_space_bench PRIVATE ${CMAKE_SOURCE_DIR}/src/utils/include)

find_package(Threads)
if (TARGET Threads::Threads)
  target_link_libraries(is_space_bench PRIVATE Threads::Threads)
endif()

include(CTest)

# 🔑 Put JSON right beside the exe:
set(BENCH_JSON "${CMAKE_CURRENT_BINARY_DIR}/is_space_bench.json")

add_test(NAME is_space_bench_json
  COMMAND is_space_bench
          --benchmark_out=${BENCH_JSON}
          --benchmark_out_format=json
          --benchmark_repetitions=10
          --benchmark_report_aggregates_only=true
)
set_tests_properties(is_space_bench_json PROPERTIES
  LABELS "benchmark"
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Handy target: `cmake --build build --target bench`
add_custom_target(bench
  COMMAND is_space_bench
          --benchmark_out=${BENCH_JSON}
          --benchmark_out_format=json
          --benchmark_repetitions=10
          --benchmark_report_aggregates_only=true
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Running is_space_bench -> ${BENCH_JSON}"
  USES_TERMINAL
)