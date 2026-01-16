#pragma once
#include <gtest/gtest.h>

#include <lutra-math/Quaternion.h>

TEST(Quaternion, Identity)
{
	const lma::quat q = lma::quat::Identity();
	ASSERT_TRUE(q.ToVector() == lma::vec4(1.0f, 0.0f, 0.0f, 0.0f));
}

TEST(Quaternion, Identities)
{
	const lma::quat one = lma::quat::Identity();
	const lma::quat i = lma::quat::I();
	const lma::quat j = lma::quat::J();
	const lma::quat k = lma::quat::K();

	ASSERT_TRUE((one * one).ToVector() == one.ToVector());
	ASSERT_TRUE((one * one).ToVector() == one.ToVector());
	ASSERT_TRUE((one * i).ToVector() == i.ToVector());
	ASSERT_TRUE((i * one).ToVector() == i.ToVector());
	ASSERT_TRUE((one * j).ToVector() == j.ToVector());
	ASSERT_TRUE((j * one).ToVector() == j.ToVector());
	ASSERT_TRUE((one * k).ToVector() == k.ToVector());
	ASSERT_TRUE((k * one).ToVector() == k.ToVector());

	ASSERT_TRUE((i * i).ToVector() == (-one).ToVector());
	ASSERT_TRUE((j * j).ToVector() == (-one).ToVector());
	ASSERT_TRUE((k * k).ToVector() == (-one).ToVector());
	ASSERT_TRUE((i * j * k).ToVector() == (-one).ToVector());

	ASSERT_TRUE((i * j).ToVector() == k.ToVector());
	ASSERT_TRUE((-j * i).ToVector() == k.ToVector());
	ASSERT_TRUE((j * k).ToVector() == i.ToVector());
	ASSERT_TRUE((-k * j).ToVector() == i.ToVector());
	ASSERT_TRUE((k * i).ToVector() == j.ToVector());
	ASSERT_TRUE((-i * k).ToVector() == j.ToVector());
}
