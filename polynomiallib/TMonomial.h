#ifndef __TMONOMIAL_H__
#define __TMONOMIAL_H__
#include <iostream>
#include "TExeption.h"

using namespace std;

class TMonomial 
{
protected:
  int coeff; // коэффициент монома
  int count; // число членов монома
  int* arDegrees; // массив степеней

public:
  TMonomial(int cval = 1, int ival = 0, int* degrarr = NULL);
  TMonomial(const TMonomial& monom);
  ~TMonomial();

  void SetCoeff(int cval);
  int GetCoeff();
  int GetPower(int pos);
  void SetPower(int val, int pos);
  void SetCount(int countval);
  int GetCount();

  TMonomial& operator = (const TMonomial& monom);
  TMonomial operator + (const TMonomial& monom);
  TMonomial operator - (const TMonomial& monom);
  TMonomial operator * (const TMonomial& monom);
  bool operator > (const TMonomial& monom);
  bool operator < (const TMonomial& monom);
  bool operator == (const TMonomial& monom);
  friend ostream& operator<<(ostream &os, TMonomial &tm);
  friend class TPolinomial;
};
#endif __TMONOMIAL_H__
