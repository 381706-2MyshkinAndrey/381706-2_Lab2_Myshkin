#include <TQueue.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TQueue<int> sttest(64);
  int temp;
  int v = 0;
  cout << " Тестирование выполнения программы структуры хранения данных: очередь " << endl;
  for (int i = 0; i<15; i++) {
	  printf(" Введите новый элемент очереди\n ");
	  scanf_s("%d", &v);
	  sttest.Put(v);
    cout << " Положить элемент " << v << endl;
  }
  printf("\n");
  while (!sttest.IsEmpty()) {
    temp = sttest.Get();
    cout << " Взять элемент " << temp << endl;
  }
  return 0;
}