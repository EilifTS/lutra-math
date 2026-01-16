#pragma once
#include <lutra-math/Vector.h>

namespace lma
{
	class mat4
	{
	public:
		static constexpr u32 D = 4;
		static constexpr u32 N = D * D;
		using T = float;

		inline mat4() {};
		inline mat4(std::initializer_list<T> l)
		{
			assert(l.size() == N);
			u32 i = 0;
			for (T v : l)
			{
				data[i] = v;
				i++;
			}
		};

		/* Operators */
		inline mat4& operator+=(const mat4& rhs)
		{
			for (u32 i = 0; i < N; i++)
			{
				this->data[i] += rhs.data[i];
			}
			return *this;
		};
		inline mat4& operator-=(const mat4& rhs)
		{
			for (u32 i = 0; i < N; i++)
			{
				this->data[i] -= rhs.data[i];
			}
			return *this;
		};
		inline mat4& operator/=(const mat4& rhs)
		{
			for (u32 i = 0; i < N; i++)
			{
				this->data[i] /= rhs.data[i];
			}
			return *this;
		};
		inline mat4 operator+(const mat4& rhs) const
		{
			mat4 temp(*this);
			temp += rhs;
			return temp;
		};
		inline mat4 operator-(const mat4& rhs) const
		{
			mat4 temp(*this);
			temp -= rhs;
			return temp;
		};
		inline mat4 operator/(const mat4& rhs) const
		{
			mat4 temp(*this);
			temp /= rhs;
			return temp;
		};
		inline mat4 operator-() const
		{
			mat4 temp;
			temp -= *this;
			return temp;
		};
		inline mat4& operator*=(T rhs)
		{
			for (u32 i = 0; i < N; i++)
			{
				this->data[i] *= rhs;
			}
			return *this;
		};
		inline mat4& operator/=(T rhs)
		{
			for (u32 i = 0; i < N; i++)
			{
				this->data[i] /= rhs;
			}
			return *this;
		};
		inline mat4 operator*(T rhs) const
		{
			mat4 temp(*this);
			temp *= rhs;
			return temp;
		};
		inline mat4 operator/(T rhs) const
		{
			mat4 temp(*this);
			temp /= rhs;
			return temp;
		};
		inline bool operator==(const mat4& rhs) const
		{
			bool result = true;
			for (u32 i = 0; i < N; i++)
			{
				result = result && this->data[i] == rhs.data[i];;
			}
			return result;
		};
		inline T operator[](int i) const
		{
			assert(i >= 0 && i < N);
			return data[i];
		};
		inline T& operator[](int i)
		{
			assert(i >= 0 && i < N);
			return data[i];
		};

		inline mat4 operator*(const mat4& rhs) const
		{
			const mat4& lhs = *this;
			mat4 out{};
			for (u32 row = 0; row < D; row++)
			{
				for (u32 col = 0; col < D; col++)
				{
					for (u32 i = 0; i < D; i++)
					{
						out.data[D * col + row] += lhs[D * col + i] * rhs[D * i + row];
					}
				}
			}
			return out;
		};
		inline mat4& operator*=(const mat4& rhs)
		{
			const mat4 cpy = *this;
			*this = cpy * rhs;
			return *this;
		}

	private:
		T data[N]{};
	};
}