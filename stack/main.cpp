#include <TStack.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TStack<int> sttest(64);
  int temp;
  int v = 0;
  cout << "Тестирование выполнения программы структуры хранения данных: стек" << endl;
  for (int i = 0; i<15; i++) {
	  cout << " Введите новый элемент стека " << endl;
	  cin >> v;
	  sttest.Put(v);
      cout << "Положить элемент " << v << endl;
  }
  while (!sttest.IsEmpty()) {
    temp = sttest.Get();
    cout << "Взять элемент " << temp << endl;
  }
  return 0;
}