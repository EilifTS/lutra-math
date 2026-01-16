#pragma once
#include <lutra-math/Vector.h>

namespace lma
{
	class quat
	{
	public:
		inline quat() {};
		inline quat(float a, float b, float c, float d) : q(a, b, c, d) {};
		inline explicit quat(const vec4& in) : q(in) {};

		static inline quat Identity() { return quat( 1.0f, 0.0f, 0.0f, 0.0f); }
		static inline quat I() { return quat(0.0f, 1.0f, 0.0f, 0.0f); }
		static inline quat J() { return quat(0.0f, 0.0f, 1.0f, 0.0f); }
		static inline quat K() { return quat(0.0f, 0.0f, 0.0f, 1.0f); }

		inline const vec4& ToVector() const { return q; }

		inline quat operator*(const quat& rhs) const
		{
			const vec4& v1 = q;
			const vec4& v2 = rhs.q;

			const quat out{
				v1.x() * v2.x() - v1.y() * v2.y() - v1.z() * v2.z() - v1.w() * v2.w(),
				v1.x() * v2.y() + v1.y() * v2.x() + v1.z() * v2.w() - v1.w() * v2.z(),
				v1.x() * v2.z() - v1.y() * v2.w() + v1.z() * v2.x() + v1.w() * v2.y(),
				v1.x() * v2.w() + v1.y() * v2.z() - v1.z() * v2.y() + v1.w() * v2.x(),
			};
			return out;
		};
		inline quat operator-() const
		{
			return quat(-q);
		};
	private:
		vec4 q{};
	};
}