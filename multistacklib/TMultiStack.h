#ifndef __MULTISTACK_H__
#define __MULTISTACK_H__
#include "MStack.h"
#include <TExeption.h>

template <class ValType>
class TMultiStack
{
protected:
  MStack <ValType> ** pStack; // стеки - память выделяется из StackMem
  int MemSize; // всего выделено памяти
  ValType** StackInd;
  int RelocationCount;
  int CurrentCount; // число элементов в мультистеке в данный момент
  int *StackTops;
  int StackCount; // число стеков
  ValType* StackMem; // память под стек
protected: // поля и методы для перепаковки
  ValType * * pStackMem; // базовые адреса для памяти стеков
  void StackRelocation(int nst); // перепаковка памяти
  int GetFreeMemSize(); // оценка объема свободной памяти
public:
  TMultiStack(int Size = 50, int Count = 5);
  TMultiStack(TMultiStack &ms);
  ~TMultiStack();
  int IsEmpty(int ns) const; // контроль пустоты СД
  int IsFull(int ns) const; // контроль переполнения СД
  int operator==(const TMultiStack &ms); // сравнение
  TMultiStack & operator= (const TMultiStack &ms); // присванивание
  void Put(int ns, const ValType &Val); // положить в стек 
  ValType Get(int ns); // взять из стека с удалением
  void Print();
  int GetRelocationCount() { return RelocationCount; }
};

template<class ValType>
void TMultiStack<ValType>::StackRelocation(int nst)
{
  int l;
  StackTops[nst] += 1;
  int temp = GetFreeMemSize() - 1;
  if (temp > -1)
  {
    pStackMem[0] = &StackMem[0];
    for (int i = 1; i < StackCount; i++)
      pStackMem[i] = pStackMem[i - 1] + StackTops[i - 1] + temp / StackCount;
  }
  for (int i = 0; i < StackCount; i++)
    if (pStackMem[i] < StackInd[i])
    {
      for (int k = 0; k < StackTops[i]; k++)
        pStackMem[i][k] = StackInd[i][k];
      if(i != StackCount - 1)
        pStack[i]->SetMem(pStackMem[i], pStackMem[i + 1] - pStackMem[i]);
      StackInd[i] = pStackMem[i];
    }
    else if (pStackMem[i] > StackInd[i])
    {
      for (l = i; pStackMem[l + 1] > StackInd[l + 1]; l++)
        if (l == StackCount - 1)
        {
          break;
        }
      for (int k = l; k >= i; k--)
      {
        for (int j = (StackTops[k] - 1); j >= 0; j--)
          pStackMem[k][j] = StackInd[k][j];
        if (k != StackCount - 1)
         pStack[k]->SetMem(pStackMem[k], pStackMem[k + 1] - pStackMem[k]);
        StackInd[k] = pStackMem[k];
      }
    }
    else
    {
      if (i != StackCount - 1)
        pStack[i]->SetMem(pStackMem[i], pStackMem[i + 1] - pStackMem[i]);
    }
  pStack[StackCount - 1]->SetMem(pStackMem[StackCount - 1], MemSize - (pStackMem[StackCount - 1] - pStackMem[0]));
  StackTops[nst] -= 1;
  RelocationCount++;
}

template <class ValType>
void TMultiStack<ValType>::Print()
{
  for (int i = 0; i<StackCount; i++)
  {
    pStack[i]->Print();
  }
}

template<class ValType>
int  TMultiStack<ValType>::GetFreeMemSize()
{
  return MemSize - CurrentCount;
}

template<class ValType>
TMultiStack<ValType>::TMultiStack(int Size, int count)
{
  if ((Size <= 0) || (count <= 0))
    throw 1;
  MemSize = Size;
  RelocationCount = 0;
  CurrentCount = 0;
  StackCount = count;
  StackTops = new int[StackCount];
  for (int i = 0; i < StackCount; i++)
    StackTops[i] = 0;
  StackInd = new ValType*[StackCount];
  pStackMem = new ValType*[StackCount];
  pStack = new MStack<ValType>*[StackCount];
  StackMem = new ValType[MemSize];
  int TmpSize = MemSize / StackCount;
  StackInd[0] = StackMem;
  pStack[0] = new MStack<ValType>(StackInd[0], TmpSize);
  for (int i = 1; i < StackCount - 1; i++)
  {
    StackInd[i] = StackInd[i - 1] + TmpSize;
    pStack[i] = new MStack<ValType>(StackInd[i], TmpSize);
  }
  StackInd[StackCount - 1] = StackInd[StackCount - 2] + TmpSize;
  pStack[StackCount - 1] = new MStack<ValType>(StackInd[StackCount - 1], TmpSize + MemSize % StackCount);
}

template<class ValType>
TMultiStack<ValType>::TMultiStack(TMultiStack & ms)
{
  MemSize = ms.MemSize;
  CurrentCount = ms.CurrentCount;
  RelocationCount = ms.RelocationCount;
  StackCount = ms.StackCount;
  StackTops = new int[StackCount];
  for (int i = 0; i < StackCount; i++)
    StackTops[i] = ms.StackTops[i];
  StackInd = new ValType*[StackCount];
  pStackMem = new ValType*[StackCount];
  pStack = new MStack<ValType>*[StackCount];
  StackMem = new ValType[MemSize];
  int TmpSize = MemSize / StackCount;
  StackInd[0] = StackMem;
  pStack[0] = new MStack<ValType>(StackInd[0], TmpSize);
  for (int i = 1; i < StackCount - 1; i++)
  {
    StackInd[i] = StackInd[i - 1] + TmpSize;
    pStack[i] = new MStack<ValType>(StackInd[i], TmpSize);
  }
  StackInd[StackCount - 1] = StackInd[StackCount - 2] + TmpSize;
  pStack[StackCount - 1] = new MStack<ValType>(StackInd[StackCount - 1], TmpSize + MemSize % StackCount);
  StackMem = new ValType[MemSize];
  for (int i = 0; i < MemSize; i++)
    pStack[i] = ms.pStack[i];
}

template<class ValType>
TMultiStack<ValType>::~TMultiStack<ValType>()
{
  delete[]StackMem;
  for (int i = 0; i < StackCount; i++)
    delete pStack[i];
  delete[]pStack;
  delete[]pStackMem;
  delete[]StackTops;
  delete[]StackInd;
}

template<class ValType>
 int TMultiStack<ValType>::IsEmpty(int ns) const
{
  return pStack[ns]->IsEmpty();
}

template<class ValType>
 int TMultiStack<ValType>::IsFull(int ns) const
{
  return pStack[ns]->IsFull();
}

template<class ValType>
int TMultiStack<ValType>::operator==(const TMultiStack & ms)
{
  if (MemSize != ms.MemSize)
    return 0;
  if (StackCount != ms.StackCount)
    return 0;
  for (int i = 0; i < CurrentCount; i++)
    if (StackMem[i] != ms.StackMem[i])
      return 0;
  return 1;
}

template<class ValType>
TMultiStack<ValType> & TMultiStack<ValType>::operator=(const TMultiStack & ms)
{
  if (&ms != this)
  {
    MemSize = ms.MemSize;
    RelocationCount = ms.RelocationCount;
    StackCount = ms.StackCount;
    CurrentCount = ms.CurrentCount;
    StackTops = new int[StackCount];
    for (int i = 0; i < StackCount; i++)
      StackTops[i] = ms.StackTops[i];
    StackInd = new ValType*[StackCount];
    pStackMem = new ValType*[StackCount];
    pStack = new MStack<ValType>*[StackCount];
    StackMem = new ValType[MemSize];
    int TmpSize = MemSize / StackCount;
    StackInd[0] = StackMem;
    pStack[0] = new MStack<ValType>(StackInd[0], TmpSize);
    for (int i = 1; i < StackCount - 1; i++)
    {
      StackInd[i] = StackInd[i - 1] + TmpSize;
      pStack[i] = new MStack<ValType>(StackInd[i], TmpSize);
    }
    StackInd[StackCount - 1] = StackInd[StackCount - 2] + TmpSize;
    pStack[StackCount - 1] = new MStack<ValType>(StackInd[StackCount - 1], TmpSize + MemSize % StackCount);
    for (int i = 0; i < MemSize; i++)
      StackMem[i] = ms.StackMem[i];
  }
  return *this;
}

template<class ValType>
void TMultiStack<ValType>::Put(int ns, const ValType & Val)
{
  if (GetFreeMemSize() == 0)
    throw TExeption(DataNoMem);
  if (pStack[ns]->IsFull())
    StackRelocation(ns);
  pStack[ns]->Put(Val);
  StackTops[ns]++;
  CurrentCount++;
}

template<class ValType>
 ValType TMultiStack<ValType>::Get(int ns)
{
  StackTops[ns]--;
  CurrentCount--;
  return pStack[ns]->Get();
}
#endif __MULTISTACK_H__

