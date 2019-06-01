#include "TPlexGragh.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  cout << " Тестирование структуры хранения данных: плекс " << endl;
  cout << " ___________________________________________________ " << endl;
  
  TPlexGragh plex;
  TPointGragh point[5];
  TLineGragh line;
  cout << " Необходимо ввести " << 5 << " точек " << endl;
  for (int i = 0; i < 5 ; i++)
  {
    int tmp;
    cout << "X" << i + 1 << " = ";
    cin >> tmp;
	cout << endl;
	point[i].SetX(tmp);
	int tmp1;
    cout << "Y" << i + 1 << " = ";
    cin >> tmp1;
	cout << endl;
	point[i].SetY(tmp1);
  }
  for (int i = 0 ; i < 5 - 1 ; i++)
  {
	line.SetA(point + i);
	line.SetB(point + i + 1);
	plex += line;
  }

  plex.Show();
  return 0;
}
