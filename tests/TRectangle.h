#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Rectangle.h>

TEST(Rectanglef, Clamp)
{
	const lma::Rectanglef rect({ 0.0f, 0.0f }, { 0.5f, 0.5f });
	const lma::vec2 point(5.0f, 0.1f);
	const lma::vec2 clamped = rect.Clamp(point);
	ASSERT_TRUE(rect.Contains(clamped));
}
