#include "TPolinomial.h"

TPolinomial::TPolinomial() : TDatList<TMonomial>()
{
}

TPolinomial::TPolinomial(const TPolinomial & a) : TDatList<TMonomial>(a)
{
}

TPolinomial::TPolinomial(const TDatList<TMonomial>& a) : TDatList<TMonomial>(a)
{
}

TPolinomial TPolinomial::operator+(const TPolinomial & a)
{
  if (this->listCount != a.listCount)
    throw TExeption(DataErr);
  TDatLink<TMonomial>* tmp1 = this->pFirst;
  TDatLink<TMonomial>* tmp2 = a.pFirst;
  TPolinomial res;
  while (tmp1 && tmp2)
    if (tmp1->GetDatValue() == tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue() + tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1->GetDatValue() > tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinomial TPolinomial::operator-(const TPolinomial & a)
{
  if (this->listCount != a.listCount)
    throw TExeption(DataErr);
  TDatLink<TMonomial>* tmp1 = pFirst;
  TDatLink<TMonomial>* tmp2 = a.pFirst;
  TPolinomial res;
  while (tmp1 && tmp2)
    if (tmp1->GetDatValue() == tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue() - tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1->GetDatValue() > tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinomial TPolinomial::operator*(const TPolinomial & a)
{
	TPolinomial res;
  TDatLink<TMonomial>* tmp1 = pFirst;
  TDatLink<TMonomial>* tmp2 = a.pFirst;
  for (int i = 0; i < this->listCount - 1; i++)
  {
    for (int j = 0; j < a.listCount - 1; j++)
    {
      res.InsLast(tmp1->GetDatValue() * tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    tmp2 = tmp2->GetNextLink();
  }
  return res;
}

TPolinomial & TPolinomial::operator+=(const TMonomial & m)
{
  for (int i = 0; i < listCount; i++)
  {
    TMonomial  tmp = GetDatValue(i);
    if (tmp == m)
    {
      Del(i);
      InsTo(i, tmp + m);
      return *this;
    }
    else if (tmp < m)
    {
      InsTo(i, m);
      return *this;
    }
  }
  InsLast(m);
  return *this;
}

TMonomial & TPolinomial::operator[](int pos) const
{
  return GetDatValue(pos);
}

TPolinomial & TPolinomial::operator=(const TPolinomial & a)
{
  if (this != &a)
  {
    this->listCount = a.listCount;
    TDatLink<TMonomial>* pTemp = a.pFirst;
    pFirst = new TDatLink<TMonomial>(pTemp->GetDatValue(), NULL);
    TDatLink<TMonomial>* TmpLast = pFirst;
    TDatLink<TMonomial>* TmpCurr = NULL;
    for (int i = 1; i < a.listCount; i++)
    {
      pTemp = pTemp->GetNextLink();
      TmpCurr = new TDatLink<TMonomial>(pTemp->GetDatValue(), NULL);
      TmpLast->SetNextLink(TmpCurr);
      TmpLast = TmpCurr;
    }
    this->pLast = TmpCurr;
  }
  return *this;
}

ostream & operator<<(ostream & os, TPolinomial & a)
{
  TDatLink<TMonomial>* tmp = a.pFirst;
  for (int i = 0; i < a.listCount - 1; i++)
  {
    os << a.GetDatValue(i) << '+';
    tmp = tmp->GetNextLink();
  }
  os << a.GetDatValue(a.listCount - 1) << endl;
  return os;
}
