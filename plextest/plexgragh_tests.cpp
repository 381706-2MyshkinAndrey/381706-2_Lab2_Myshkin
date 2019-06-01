#include <gtest.h>
#include <TPlexGragh.h>


TEST(TPlexGragh, can_create_plex)
{
  ASSERT_NO_THROW(TPlexGragh pl);
}

TEST(TPlexGragh, can_set_left)
{
	TPlexGragh pl;
	TPointGragh a(0, 0);
  ASSERT_NO_THROW(pl.SetLeft(&a));
}

TEST(TChartPlex, can_set_right)
{
	TPlexGragh pl;
	TPointGragh a(0, 0);
  ASSERT_NO_THROW(pl.SetRight(&a));
}

TEST(TPlexGragh, can_get_left)
{
	TPlexGragh pl;
	TPointGragh a(0, 0);
  pl.SetLeft(&a);
  EXPECT_EQ(*pl.GetLeft() == a, 1);
}

TEST(TPlexGragh, can_get_right)
{
	TPlexGragh pl;
	TPointGragh a(0, 0);
  pl.SetRight(&a);
  EXPECT_EQ(*pl.GetRight() == a, 1);
}

TEST(TChartPlex, can_add_line)
{
	TPlexGragh pl;
	TPointGragh a(0, 0), b(1, 1), c(2, 1);
	TLineGragh l1(&a, &b), l2(&c, &b);
  ASSERT_NO_THROW(pl += l1;);
}

TEST(TPlexGragh, can_add_line_right_to_right)
{
	TPlexGragh pl;
	TPointGragh a(0, 0), b(1, 1), c(2, 1);
	TLineGragh l1(&a, &b), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TPlexGragh, can_add_line_right_to_left)
{
	TPlexGragh pl;
	TPointGragh a(0, 0), b(1, 1), c(2, 1);
	TLineGragh l1(&a, &b), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TPlexGragh, can_add_line_left_to_right)
{
	TPlexGragh pl;
	TPointGragh a(0, 0), b(1, 1), c(2, 1);
	TLineGragh l1(&b, &a), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetLeft())->GetLeft())) == c, 1);
}

TEST(TPlexGragh, can_add_line_left_to_left)
{
	TPlexGragh pl;
	TPointGragh a(0, 0), b(1, 1), c(2, 1);
	TLineGragh l1(&b, &a), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TPlexGragh*>(pl.GetLeft())->GetLeft())) == c, 1);
}