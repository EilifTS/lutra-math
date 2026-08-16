cmake_minimum_required (VERSION 3.28)
project(lutra-math LANGUAGES CXX)

option(LUTRA_MATH_BUILD_BENCHMARKS "Build benchmarks" ${PROJECT_IS_TOP_LEVEL})
option(LUTRA_MATH_BUILD_TESTS "Build tests" ${PROJECT_IS_TOP_LEVEL})

# Define library files
file(GLOB LUTRA_MATH_INCLUDES CONFIGURE_DEPENDS
    include/lutra-math/*.h
    include/lutra-math/internal/*.h
)

# Create library
add_library(lutra-math INTERFACE ${LUTRA_MATH_INCLUDES})

# Finish up library
target_include_directories(lutra-math INTERFACE "include")
target_compile_features(lutra-math INTERFACE cxx_std_20)

# Testing dependencies
include(FetchContent)

if (LUTRA_MATH_BUILD_TESTS)
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
    enable_testing()
    add_subdirectory(tests)
endif()
