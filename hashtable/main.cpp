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

  cout << " ������������ ������ ��������� ������: ���-������� " << endl;
  cout << " _______________________________________________________________ " << endl;
  bool flag = true;
  while (flag)
  {
    char buff[512];
	cout << " ������� 1 - ����� �������� � ������� ����� ������� " << endl;
	cout << " ������� 2 - ����� ������� ������� �� ��� ����� " << endl;
	cout << " ������� 3 - ����� ����� ������ ������� �� ����� " << endl;
	cout << " ������� 4 - ����� ��������� ������������" << endl;
	cin >> tmp;
    switch (tmp)
    {
	case 1:
		val = new int;
		cout << " ������� ������ " << endl;
		cin >> *val;
		cout << " ������� ���� " << endl;
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
	cout << " ���-������� " << endl;
	cout << table << endl;
  }

  return 0;
}