#ifndef __STACKLIST_H__
#define __STACKLIST_H__
#include <TExeption.h>
#include <TDatLink.h>
#include<iostream>

using namespace std;

template<class ValType>
class TListStack
{
protected:
  TDatLink<ValType>* firstLink; // указатель на первое звено списка
  int length;

public:
  TListStack();
  ~TListStack();
  int IsEmpty() const; 
  int GetLength();
  void Put(ValType Val); 
  ValType Get(); 
  void Print();
};

template<class ValType>
TListStack<ValType>::TListStack()
{
  firstLink = NULL;
  length = 0;
}

template<class ValType>
TListStack<ValType>::~TListStack()
{
  while (!IsEmpty())
  {
    TDatLink<ValType>* tmp = firstLink;
	firstLink = firstLink->GetNextLink();
    delete tmp;
  }
}

template<class ValType>
int TListStack<ValType>::IsEmpty() const
{
  return firstLink == 0;
}

template<class ValType>
int TListStack<ValType>::GetLength()
{
  return length;
}

template<class ValType>
void TListStack<ValType>::Put(ValType Val)
{
  TDatLink<ValType>* lTemp = new TDatLink<ValType>;
  lTemp->SetDatValue(Val);
  lTemp->SetNextLink(firstLink);
  firstLink = lTemp;
  length++;
}

template<class ValType>
ValType TListStack<ValType>::Get()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  TDatLink<ValType>* lTemp = new TDatLink<ValType>;
  ValType Val = firstLink->GetDatValue();
  firstLink = firstLink->GetNextLink();
  delete lTemp;
  length--;
  return Val;
}

template<class ValType>
void TListStack<ValType>::Print()
{
  TDatLink<ValType>* lTemp = firstLink;
  while (lTemp != NULL) {
    cout << " Взять из стека значение : " << lTemp->GetDatValue() << " " << endl;
	lTemp = lTemp->GetNextLink();
  }
}

#endif __STACKLIST_H__
