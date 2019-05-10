#include <gtest.h>
#include <TListStack.h>


TEST(TListStack, can_create_list)
{
  ASSERT_NO_THROW(TListStack<int> l);
}

TEST(TListStack, empty_list_is_empty)
{
  TListStack<int> l;
   EXPECT_EQ(1, l.IsEmpty());
}


TEST(TListStack, can_put_value)
{
  TListStack<int> MyListStack;
  MyListStack.Put(3);

  EXPECT_EQ(3, MyListStack.Get());
}

TEST(TListStack, can_put_multy_value)
{
  TListStack<int> MyListStack;
  MyListStack.Put(1);
  MyListStack.Put(2);
  MyListStack.Put(3);

  EXPECT_EQ(3, MyListStack.Get());
}


TEST(TListStack, can_get_leight)
{
  TListStack<int> MyListStack;
  MyListStack.Put(1);
  MyListStack.Put(2);
  MyListStack.Put(3);

  EXPECT_EQ(3, MyListStack.GetLength());
}
