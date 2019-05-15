#include "TMonomial.h"

TMonomial::TMonomial(int coeffval, int countval, int * degrarr)
{
  if (countval < 0)
    throw TExeption(DataErr);
  count = countval;
  coeff = coeffval;
  if(count)
	arDegrees = new  int[count];
  if (degrarr)
    for (int i = 0; i < count; i++)
		arDegrees[i] = degrarr[i];
  else
    for (int i = 0; i < count; i++)
		arDegrees[i] = 0;
}

TMonomial::TMonomial(const TMonomial & monom)
{
  count = monom.count;
  coeff = monom.coeff;
  arDegrees = new int[count];
  for (int i = 0; i < count; i++)
    arDegrees[i] = monom.arDegrees[i];
}

TMonomial::~TMonomial()
{
  if (arDegrees)
    delete[]arDegrees;
}


 void TMonomial::SetCoeff(int cval)
{
  coeff = cval;
}

 int TMonomial::GetCoeff()
{
  return coeff;
}

int TMonomial::GetPower(int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  return arDegrees[pos];
}

void TMonomial::SetPower(int val, int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  arDegrees[pos] = val;
}

void TMonomial::SetCount(int countval)
{
  if (countval <= 0)
    throw TExeption(DataErr);
  unsigned* tmp = new unsigned int[count];
  for (int i = 0; i < count; i++)
    tmp[i] = arDegrees[i];
  delete[] arDegrees;
  arDegrees = new int[countval];
  for (int i = 0; i < (count > countval ? countval : count); i++)
	  arDegrees[i] = tmp[i];
  delete[] tmp;
}


 int TMonomial::GetCount()
{
  return count;
}


 TMonomial & TMonomial::operator=(const TMonomial & monom)
{
  if (this != &monom)
  {
    if (count != monom.count && count)
    {
      delete[] arDegrees;
	  arDegrees = new int[count];
    }
    count = monom.count;
    coeff = monom.coeff;
	arDegrees = new int[count];
    for (int i = 0; i < count; i++)
		arDegrees[i] = monom.arDegrees[i];
  }
  return *this;
}

 TMonomial TMonomial::operator+(const TMonomial & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonomial tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff + monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}


 TMonomial TMonomial::operator-(const TMonomial & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonomial tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff - monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}

 TMonomial TMonomial::operator*(const TMonomial & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonomial tmp(monom);
  tmp.coeff = coeff * monom.coeff;
  for (int i = 0; i < count; i++)
    tmp.arDegrees[i] = arDegrees[i] + monom.arDegrees[i];
  return tmp;
}

bool TMonomial::operator>(const TMonomial & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (arDegrees[i] > monom.arDegrees[i])
      return true;
    else if (arDegrees[i] < monom.arDegrees[i])
      return false;
  return false;
}

bool TMonomial::operator<(const TMonomial & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (arDegrees[i] > monom.arDegrees[i])
      return true;
    else if (arDegrees[i] < monom.arDegrees[i])
      return false;
  return false;
}


bool TMonomial::operator==(const TMonomial&  monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (arDegrees[i] != monom.arDegrees[i])
      return false;
  return true;
}

ostream & operator<<(ostream & os, TMonomial & tm)
{
  os << tm.coeff << '*';
  for (int i = 0; i < tm.count -1; i++)
    os << "x" << i << "^" << tm.arDegrees[i] << '*';
  os << "x" << tm.count - 1 << "^" << tm.arDegrees[tm.count - 1];
  return os;
}
