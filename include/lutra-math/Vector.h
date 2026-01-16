#pragma once
#include <lutra-math/Types.h>
#include <lutra-math/internal/VectorInternal.h>
#include <cassert>
#include <cmath>

namespace ef
{
	template<typename T>
	class tpoint2
	{
	public:
		T x;
		T y;

	public:
		inline tpoint2()
			: x(0), y(0)
		{}
		explicit inline tpoint2(T v)
			: x(v), y(v)
		{}
		inline tpoint2(T x, T y)
			: x(x), y(y)
		{}

		inline tpoint2& operator+=(const tpoint2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		inline tpoint2& operator-=(const tpoint2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}
		inline tpoint2 operator+(const tpoint2& rhs) const
		{
			return tpoint2(x + rhs.x, y + rhs.y);
		}
		inline tpoint2 operator-(const tpoint2& rhs) const
		{
			return tpoint2(x - rhs.x, y - rhs.y);
		}
		inline tpoint2 operator*(int rhs) const
		{
			return tpoint2(x * rhs, y * rhs);
		}
		inline tpoint2 operator*(const tpoint2& rhs) const
		{
			return tpoint2(x * rhs.x, y * rhs.y);
		}
		inline tpoint2 operator/(int rhs) const
		{
			return tpoint2(x / rhs, y / rhs);
		}
		inline tpoint2 operator/(const tpoint2& rhs) const
		{
			return tpoint2(x / rhs.x, y / rhs.y);
		}
		inline tpoint2 operator>>(int rhs) const
		{
			return tpoint2(x >> rhs, y >> rhs);
		}
		inline tpoint2 operator<<(int rhs) const
		{
			return tpoint2(x << rhs, y << rhs);
		}
		inline tpoint2 operator-() const
		{
			tpoint2 temp;
			temp -= *this;
			return temp;
		};
		inline tpoint2& operator=(const tpoint2& rhs)
		{
			this->x = rhs.x;
			this->y = rhs.y;
			return *this;
		}

		inline bool operator==(const tpoint2& rhs) const
		{
			return x == rhs.x && y == rhs.y;
		}
	};

	template <typename T>
	inline tpoint2<T> operator*(T lhs, const tpoint2<T>& a)
	{
		return a * lhs;
	};

	using point2 = tpoint2<int>;
	using point2u = tpoint2<u32>;

	template<typename T>
	class tpoint3
	{
	public:
		T x;
		T y;
		T z;

	public:
		inline tpoint3()
			: x(0), y(0), z(0)
		{}
		explicit inline tpoint3(T v)
			: x(v), y(v), z(v)
		{}
		inline tpoint3(T x, T y, T z)
			: x(x), y(y), z(z)
		{}

		inline tpoint3& operator+=(const tpoint3& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}
		inline tpoint3& operator-=(const tpoint3& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}
		inline tpoint3 operator+(const tpoint3& rhs) const
		{
			return tpoint3(x + rhs.x, y + rhs.y, z + rhs.z);
		}
		inline tpoint3 operator-(const tpoint3& rhs) const
		{
			return tpoint3(x - rhs.x, y - rhs.y, z - rhs.z);
		}
		inline tpoint3 operator*(int rhs) const
		{
			return tpoint3(x * rhs, y * rhs, z * rhs);
		}
		inline tpoint3 operator*(const tpoint3& rhs) const
		{
			return tpoint3(x * rhs.x, y * rhs.y, z * rhs.z);
		}
		inline tpoint3 operator/(int rhs) const
		{
			return tpoint3(x / rhs, y / rhs, z / rhs);
		}
		inline tpoint3 operator/(const tpoint3& rhs) const
		{
			return tpoint3(x / rhs.x, y / rhs.y, z / rhs.z);
		}
		inline tpoint3 operator>>(int rhs) const
		{
			return tpoint3(x >> rhs, y >> rhs, z >> rhs);
		}
		inline tpoint3 operator<<(int rhs) const
		{
			return tpoint3(x << rhs, y << rhs, z << rhs);
		}
		inline tpoint3 operator-() const
		{
			tpoint3 temp;
			temp -= *this;
			return temp;
		};

		inline bool operator==(const tpoint3& rhs) const
		{
			return x == rhs.x && y == rhs.y && z == rhs.z;
		}
	};
	
	template <typename T>
	inline tpoint3<T> operator*(T lhs, const tpoint3<T>& a)
	{
		return a * lhs;
	};

	using point3 = tpoint3<int>;
	using point3u = tpoint3<u32>;

	template<typename T>
	class tpoint4
	{
	public:
		T x;
		T y;
		T z;
		T w;

	public:
		inline tpoint4()
			: x(0), y(0), z(0), w(0)
		{}
		explicit inline tpoint4(T v)
			: x(v), y(v), z(v), w(v)
		{}
		inline tpoint4(T x, T y, T z, T w)
			: x(x), y(y), z(z), w(w)
		{}

		inline tpoint4& operator+=(const tpoint4& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}
		inline tpoint4& operator-=(const tpoint4& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}
		inline tpoint4 operator+(const tpoint4& rhs) const
		{
			return tpoint4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}
		inline tpoint4 operator-(const tpoint4& rhs) const
		{
			return tpoint4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}
		inline tpoint4 operator*(int rhs) const
		{
			return tpoint4(x * rhs, y * rhs, z * rhs, w * rhs);
		}
		inline tpoint4 operator*(const tpoint4& rhs) const
		{
			return tpoint4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}
		inline tpoint4 operator/(int rhs) const
		{
			return tpoint4(x / rhs, y / rhs, z / rhs, w / rhs);
		}
		inline tpoint4 operator/(const tpoint4& rhs) const
		{
			return tpoint4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}
		inline tpoint4 operator>>(int rhs) const
		{
			return tpoint4(x >> rhs, y >> rhs, z >> rhs, w >> rhs);
		}
		inline tpoint4 operator<<(int rhs) const
		{
			return tpoint4(x << rhs, y << rhs, z << rhs, w << rhs);
		}
		inline tpoint4 operator-() const
		{
			tpoint4 temp;
			temp -= *this;
			return temp;
		};

		inline bool operator==(const tpoint4& rhs) const
		{
			return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
		}
	};

	template <typename T>
	inline tpoint4<T> operator*(T lhs, const tpoint4<T>& a)
	{
		return a * lhs;
	};

	using point4 = tpoint4<int>;
	using point4u = tpoint4<u32>;

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