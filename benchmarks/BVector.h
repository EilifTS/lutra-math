#pragma once
#include <benchmark/benchmark.h>

#include <lutra-math/Vector.h>

#include <vector>

static void BenchmarkVector4AddBaseline(benchmark::State& state)
{
	const u32 size = u32(state.range(0));

	struct TmpVec4 {
		float x{};
		float y{};
		float z{};
		float w{};
	};

	std::vector<TmpVec4> a(size, { 1.0f, 2.0f, 3.0f, 4.0f });

	benchmark::ClobberMemory();

	TmpVec4 sum{};
	for (auto _ : state)
	{
		for (u32 i = 0; i < size; i++)
		{
			sum.x += a[i].x;
			sum.y += a[i].y;
			sum.z += a[i].z;
			sum.w += a[i].w;
		}
	}

	benchmark::DoNotOptimize(sum);
}

static void BenchmarkVector4Add(benchmark::State& state)
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
