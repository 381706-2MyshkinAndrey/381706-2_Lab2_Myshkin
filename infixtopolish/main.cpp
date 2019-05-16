#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, ""); 
  TInfixToPolish ExpConversion;
  char Exp[100], *PolishExp;
  cout << " Проверка перевода арифмитических выражения из инфискной записи в постфиксную " << endl;
  cout << " ___________________________________________________________ " << endl;
  cout << " Введите выбранное выражение " << endl << " ";
  cin >> Exp;
  PolishExp = ExpConversion.ConversionToPolish(Exp, strlen(Exp));
  cout << " ___________________________________________________________ " << endl;
  cout << " ___________________________________________________________ " << endl;
  cout << " Запись выражения в инфиксной форме - " << endl << " " << Exp << endl;
  cout << " Выражения в обратной польской записи - " << endl << " " << PolishExp << endl;
  cout << " Получившийся результат данного выражения - "  << ExpConversion.Calculator(PolishExp, strlen(Exp)) << endl;
  delete PolishExp;

  return 0;
}