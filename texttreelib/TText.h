#ifndef _TTEXT_H
#define _TTEXT_H

#include "TTextLink.h"

class TText
{
protected:
  TTextLink* pFirst;
  TTextLink* pCurrent;
  TListStack<TTextLink*> stack;
public:
  TText(char* st = 0);
  void GoNextNBLink();
  void GoNextLvlLink();
  TTextLink* GetCurrent();
  int Reset();	
  int GoNextNB();
  int IsEnded();
  TTextLink* GetLine();
  void InsertNextNB(char st);
  void InsertNextNB(char* st);
  void InsertNextNB(TTextLink* st);
  void InsertNextLvl(char* st);
  void InsertNextLvl(TTextLink* st);
  void DelNextNB();
  void DelNextLvl();
  void Print(TTextLink *pLink);
  void Print();
};
#endif // _TTEXT_H