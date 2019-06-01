#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <TScanTable.h>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  TScanTable<int> tableSee(10);
  
  TKey k;
  int cmd = 0;
  int * val;

  cout << " Тестирование работы структуры данных: просмотровая таблица " << endl;
  cout << " _______________________________________________________________ " << endl;
  bool flag = true;
  while (flag)
  {
    char buff[512];
    cout << endl;
    cout << " Нажмите 1 - чтобы добавить в таблицу новый элемент " << endl;
    cout << " Нажмите 2 - чтобы удалить элемент по его ключу " << endl;
    cout << " Нажмите 3 - чтобы найти нужный элемент по ключу " << endl;
    cout << " Нажмите 4 - чтобы закончить тестирование" << endl;
    cin >> cmd;
    switch (cmd)
    {
    case 1:
      val = new int;
	  cout << " Введите данные " << endl;
	  cin >> *val;
	  cout << " Введите ключ " << endl;
	  cin >> buff;
     
	  tableSee.Add(new TTabRecord<int>(buff, val, true));
      break;
    case 2:
      cin >> buff;
      k = buff;
	  tableSee.Delete(k);
      break;
    case 3:
      cin >> buff;
      k = buff;
	  tableSee.Search(k);
      break;
	case 4:
		flag = false;
		break;
    }
	cout << " Просмотровая таблица " << endl;
	cout << tableSee << endl;
  }

  return 0;
}
