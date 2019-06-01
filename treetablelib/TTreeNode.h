#ifndef __TTREENODE_H__
#define __TTREENODE_H__

#include <iostream>
#include <TTabRecord.h>
#include <TExeption.h>

template <class ValType> class TTreeTable;
template <class ValType> class TScanTable;
template <class ValType> class TSortTable;

using namespace std;



template<class ValType>
class TTreeNode : public TTabRecord<ValType>
{
private:
  TTreeNode<ValType>* pLeft;
  TTreeNode<ValType>* pRight;
public:
  TTreeNode(TKey k = "", ValType* val = NULL, TTreeNode<ValType>*left = NULL, TTreeNode<ValType>*right = NULL, bool needtoDel = false);
  ~TTreeNode();
  TTreeNode* GetLeft();
  TTreeNode* GetRight();
  friend class TTreeTable<ValType>;
};

template<class ValType>
TTreeNode<ValType>::TTreeNode(TKey k, ValType * val, TTreeNode<ValType>* left, TTreeNode<ValType>* right, bool needtoDel) :TTabRecord<ValType>(k, val, needtoDel)
{
  pLeft = left;
  pRight = right;
}

template<class ValType>
TTreeNode<ValType>::~TTreeNode()
{
  //if (this->needtoDel)
   // delete this->value;
}
template<class ValType>
TTreeNode<ValType> * TTreeNode<ValType>::GetLeft()
{
  return pLeft;
}

template<class ValType>
TTreeNode<ValType> * TTreeNode<ValType>::GetRight()
{
  return pRight;
}
#endif __TTREENODE_H__