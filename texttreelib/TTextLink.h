#ifndef __TEXTTREE_H__
#define __TEXTTREE_H__
#include <string.h>
#include <iostream>
#include <TExeption.h>
#include <TListStack.h>



class TTextLink;
class TText;
using namespace std;


class TTextMem
{
public:
  TTextLink* pFirst; // ������ �����
  TTextLink* pLast; // ��������� �����
  TTextLink* pFirstFree; // ������ ���������
  friend class TTextLink;
};


class TTextLink
{
  protected:
    TTextLink* pNextLvl; // ��������� �������
    TTextLink* pNextNB; // ������
    char letter; // �����, ������ �� ������ ������
    int level;//�������, 0 -�����, 1 -������ 2 - �����, 3 - �����
    static TTextMem memory;
  public:
    TTextLink(char* st = 0);
    TTextLink(int l);
    TTextLink(char _letter = 0);
    TTextLink(const TTextLink& A);
    ~TTextLink();
    static void InitMemory(int size);
    static void MemCleaner(TText &txt);
    void * operator new(const size_t size);
    void operator delete(void* pM);
    TTextLink& operator=(const TTextLink& A);
    TTextLink& operator+=(TTextLink& A);
    TTextLink& operator+=(char c);
    TTextLink& operator+=(char* c);
    friend ostream & operator<<(ostream& o, const TTextLink& A);
    char* ToStr();
    void SetNextLvl(TTextLink* p);
    void SetNextNB(TTextLink* p);
    void SetLetter(char _letter);
    void SetLevel(int _level);
    TTextLink* GetNextLvl();
    TTextLink* GetNextNB();
    char GetLetter();
    int GetLevel();
    TTextLink* Clone();
    friend class TText;
  };
#endif __TEXTTREE_H__