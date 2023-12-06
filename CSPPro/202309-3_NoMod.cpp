#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
inline unsigned GetNum(char *x, unsigned Len) {
  unsigned intmp(0);
  for (unsigned i(0); i < Len; ++i)
    intmp = (intmp << 3) + (intmp << 1) + x[i] - '0';
  return intmp;
}
inline unsigned Pow(unsigned x, unsigned y) {
  unsigned Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x;
    x = x * x, y >>= 1;
  }
  return Rt;
}
char Express[10005];
int Xs[100005];
struct Expr {
  char Type;  // Single 1, Times 2, Plus 3
  unsigned Xn, Exp;
  int Const;  // Const {0, 0, Const} Plus Expr Const = 1
  vector<Expr> Contain;
  Expr() { Type = 1, Xn = Exp = 0, Const = 1; }
  Expr(int x) { Type = 1, Xn = Exp = 0, Const = x; }
  Expr(unsigned x, int y) { Type = 1, Xn = x, Exp = 1, Const = y; }
  Expr(const Expr &x) {
    Type = x.Type, Xn = x.Xn, Exp = x.Exp, Const = x.Const, Contain = x.Contain;
  }
  Expr(Expr *x) { *this = *x; }
  Expr Tran();
  void AddTo(const Expr &x);
  void MulTo(const Expr &x);
  Expr Neg() const;
  const char operator<(const Expr &x) const;
  const char operator==(const Expr &x) const;
  const char operator!=(const Expr &x) const;
  Expr operator+(const Expr &x) const;
  Expr operator-(const Expr &x) const;
  unsigned operator()();
  Expr operator*(const Expr &x) const;
  Expr operator*(int x) const;
  const char SameC(const Expr &x) const;
  const char VctEq(const Expr &x) const;
  const char VctLs(const Expr &x) const;
  Expr Derivative(unsigned x);

  Expr &operator+=(const Expr &x) {
    *this = *this + x;
    return *this;
  }
  Expr(char *In) {
    unsigned Len(strlen(In));
    while (In[Len - 1] == 0x0A || In[Len - 1] == 0x0D) --Len;
    In[Len++] = ' ';
    stack<Expr> StackE;
    for (unsigned i(0); i < Len;) {
      unsigned j(0);
      while (In[i + j] != ' ') ++j;
      // printf("Here %u %u\n", i, j);
      if ((j == 1) && (In[i] == '+' || In[i] == '*' || In[i] == '-')) {
        Expr Fst(StackE.top());
        StackE.pop();
        Expr Scd(StackE.top());
        StackE.pop();
        if (In[i] == '*') StackE.push(Scd * Fst);
        if (In[i] == '+') StackE.push(Scd + Fst);
        if (In[i] == '-') StackE.push(Scd - Fst);
        i += j + 1;
        // printf("Ee  %u %u\n", i, j);
        continue;
      }
      if (In[i] == 'x') {
        StackE.push(Expr(GetNum(In + i + 1, j - 1), 1));
        i += j + 1;
        continue;
      }
      int Con;
      if (In[i] == '-')
        Con = -GetNum(In + i + 1, j - 1);
      else
        Con = GetNum(In + i, j);
      StackE.push(Expr(Con));
      i += j + 1;
    }
    (*this) = StackE.top();
  }
  inline void PrtC() const {
    unsigned SzT(Contain.size());
    for (unsigned i(0); i < SzT; ++i) {
      Contain[i].Prt();
      if (Type == 3 && i + 1 < SzT) putchar('+');
    }
  }
  inline void Prt() const {
    if (Type == 3) {
      printf("\\left ("), PrtC(), printf("\\right )");
      return;
    }
    if (Type == 2) return PrtC();
    if (Exp == 0)
      printf("%u", Const);
    else {
      if (Const ^ 1) printf("%u", Const);
      printf("x_{%u}", Xn);
      if (Exp ^ 1) printf("^{%u}", Exp);
    }
  }
};
const char Expr::SameC(const Expr &x) const {
  // Prt(), printf("Same"), x.Prt(), putchar(0x0A);
  if (Type != x.Type) return 0;
  if (Type == 3) return 0;
  if (Type == 1) return Xn == x.Xn && Exp == x.Exp;
  if (Contain.size() != x.Contain.size()) return 0;
  unsigned SzT(Contain.size());
  for (unsigned i(0); i < SzT; ++i)
    if (!Contain[i].SameC(x.Contain[i])) return 0;
  return 1;
}
const char Expr::VctEq(const Expr &x) const {
  if (Contain.size() != x.Contain.size()) return 0;
  unsigned SzT(Contain.size());
  for (unsigned i(0); i < SzT; ++i)
    if (Contain[i] != x.Contain[i]) return 0;
  return 1;
}
const char Expr::VctLs(const Expr &x) const {
  if (Contain.size() != x.Contain.size())
    return Contain.size() < x.Contain.size();
  unsigned SzT(Contain.size());
  for (unsigned i(0); i < SzT; ++i)
    if (Contain[i] != x.Contain[i]) return Contain[i] < x.Contain[i];
  return 0;
}
void Expr::AddTo(const Expr &x) {
  if (x.Type == 1 && x.Const == 0) return;
  if (x.Type == 3)
    for (unsigned i(x.Contain.size() - 1); ~i; --i)
      Contain.push_back(x.Contain[i]);
  else
    Contain.push_back(x);
}
void Expr::MulTo(const Expr &x) {
  if (x.Type == 1 && x.Xn == 0 && x.Const == 1) return;
  Const *= x.Const;
  if (x.Type == 2)
    for (unsigned i(x.Contain.size() - 1); ~i; --i)
      Contain.push_back(x.Contain[i]);
  else
    Contain.push_back(x);
  // printf("MulTo "), x.Prt(), putchar(0x0A);
}
const char Expr::operator!=(const Expr &x) const { return !((*this) == x); }
const char Expr::operator==(const Expr &x) const {
  if (Type ^ x.Type) return 0;
  if (Type == 1) return (Xn == x.Xn) && (Exp == x.Exp) && (Const == x.Const);
  if (Const != x.Const) return 0;
  return VctEq(x);
}
const char Expr::operator<(const Expr &x) const {
  if (Type ^ x.Type) return Type < x.Type;
  if (Type == 1) {
    if (Xn ^ x.Xn) return Xn < x.Xn;
    if (Exp ^ x.Exp) return Exp < x.Exp;
    if (Const ^ x.Const) return Const < x.Const;
    return 0;
  }
  if (Const != x.Const) return Const < x.Const;
  return VctLs(x);
}
Expr Expr::Neg() const {
  Expr Rt(*this);
  if (Type == 3) {
    unsigned SzT(Contain.size());
    for (unsigned i(0); i < SzT; ++i) Rt.Contain[i] = Contain[i].Neg();
    return Rt;
  }
  Rt.Const = -Const;
  return Rt;
}
Expr Expr::operator-(const Expr &x) const { return (*this) + x.Neg(); }
Expr Expr::operator+(const Expr &x) const {
  // Prt(), putchar('+'), x.Prt(), putchar(0x0A);
  Expr Rt;
  Rt.Type = 3;
  Rt.AddTo(*this);
  // printf("Here");
  Rt.AddTo(x);
  return Rt.Tran();
}
Expr Expr::operator*(int x) const {
  Expr Rt(*this);
  if (Type ^ 3) {
    Rt.Const *= x;
    return Rt;
  }
  for (unsigned i(Contain.size() - 1); ~i; --i) Rt.Contain[i] = Contain[i] * x;
  return Rt;
}
Expr Expr::operator*(const Expr &x) const {
  // Prt(), putchar('*'), x.Prt(), putchar(0x0A);
  if (Type == 1 && Xn == 0) return x * Const;
  if (x.Type == 1 && x.Xn == 0) return (*this) * x.Const;
  Expr Rt;
  if (Type == 3 && x.Type == 3) {
    Rt.Type = 3;
    for (unsigned i(Contain.size() - 1); ~i; --i)
      for (unsigned j(x.Contain.size() - 1); ~j; --j)
        Rt.Contain.push_back(Contain[i] * x.Contain[j]);
    return Rt.Tran();
  }
  if (Type == 3) {
    Rt.Type = 3;
    for (unsigned i(Contain.size() - 1); ~i; --i)
      Rt.Contain.push_back(x * Contain[i]);
    return Rt.Tran();
  }
  if (x.Type == 3) {
    Rt.Type = 3;
    for (unsigned i(x.Contain.size() - 1); ~i; --i)
      Rt.Contain.push_back((*this) * x.Contain[i]);
    return Rt.Tran();
  }
  Rt.Type = 2;
  Rt.MulTo(*this);
  Rt.MulTo(x);
  return Rt.Tran();
}
Expr Expr::Tran() {
  // printf("Tran "), Prt(), putchar(0x0A);
  if (Type == 1) return *this;
  Expr Cur(*this);
  for (unsigned i(Contain.size() - 1); ~i; --i)
    Cur.Contain[i] = Contain[i].Tran();
  if (Type == 2) {
    Expr Rt(Cur.Contain[0]);
    for (unsigned i(Cur.Contain.size() - 1); ~i; --i)
      if (Cur.Contain[i].Type == 3 || Rt.Type == 3)
        Rt = Rt * Cur.Contain[i];
      else
        Rt.MulTo(Cur.Contain[i]);
    // printf("Tran %u ", Contain.size()), Rt.Prt(), putchar(0x0A);
    if (Rt.Type == 3) return Rt.Tran();
    sort(Rt.Contain.begin(), Rt.Contain.end());
    Cur = Rt, Rt = Expr(), Rt.Type = 2, Rt.Const = Cur.Const;
    for (unsigned i(Cur.Contain.size() - 1), j(0); ~i; --i) {
      if (!j) {
        Rt.Contain.push_back(Cur.Contain[i]), ++j;
        continue;
      }
      if (Rt.Contain[j - 1].Xn == Cur.Contain[i].Xn)
        Rt.Contain[j - 1].Exp += Cur.Contain[i].Exp;
      else
        Rt.Contain.push_back(Cur.Contain[i]), ++j;
    }
    if (Rt.Contain.size() == 1) return Rt.Contain[0] * Rt.Const;
    return Rt;
  }
  Expr Rt;
  Rt.Type = 3;
  for (unsigned i(Cur.Contain.size() - 1); ~i; --i) Rt.AddTo(Cur.Contain[i]);
  // printf("Here\n"), Rt.Prt(), putchar(0x0A);
  sort(Rt.Contain.begin(), Rt.Contain.end());
  Cur = Rt, Rt = Expr(), Rt.Type = 3;
  for (unsigned i(Cur.Contain.size() - 1), j(0); ~i; --i) {
    // printf("%u %u\n", i, j);
    if (!j) {
      Rt.Contain.push_back(Cur.Contain[i]), ++j;
      continue;
    }
    if (Rt.Contain[j - 1].SameC(Cur.Contain[i]))
      Rt.Contain[j - 1].Const += Cur.Contain[i].Const;
    else
      Rt.Contain.push_back(Cur.Contain[i]), ++j;
  }
  if (Rt.Contain.size() == 1) return Rt.Contain[0];
  // printf("Done\n"), Rt.Prt(), putchar(0x0A);
  return Rt;
}
unsigned Expr::operator()() {
  if (Type == 1) return Pow((Xn ? Xs[Xn] : 1), Exp) * Const;
  unsigned Rt;
  if (Type == 2) {
    Rt = 1;
    for (unsigned i(Contain.size() - 1); ~i; --i) Rt *= Contain[i]();
    return Rt;
  }
  Rt = 0;
  for (unsigned i(Contain.size() - 1); ~i; --i) Rt += Contain[i]();
  return Rt;
}
Expr Expr::Derivative(unsigned x) {
  if (Type == 1) {
    Expr Rt;
    if (Xn ^ x) {
      Rt.Const = 0;
      return Rt;
    }
    if (Exp == 1) return Expr(Const);
    Rt.Xn = Xn;
    Rt.Exp = Exp - 1;
    Rt.Const = Exp * Const;
    return Rt;
  }
  if (Type == 3) {
    Expr Rt;
    Rt.Const = 0;
    for (unsigned i(Contain.size() - 1); ~i; --i)
      Rt += Contain[i].Derivative(x);
    return Rt;
  }
  if (Contain.size() == 2)
    return (Contain[0].Derivative(x) * Contain[1] +
            Contain[1].Derivative(x) * Contain[0]) *
           Const;
  unsigned Mid(Contain.size() / 2);
  Expr Fst, Scd;
  if (Mid > 1) {
    Fst.Type = 2;
    for (unsigned i(0); i < Mid; ++i) Fst.Contain.push_back(Contain[i]);
  } else
    Fst = Contain[0];
  Scd.Type = 2;
  for (unsigned i(Contain.size() - 1); i > Mid; --i)
    Scd.Contain.push_back(Contain[i]);
  return (Fst.Derivative(x) * Scd + Scd.Derivative(x) * Fst) * Const;
}

//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  unsigned n, m;
  n = RD(), m = RD();
  cin.getline(Express, 1000);
  Expr E(Express);
  E.Prt(), putchar(0x0A);
  E.Derivative(2).Prt(), putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    unsigned Dx(RD());
    for (unsigned j(1); j <= n; ++j) Xs[j] = RD();
    printf("%u\n", E.Derivative(Dx)());
  }
  // n = RD()
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
x1 x2 + x3 *
*/