#ifndef __DATLINK_H__
#define __DATLINK_H__
#include <iostream>

template<class ValType>
class TDatLink {
protected:
  ValType val; // значение
  TDatLink* pNext; // указатель на следующее звено

public:
  TDatLink(ValType Val = 0, TDatLink* next = NULL);
  void SetDatValue(ValType Val);
  ValType& GetDatValue();
  void SetNextLink(TDatLink* pLink);
  TDatLink* GetNextLink();
};

template<class ValType>
TDatLink<ValType>::TDatLink(ValType Val, TDatLink* next)
{
  val = Val;
  pNext = next;
}

template<class ValType>
void TDatLink<ValType>::SetDatValue(ValType Val)
{
  val = Val;
}

template<class ValType>
ValType& TDatLink<ValType>::GetDatValue() {  return val;  }

template<class ValType>
void TDatLink<ValType>::SetNextLink(TDatLink* pLink)
{
  pNext = pLink;
}

template<class ValType>
TDatLink<ValType> * TDatLink<ValType>::GetNextLink(){  return pNext;  }

#endif __DATLINK_H__