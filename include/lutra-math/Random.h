#pragma once
#include <lutra-math/Types.h>

namespace lma
{
	inline void SetRandomSeed(u32 seed)
	{
		srand(seed);
	}

	inline u32 RandomU32()
	{
		return u32(rand());
	}

	/* Returns a random float in the interval [0, 1] */
	inline float RandomFloat()
	{
		return float(rand() / double(RAND_MAX));
	}
	inline vec2 RandomVec2Direction()
	{
		const float random_angle = 2.0f * 3.141592f * RandomFloat();
		vec2 v{ 1.0f, 0.0f };
		v.Rotate(random_angle);
		return v;
	}

	template <typename T>
	inline void Shuffle(T* v, u32 size)
	{
		for (int s = int(size); s > 0; s--)
		{
			const int i = (rand() % s);
			std::swap(v[s - 1], v[i]);
		}
	}

	template <typename T>
	inline void Shuffle(std::vector<T>& v)
	{
		Shuffle(v.data(), u32(v.size()));
	}
}