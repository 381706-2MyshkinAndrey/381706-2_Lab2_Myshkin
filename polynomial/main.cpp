#include "TPolinomial.h"
#include <iostream>
#include <cstdlib>

int main() 
{
  setlocale(LC_ALL, "");
  cout << " ������������ ��������� � ���������� " << endl;
  TPolinomial polynom1;
  for (int i = 0; i < 5; i++)
  {
	int ms1[] = { i + 1, i + 2, i + 3};
	TMonomial m1(2*(i + 1), 3, ms1);
	polynom1 += m1;
  }
  cout << " ������ ������� �������� " << endl << polynom1;
  cout << " ________________________________________________ " << endl;
  TPolinomial polynom2;
  for (int i = 0; i < 5; i++)
  {
	int numder = rand() % 10;
	int ms2[] = { i + 1, i + 2, i + 3 };
    TMonomial m2(i + numder, 3, ms2);
	polynom2 += m2;
  }
  cout << " ������ ������� �������� " << endl << polynom2;
  cout << " ________________________________________________ " << endl;
  TPolinomial Sum = polynom1 + polynom2;
  cout << " ������� ����� ������� � ������� ��������� " << endl << Sum;
  cout << " ________________________________________________ " << endl;
  TPolinomial Difference = polynom1 - polynom2;
  cout << " ������� �������� ������� � ������� ��������� " << endl << Difference;
  cout << " ________________________________________________ " << endl;
  return 0;
}