#include <TLineGragh.h>

TLineGragh::TLineGragh(TPointGragh * pA, TPointGragh * pB)
{
  a = pA;
  b = pB;
}


TLineGragh::TLineGragh(TLineGragh & graphP)
{
  a = graphP.a;
  b = graphP.b;
}

void TLineGragh::Show()
{
  cout << "a : ";
  a->Show();
  cout << endl << "b : ";
  b->Show();
}

void TLineGragh::SetA(TPointGragh* p)
{
  a = p;
}

void TLineGragh::SetB(TPointGragh* p)
{
  b = p;
}

TPointGragh * TLineGragh::GetA()
{
  return a;
}

TPointGragh * TLineGragh::GetB()
{
  return b;
}
