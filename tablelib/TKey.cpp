#include <TKey.h>

TKey::TKey(char * kkey)
{
  length = strlen(kkey);
  key = new char[length + 1];
  strcpy(key, kkey);
}

TKey::TKey(const TKey & k)
{
  length = strlen(k.key);
  key = new char[k.length + 1];
  strcpy(key, k.key);
}

void TKey::SetKey(char * kkey)
{
  length = strlen(kkey);
  key = new char[length + 1];
  strcpy(key, kkey);
}

int TKey::GetLength()
{
  return length;
}

char * TKey::GetKey()
{
  return key;
}

TKey& TKey::operator=(const TKey & tko)
{
	length = strlen(tko.key);
    key = new char[length + 1];
    strcpy(key, tko.key);
  return *this;
}

TKey& TKey::operator=(const char * str)
{
  if(length != 0)
    delete key;
  length = strlen(str);
  key = new char[length + 1];
  strcpy(key, str);
  return *this;
}

bool TKey::operator==(const TKey & tko)
{
  if (length != tko.length)
    return false;
  for (int i = 0; i < length; i++)
  {
    if (key[i] != tko.key[i])
      return false;
  }
  return true;
}

bool TKey::operator>(const TKey & tko)
{
  int clamp = length;
  if (tko.length < length)
    clamp = tko.length;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] < tko.key[i])
      return true;
    else if (key[i] > tko.key[i])
      return false;
  }
  if (length < tko.length)
    return true;
  return false;
}

bool TKey::operator<(const TKey & tko)
{
  int clamp = length;
  if (tko.length < length)
    clamp = tko.length;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] > tko.key[i])
      return true;
    else if (key[i] < tko.key[i])
      return false;
  }
  if (length > tko.length)
    return true;
  return false;
}

char TKey::operator[](const int pos)
{
  if((pos < length) && (pos > 0))
    return key[pos];
  return -1;
}

TKey::~TKey()
{
  if (length != 0)
    delete key;
}

ostream & operator<<(ostream & os, const TKey & q)
{
  os << q.key;
  return os;
}
