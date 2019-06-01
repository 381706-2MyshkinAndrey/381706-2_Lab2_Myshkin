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

  cout << " ������������ ������ ��������� ������: ������� ������ " << endl;
  cout << " _______________________________________________________________ " << endl;
  bool flag = true;
  while (flag)
  {
    char buff[512];
	cout << endl;
	cout << " ������� 1 - ����� �������� � ������� ����� ������� " << endl;
	cout << " ������� 2 - ����� ������� ������� �� ��� ����� " << endl;
	cout << " ������� 3 - ����� ����� ������ ������� �� ����� " << endl;
	cout << " ������� 4 - ����� ��������� ������������" << endl;
	cin >> cmd;
    switch (cmd)
    {
	case 1:
		val = new int;
		cout << " ������� ������ " << endl;
		cin >> *val;
		cout << " ������� ���� " << endl;
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
	cout << " �������-������ " << endl;
    table.Print();
  }

  return 0;
}