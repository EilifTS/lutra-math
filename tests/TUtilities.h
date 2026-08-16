#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Utilities.h>
#include <limits>

TEST(Utilities, MaxIntMin)
{
	const int min_value = std::numeric_limits<int>::min();
	ASSERT_EQ(lma::Max(min_value, 5), 5);
}

TEST(Utilities, RoundDownNegative)
{
	ASSERT_EQ(lma::RoundDown(-5, 3), -6);
}
