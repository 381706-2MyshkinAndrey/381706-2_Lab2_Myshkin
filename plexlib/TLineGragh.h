#ifndef __LINEGRAGH_H__
#define __LINEGRAGH_H__
#include <TExeption.h>
#include <TPointGragh.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TLineGragh
{
protected:
  TPointGragh * a;
  TPointGragh* b;
public:
  TLineGragh(TPointGragh * pA = NULL, TPointGragh * pB = NULL);
  TLineGragh(TLineGragh& graphP);
  virtual void Show();
  void SetA(TPointGragh*);
  void SetB(TPointGragh*);
  TPointGragh* GetA();
  TPointGragh* GetB();
};
#endif __LINEGRAGH_H__