#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TArrList<int> trial(20);
  int val;

  cout << " Тестирование работы структуры хранения данных : список на массивах " << endl;
  for (int i = 0; i < 20; i++)
  {
	val = rand() % 50;
	trial.InsLast(val);
    cout << "  " << i << " Положить в Список значение : " << val << endl;
  }

  cout << " ______________________________________ " << endl;
  for (int i = 0; i < trial.GetListLength(); i++)
  {
	 val = trial.GetDatValue(i);
     cout << "  " << i << " Взять из Списка значение : " << val << endl;
  }
  return 0;
}
