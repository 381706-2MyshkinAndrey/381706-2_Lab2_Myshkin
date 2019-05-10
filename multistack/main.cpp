#include <iostream>
#include "TMultiStack.h"
#include "TQueue.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  int CurrCount = 1;
  TMultiStack<int> MultiSt(50, 5);
  MultiSt.Put(0, 10);
  srand(1);
  int nstack = 5; 
  int numSt, code;
  int temp; 
  int cycles = 0;

  cout << " Тестирование выполнения программы структуры хранения данных: мультистек  " << endl;
  while (CurrCount != 50)
  {
	cycles++;
    code = rand() % 4; 
    numSt = rand() % nstack; 
    if (code < 3)
    {
      CurrCount++;
	  MultiSt.Put(numSt, cycles);
    }
    else if (!MultiSt.IsEmpty(numSt))
    {
      CurrCount--;
      temp = MultiSt.Get(numSt);
    }
	cout << "  __________________________________________ " << endl;
    cout << " Циклов - " << cycles << " , Перепаковок - " << MultiSt.GetRelocationCount() << endl;
    cout << " На данный момент в мультистеке: " << CurrCount << endl;
	MultiSt.Print();
  }
  return 0;
}