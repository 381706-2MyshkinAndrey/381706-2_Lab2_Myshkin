#include "TText.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  TText testText;
  bool flag = true;
  int var = 0;
  cout << " Тестирование динамической структуры: текст " << endl;
  cout << " _______________________________________________ " << endl;
  while (flag)
  {
    char buff[512];
	testText.Print();
    cout << endl;
    cout << " Текущий уровень текста " << testText.GetCurrent()->GetLevel() << endl;
    cout << " Текущая ячейка текста  ' " << (testText.GetCurrent())->ToStr() << " ' "<< endl;
    cout << " Нажмите 1 - Перейти в начало текста " << endl;
    cout << " Нажмите 2 - Перейти на уровень ниже " << endl;
    cout << " Нажмите 3 - Перейти к следующей ячейке " << endl;
    cout << " Нажмите 4 - Вставить после текущей ячейки " << endl;
    cout << " Нажмите 5 - Вставить на уровень ниже " << endl;
    cout << " Нажмите 6 - Удалить следующую ячейку " << endl;
    cout << " Нажмите 7 - Удалить ячейку на уровень ниже " << endl;
    cout << " Нажмите 8 - Чтобы выйти из программы " << endl;
    cin >> var;

    switch (var)
    {
    case 1:
	  testText.Reset();
	  break;
    case 2:
	  testText.GoNextLvlLink();
      break;
    case 3:
	  testText.GoNextNBLink();
      break;
    case 4:
      std::cout << " Введите данные " << endl;
      cin >> buff;
	  testText.InsertNextNB(buff);
      break;
    case 5:
      std::cout << " Введите данные " << endl;
      cin >> buff;
	  testText.InsertNextLvl(buff);
      break;
    case 6:
	  testText.DelNextNB();
      break;
    case 7:
	  testText.DelNextLvl();
      break;
    case 8:
	  flag = false;
	  break;
    }
  }
}
