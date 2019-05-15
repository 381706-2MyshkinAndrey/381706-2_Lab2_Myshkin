#include <gtest.h>
#include <TPolinomial.h>
#include <iostream>


TEST(TPolinomial, can_create_polinomial)
{
	ASSERT_NO_THROW(TPolinomial p());
}

TEST(TPolinomial, throw_when_add_different_size)
{
  TPolinomial p1, p2, p;
  int ms1[] = { 1, 2, 3 };
  p1 += TMonomial(5, 3, ms1);
  ASSERT_ANY_THROW(p = p1 + p2);
}

TEST(TPolinomial, throw_when_sub_different_size)
{
  TPolinomial p1, p2, p;
  int ms1[] = { 1, 2, 3 };
  p1 += TMonomial(5, 3, ms1);
  ASSERT_ANY_THROW(p = p1 - p2);
}

TEST(TPolinomial, can_add_polinomial)
{
  TPolinomial p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonomial(i + 5, 3, ms1);
    p2 += TMonomial(i + 6, 3, ms2);
  }
  p3 = p1 + p2;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 11);
}

TEST(TPolinomial, can_sub_polinomial)
{
  TPolinomial p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonomial(i + 5, 3, ms1);
    p2 += TMonomial(i + 6, 3, ms2);
  }
  p3 = p2 - p1;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 1);
}

TEST(TPolinomial, can_mult_polinomial)
{
  TPolinomial p1, p2, p3;
  for (int i = 0; i < 2; i++)
  {
    int ms1[] = { i + 1, i + 2, i + 3 };
    int ms2[] = { i + 1, i + 2, i + 3 };
    p1 += TMonomial(i + 5, 3, ms1);
    p2 += TMonomial(i + 6, 3, ms2);
  }
  p3 = p2 * p1;
  EXPECT_EQ(p3.GetDatValue(0).GetCoeff(), 30);
}


