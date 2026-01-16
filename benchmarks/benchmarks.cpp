#include <benchmark/benchmark.h>

#include "BVector.h"


BENCHMARK(BenchmarkVector4AddBaseline)->RangeMultiplier(2)->Range(1024, 1024 * 8);
BENCHMARK(BenchmarkVector4Add        )->RangeMultiplier(2)->Range(1024, 1024 * 8);

BENCHMARK_MAIN();
