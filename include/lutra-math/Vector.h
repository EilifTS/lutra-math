#pragma once
#include <lutra-math/Types.h>
#include <lutra-math/internal/VectorInternal.h>
#include <cassert>
#include <cmath>

namespace lma
{
	using uint2 = internal::BaseVector<u32, 2>;
	using uint3 = internal::BaseVector<u32, 3>;
	using uint4 = internal::BaseVector<u32, 4>;
	using int2 = internal::BaseVector<s32, 2>;
	using int3 = internal::BaseVector<s32, 3>;
	using int4 = internal::BaseVector<s32, 4>;
	using vec2 = internal::BaseVector<float, 2>;
	using vec3 = internal::BaseVector<float, 3>;
	using vec4 = internal::BaseVector<float, 4>;
}