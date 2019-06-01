#ifndef __TSORTTABLE_H__
#define __TSORTTABLE_H__

#include <iostream>
#include <TExeption.h>
#include <TScanTable.h>


enum SortType
{QUICK, MERGE, INSERT};

template<class ValType>
class TSortTable
{
protected:
  int dataC;
  int tableSize;
  SortType stype;
  TTabRecord<ValType>** pRecord;
  void MergeSort(TTabRecord<ValType>** nRec, int datCount);
  void MergeSorter(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int size);
  void MergeData(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int n1, int n2);
  void InsertSort(TTabRecord<ValType>** nRec, int datCount);
  void QuickSort(TTabRecord<ValType>** nRec, int datCount);
  void QuickSplit(TTabRecord<ValType>** pData, int size, int &pivot);
public:
  TSortTable(int size = 2);
  TSortTable(TScanTable<ValType> &st);
  ~TSortTable();
  void SetSortType(SortType t);
  void SortData();
  TSortTable& operator = (const TScanTable<ValType> &st);
  int Add(TTabRecord<ValType> *tr);
  void Delete(TKey k);
  TTabRecord<ValType>* Search(TKey);
  ValType * operator[] (TKey);

  friend ostream& operator<<(ostream &os, const TSortTable &q)
  {
    for (int i = 0; i < q.dataC; i++)
    {
      for (int i = 0; i < q.dataC - 1; i++)
      {
        os << "Key :" << q.pRecord[i]->GetKey();
        os << " val :" << *q.pRecord[i]->GetVal();
        os << endl;
      }
      os << "Key :" << q.pRecord[q.dataC - 1]->GetKey();
      os << " val :" << *q.pRecord[q.dataC - 1]->GetVal();
      return os;
    }
    return os;
  }
};


template<class ValType>
void TSortTable<ValType>::MergeSort(TTabRecord<ValType>** nRec, int datCount)
{
  TTabRecord<ValType>** pData = nRec;
  TTabRecord<ValType>** pBuff = new TTabRecord<ValType>*[datCount];
  TTabRecord<ValType>** pTemp = pBuff;
  MergeSorter(pData, pBuff, datCount);
  if (pData == pTemp)
    for (int i = 0; i < datCount; i++)
      pBuff[i] = pData[i];
  delete pTemp;
}

template<class ValType>
void TSortTable<ValType>::MergeSorter(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int size)
{
  int n1 = (size + 1) / 2;
  int n2 = size - n1;
  if (size > 2)
  {
    TTabRecord<ValType>** pDat2 = pData + n1;
    TTabRecord<ValType>** pBuff2 = pBuff + n1;
    MergeSorter(pData, pBuff, n1);
    MergeSorter(pDat2, pBuff2, n2);
  }
  MergeData(pData, pBuff, n1, n2);
}

template<class ValType>
void TSortTable<ValType>::MergeData(TTabRecord<ValType>**& pData, TTabRecord<ValType>**& pBuff, int n1, int n2)
{
  TTabRecord<ValType>** pDat2 = pData + n1;
  int i = 0, j = 0, k = 0;
  while((i < n1) && (j < n2))
  {
    if (*pData[i] > *pDat2[j])
    {
      pBuff[k] = pData[i];
      k++;
      i++;
    }
    else
    {
      pBuff[k] = pDat2[j];
      k++;
      j++;
    }
  }
  if(i < n1)
    for (; i < n1; i++)
    {
      pBuff[k] = pData[i];
      k++;
    }
  else if (j < n2)
  {
    for (; j < n1; j++)
    {
      pBuff[k] = pData[i];
      k++;
    }
  }
  TTabRecord<ValType>** pTemp = pData;
  pData = pBuff;
  pBuff = pTemp;
}

template<class ValType>
void TSortTable<ValType>::InsertSort(TTabRecord<ValType>** nRec, int datCount)
{
  TTabRecord<ValType>* pR;
  for (int i = 1, j; i < datCount; i++)
  {
    pR = nRec[i];
    for (j = i - 1; j > -1; j--)
    {
      if (*nRec[i] > *pR)
		  nRec[j + 1] = nRec[j];
      else
        break;
    }
	nRec[j + 1] = pR;
  }
}

template<class ValType>
void TSortTable<ValType>::QuickSort(TTabRecord<ValType>** nRec, int datCount)
{
  int pivot;
  int n1, n2;
  if (datCount > 1)
  {
    QuickSplit(nRec, datCount, pivot);
    n1 = pivot + 1;
    n2 = datCount - n1;
    QuickSort(nRec, n1 - 1);
    QuickSort(nRec + n1, n2);
  }
}

template<class ValType>
void TSortTable<ValType>::QuickSplit(TTabRecord<ValType>** pData, int size, int & pivot)
{
  TTabRecord<ValType>* pPivot = pData[0];
  TTabRecord<ValType>* pTemp;
  int i1 = 1;
  int i2 = size - 1;
  while (i1 <= i2)
  {
    while ((i1 < size) && !(pData[i1]->key < pPivot->key))
      i1++;
    while (pData[i2]->key < pPivot->key)
      i2--;
    if (i1 < i2)
    {
      pTemp = pData[i1];
      pData[i1] = pData[i2];
      pData[i2] = pTemp;
    }
  }
  pData[0] = pData[i2];
  pData[i2] = pPivot;
  pivot = i2;  
}

template<class ValType>
TSortTable<ValType>::TSortTable(int size)
{
  stype = QUICK;
  tableSize = size;
  dataC = 0;
  if (size < 1)
    throw TExeption(DataErr);
  pRecord = new TTabRecord<ValType>*[size];
  for (int i = 0; i < size; i++)
  {
	  pRecord[i] = NULL;
  }
}

template<class ValType>
TSortTable<ValType>::TSortTable(TScanTable<ValType> & st)
{
  stype = QUICK;
  *this = st;
}

template<class ValType>
TSortTable<ValType>::~TSortTable()
{
  if (pRecord != NULL)
  {
    for (int i = 0; i < dataC; i++)
      delete pRecord[i];
    delete[]pRecord;
  }
}

template<class ValType>
void TSortTable<ValType>::SetSortType(SortType t)
{
  stype = t;
}

template<class ValType>
void TSortTable<ValType>::SortData()
{
  switch (stype)
  {
  case QUICK:
      QuickSort(pRecord, dataC);
      break;
  case MERGE:
    MergeSort(pRecord, dataC);
    break;
  case INSERT:
    InsertSort(pRecord, dataC);
    break;
  }
}

template<class ValType>
TSortTable<ValType> & TSortTable<ValType>::operator=(const TScanTable<ValType> & st)
{
  if (pRecord != NULL)
  {
    for (int i = 0; i < dataC; i++)
      delete pRecord[i];
    delete[]pRecord;
  }
  tableSize = st.tableSize;
  dataC = st.dataC;
  pRecord = new TTabRecord<ValType>*[tableSize];
  for (int i = 0; i < dataC; i++)
	  pRecord[i] = new TTabRecord<ValType>(*st.pRecord[i]);
  for (int i = dataC; i < tableSize; i++)
	  pRecord[i] = NULL;
  SortData();
  return *this;
}
template<class ValType>
int TSortTable<ValType>::Add(TTabRecord<ValType> * tr)
{
  if (dataC == tableSize)
    throw TExeption(DataNoMem);
  if (dataC == 0)
  {
	pRecord[0] = tr;
    return dataC++;;
  }
  int left = 0;
  int right = dataC;
  int curr = (left + right) / 2;
  while (right - left != 1)
  {
    if (pRecord[curr]->key == tr->key)
      throw TExeption(DataErr);
    if (tr->key < pRecord[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
  if(tr->key < pRecord[curr]->key)
    curr++;
  for (int i = dataC; i > curr; i--)
	  pRecord[i] = pRecord[i - 1];
  pRecord[curr] = tr;
  dataC++;
  return curr;
}

template<class ValType>
void TSortTable<ValType>::Delete(TKey k)
{
  if (dataC == 0)
    return;
  int left = 0;
  int right = dataC;
  int curr = (left + right) / 2;
  while (right - left != 1)
  {
    if (pRecord[curr]->key == k)
    {
      for (int i = curr; i < dataC - 1; i++)
		  pRecord[i] = pRecord[i + 1];
	  dataC--;
    }
    if (k < pRecord[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
}

template<class ValType>
TTabRecord<ValType> * TSortTable<ValType>::Search(TKey k)
{
  int left = 0;
  int right = dataC;
  int curr = (left + right) / 2;
  while (right - left != 0)
  {
    if (pRecord[curr]->key == k)
      return pRecord[curr];
    if (k < pRecord[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
  return NULL;
}

template<class ValType>
ValType * TSortTable<ValType>::operator[](TKey k)
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
#endif __TSORTTABLE_H__