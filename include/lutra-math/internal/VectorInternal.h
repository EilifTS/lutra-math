#pragma once
#include <lutra-math/Types.h>
#include <cassert>
#include <cmath>
#include <initializer_list>

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
			explicit inline BaseVector(std::initializer_list<T> l)
			{
				assert(l.size() == N);
				u32 i = 0;
				for (T v : l)
				{
					data[i] = v;
					i++;
				}
			};

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
				assert(i >= 0 && i < 4);
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

		protected:
			T data[4]{};
		};

		template <typename T, u32 N>
		inline BaseVector<T, N> operator*(T lhs, const BaseVector<T, N>& a)
		{
			return a * lhs;
		};

		template <typename T>
		class BaseVector2 : public BaseVector<T, 2>
		{
		public:
			using Base = BaseVector<T, 2>;
			using typename Base::BaseVector; /* Inherit constructors */

			/* Specialized constructors */
			inline BaseVector2() : Base() {};
			inline BaseVector2(T x, T y) : Base({ x, y }) {};

			/* Specialized accessors */
			inline T& x() { return Base::data[0]; };
			inline T x() const { return Base::data[0]; };
			inline T& y() { return Base::data[1]; };
			inline T y() const { return Base::data[1]; };

			/* Specialized functions */
			inline static float Cross(const BaseVector2& lhs, const BaseVector2& rhs)
			{
				return lhs.x() * rhs.y() - lhs.y() * rhs.x();
			}
			inline float Angle() const
			{
				return atan2f(float(y()), float(x()));
			}
			inline void Rotate(float angle)
			{
				const float c = cosf(angle);
				const float s = sinf(angle);
				const float ox = float(x());
				const float oy = float(y());
				x() = T(c * ox - s * oy);
				y() = T(s * ox + c * oy);
			}
		};

		template <typename T>
		class BaseVector3 : public BaseVector<T, 3>
		{
		public:
			using Base = BaseVector<T, 3>;
			using typename Base::BaseVector; /* Inherit constructors */

			/* Specialized constructors */
			inline BaseVector3() : Base() {};
			inline BaseVector3(T x, T y, T z) : Base({ x, y, z }) {};
			inline BaseVector3(const BaseVector2<T>& xy, T z) : Base({ xy.x, xy.y, z }) {};
			inline BaseVector3(T x, const BaseVector2<T>& yz) : Base({ x, yz.x, yz.y }) {};

			/* Specialized accessors */
			inline T& x() { return Base::data[0]; };
			inline T x() const { return Base::data[0]; };
			inline T& y() { return Base::data[1]; };
			inline T y() const { return Base::data[1]; };
			inline T& z() { return Base::data[2]; };
			inline T z() const { return Base::data[2]; };

			/* Specialized functions */
			inline static BaseVector3 Cross(const BaseVector3& lhs, const BaseVector3& rhs)
			{
				return BaseVector3(
					lhs.y() * rhs.z() - lhs.z() * rhs.y(),
					lhs.z() * rhs.x() - lhs.x() * rhs.z(),
					lhs.x() * rhs.y() - lhs.y() * rhs.x()
				);
			}
		};

		template <typename T>
		class BaseVector4 : public BaseVector<T, 4>
		{
		public:
			using Base = BaseVector<T, 4>;
			using typename Base::BaseVector; /* Inherit constructors */

			/* Specialized constructors */
			inline BaseVector4() : Base() {};
			inline BaseVector4(T x, T y, T z, T w) : Base({ x, y, z, w }) {};
			inline BaseVector4(const BaseVector2<T>& xy, const BaseVector2<T>& zw) : Base({ xy.x, xy.y, zw.x, zw.y }) {};
			inline BaseVector4(const BaseVector2<T>& xy, T z, T w) : Base({ xy.x, xy.y, z, w }) {};
			inline BaseVector4(T x, T y, const BaseVector2<T>& zw) : Base({ x, y, zw.x, zw.y }) {};
			inline BaseVector4(T x, const BaseVector2<T>& yz, T w) : Base({ x, yz.x, yz.y, w }) {};
			inline BaseVector4(const BaseVector3<T>& xyz, T w) : Base({ xyz.x, xyz.y, xyz.z, w }) {};
			inline BaseVector4(T x, const BaseVector3<T>& yzw) : Base({ x, yzw.x, yzw.y, yzw.z }) {};


			/* Specialized accessors */
			inline T& x() { return Base::data[0]; };
			inline T x() const { return Base::data[0]; };
			inline T& y() { return Base::data[1]; };
			inline T y() const { return Base::data[1]; };
			inline T& z() { return Base::data[2]; };
			inline T z() const { return Base::data[2]; };
			inline T& w() { return Base::data[3]; };
			inline T w() const { return Base::data[3]; };
		};
	}
}