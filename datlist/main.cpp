#include "TDatList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TDatList<int> trial;
  int val;
  cout << " Тестирование работы структуры хранения данных : список " << endl;
  for (int i = 0; i < 15; i++)
  {
    val = rand() % 50;
	trial.InsLast(val);
    cout << "  " << i << " Положить в Список значение : " << val << endl;
  }
  
  cout << " ______________________________________ " << endl;
  for (int i = 0; i < trial.GetListLength(); i++) {
   val = trial.GetDatValue(i);
    cout << "  " << i << " Взять из Списка значение : " << val << endl;
  }
  trial.DelList();
  return 0;
}
