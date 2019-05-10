#include <TQueue.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TQueue<int> sttest(64);
  int temp;
  int v = 0;
  cout << " ������������ ���������� ��������� ��������� �������� ������: ������� " << endl;
  for (int i = 0; i < 15; i++) {
	  cout << " ������� ����� ������� ������� " << endl;
	  cin >> v;
	  sttest.Put(v);
	  cout << " �������� ������� " << v << endl;
  }
  while (!sttest.IsEmpty()) {
    temp = sttest.Get();
    cout << " ����� ������� " << temp << endl;
  }
  return 0;
}