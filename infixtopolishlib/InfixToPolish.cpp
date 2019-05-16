#include "InfixToPolish.h"

int TInfixToPolish::GetOpePrt(char ope)
{
  switch (ope) {
  case '*': return 3;
  case '/': return 3;
  case '+': return 2;
  case '-': return 2;
  case '(': return 1;
  case '=': return 0;
  default: return-1;
  }
}

int TInfixToPolish::OpeMark(char ope)
{
  if (ope == '(' || ope == ')' || ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '=')
    return 1;
  return 0;
}

double TInfixToPolish::Calculator(char* memory, int length)
{
  TStack<int> st;
  int res;
  int i = 0;
  int j;
  while (memory[i]!='=')
  {
    if (!OpeMark(memory[i]))
    {
      j = 0;
      char* buff = new char[length];
      while (memory[i] != ' ')
        buff[j++] = memory[i++];
      buff[j] = '\n';
      st.Put(atoi(buff));
      delete[] buff;
    }
    else
    {
      double x, y;
      y = st.Get();
      x = st.Get();
      double z;
      switch (memory[i])
      {
      case '*': z = x * y;
        break;
      case '/': z = x / y;
        break;
      case '+': z = x + y;
        break;
      case '-': z = x - y;
        break;
      default: throw(TExeption(DataErr));
      }
      st.Put(z);
    }
    i++;
  }
  res = st.Get();
  return res;
}

char* TInfixToPolish::ConversionToPolish(char* exp, int length)
{
  TListStack<char> ope, polish;
  int i = 0;
  char t;
  while (i < length)
  {
    if (!OpeMark(exp[i]))
    {
      while (!OpeMark(exp[i]))
      {
        polish.Put(exp[i++]);
      }
      i--;
      polish.Put(' ');
    }
    else if (exp[i] == '(')
		ope.Put('(');
    else if (exp[i] == ')')
    {
      while (1)
      {
        char k = ope.Get();
        if (k == '(')
          break;
        polish.Put(k);
      }
    }
    else
    {
      while (!ope.IsEmpty())
      {
        t = ope.Get();
        if (GetOpePrt(exp[i]) <= GetOpePrt(t))
          polish.Put(t);
        else
        {
			ope.Put(t);
          break;
        }
      }
	  ope.Put(exp[i]);
    }
    if (exp[i] == '=')
      break;
    i++;
  }
  int pos = polish.GetLength() + ope.GetLength();
  char * memory = new char[pos + 1];
  memory[pos] = '\0';
  memory[--pos] = '=';
  while (!polish.IsEmpty())
	  memory[--pos] = polish.Get();
  return memory;
}
