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
  cout << " ������������ ���������� ��������� ��������� �������� ������: ������� " << endl;
  for (int i = 0; i<15; i++) {
	  printf(" ������� ����� ������� �������\n ");
	  scanf_s("%d", &v);
	  sttest.Put(v);
    cout << " �������� ������� " << v << endl;
  }
  printf("\n");
  while (!sttest.IsEmpty()) {
    temp = sttest.Get();
    cout << " ����� ������� " << temp << endl;
  }
  return 0;
}