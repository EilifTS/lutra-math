cmake_minimum_required (VERSION 3.16)
project(lutra-math LANGUAGES CXX)

option(LUTRA_MATH_BUILD_BENCHMARKS "Build benchmarks" ON)
option(LUTRA_MATH_BUILD_TESTS "Build tests" ON)

# Define library files
file(GLOB LUTRA_MATH_INCLUDES
    include/lutra-math/*.h
    include/lutra-math/internal/*.h
)

# Create library
add_library(lutra-math INTERFACE ${LUTRA_MATH_INCLUDES})

# Finish up library
target_include_directories(lutra-math INTERFACE "include")

# Testing dependencies
include(FetchContent)

if (LUTRA_MATH_BUILD_BENCHMARKS OR LUTRA_MATH_BUILD_TESTS)
    FetchContent_Declare(GTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(GTest)
endif()

if (LUTRA_MATH_BUILD_BENCHMARKS)
    FetchContent_Declare(benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
    set(BENCHMARK_ENABLE_TESTING OFF)
    set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
    FetchContent_MakeAvailable(benchmark)
endif()

# Benchmarks
if (LUTRA_MATH_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()

# Tests
if (LUTRA_MATH_BUILD_TESTS)
    add_subdirectory(tests)
endif()
