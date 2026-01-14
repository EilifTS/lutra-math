#include <benchmark/benchmark.h>

#include "BVector.h"


BENCHMARK(BenchmarkVectorAdd)->RangeMultiplier(2)->Range(1024, 1024 * 8);

BENCHMARK_MAIN();
