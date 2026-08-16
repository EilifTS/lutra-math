#pragma once
#include <lutra-math/Types.h>
#include <cmath>

namespace lma
{
	class Angle
	{
	public:
		static inline Angle FromDegrees(float degrees) { return FromTurns(degrees / 360.0f); }
		static inline Angle FromRadians(float radians) { return FromTurns(radians / (2.0f * float(pi))); }

		inline float ToDegrees() const { return (float(angle) / float(UINT32_MAX)) * 360.0f; }
		inline float ToRadians() const { return (float(angle) / float(UINT32_MAX)) * (2.0f * float(pi)); }

		static inline float DegreesToRadians(float degrees) { return degrees * ((2.0f * pi) / 360.0f); }

		u32 angle{};

	private:
		static inline Angle FromTurns(float turns)
		{
			float wrapped = std::fmod(turns, 1.0f);
			if (wrapped < 0.0f)
			{
				wrapped += 1.0f;
			}
			const double scaled = double(wrapped) * (double(UINT32_MAX) + 1.0);
			return { u32(scaled) };
		}
	};
}