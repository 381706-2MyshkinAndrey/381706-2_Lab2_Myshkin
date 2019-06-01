#ifndef __TPOINTGRAGH_H__
#define __TPOINTGRAGH_H__
#include <TExeption.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TPointGragh
{
protected:
  double x, y;
public:
  TPointGragh(double datX = 0, double datY = 0);
  TPointGragh(TPointGragh& graphP);
  virtual void Show();
  void SetX(double datX);
  void SetY(double datY);
  int operator== (const TPointGragh&);
  int operator!= (const TPointGragh&);
  double GetX();
  double GetY();
};
#endif __TPOINTGRAGH_H__