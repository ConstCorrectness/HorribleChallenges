cmake_minimum_required(VERSION 3.21)

project(HorribleChallenges
	VERSION 1.0.0.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
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



