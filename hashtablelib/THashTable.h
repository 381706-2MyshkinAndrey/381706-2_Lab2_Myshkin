#ifndef __THASHTABLE_H__
#define __THASHTABLE_H__

#include <iostream>
#include <TTabRecord.h>
#include <TExeption.h>
#include <TScanTable.h>

using namespace std;


template<class ValType>
class THashTable
{
private:
  int dataC;
  int tableSize;
  TTabRecord<ValType>** pRecs;
  unsigned long HashFunc(TKey k);
  int hashStep;
  int currPos;
  int GCD(int n, int m);
  int GetNextPos(int pos);
public:
  THashTable(int size = 3);
  ~THashTable();
  int Add(TTabRecord<ValType> *tr);
  void Delete(TKey k);
  TTabRecord<ValType>* Search(TKey k);
  ValType* operator[] (TKey k);
  friend ostream& operator<<(ostream &os, const THashTable &q)
  {
    if (q.dataC == 0)
      return os;
    for (int i = 0; i < q.dataC - 1; i++)
    {
      os << "Key :" << q.pRecs[i]->GetKey();
      os << " val :" << *q.pRecs[i]->GetVal();
      os << endl;
    }
    os << "Key :" << q.pRecs[q.dataC - 1]->GetKey();
    os << " val :" << *q.pRecs[q.dataC - 1]->GetVal();
    return os;
  }
};
#endif

template<class ValType>
unsigned long THashTable<ValType>::HashFunc(TKey k)
{
  unsigned  long hashval = 0;
  int len = k.GetLength();
  for (int i = 0; i < len; i++)
    hashval = (hashval << 3) + k[i];
  return hashval;
}

template<class ValType>
int THashTable<ValType>::GCD(int n, int m)
{
  if (!(n && m))
    return(n + m);
  if (n >= m)
    return GCD(n%m, m);
  return GCD(m%n, n);
}

template<class ValType>
int THashTable<ValType>::GetNextPos(int pos)
{
  return (pos + hashStep) % tableSize;;
}

template<class ValType>
THashTable<ValType>::THashTable(int size)
{
  tableSize = size;
  dataC = 0;
  if (size < 1)
    throw TExeption(DataErr);
  pRecs = new TTabRecord<ValType>*[size];
  for (int i = 0; i < size; i++)
  {
    pRecs[i] = NULL;
  }

  hashStep = 2;
  while (true)
  {
    int buff = GCD(hashStep, tableSize);
      if (buff == 1)
        break;
    hashStep++;
  }
}

template<class ValType>
THashTable<ValType>::~THashTable()
{
  if (pRecs != NULL)
  {
    for (int i = 0; i < tableSize; i++)
      if(pRecs[i] != NULL)
        delete pRecs[i];
    delete[]pRecs;
  }
}

template<class ValType>
int THashTable<ValType>::Add(TTabRecord<ValType>* tr)
{
  if (dataC == tableSize)
    throw TExeption(DataNoMem);
  currPos = HashFunc(tr->key) % tableSize;
  for (int i = 0; i < tableSize; i++)
  {
    if ((pRecs[currPos] != NULL))
    {
      if ((pRecs[currPos]->key == tr->key))
        throw TExeption(DataErr);
    }
    else
    {
      pRecs[currPos] = tr;
	  dataC++;
      return currPos;
    }
    currPos = GetNextPos(currPos);
  }
  return -1;
}

template<class ValType>
void THashTable<ValType>::Delete(TKey k)
{
  if (dataC == 0)
    throw TExeption(DataEmpty);
  currPos = HashFunc(k) % tableSize;
  for (int i = 0; i < tableSize; i++)
  {
    if ((pRecs[currPos] != NULL))
    {
      if ((pRecs[currPos]->key == k))
      {
        delete pRecs[currPos];
        pRecs[currPos] = NULL;
      }
    }
    currPos = GetNextPos(currPos);
  }
}

template<class ValType>
TTabRecord<ValType>* THashTable<ValType>::Search(TKey k)
{
  currPos = HashFunc(k) % tableSize;
  for (int i = 0; i < tableSize; i++)
  {
    if (pRecs[currPos] == NULL)
      break;
    else if (pRecs[currPos]->key == k)
      return pRecs[currPos];
    currPos = GetNextPos(currPos);
  }
  return NULL;
}

template<class ValType>
ValType * THashTable<ValType>::operator[](TKey k)
{
  TTabRecord<ValType>* res = Search(k);
  if (res == NULL)
  {
    TTabRecord<ValType>* n = new TTabRecord<ValType>(k, NULL, true);
    Add(n);
    return n->value;
  }
  return res->value;
}
