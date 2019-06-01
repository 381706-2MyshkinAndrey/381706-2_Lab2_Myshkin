#include "TText.h"

TText::TText(char * st)
{
  TTextLink::InitMemory(100);
  pFirst = new TTextLink(0);
  pCurrent = pFirst;
  if (st != NULL)
  {
    TTextLink* buff = new TTextLink(1); 
    pCurrent = buff;
    pFirst->SetNextLvl(buff);
    buff->SetNextLvl(new TTextLink(st));
  }
}

void TText::GoNextNBLink()
{
  pCurrent = pCurrent->GetNextNB();
}

void TText::GoNextLvlLink()
{
  pCurrent = pCurrent->GetNextLvl();
}

TTextLink * TText::GetCurrent()
{
  return pCurrent;
}

int TText::Reset()
{
  while (!stack.IsEmpty())
	  stack.Get();
  pCurrent = pFirst;
  stack.Put(pCurrent);
  if (pCurrent->pNextNB != NULL)
	  stack.Put(pCurrent->pNextNB);
  if (pCurrent->pNextLvl != NULL)
	  stack.Put(pCurrent->pNextLvl);
  return IsEnded();
}

int TText::GoNextNB()
{
  if (!IsEnded())
  {
    pCurrent = stack.Get();
    if (pCurrent != pFirst)
    {
      if (pCurrent->pNextNB != NULL)
		  stack.Put(pCurrent->pNextNB);
      if (pCurrent->pNextLvl != NULL)
		  stack.Put(pCurrent->pNextLvl);
    }
  }
  return IsEnded();
}

int TText::IsEnded()
{
  return !stack.GetLength();
}

TTextLink * TText::GetLine()
{
  return pCurrent;
}

void TText::Print(TTextLink *pLink)
{
  if (pLink != NULL)
  {
    std::cout << *pLink;
    Print(pLink->GetNextLvl());
    if (pLink->pNextNB != NULL)
    {
      switch (pLink->level)
      {
      case(1):
        std::cout << '\n';
        break;
      case(2):
        std::cout << ' ';
        break;
      }
      Print(pLink->GetNextNB());
    }
  }
}

void TText::Print()
{
  Print(pFirst);
}

void TText::InsertNextNB(char s)
{
  if (pCurrent->level != 3)
    return;
  TTextLink* res = new TTextLink(s);
  InsertNextNB(res);
}

void TText::InsertNextNB(char * s)
{
  TTextLink* res = new TTextLink(s);
  if (pCurrent->level == 2)
  {
    res->level = 2;
  }
  InsertNextNB(res);
}

void TText::InsertNextNB(TTextLink* s)
{
  if (pCurrent == NULL)
    throw TExeption(DataErr);
  TTextLink * pN = pCurrent->GetNextNB();
  pCurrent->SetNextNB(s);
  s->SetNextNB(pN);
}

void TText::InsertNextLvl(char * s)
{
  if(pCurrent->level < 2)
  {
    TTextLink* res = new TTextLink(s);
    if (pCurrent->level == 2)
    {
      res->level = 2;
    }
    InsertNextLvl(res);
  }
}

void TText::InsertNextLvl(TTextLink * s)
{
  if (pCurrent == NULL)
    throw TExeption(DataErr);
  TTextLink * pN = pCurrent->GetNextLvl();
  if (pN == NULL)
  {
    pCurrent->pNextLvl = s;
  }
  else
  {
    while (pN->pNextNB != NULL)
    {
      pN = pN->pNextNB;
    }
    pN->pNextNB = s;
  }
}

void TText::DelNextNB()
{
  if(pCurrent == NULL)
    throw TExeption(DataErr);
  TTextLink * pN = pCurrent->GetNextNB();
  if (pN != NULL)
  {
    pCurrent->SetNextNB(pN->GetNextNB());
    delete pN;
  }
}

void TText::DelNextLvl()
{
  if (pCurrent == NULL)
    throw TExeption(DataErr);
  TTextLink * pD = pCurrent->GetNextLvl();
  if (pD != NULL)
  {
    pCurrent->SetNextLvl(pD->GetNextNB());
    delete pD;
  }
}

