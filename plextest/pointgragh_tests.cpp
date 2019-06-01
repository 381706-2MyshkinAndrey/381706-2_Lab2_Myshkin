#include <gtest.h>
#include <TPointGragh.h>

TEST(TPointGragh, can_create_point)
{
  ASSERT_NO_THROW(TPointGragh p);
}

TEST(TPointGragh, can_set_x)
{
  TPointGragh a(0, 1);
  ASSERT_NO_THROW(a.SetX(1));
}

TEST(TPointGragh, can_set_y)
{
  TPointGragh a(0, 1);
  ASSERT_NO_THROW(a.SetY(1));
}

TEST(TPointGragh, can_get_x)
{
  TPointGragh a(0, 1);
  a.SetX(1);
  EXPECT_EQ(a.GetX(), 1);
}

TEST(TPointGragh, can_get_y)
{
  TPointGragh a(0, 1);
  a.SetY(2);
  EXPECT_EQ(a.GetY(), 2);
}

TEST(TPointGragh, can_compare_equal_points)
{
  TPointGragh a(256, 256);
  TPointGragh b(256, 256);
  EXPECT_EQ(a == b, 1);
}

TEST(TPointGragh, can_compare_equal_points_with_unequality)
{
  TPointGragh a(256, 256);
  TPointGragh b(256, 256);
  EXPECT_EQ(a != b, 0);
}

TEST(TPointGragh, can_compare_non_equal_points)
{
  TPointGragh a(256, 256);
  TPointGragh b(256, 256.5);
  EXPECT_EQ(a == b, 0);
}

TEST(TPointGragh, can_compare_non_equal_points_with_unequality)
{
  TPointGragh a(256, 256);
  TPointGragh b(256, 256.5);
  EXPECT_EQ(a != b, 1);
}
