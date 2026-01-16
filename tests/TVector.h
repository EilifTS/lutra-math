#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Vector.h>

TEST(uint2, Add)
{
	const lma::uint2 a{ 1, 2 };
	const lma::uint2 b{ 5, 6 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::uint2(6, 8));
}

TEST(uint3, Add)
{
	const lma::uint3 a{ 1, 2, 3 };
	const lma::uint3 b{ 5, 6, 7 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::uint3(6, 8, 10));
}

TEST(uint4, Add)
{
	const lma::uint4 a{ 1, 2, 3, 4 };
	const lma::uint4 b{ 5, 6, 7, 8 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::uint4(6, 8, 10, 12));
}

TEST(int2, Add)
{
	const lma::int2 a{ 1, 2 };
	const lma::int2 b{ 5, 6 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::int2(6, 8));
}

TEST(int3, Add)
{
	const lma::int3 a{ 1, 2, 3 };
	const lma::int3 b{ 5, 6, 7 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::int3(6, 8, 10));
}

TEST(int4, Add)
{
	const lma::int4 a{ 1, 2, 3, 4 };
	const lma::int4 b{ 5, 6, 7, 8 };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::int4(6, 8, 10, 12));
}

TEST(int4, ShiftLeft)
{
	const lma::int4 a{ 1, 2, 3, 4 };
	const lma::int4 b{ 1, 2, 3, 4 };
	const auto c = a << b;
	ASSERT_TRUE(c == lma::int4(1 * 2, 2 * 4, 3 * 8, 4 * 16));
}

TEST(vec2, Add)
{
	const lma::vec2 a{ 1.0f, 2.0f };
	const lma::vec2 b{ 5.0f, 6.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::vec2(6.0f, 8.0f));
}

TEST(vec3, Add)
{
	const lma::vec3 a{ 1.0f, 2.0f, 3.0f };
	const lma::vec3 b{ 5.0f, 6.0f, 7.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::vec3(6.0f, 8.0f, 10.0f));
}

TEST(vec4, Add)
{
	const lma::vec4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
	const lma::vec4 b{ 5.0f, 6.0f, 7.0f, 8.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == lma::vec4(6.0f, 8.0f, 10.0f, 12.0f));
}