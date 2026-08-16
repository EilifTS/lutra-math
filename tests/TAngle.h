#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Angle.h>

TEST(Angle, Degrees1)
{
	const float angle = 1.0f;
	const lma::Angle a = lma::Angle::FromDegrees(angle);
	const float angle_result = a.ToDegrees();
	ASSERT_EQ(angle, angle_result);
}

TEST(Angle, Degrees359)
{
	const float angle = 359.0f;
	const lma::Angle a = lma::Angle::FromDegrees(angle);
	const float angle_result = a.ToDegrees();
	ASSERT_EQ(angle, angle_result);
}

TEST(Angle, DegreesNegative90)
{
	const lma::Angle a = lma::Angle::FromDegrees(-90.0f);
	const lma::Angle b = lma::Angle::FromDegrees(270.0f);
	ASSERT_EQ(a.angle, b.angle);
}

TEST(Angle, Degrees360)
{
	const lma::Angle a = lma::Angle::FromDegrees(360.0f);
	const lma::Angle b = lma::Angle::FromDegrees(0.0f);
	ASSERT_EQ(a.angle, b.angle);
}

