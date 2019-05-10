#ifndef __MSTACK_H__
#define __MSTACK_H__

#include <TStack.h> 

template <class ValType>
class MStack : public TStack<ValType>
{
public:
  MStack(ValType* ind = NULL, int Size = 0);
  ~MStack();
  void SetMem(ValType* ind, int Size);
};

template<class ValType>
MStack<ValType>::MStack(ValType * ind, int Size)
{
  this->mem = ind;
  this->t = -1;
  this->memSize = Size;
}

template<class ValType>
MStack<ValType>::~MStack()
{
  this->mem = NULL;
}


template<class ValType>
void MStack<ValType>::SetMem(ValType * ind, int Size)
{
  this->mem = ind;
  this->memSize = Size;
}
#endif __MSTACK_H__
