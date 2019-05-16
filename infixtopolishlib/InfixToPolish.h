#ifndef __POLISH_H__
#define __POLISH_H__
#include <TExeption.h>
#include<TStack.h>
#include<TListStack.h>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

class TInfixToPolish {
protected:
  int GetOpePrt(char ope); // �������� ��������� ��������
  int OpeMark(char ope); // �������� �� ���� ��������

public:
  double Calculator(char* memory, int length);
  char* ConversionToPolish(char* exp, int length); // �������������� � �������� ������
};
#endif __POLISH_H__
