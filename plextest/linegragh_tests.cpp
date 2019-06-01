#include <gtest.h>
#include <TLineGragh.h>

TEST(TLineGragh, can_create_line)
{
  ASSERT_NO_THROW(TLineGragh l);
}

TEST(TLineGragh, can_set_a)
{
  TLineGragh l;
  TPointGragh a(0, 1);
  ASSERT_NO_THROW(l.SetA(&a));
}

TEST(TLineGragh, can_set_b)
{
  TLineGragh l;
  TPointGragh a(0, 1);
  ASSERT_NO_THROW(l.SetB(&a));
}

TEST(TLineGragh, can_get_a)
{
  TLineGragh l;
  TPointGragh a(0, 1);
  l.SetA(&a);
  EXPECT_EQ(*l.GetA() == a, 1);
}

TEST(TChartLine, can_get_b)
{
 
  TLineGragh l;
  TPointGragh b(0, 1);
  l.SetB(&b);
  EXPECT_EQ(*l.GetB() == b, 1);
}