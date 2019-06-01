#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <TTreeTable.h>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  TTreeTable<int> table;

  TKey k;
  int cmd = 0;
  int * val;

  cout << " Тестирование работы структуры данных: таблица дерево " << endl;
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

		table.Add(new TTreeNode<int>(buff, val));
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
	cout << " Таблица-дерево " << endl;
    table.Print();
  }

  return 0;
}