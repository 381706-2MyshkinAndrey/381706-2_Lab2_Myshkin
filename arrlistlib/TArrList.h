#ifndef __ARRLIST_H__
#define __ARRLIST_H__
#include <TExeption.h>
#include <iostream>

template<class ValType>
class TArrList
{
protected:
  ValType * mem; // память под элементы списка
  int* indexNext; // индексы следующих элементов
  int size; // максимальный размер списка
  int count; // число элементов в списке
  int firstInd; // индекс начала списка
  int firstFreeInd; // индекс первого пуcтого элемента в массиве

private:
  int NextFreeInd(); // нахождение свободное место в массиве

public:
  TArrList(int n = 10); 
  TArrList(TArrList& al); 
  ~TArrList(); 
  void InsFirst(ValType val); 
  void InsLast(ValType val); 
  ValType GetFirst(); 
  ValType GetDatValue(int num); 
  ValType GetLast(); 
  void DelFirst(); 
  void DelLast();
  void Del(int num); 
  bool IsFull(); 
  int GetListLength();
  bool IsEmpty();
};

template<class ValType>
int TArrList<ValType>::NextFreeInd()
{
  for (int i = 0; i < size; i++)
    if (indexNext[i] == -2)
    {
      return i;
    }
  return -2;
}

template<class ValType>
TArrList<ValType>::TArrList(int n)
{
  if (n < 0)
    throw TExeption(DataErr);
  else if (n == 0)
  {
    size = 0;
    count = 0;
    mem = 0;
	indexNext = NULL;
    firstInd = -1;
	firstFreeInd = 0;
  }
  else
  {
    size = n;
    count = 0;
    firstInd = -1;
	firstFreeInd = 0;
	indexNext = new int[size];
    for (int i = 0; i < size; i++)
	  indexNext[i] = -2;
    mem = new ValType[size];
  }
}

template<class ValType>
TArrList<ValType>::TArrList(TArrList & al)
{
  if (size == 0)
  {
    size = 0;
    count = 0;
    mem = NULL;
	indexNext = NULL;
    firstInd = -1;
	firstFreeInd = 0;
  }
  else
  {
    size = al.size;
    count = al.count;
    firstInd = al.firstInd;
	firstFreeInd = al.firstFreeInd;
	indexNext = new int[size];
    mem = new ValType[size];
    for (int i = 0; i < size; i++)
    {
	  indexNext[i] = al.indexNext[i];
      mem[i] = al.mem[i];
    }
  }
}

template<class ValType>
TArrList<ValType>::~TArrList()
{
  delete[]indexNext;
  delete[]mem;
}

template<class ValType>
void TArrList<ValType>::InsFirst(ValType val)
{
  if (IsFull())
    throw TExeption(DataFull);
  mem[firstFreeInd] = val;
  indexNext[firstFreeInd] = firstInd;
  firstInd = firstFreeInd;
  firstFreeInd = NextFreeInd();
  count++;
}
template<class ValType>
void TArrList<ValType>::InsLast(ValType val)
{
  if (IsFull())
    throw TExeption(DataFull);
  if (IsEmpty())
    InsFirst(val);
  else
  {
    int i = firstInd;
    while (indexNext[i] != -1)
      i = indexNext[i];
    mem[firstFreeInd] = val;
	indexNext[firstFreeInd] = -1;
	indexNext[i] = firstFreeInd;
	firstFreeInd = NextFreeInd();
    count++;
  }
}
template<class ValType>
ValType TArrList<ValType>::GetFirst()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  return mem[firstInd];
}

template<class ValType>
ValType TArrList<ValType>::GetDatValue(int num)
{
  if ((num < 0) || (num > count - 1))
    throw TExeption(DataErr);
  int Ind = firstInd;
  for (int i = 0; i < num; i++)
  {
    Ind = indexNext[Ind];
  }
  return mem[Ind];
}

template<class ValType>
ValType TArrList<ValType>::GetLast()
{
  int LastInd = firstInd;
  while (indexNext[LastInd] != -1)
  {
    LastInd = indexNext[LastInd];
  }
  return mem[LastInd];
}

template<class ValType>
void TArrList<ValType>::DelFirst()
{
  if (IsEmpty())
    throw TExeption(DataEmpty);
  int tmp = firstInd;
  firstInd = index[firstInd];
  indexNext[tmp] = -2;
  count--;
}

template<class ValType>
void TArrList<ValType>::DelLast()
{
  int LastInd = firstInd;
  int PrevInd;
  while (indexNext[LastInd] != -1)
  {
    PrevInd = LastInd;
    LastInd = index[LastInd];
  }
  indexNext[LastInd] = -2;
  indexNext[PrevInd] = -1;
  count--;
}

template<class ValType>
void TArrList<ValType>::Del(int num)
{
  if ((num < 0) || (num > count - 1))
    throw TExeption(DataErr);
  else if (num == 0)
    return DelFirst();
  int Ind = firstInd;
  int PrevInd;
  for (int i = 0; i < num, indexNext[Ind] != -1; i++)
  {
    PrevInd = Ind;
    Ind = indexNext[Ind];
  }
  indexNext[Ind] = -2;
  indexNext[PrevInd] = -1;
  count--;
}

template<class ValType>
bool TArrList<ValType>::IsFull()
{
  return (count == size);
}

template<class ValType>
int TArrList<ValType>::GetListLength()
{
  return size;
}

template<class ValType>
bool TArrList<ValType>::IsEmpty()
{
  return (firstInd == -1);
}
#endif __ARRLIST_H__