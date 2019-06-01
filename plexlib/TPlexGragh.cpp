#include <TPlexGragh.h>

TPointGragh * TPlexGragh::Show(TPlexGragh * p)
{
  TPlexGragh* lp = dynamic_cast<TPlexGragh*>(p->left);
  TPlexGragh* rp = dynamic_cast<TPlexGragh* > (p->right);
  TPointGragh* tmp_l;
  TPointGragh* tmp_r;
  if (lp == NULL)
    tmp_l = p->left;
  else
    tmp_l = Show(lp);
  if (rp == NULL)
    tmp_r = p->right;
  else
    tmp_r = Show(rp);
  cout << "Line: ";
  tmp_l->Show();
  cout << " - ";
  tmp_r->Show();
  cout << endl;
  return tmp_r;
}

TPlexGragh::TPlexGragh()
{
  left = NULL;
  right = NULL;
}

TPlexGragh::TPlexGragh(TPlexGragh & cp)
{
  TPlexGragh* lBuff = dynamic_cast<TPlexGragh*>(cp.left);
  TPlexGragh* rBuff = dynamic_cast<TPlexGragh*>(cp.right);
  if (lBuff != NULL)
    left = new TPlexGragh(*lBuff);
  else
    left = new TPointGragh(*cp.left);
  if (rBuff != NULL)
    right = new TPlexGragh(*rBuff);
  else
    right = new TPointGragh(*cp.right);
}

TPlexGragh::TPlexGragh(TPointGragh * l, TPointGragh * r)
{
  TPlexGragh* lBuff = dynamic_cast<TPlexGragh*>(l);
  TPlexGragh* rBuff = dynamic_cast<TPlexGragh*>(r);
  if (lBuff != NULL)
    left = new TPlexGragh(*lBuff);
  else
    left = new TPointGragh(*l);
  if (rBuff != NULL)
    right = new TPlexGragh(*rBuff);
  else
    right = new TPointGragh(*r);
}

TPlexGragh & TPlexGragh::operator+=(TLineGragh & l)
{
  if (left == NULL && right == NULL)
  {
    left = l.GetA();
    right = l.GetB();
  }
  else
  {
    TListStack<TPointGragh*> st;
    TListStack<TPlexGragh*> parentSt;
    st.Put(left);
    st.Put(right);
    parentSt.Put(this);
    parentSt.Put(this);
    bool flag = true;
    while (flag)
    {
		TPointGragh* buff = st.Get();
	  TPlexGragh* parentBuff = parentSt.Get();
      if (*buff != *l.GetA() && *buff != *l.GetB())
      {
		TPlexGragh* pl = dynamic_cast<TPlexGragh*>(buff);
        if (pl != 0)
        {
          st.Put(pl->GetLeft());
          st.Put(pl->GetRight());
          parentSt.Put(pl);
          parentSt.Put(pl);
        }
      }
      else if (*buff == *l.GetA())
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TPlexGragh(l.GetB(), l.GetA());
        }
        else
        {
          parentBuff->right = new TPlexGragh(l.GetB(), l.GetA());
        }
      }
      else
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TPlexGragh(l.GetA(), l.GetB());
        }
        else
        {
          parentBuff->right = new TPlexGragh(l.GetA(), l.GetB());
        }
      }
    }
  }
  return *this;
}

TPointGragh * TPlexGragh::GetLeft()
{
  return left;
}

TPointGragh * TPlexGragh::GetRight()
{
  return right;
}

void TPlexGragh::SetLeft(TPointGragh * l)
{
  left = l;
}

void TPlexGragh::SetRight(TPointGragh *r)
{
  right = r;
}

void TPlexGragh::Show()
{
  Show(this);
}

