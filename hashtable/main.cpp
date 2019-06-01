#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <THashTable.h>

using namespace std;

int main()
{
  THashTable<int> table(10);
  setlocale(LC_ALL, "");

  TKey k;
  int  tmp = 0;
  int * val;

  cout << " Тестирование работы структуры данных: ХЕШ-таблица " << endl;
  cout << " _______________________________________________________________ " << endl;
  bool flag = true;
  while (flag)
  {
    char buff[512];
	cout << " Нажмите 1 - чтобы добавить в таблицу новый элемент " << endl;
	cout << " Нажмите 2 - чтобы удалить элемент по его ключу " << endl;
	cout << " Нажмите 3 - чтобы найти нужный элемент по ключу " << endl;
	cout << " Нажмите 4 - чтобы закончить тестирование" << endl;
	cin >> tmp;
    switch (tmp)
    {
	case 1:
		val = new int;
		cout << " Введите данные " << endl;
		cin >> *val;
		cout << " Введите ключ " << endl;
		cin >> buff;

		table.Add(new TTabRecord<int>(buff, val, true));
		break;
	case 2:
		cin >> buff;
		k = buff;
		table.Delete(k);
		break;
	case 3:
		cin >> buff;
		k = buff;
		table.Search(k);
		break;
	case 4:
		flag = false;
		break;
    }
	cout << " ХЕШ-таблица " << endl;
	cout << table << endl;
  }

  return 0;
}