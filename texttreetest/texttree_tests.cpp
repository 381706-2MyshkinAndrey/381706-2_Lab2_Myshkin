#include <gtest.h>
#include <TText.h>


TEST(TText, can_create_text)
{
  ASSERT_NO_THROW(TText t);
}

TEST(TText, can_initalize_text)
{
  ASSERT_NO_THROW(TText t(" Test test text "));
}

TEST(TText, can_isert_link_down_text)
{
  TText txt;
  TTextLink* link = new TTextLink(" Test test text ");
  ASSERT_NO_THROW(txt.InsertNextLvl(link));
}

TEST(TText, can_insert_string_down)
{
  TText txt;
  ASSERT_NO_THROW(txt.InsertNextLvl(" Test test text "));
}

TEST(TText, can_go_down_link)
{
  TText txt;
  TTextLink* link = new TTextLink(" Eeeee boooy ");
  txt.InsertNextLvl(link);
  txt.GoNextLvlLink();
  EXPECT_EQ(txt.GetCurrent(), link);
}

TEST(TText, can_insert_link_next)
{
  TText txt;
  TTextLink* link = new TTextLink(" Eeeeeee Booooy ");
  TTextLink* nextlink = new TTextLink(" Test test text ");
  txt.InsertNextLvl(link);
  txt.GoNextLvlLink();
  ASSERT_NO_THROW(txt.InsertNextNB(nextlink));
}

TEST(TText, can_insert_string_next)
{
  TText txt;
  txt.InsertNextLvl(" Eeeeee Booooy ");
  txt.GoNextLvlLink();
  ASSERT_NO_THROW(txt.InsertNextNB(" Test test text "));
}

TEST(TText, can_go_next_link)
{
  TText txt;
  TTextLink* link = new TTextLink("Eeeeee Booooy ");
  TTextLink* nextlink = new TTextLink(" Test test text ");
  txt.InsertNextLvl(link);
  txt.GoNextLvlLink();
  txt.InsertNextNB(nextlink);
  txt.GoNextNBLink();
  EXPECT_EQ(txt.GetCurrent(), nextlink);
}


TEST(TText, can_delete_link_next)
{
  TText txt;
  TTextLink* link = new TTextLink(" Something else ");
  TTextLink* nextlink = new TTextLink(" Test test text ");
  txt.InsertNextLvl(link);
  txt.GoNextLvlLink();
  txt.InsertNextNB(nextlink);
  ASSERT_NO_THROW(txt.DelNextNB());
}

TEST(TText, can_delete_string_down)
{
  TText txt;
  txt.InsertNextLvl(" Test test text ");
  ASSERT_NO_THROW(txt.DelNextLvl());
}

TEST(TText, can_use_memory_cleaner)
{
  TTextLink* a;
  TText txt;
  txt.InsertNextLvl(" Eeeeee Boooyzz");
  for (int i = 0; i < 10; i++)
  {
    a = new TTextLink(1);
    delete a;
  }
  ASSERT_NO_THROW(a->MemCleaner(txt));
}
