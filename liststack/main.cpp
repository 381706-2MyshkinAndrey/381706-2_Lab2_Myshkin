#include <iostream>
#include <TListStack.h>
#include <ctime>
#include <cstdlib>

int main()
{
  setlocale(LC_ALL, "");
  srand(time(NULL));
  TListStack<int> stackList;
  int val = 0;
  int Size;
  cout << " “естирование работы структуры хранени€ данных : стек на списке " << endl;
  cout << " ___________________________________________ " << endl;
  cout << " ¬ведите размер стека : ";
  cin >> Size;
  cout << endl;
  cout << " ___________________________________________ " << endl;
  for (int i = 0; i < Size; i++)
  {
    val = rand() % 150;
	stackList.Put(val);
	cout << " ѕоложить в стек значение : " << val << endl;
  }
  cout << " ___________________________________________ " << endl;
  cout << " ѕечать полученного стека на консоль " << endl;
  cout << " ___________________________________________ " << endl;
  stackList.Print();
  cout << " ___________________________________________ " << endl;

  return 0;
}