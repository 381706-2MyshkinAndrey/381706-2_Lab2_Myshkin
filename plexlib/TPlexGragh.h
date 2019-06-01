#ifndef __PLEXGRAGH_H__
#define __PLEXGRAGH_H__
#include <TExeption.h>
#include <TPointGragh.h>
#include <TLineGragh.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TPlexGragh : public TPointGragh
{
protected:
  TPointGragh * left;
  TPointGragh* right;
  virtual TPointGragh* Show(TPlexGragh* p);
public:
  TPlexGragh();
  TPlexGragh(TPlexGragh& cp);
  TPlexGragh(TPointGragh* l, TPointGragh* r);
  TPlexGragh& operator +=(TLineGragh &l);
  TPointGragh* GetLeft();
  TPointGragh* GetRight();
  void SetLeft(TPointGragh*);
  void SetRight(TPointGragh*);
  virtual void Show();
};
#endif __PLEXGRAGH_H__