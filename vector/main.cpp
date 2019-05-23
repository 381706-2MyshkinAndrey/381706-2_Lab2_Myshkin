#include <iostream>
#include "TMatrix.h"
#include <ctime>
#include <cstdlib>


int main(int argc, char* argv[]) 
{
  setlocale(LC_ALL, "");
  srand(time(NULL));
  TMatrix<int> a(5), b(5), c(5), d(5);
  int i, j;
  cout << "Тестирование программ поддержки треугольных матриц" << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++) 
    {
      a[i][j] = rand() % 20 ;
      b[i][j] = rand() % 30 ;
    }
  c = a + b;
  d = a * b;

  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  cout << "Matrix c = a * b" << endl << d << endl;
  return 0;
}