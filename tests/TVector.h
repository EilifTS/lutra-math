#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Vector.h>

TEST(Vector, Add)
{
	const ef::vec4 a{ 1.0f, 2.0f, 3.0f, 4.0f };
	const ef::vec4 b{ 5.0f, 6.0f, 7.0f, 8.0f };
	const auto c = a + b;
	ASSERT_TRUE(c == ef::vec4(6.0f, 8.0f, 10.0f, 12.0f));
}