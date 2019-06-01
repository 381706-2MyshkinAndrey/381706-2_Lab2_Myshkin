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
  cout << " ������������ ������������ ���������: ����� " << endl;
  cout << " _______________________________________________ " << endl;
  while (flag)
  {
    char buff[512];
	testText.Print();
    cout << endl;
    cout << " ������� ������� ������ " << testText.GetCurrent()->GetLevel() << endl;
    cout << " ������� ������ ������  ' " << (testText.GetCurrent())->ToStr() << " ' "<< endl;
    cout << " ������� 1 - ������� � ������ ������ " << endl;
    cout << " ������� 2 - ������� �� ������� ���� " << endl;
    cout << " ������� 3 - ������� � ��������� ������ " << endl;
    cout << " ������� 4 - �������� ����� ������� ������ " << endl;
    cout << " ������� 5 - �������� �� ������� ���� " << endl;
    cout << " ������� 6 - ������� ��������� ������ " << endl;
    cout << " ������� 7 - ������� ������ �� ������� ���� " << endl;
    cout << " ������� 8 - ����� ����� �� ��������� " << endl;
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
      std::cout << " ������� ������ " << endl;
      cin >> buff;
	  testText.InsertNextNB(buff);
      break;
    case 5:
      std::cout << " ������� ������ " << endl;
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
