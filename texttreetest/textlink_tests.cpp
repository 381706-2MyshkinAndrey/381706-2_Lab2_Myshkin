#include <gtest.h>
#include <TTextLink.h>


TEST(TTextLink, can_init_memory)
{
  TTextLink* test;
  ASSERT_NO_THROW(test->InitMemory(100));
}

TEST(TTextLink, can_use_memory)
{
  TTextLink* test;
  test->InitMemory(100);
  ASSERT_NO_THROW(test = new TTextLink(1));
}

TEST(TTextLink, can_delete_memory)
{
  TTextLink* test;
  test->InitMemory(100);
  test = new TTextLink(1);
  ASSERT_NO_THROW(delete test);
}

TEST(TTextLink, can_use_assigment)
{
  TTextLink test1(3),test2(3);
  test1.SetLetter('M');
  test2.SetLetter('W');
  test1 = test2;
  EXPECT_EQ(test1.GetLetter(), 'W');
}


TEST(TTextLink, can_clone_assigment)
{
  TTextLink test1(3), test2(2), *c;
  test1.SetLetter('M');
  test2.SetLetter('W');
  test2.SetNextLvl(&test1);
  c = test2.Clone();
  EXPECT_NE(c->GetNextLvl(), test2.GetNextLvl());
}

TEST(TTextLink, can_convert_to_string)
{
  TTextLink test1("Mark");
  int flag = 1;
  char* res = test1.ToStr();
  char* exp = "Mark";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}

TEST(TTextLink, can_add_letter)
{
  TTextLink test1("DON");
  test1 += 'T';
  int flag = 1;
  char* res = test1.ToStr();
  char* exp = "DONT";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}

TEST(TTextLink, can_add_sentense)
{
  TTextLink test1("to");
  test1 += " be";
  int flag = 1;
  char* res = test1.ToStr();
  char* exp = "to be";
  for (int i = 0; i < strlen(exp); i++)
  {
    if (res[i] != exp[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}