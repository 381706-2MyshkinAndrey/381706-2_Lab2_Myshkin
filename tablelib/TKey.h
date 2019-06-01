#ifndef __TKEY_H__
#define __TKEY_H__

#include <iostream>
#include <TExeption.h>
#include <string.h>

using namespace std;

class TKey
{
protected:
  char* key;
  int length;
public:
  TKey(char* kkey = "");
  TKey(const TKey &k);
  void SetKey(char* kkey);
  int GetLength();
  char* GetKey();
  TKey& operator = (const TKey& tko);
  TKey& operator = (const char* str);
  bool operator == (const TKey& tko);
  bool operator > (const TKey& tko);
  bool operator < (const TKey& tko);
  char operator [] (const int pos);
  friend ostream& operator<<(ostream &os, const TKey &q);
  ~TKey();
};

#endif __TKEY_H__