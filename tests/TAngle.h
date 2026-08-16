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

TEST(Angle, Zero)
{
	ASSERT_EQ(lma::Angle::Zero().angle, 0u);
}

TEST(Angle, Equality)
{
	ASSERT_TRUE(lma::Angle::FromDegrees(45.0f) == lma::Angle::FromDegrees(45.0f));
	ASSERT_TRUE(lma::Angle::FromDegrees(45.0f) != lma::Angle::FromDegrees(90.0f));
}

TEST(Angle, Add)
{
	const lma::Angle a = lma::Angle::FromDegrees(90.0f);
	const lma::Angle b = lma::Angle::FromDegrees(180.0f);
	ASSERT_TRUE((a + b) == lma::Angle::FromDegrees(270.0f));
}

TEST(Angle, Subtract)
{
	const lma::Angle a = lma::Angle::FromDegrees(90.0f);
	const lma::Angle b = lma::Angle::FromDegrees(180.0f);
	ASSERT_TRUE((a - b) == lma::Angle::FromDegrees(270.0f));
}

TEST(Angle, Negate)
{
	const lma::Angle a = lma::Angle::FromDegrees(90.0f);
	ASSERT_TRUE((-a) == lma::Angle::FromDegrees(270.0f));
}

TEST(Angle, DegreesToWrapsForward)
{
	const lma::Angle a = lma::Angle::FromDegrees(350.0f);
	const lma::Angle b = lma::Angle::FromDegrees(10.0f);
	ASSERT_NEAR(a.DegreesTo(b), 20.0f, 0.001f);
}

TEST(Angle, DegreesToWrapsBackward)
{
	const lma::Angle a = lma::Angle::FromDegrees(10.0f);
	const lma::Angle b = lma::Angle::FromDegrees(350.0f);
	ASSERT_NEAR(a.DegreesTo(b), -20.0f, 0.001f);
}

TEST(Angle, LerpTakesShortestPath)
{
	const lma::Angle a = lma::Angle::FromDegrees(350.0f);
	const lma::Angle b = lma::Angle::FromDegrees(10.0f);
	const lma::Angle mid = lma::Angle::Lerp(a, b, 0.5f);
	ASSERT_NEAR(mid.DegreesTo(lma::Angle::Zero()), 0.0f, 0.01f);
}

