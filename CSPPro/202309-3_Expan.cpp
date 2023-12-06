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
const unsigned long long Mod(1000000007);
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
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
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
char Express[10005];
unsigned Xs[105];
struct Expr {
  char Type;                // Single 1, Times 2, Plus 3
  unsigned Xn, Exp, Const;  // Const {0, 0, Const} Plus Expr Const = 1
  vector<Expr> Contain;
  Expr() { Type = 1, Xn = Exp = 0, Const = 1; }
  Expr(unsigned x) { Type = 1, Xn = Exp = 0, Const = x; }
  Expr(unsigned x, unsigned y) { Type = 1, Xn = x, Exp = 1, Const = y; }
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
  unsigned operator()() const;
  Expr operator*(const Expr &x) const;
  Expr operator*(unsigned x) const;
  const char SameC(const Expr &x) const;
  const char VctEq(const Expr &x) const;
  const char VctLs(const Expr &x) const;
  Expr Derivative(unsigned x) const;

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
      unsigned Con;
      if (In[i] == '-')
        Con = Mod - GetNum(In + i + 1, j - 1);
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
    if (Const ^ 1) printf("%u", Const);
    if (Type == 2) return PrtC();
    if (Exp) {
      printf("x_{%u}", Xn);
      if (Exp ^ 1) printf("^{%u}", Exp);
    }
  }
};
const char Expr::SameC(const Expr &x) const {
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
  // printf("Multi"), x.Prt(), printf("To"), Prt(), putchar(0x0A);
  Const = (unsigned long long)Const * x.Const % Mod;
  if (x.Type == 2)
    for (unsigned i(x.Contain.size() - 1); ~i; --i)
      Contain.push_back(x.Contain[i]);
  else
    Contain.push_back(x), Contain.rbegin()->Const = 1;
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
  Mn(Rt.Const = Mod - Const);
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
Expr Expr::operator*(unsigned x) const {
  Expr Rt(*this);
  if (Type ^ 3) {
    // printf("DigiMul %u ", x), Rt.Prt(), putchar(0x0A);
    Rt.Const = Rt.Const * (unsigned long long)x % Mod;
    // printf("Muled %u ", x), Rt.Prt(), putchar(0x0A);
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
  if (Type == 3) {
    Rt.Type = 3;
    for (unsigned i(Contain.size() - 1); ~i; --i)
      Rt.Contain.push_back(x * Contain[i]);
    // printf("Done"), Rt.Contain[0].Prt(), putchar(0x0A);
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
  // return *this;
  if (Type == 1) return *this;
  Expr Cur(*this);
  for (unsigned i(Contain.size() - 1); ~i; --i)
    Cur.Contain[i] = Contain[i].Tran();
  if (Type == 2) {
    char Type3(0);
    for (unsigned i(Cur.Contain.size() - 1); ~i; --i)
      if (Cur.Contain[i].Type == 3) {
        Type3 = 1;
        break;
      }
    if (Type3) {
      Expr Rt;
      Rt.Const = Cur.Const;
      for (unsigned i(Cur.Contain.size() - 1); ~i; --i)
        Rt = Rt * Cur.Contain[i].Type;
      return Rt.Tran();
    }
    Expr Rt;
    Rt.Const = Cur.Const, Rt.Type = 2;
    for (unsigned i(Cur.Contain.size() - 1); ~i; --i) Rt.MulTo(Cur.Contain[i]);
    sort(Rt.Contain.begin(), Rt.Contain.end());
    Cur = Rt, Rt = Expr(), Rt.Type = 2, Rt.Const = Cur.Const;
    for (unsigned i(Cur.Contain.size() - 1), j(0); ~i; --i) {
      if (!j) {
        Rt.Contain.push_back(Cur.Contain[i]), ++j;
        continue;
      }
      if (Rt.Contain[j - 1].Xn == Cur.Contain[i].Xn)
        Rt.Contain[j - 1].Exp += Cur.Contain[i].Exp,
            Rt.Contain[j - 1].Const =
                (unsigned long long)Rt.Contain[j - 1].Const *
                Cur.Contain[i].Const % Mod;
      else
        Rt.Contain.push_back(Cur.Contain[i]), ++j;
    }
    if (Rt.Contain.size() == 1) return Rt.Contain[0] * Rt.Const;
    if (Rt.Contain.size() == 0) return Expr(Rt.Const);
    return Rt;
  }
  Expr Rt;
  Rt.Type = 3;
  for (unsigned i(Cur.Contain.size() - 1); ~i; --i) Rt.AddTo(Cur.Contain[i]);
  sort(Rt.Contain.begin(), Rt.Contain.end());
  Cur = Rt, Rt = Expr(), Rt.Type = 3;
  for (unsigned i(Cur.Contain.size() - 1), j(0); ~i; --i) {
    if (!j) {
      Rt.Contain.push_back(Cur.Contain[i]), ++j;
      continue;
    }
    if (Rt.Contain[j - 1].SameC(Cur.Contain[i]))
      Mn(Rt.Contain[j - 1].Const += Cur.Contain[i].Const);
    else
      Rt.Contain.push_back(Cur.Contain[i]), ++j;
  }
  if (Rt.Contain.size() == 1) return Rt.Contain[0];
  if (Rt.Contain.size() == 0) return Expr((unsigned)0);
  return Rt;
}
unsigned Expr::operator()() const {
  if (Type == 1) return Pow((Xn ? Xs[Xn] : 1), Exp) * Const % Mod;
  unsigned long long Rt;
  if (Type == 2) {
    Rt = Const;
    for (unsigned i(Contain.size() - 1); ~i; --i) Rt = Rt * Contain[i]() % Mod;
    return Rt;
  }
  Rt = 0;
  for (unsigned i(Contain.size() - 1); ~i; --i) Mn(Rt += Contain[i]());
  // Contain[i].Prt(), printf(" %llu\n", Rt);
  return Rt;
}
Expr Expr::Derivative(unsigned x) const {
  if (Type == 1) {
    Expr Rt;
    if (Xn ^ x) {
      Rt.Const = 0;
      return Rt;
    }
    if (Exp == 1) return Expr(Const);
    Rt.Xn = Xn;
    Rt.Exp = Exp - 1;
    Rt.Const = (unsigned long long)Exp * Const % Mod;
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
  for (unsigned i(Contain.size() - 1); i >= Mid; --i)
    Scd.Contain.push_back(Contain[i]);
  return (Fst.Derivative(x) * Scd + Scd.Derivative(x) * Fst) * Const;
}
signed main() {
  unsigned n, m;
  n = RD(), m = RD();
  cin.getline(Express, 10000);
  Expr E(Express);
  E = E.Tran();
  // printf("Here %llu\n", Pow(2, 10000));
  // E.Prt(), putchar(0x0A);
  // E.Derivative(1).Prt(), putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    unsigned Dx(RD());
    for (unsigned j(1); j <= n; ++j) Mn(Xs[j] = Mod + RDsg());
    printf("%u\n", E.Derivative(Dx)());
  }
  return Wild_Donkey;
}
/*
x1 x2 + x3 *
2 2
1 x1 + x1 x1 * + x1 x1 x1 * * + x1 x1 x1 x1 * * * + x1 1 - *
1 2 3
2 2 1
2 2
x1 x2 * x2 x1 * -
1 2 2
2 2 2
*/