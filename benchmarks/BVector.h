#pragma once
#include <benchmark/benchmark.h>

#include <lutra-math/Vector.h>

#include <vector>

static void BenchmarkVectorAdd(benchmark::State& state)
{
	const u32 size = u32(state.range(0));

	std::vector<ef::vec4> a(size, ef::vec4(1.0f, 2.0f, 3.0f, 4.0f));

	benchmark::ClobberMemory();

	ef::vec4 sum{};
	for (auto _ : state)
	{
		for (u32 i = 0; i < size; i++)
		{
			sum += a[i];
		}
	}

	benchmark::DoNotOptimize(sum);
}
