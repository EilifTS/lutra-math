#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Vector.h>

TEST(uint2, Add)
{
	const ef::uint2 a{ 1, 2 };
	const ef::uint2 b{ 5, 6 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::uint2(6, 8));
}

TEST(uint3, Add)
{
	const ef::uint3 a{ 1, 2, 3 };
	const ef::uint3 b{ 5, 6, 7 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::uint3(6, 8, 10));
}

TEST(uint4, Add)
{
	const ef::uint4 a{ 1, 2, 3, 4 };
	const ef::uint4 b{ 5, 6, 7, 8 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::uint4(6, 8, 10, 12));
}

TEST(int2, Add)
{
	const ef::int2 a{ 1, 2 };
	const ef::int2 b{ 5, 6 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::int2(6, 8));
}

TEST(int3, Add)
{
	const ef::int3 a{ 1, 2, 3 };
	const ef::int3 b{ 5, 6, 7 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::int3(6, 8, 10));
}

TEST(int4, Add)
{
	const ef::int4 a{ 1, 2, 3, 4 };
	const ef::int4 b{ 5, 6, 7, 8 };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::int4(6, 8, 10, 12));
}

TEST(int4, ShiftLeft)
{
	const ef::int4 a{ 1, 2, 3, 4 };
	const ef::int4 b{ 1, 2, 3, 4 };
	const auto c = a << b;
	ASSERT_TRUE(c == ef::int4(1 * 2, 2 * 4, 3 * 8, 4 * 16));
}

TEST(vec2, Add)
{
	const ef::vec2 a{ 1.0f, 2.0f };
	const ef::vec2 b{ 5.0f, 6.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::vec2(6.0f, 8.0f));
}

TEST(vec3, Add)
{
	const ef::vec3 a{ 1.0f, 2.0f, 3.0f };
	const ef::vec3 b{ 5.0f, 6.0f, 7.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::vec3(6.0f, 8.0f, 10.0f));
}

TEST(vec4, Add)
{
	const ef::vec4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
	const ef::vec4 b{ 5.0f, 6.0f, 7.0f, 8.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::vec4(6.0f, 8.0f, 10.0f, 12.0f));
}