#include "TPointGragh.h"

TPointGragh::TPointGragh(double datX, double datY)
{
  x = datX;
  y = datY;
}

TPointGragh::TPointGragh(TPointGragh & graphP)
{
  x = graphP.x;
  y = graphP.y;
}

void TPointGragh::Show()
{
  cout << "x = " << x;
  cout << " y = " << y;
}

void TPointGragh::SetX(double datX)
{
  x = datX;
}

void TPointGragh::SetY(double datY)
{
  y = datY;
}

int TPointGragh::operator==(const TPointGragh &p)
{
  if (x == p.x && y == p.y)
    return 1;
  return 0;
}

int TPointGragh::operator!=(const TPointGragh &p)
{
  return !(*this == p);
}

double TPointGragh::GetX()
{
  return x;
}

double TPointGragh::GetY()
{
  return y;
}