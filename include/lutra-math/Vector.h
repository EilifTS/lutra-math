#pragma once
#include <lutra-math/Types.h>
#include <lutra-math/internal/VectorInternal.h>
#include <cassert>
#include <cmath>

namespace ef
{
	class uint2 : public internal::BaseVector2<u32>
	{
		using internal::BaseVector2<u32>::BaseVector2; /* Inherit constructors */
	};
	class uint3 : public internal::BaseVector3<u32>
	{
		using internal::BaseVector3<u32>::BaseVector3; /* Inherit constructors */
	};
	class uint4 : public internal::BaseVector4<u32>
	{
		using internal::BaseVector4<u32>::BaseVector4; /* Inherit constructors */
	};

	class int2 : public internal::BaseVector2<s32>
	{
		using internal::BaseVector2<s32>::BaseVector2; /* Inherit constructors */
	};
	class int3 : public internal::BaseVector3<s32>
	{
		using internal::BaseVector3<s32>::BaseVector3; /* Inherit constructors */
	};
	class int4 : public internal::BaseVector4<s32>
	{
		using internal::BaseVector4<s32>::BaseVector4; /* Inherit constructors */
	};

	class vec2 : public internal::BaseVector2<float>
	{
		using internal::BaseVector2<float>::BaseVector2; /* Inherit constructors */
	};
	class vec3 : public internal::BaseVector3<float>
	{
		using internal::BaseVector3<float>::BaseVector3; /* Inherit constructors */
	};
	class vec4 : public internal::BaseVector4<float>
	{
		using internal::BaseVector4<float>::BaseVector4; /* Inherit constructors */
	};
}