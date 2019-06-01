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

  cout << " ������������ ������ ��������� ������: ������������ ������� " << endl;
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
	cout << " ������������ ������� " << endl;
	cout << tableSee << endl;
  }

  return 0;
}
