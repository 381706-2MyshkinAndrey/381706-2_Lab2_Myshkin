#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, ""); 
  TInfixToPolish ExpConversion;
  char Exp[100], *PolishExp;
  cout << " �������� �������� �������������� ��������� �� ��������� ������ � ����������� " << endl;
  cout << " ___________________________________________________________ " << endl;
  cout << " ������� ��������� ��������� " << endl << " ";
  cin >> Exp;
  PolishExp = ExpConversion.ConversionToPolish(Exp, strlen(Exp));
  cout << " ___________________________________________________________ " << endl;
  cout << " ___________________________________________________________ " << endl;
  cout << " ������ ��������� � ��������� ����� - " << endl << " " << Exp << endl;
  cout << " ��������� � �������� �������� ������ - " << endl << " " << PolishExp << endl;
  cout << " ������������ ��������� ������� ��������� - "  << ExpConversion.Calculator(PolishExp, strlen(Exp)) << endl;
  delete PolishExp;

  return 0;
}