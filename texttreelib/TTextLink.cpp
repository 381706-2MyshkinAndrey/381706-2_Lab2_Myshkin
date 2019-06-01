#include "TTextLink.h"
#include "TText.h"

TTextMem TTextLink::memory;

TTextLink::TTextLink(char * st)
{
  level = 1;
  pNextNB = NULL;
  pNextLvl = NULL;
  letter = 0;
  if (st != NULL)
  {
    int l = strlen(st);
	pNextLvl = new TTextLink(2);
    TTextLink* pWord = pNextLvl;
    pWord->pNextLvl = new TTextLink(st[0]);
    TTextLink*buff = pWord->pNextLvl;
    for (int i = 1; i < l; i++)
    {
      if (st[i] == ' ')
      {
        pWord->pNextNB = new TTextLink(2);
        pWord = pWord->pNextNB;
        i++;
        pWord->pNextLvl = new TTextLink(st[i]);
        buff = pWord->pNextLvl;
      }
      else
      {
        buff->pNextNB = new TTextLink(st[i]);
        buff = buff->pNextNB;
      }
    }
  }
}

TTextLink::TTextLink(int l)
{
  pNextLvl = NULL;
  pNextNB = NULL;
  level = l;
  letter = 0;
}

TTextLink::TTextLink(char _letter)
{
  level = 3;
  letter = _letter;
  pNextNB = NULL;
  pNextLvl = NULL;
}

TTextLink::TTextLink(const TTextLink & A)
{
  level = A.level;
  letter = A.letter;
  pNextLvl = A.pNextLvl;
  pNextNB = A.pNextNB;
}

TTextLink::~TTextLink()
{
}


void TTextLink::InitMemory(int size)
{
  memory.pFirst = (TTextLink*) new char[sizeof(TTextLink) * size];
  TTextLink::memory.pFirstFree = TTextLink::memory.pFirst;
  TTextLink::memory.pLast = TTextLink::memory.pFirst + size - 1;
  TTextLink* buff = memory.pFirst;
  for (int i = 0; i < size - 1; i++, buff++)
  {
    buff->pNextNB = buff + 1;
    buff->level = 0;
  }
  buff->pNextNB = NULL;
}

void TTextLink::MemCleaner(TText &txt)
{
  for (txt.Reset(); !txt.IsEnded(); txt.GoNextNB())
    txt.GetLine()->level -=4;
  TTextLink* pLink = memory.pFirstFree;
  for (; pLink != NULL; pLink = pLink->pNextNB)
    pLink->level -= 4;
  pLink = memory.pFirst;
  for (; pLink <= memory.pLast; pLink++)
    if (pLink->level < 0)
      pLink->level += 4;
    else
      delete pLink;
}

void * TTextLink::operator new(const size_t size)
{
  if (memory.pFirstFree == NULL)
    throw TExeption(DataNoMem);
  TTextLink* res = memory.pFirstFree;
  memory.pFirstFree = res->pNextNB;
  return res;
}

void TTextLink::operator delete(void * pM)
{
  TTextLink* buff = memory.pFirstFree;
  memory.pFirstFree = (TTextLink*)pM;
  memory.pFirstFree->pNextNB = buff;
}

TTextLink & TTextLink::operator=(const TTextLink & A)
{
  if (level != A.level)
    throw TExeption(DataErr);

  if (&A != this)
  {
	letter = A.letter;
	pNextLvl = A.pNextLvl;
	pNextNB = A.pNextNB;
  }

  return *this;
}

TTextLink & TTextLink::operator+=(TTextLink & A)
{
  TTextLink* copy = A.Clone();
  TTextLink* i = this;
  while (i->level != copy->level)
    i = i->pNextLvl;
  while (i->pNextNB != 0)
    i = i->pNextNB;
  i->pNextNB = copy;
  return *this;
}

TTextLink & TTextLink::operator+=(char c)
{
  TTextLink symb(c);
  return (*this += symb);
}

TTextLink & TTextLink::operator+=(char * c)
{
  TTextLink symb(c);
  return (*this += symb);
}

char * TTextLink::ToStr()
{
  TListStack <TTextLink*> t;
  t.Put(this);
  int l = 0;
  while (!t.IsEmpty())
  {
    TTextLink* i = t.Get(); 
    if (i->level == 3)
      l++;
    if (i->pNextNB != 0)
      t.Put(i->pNextNB);
    if (i->pNextLvl != 0)
      t.Put(i->pNextLvl);
  }
  t.Put(this);
  char *res = new char[l + 1];
  int j = 0;

  while (!t.IsEmpty())
  {
    TTextLink* i = t.Get();
    if (i->level == 3)
    {
      res[j] = i->letter;
      j++;
    }
    if (i->pNextNB != 0)
      t.Put(i->pNextNB);
    if (i->pNextLvl != 0)
      t.Put(i->pNextLvl);
  }
  res[l] = 0;
  return res;
}

void TTextLink::SetNextLvl(TTextLink * p)
{
	pNextLvl = p;
}

void TTextLink::SetNextNB(TTextLink * p)
{
	pNextNB = p;
}

void TTextLink::SetLetter(char _letter)
{
	letter = _letter;
}

void TTextLink::SetLevel(int _level)
{
  level = _level;
}

TTextLink * TTextLink::GetNextLvl()
{
  return pNextLvl;
}

TTextLink * TTextLink::GetNextNB()
{
  return pNextNB;
}

char TTextLink::GetLetter()
{
  return letter;
}

int TTextLink::GetLevel()
{
  return level;
}

TTextLink * TTextLink::Clone()
{
  TTextLink* resTree = new TTextLink(*this);
  TListStack<TTextLink*> st;
  TListStack<TTextLink*> copy;
  st.Put(this);
  copy.Put(resTree);
  while (!st.IsEmpty())
  {
    TTextLink* t1 = st.Get();
    TTextLink* c1 = copy.Get();
    if (t1->pNextLvl != 0)
    {
      c1->pNextLvl = new TTextLink(*t1->pNextLvl);
      copy.Put(c1->pNextLvl);
      st.Put(t1->pNextLvl);
    }
    if (t1->pNextNB != 0)
    {
      c1->pNextNB = new TTextLink(*t1->pNextNB);
      copy.Put(c1->pNextNB);
      st.Put(t1->pNextNB);
    }
  }
  return resTree;
}

ostream & operator<<(ostream & o, const TTextLink & A)
{
  if (A.letter != 0)
    o << A.letter;
  return o;
}
