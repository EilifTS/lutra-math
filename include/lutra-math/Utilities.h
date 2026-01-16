#pragma once
#include <lutra-math/Vector.h>
#include <vector>

namespace lma
{
	namespace easing
	{
		inline float Linear(float x)
		{
			return x;
		}
		inline float Smooth(float x)
		{
			return x * x * (3.0f - 2.0f * x);
		}
	}

	template <typename T>
	inline T Lerp(const T& a, const T& b, float x)
	{
		return a * (1.0f - x) + b * x;
	}

	inline int Min(int v1, int v2)
	{
		return v1 < v2 ? v1 : v2;
	}

	inline u32 Min(u32 v1, u32 v2)
	{
		return v1 < v2 ? v1 : v2;
	}

	inline float Min(float v1, float v2)
	{
		return v1 < v2 ? v1 : v2;
	}

	inline vec2 Min(vec2 v1, vec2 v2)
	{
		return vec2(
			Min(v1.x, v2.x),
			Min(v1.y, v2.y));
	}

	inline point2 Min(point2 v1, point2 v2)
	{
		return point2(
			Min(v1.x, v2.x),
			Min(v1.y, v2.y));
	}

	inline vec3 Min(vec3 v1, vec3 v2)
	{
		return vec3(
			Min(v1.x, v2.x),
			Min(v1.y, v2.y),
			Min(v1.z, v2.z));
	}

	inline point3 Min(point3 v1, point3 v2)
	{
		return point3(
			Min(v1.x, v2.x),
			Min(v1.y, v2.y),
			Min(v1.z, v2.z));
	}

	inline vec4 Min(vec4 v1, vec4 v2)
	{
		return vec4(
			Min(v1.x, v2.x),
			Min(v1.y, v2.y),
			Min(v1.z, v2.z),
			Min(v1.w, v2.w));
	}

	template <typename T>
	inline T Max(T v1, T v2)
	{
		return -Min(-v1, -v2);
	}

	template <>
	inline u32 Max(u32 v1, u32 v2)
	{
		return v1 > v2 ? v1 : v2;
	}

	template <typename T>
	inline T Clamp(T x, T min_v, T max_v)
	{
		return Min(max_v, Max(min_v, x));
	}

	inline float Remap(float value, float min1, float max1, float min2, float max2)
	{
		return min2 + (max2 - min2) * (value - min1) / (max1 - min1);
	}

	inline float Saturate(float x)
	{
		return Clamp(x, 0.0f, 1.0f);
	}

	template <typename T>
	inline T RoundDown(T value, T multiple_of)
	{
		return (value / multiple_of) * multiple_of;
	}

	template <typename T>
	inline T RoundUp(T value, T multiple_of)
	{
		return RoundDown<T>(value + multiple_of - 1, multiple_of);
	}

	namespace flattening
	{
		inline float Linear(float x, float b)
		{
			float one_min_b = (1.0f - b);
			if (x < -1.0f) return x + one_min_b;
			if (x > 1.0f) return x - one_min_b;
			return b * x;
		}
		inline float Smooth(float x, float b)
		{
			float one_min_b = 1.0f - b;
			return x - (2.0f * one_min_b) / (1.0f + expf(-2.0f * x)) + one_min_b;
		}
		inline float Flat(float x, float start, float end, float new_end)
		{
			float b = new_end / end;
			x = (x - start) / (end - start);
			x = 2.0f * x - 1.0f;
			float v = Smooth(x, b);
			v = 0.5f*(v / b + 1.0f);
			v = v * (new_end - start) + start;
			return v;
		}
	}

	inline std::vector<float> CreateGaussianKernel(int size, float sigma)
	{
		std::vector<float> out(size);

		float center = 0.5f * (float)(size - 1);
		float norm = 0.0f;
		float c = 1.0f / (2.0f * sigma * sigma);
		for (int i = 0; i < size; i++)
		{
			float x = (float)i - center;
			out[i] = expf(-x * x * c);
			norm += out[i];
		}
		norm = 1.0f / norm;
		for (int i = 0; i < size; i++)
		{
			out[i] *= norm;
		}

		return out;
	}
}
