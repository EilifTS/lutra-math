#pragma once
#include <lutra-math/Types.h>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <type_traits>

namespace ef
{
	namespace internal
	{
		template <typename T, u32 N>
		class BaseVector
		{
		public:
			using element_t = T;
			static constexpr u32 element_count = N;

			inline BaseVector() {};
			explicit inline BaseVector(T v)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] = v;
				}
			};
			inline BaseVector(std::initializer_list<T> l)
			{
				assert(l.size() == N);
				u32 i = 0;
				for (T v : l)
				{
					data[i] = v;
					i++;
				}
			};

			/* Specialized 2-component constructors */
			inline BaseVector(T x, T y) requires(N == 2) : data{x, y} {};

			/* Specialized 3-component constructors */
			inline BaseVector(T x, T y, T z) : data{ x, y, z } {};
			inline BaseVector(const BaseVector<T, 2>& xy, T z) : data{ xy.x(), xy.y(), z} {};
			inline BaseVector(T x, const BaseVector<T, 2>& yz) : data{ x, yz.x(), yz.y() } {};

			/* Specialized 4-component constructors */
			inline BaseVector(T x, T y, T z, T w) : data{ x, y, z, w } {};
			inline BaseVector(const BaseVector<T, 2>& xy, const BaseVector<T, 2>& zw) : data{ xy.x(), xy.y(), zw.x(), zw.y() } {};
			inline BaseVector(const BaseVector<T, 2>& xy, T z, T w) : data{ xy.x(), xy.y(), z, w } {};
			inline BaseVector(T x, T y, const BaseVector<T, 2>& zw) : data{ x, y, zw.x(), zw.y() } {};
			inline BaseVector(T x, const BaseVector<T, 2>& yz, T w) : data{ x, yz.x(), yz.y(), w } {};
			inline BaseVector(const BaseVector<T, 3>& xyz, T w) : data{ xyz.x(), xyz.y(), xyz.z(), w } {};
			inline BaseVector(T x, const BaseVector<T, 3>& yzw) : data{ x, yzw.x(), yzw.y(), yzw.z() } {};

			inline T LengthSquared() const
			{
				return Dot(*this, *this);
			};
			inline float Length() const
			{
				return std::sqrt(float(LengthSquared()));
			};

			inline void Normalize()
			{
				*this /= Length();
			}
			inline BaseVector GetNormalized() const
			{
				return *this / Length();
			}

			inline bool IsZero() const
			{
				return *this == BaseVector(T(0));
			}

			/* Operators */
			inline BaseVector& operator+=(const BaseVector& rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] += rhs.data[i];
				}
				return *this;
			};
			inline BaseVector& operator-=(const BaseVector& rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] -= rhs.data[i];
				}
				return *this;
			};
			inline BaseVector& operator*=(const BaseVector& rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] *= rhs.data[i];
				}
				return *this;
			};
			inline BaseVector& operator/=(const BaseVector& rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] /= rhs.data[i];
				}
				return *this;
			};
			inline BaseVector& operator<<=(const BaseVector& rhs) requires std::integral<T>
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] <<= rhs.data[i];
				}
				return *this;
			}
			inline BaseVector& operator>>=(const BaseVector& rhs) requires std::integral<T>
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] >>= rhs.data[i];
				}
				return *this;
			}
			inline BaseVector operator+(const BaseVector& rhs) const
			{
				BaseVector temp(*this);
				temp += rhs;
				return temp;
			};
			inline BaseVector operator-(const BaseVector& rhs) const
			{
				BaseVector temp(*this);
				temp -= rhs;
				return temp;
			};
			inline BaseVector operator*(const BaseVector& rhs) const
			{
				BaseVector temp(*this);
				temp *= rhs;
				return temp;
			};
			inline BaseVector operator/(const BaseVector& rhs) const
			{
				BaseVector temp(*this);
				temp /= rhs;
				return temp;
			};
			inline BaseVector operator<<(const BaseVector& rhs) const requires std::integral<T>
			{
				BaseVector temp(*this);
				temp <<= rhs;
				return temp;
			}
			inline BaseVector operator>>(const BaseVector& rhs) const requires std::integral<T>
			{
				BaseVector temp(*this);
				temp >>= rhs;
				return temp;
			}
			inline BaseVector operator-() const
			{
				BaseVector temp;
				temp -= *this;
				return temp;
			};
			inline BaseVector& operator*=(T rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] *= rhs;
				}
				return *this;
			};
			inline BaseVector& operator/=(T rhs)
			{
				for (u32 i = 0; i < N; i++)
				{
					this->data[i] /= rhs;
				}
				return *this;
			};
			inline BaseVector operator*(T rhs) const
			{
				BaseVector temp(*this);
				temp *= rhs;
				return temp;
			};
			inline BaseVector operator/(T rhs) const
			{
				BaseVector temp(*this);
				temp /= rhs;
				return temp;
			};
			inline bool operator==(const BaseVector& rhs) const
			{
				bool result = true;
				for (u32 i = 0; i < N; i++)
				{
					result = result && this->data[i] == rhs.data[i];;
				}
				return result;
			};
			inline float operator[](int i) const
			{
				assert(i >= 0 && i < N);
				return data[i];
			};
			inline float& operator[](int i)
			{
				assert(i >= 0 && i < N);
				return data[i];
			};

			inline static T Dot(const BaseVector& lhs, const BaseVector& rhs)
			{
				float result = 0.0f;
				for (u32 i = 0; i < N; i++)
				{
					result += lhs.data[i] * rhs.data[i];
				}
				return result;
			};

			inline static float Angle(const BaseVector& lhs, const BaseVector& rhs)
			{
				const float dot = float(Dot(lhs, rhs));
				const float l = lhs.Length() * rhs.Length();
				return std::acos(dot / l);
			}

			/* Accessors */
			inline T& x()      requires(N >= 1) { return data[0]; };
			inline T x() const requires(N >= 1) { return data[0]; };
			inline T& y()      requires(N >= 2) { return data[1]; };
			inline T y() const requires(N >= 2) { return data[1]; };
			inline T& z()      requires(N >= 3) { return data[2]; };
			inline T z() const requires(N >= 3) { return data[2]; };
			inline T& w()      requires(N >= 4) { return data[3]; };
			inline T w() const requires(N >= 4) { return data[3]; };

			/* 2-component specializations */
			inline static float Cross(const BaseVector& lhs, const BaseVector& rhs) requires (N == 2)
			{
				return lhs.x() * rhs.y() - lhs.y() * rhs.x();
			}
			inline float Angle() const requires (N == 2)
			{
				return atan2f(float(y()), float(x()));
			}
			inline void Rotate(float angle) requires (N == 2)
			{
				const float c = cosf(angle);
				const float s = sinf(angle);
				const float ox = float(x());
				const float oy = float(y());
				x() = T(c * ox - s * oy);
				y() = T(s * ox + c * oy);
			}

			/* 3-component specializations */
			inline static BaseVector Cross(const BaseVector& lhs, const BaseVector& rhs) requires (N == 3)
			{
				return BaseVector(
					lhs.y() * rhs.z() - lhs.z() * rhs.y(),
					lhs.z() * rhs.x() - lhs.x() * rhs.z(),
					lhs.x() * rhs.y() - lhs.y() * rhs.x()
				);
			}

		protected:
			T data[N]{};
		};

		template <typename T, u32 N>
		inline BaseVector<T, N> operator*(T lhs, const BaseVector<T, N>& a)
		{
			return a * lhs;
		};
	}
}