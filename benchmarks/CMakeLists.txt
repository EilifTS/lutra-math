set(BENCHMARK_SOURCES
    benchmarks.cpp
)

add_executable(benchmarks ${BENCHMARK_SOURCES})
target_link_libraries(benchmarks PRIVATE benchmark::benchmark lutra-math)
