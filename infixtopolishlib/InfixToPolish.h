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
  int GetOpePrt(char ope); // получить приоритет операции
  int OpeMark(char ope); // проверка на знак операции

public:
  double Calculator(char* memory, int length);
  char* ConversionToPolish(char* exp, int length); // проебразование к польской записи
};
#endif __POLISH_H__
