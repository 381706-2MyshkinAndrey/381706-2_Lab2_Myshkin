#ifndef __POLINOMIAL_H__
#define __POLINOMIAL_H__
#include "TMonomial.h"
#include "TDatList.h"

class TPolinomial : public TDatList<TMonomial>
{
public:
  TPolinomial();
  TPolinomial(const TPolinomial &a); // конструктор копирования
  TPolinomial(const TDatList<TMonomial> &a); // конструктор приведения типа
  TPolinomial operator+(const TPolinomial &a); // сложение полиномов
  TPolinomial operator-(const TPolinomial &a); // вычитание полиномов
  TPolinomial operator*(const TPolinomial &a); // умножение полиномов
  TPolinomial & operator+=(const TMonomial &m); // добавить моном
  TMonomial & operator[](int) const;
  TPolinomial & operator=(const TPolinomial &a); // присваивание
  friend ostream& operator<<(ostream &os, TPolinomial &a);
};
#endif __POLINOMIAL_H__