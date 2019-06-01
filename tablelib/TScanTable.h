#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include <iostream>
#include <TTabRecord.h>
#include <TExeption.h>

template <class ValType> class TSortTable;

using namespace std;

template<class ValType>
class TScanTable
{
protected:
  int dataC;
  int tableSize;
  TTabRecord<ValType>** pRecord;
public:
  TScanTable(int size = 2);
  TScanTable(TScanTable<ValType> &st);
  ~TScanTable();
  int Add(TTabRecord<ValType> *tko);
  void Delete(TKey k);
  int GetTableSize();
  int GetDataC();
  TTabRecord<ValType>* Search(TKey k);
  ValType* operator[] (TKey k);
  friend ostream& operator<<(ostream &os, const TScanTable &ope)
  {
    if (ope.dataC == 0)
      return os;
    for (int i = 0; i < ope.dataC - 1; i++)
    {
      os << " Ключ : " << ope.pRecord[i]->GetKey();
      os << " Данные : " << *ope.pRecord[i]->GetVal();
      os << endl;
    }
    os << "Ключ :" << ope.pRecord[ope.dataC - 1]->GetKey();
    os << " Данные :" << *ope.pRecord[ope.dataC - 1]->GetVal();
    return os;
  }
  friend class TSortTable<ValType>;
};

template<class ValType>
TScanTable<ValType>::TScanTable(int size)
{
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
TScanTable<ValType>::TScanTable(TScanTable<ValType> &st)
{
  dataC = st.dataC;
  tableSize = st.tableSize;
  pRecord = new TTabRecord<ValType>*[tableSize];
  for (int i = 0; i < dataC; i++)
	  pRecord[i] = new TTabRecord<ValType>(*pRecord[i]);
}

template<class ValType>
TScanTable<ValType>::~TScanTable()
{
  if (pRecord != NULL)
  {
    for (int i = 0; i < dataC; i++)
      delete pRecord[i];
    delete[]pRecord;
  }
}

template<class ValType>
int TScanTable<ValType>::Add(TTabRecord<ValType>* tko)
{
  if (tableSize == dataC - 1)
    throw TExeption(DataNoMem);
  pRecord[dataC] = tko;
  return dataC++;
}

template<class ValType>
void TScanTable<ValType>::Delete(TKey k)
{
  if (dataC == 0)
    throw TExeption(DataEmpty);
  for (int i = 0; i < dataC; i++) {
    if (pRecord[i]->key == k)
    {
      delete pRecord[i];
	  pRecord[i] = NULL;
      for (int j = i; j < dataC - 1; j++)
		  pRecord[j] = pRecord[j + 1];
    }
	dataC--;
  }
}

template<class ValType>
int TScanTable<ValType>::GetTableSize()
{
  return tableSize;
}

template<class ValType>
int TScanTable<ValType>::GetDataC()
{
  return dataC;
}

template<class ValType>
TTabRecord<ValType> * TScanTable<ValType>::Search(TKey k)
{
  for (int i = 0; i < dataC; i++)
  {
    if (pRecord[i]->key == k)
      return pRecord[i];
  }
  return NULL;
}

template<class ValType>
ValType* TScanTable<ValType>::operator[](TKey k)
{
  TTabRecord<ValType>* res = Search(k);
  if (res == NULL) 
  {
    TTabRecord<ValType> *n = new TTabRecord<ValType>(k, NULL, true);
    Add(n);
    res = pRecord[dataC - 1];
  }
  return res->value;
}
#endif __TSCANTABLE_H__