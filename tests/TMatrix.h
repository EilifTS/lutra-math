#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Matrix.h>

TEST(Matrix, Multiply)
{
	const lma::mat4 a = {
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f, 7.0f,
	};
	const lma::mat4 b = {
		9.0f, 8.0f, 7.0f, 6.0f,
		5.0f, 4.0f, 3.0f, 2.0f,
		1.0f, 9.0f, 8.0f, 7.0f,
		6.0f, 5.0f, 4.0f, 3.0f,
	};
	const auto c = a * b;
	const lma::mat4 result = {
		 46.0f,  63.0f,  53.0f,  43.0f,
		130.0f, 167.0f, 141.0f, 115.0f,
		106.0f, 109.0f,  94.0f,  79.0f,
		109.0f, 141.0f, 119.0f,  97.0f
	};
	ASSERT_TRUE(result == c);
}

