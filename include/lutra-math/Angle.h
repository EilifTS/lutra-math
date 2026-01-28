#pragma once
#include <lutra-math/Types.h>

namespace lma
{
	class Angle
	{
	public:
		static inline Angle FromDegrees(float degrees) { return { u32((degrees / 360.0f) * float(UINT32_MAX)) }; }
		static inline Angle FromRadians(float radians) { return { u32((radians / (2.0f * float(pi))) * float(UINT32_MAX)) }; }

		inline float ToDegrees() const { return (float(angle) / float(UINT32_MAX)) * 360.0f; }
		inline float ToRadians() const { return (float(angle) / float(UINT32_MAX)) * (2.0f * float(pi)); }

		static inline float DegreesToRadians(float degrees) { return degrees * ((2.0f * pi) / 360.0f); }

		u32 angle{};
	};
}