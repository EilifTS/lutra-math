#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Angle.h>

TEST(Angle, Degrees1)
{
	const float angle = 1.0f;
	const lma::Angle a = lma::Angle::FromDegrees(angle);
	const float angle_result = a.ToDegrees();
	ASSERT_TRUE(angle == angle_result);
}

TEST(Angle, Degrees359)
{
	const float angle = 359.0f;
	const lma::Angle a = lma::Angle::FromDegrees(angle);
	const float angle_result = a.ToDegrees();
	ASSERT_TRUE(angle == angle_result);
}

TEST(Angle, Degrees360)
{
	const float angle = 360.0f;
	const lma::Angle a = lma::Angle::FromDegrees(angle);
	const float angle_result = a.ToDegrees();
	ASSERT_TRUE(0.0f == angle_result);
}
