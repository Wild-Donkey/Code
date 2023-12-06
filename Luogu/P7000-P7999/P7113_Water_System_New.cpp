#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
inline unsigned RD() {
  unsigned TmpRD(0);
  char TmpRC(getchar());
  while ((TmpRC < '0') || (TmpRC > '9')) TmpRC = getchar();
  while ((TmpRC >= '0') && (TmpRC <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + TmpRC - '0', TmpRC = getchar();
  return TmpRD;
}
char Debug(0);
template <typename TNum>
inline void Prt(TNum x) {
  char Stack[50], *STop(Stack);
  while (x > 0) *(++STop) = (x % 10) + '0', x /= 10;
  if (STop == Stack) {
    putchar('0');
    return;
  }
  while (STop > Stack) putchar(*(STop--));
}
const unsigned long long One(4294967295);
struct BI {
  unsigned Val[4];
  BI() {}
  BI(unsigned long long x) {
    Val[2] = Val[3] = 0, Val[0] = (x & One), Val[1] = (x >> 32);
  }
  BI operator+(const BI& x) const;
  BI operator*(const BI& x) const;
  BI operator*(unsigned long long x) const;
  BI operator/(const BI& x) const;
  BI operator/(unsigned long long x) const;
  unsigned operator%(unsigned x) const;
  BI operator%(const BI& x) const;
  unsigned& operator[](unsigned x) { return Val[x]; }
  const unsigned& operator[](unsigned x) const { return Val[x]; }
  BI& operator=(const unsigned long long& x) { return (*this) = BI(x); }
  BI& operator=(const BI& x) {
    memcpy(Val, x.Val, 16);
    return *this;
  }
  BI& operator*=(unsigned long long x) { return (*this) = (*this) * x; }
  BI& operator*=(const BI& x) { return (*this) = (*this) * x; }
  BI& operator/=(unsigned long long x) { return (*this) = (*this) / x; }
  BI& operator/=(const BI& x) { return (*this) = (*this) / x; }
  BI& operator+=(const BI& x) { return (*this) = (*this) + x; }
  BI operator<<(unsigned x) const {
    // if (Debug) Prt<BI>(*this), printf("<<%u=", x);
    BI Rt(0);
    if (x > 127) return Rt;
    unsigned X(x >> 5);
    // if (Debug && x == 0) { printf("%u %u\n", x, x & 31); }
    x &= 31;
    Rt[3] = Val[3 - X];
    Rt[2] = (X > 2) ? 0 : Val[2 - X];
    Rt[1] = (X > 1) ? 0 : Val[1 - X];
    Rt[0] = X ? 0 : Val[0];
    // if (Debug) putchar('('), Prt<BI>(Rt), putchar(')');

    if (!x) return Rt;
    Rt[3] = ((Rt[3] << x) | (Rt[2] >> (32 - x)));
    Rt[2] = ((Rt[2] << x) | (Rt[1] >> (32 - x)));
    Rt[1] = ((Rt[1] << x) | (Rt[0] >> (32 - x)));
    Rt[0] = (Rt[0] << x);
    // if (Debug && x == 0) printf("\n%u %u %u %u\n", Rt[0], Rt[1], Rt[2],
    // Rt[3]); if (Debug) Prt<BI>(Rt), putchar(0x0A);
    return Rt;
  }
  BI operator>>(unsigned x) const {
    // if (Debug) Prt<BI>(*this), printf(">>%u=", x);
    BI Rt(0);
    if (x > 127) return Rt;
    unsigned X(x >> 5);

    x &= 31;
    Rt[0] = Val[X];
    Rt[1] = (X > 2) ? 0 : Val[1 + X];
    Rt[2] = (X > 1) ? 0 : Val[2 + X];
    Rt[3] = X ? 0 : Val[3];
    // if (Debug) putchar('('), Prt<BI>(Rt), putchar(')');

    if (!x) return Rt;
    Rt[0] = ((Rt[0] >> x) | (Rt[1] << (32 - x)));
    Rt[1] = ((Rt[1] >> x) | (Rt[2] << (32 - x)));
    Rt[2] = ((Rt[2] >> x) | (Rt[3] << (32 - x)));
    Rt[3] = (Rt[3] >> x);
    // if (Debug) Prt<BI>(Rt), putchar(0x0A);
    return Rt;
  }
  inline const char operator<(const BI& x) const {
    if (Val[3] ^ x[3]) return Val[3] < x[3];
    if (Val[2] ^ x[2]) return Val[2] < x[2];
    if (Val[1] ^ x[1]) return Val[1] < x[1];
    return Val[0] < x[0];
  }
  inline const char operator<=(const BI& x) const {
    if (Val[3] ^ x[3]) return Val[3] < x[3];
    if (Val[2] ^ x[2]) return Val[2] < x[2];
    if (Val[1] ^ x[1]) return Val[1] < x[1];
    return Val[0] <= x[0];
  }
  inline const char operator<=(unsigned long long x) const {
    if (Val[3]) return 0;
    if (Val[2]) return 0;
    if (Val[1] ^ (x >> 32)) return Val[1] < (x >> 32);
    return Val[0] <= (x & One);
  }
  inline const char operator>(unsigned long long x) const {
    return BI(x) < (*this);
  }
  BI operator-() const {
    BI Rt;
    Rt[0] = (~Val[0]);
    Rt[1] = (~Val[1]);
    Rt[2] = (~Val[2]);
    Rt[3] = (~Val[3]);
    return Rt + BI(1);
  }
  BI operator-(const BI& x) { return (*this) + (-x); }
  unsigned Usign() const {
    // printf("%u Usign %u\n", this, Val[0]);
    return Val[0];
  }
};
BI Two(const unsigned x) {
  BI Rt(0);
  if (x > 127) return Rt;
  Rt[x >> 5] = 1 << (x & 31);
  return Rt;
}
BI BI::operator+(const BI& x) const {
  BI Rt(*this);
  unsigned long long Tmp, Rem(0);
  Tmp = Rem + Val[0] + x[0], Rem = (Tmp >> 32), Rt[0] = (Tmp & One);
  Tmp = Rem + Val[1] + x[1], Rem = (Tmp >> 32), Rt[1] = (Tmp & One);
  Tmp = Rem + Val[2] + x[2], Rem = (Tmp >> 32), Rt[2] = (Tmp & One);
  Tmp = Rem + Val[3] + x[3], Rt[3] = (Tmp & One);
  return Rt;
}
inline BI BI::operator*(unsigned long long x) const {
  BI Rt(0);
  unsigned long long Tmp(0);
  Tmp = Tmp + x * Val[0], Rt[0] = (Tmp & One), Tmp >>= 32;
  Tmp = Tmp + x * Val[1], Rt[1] = (Tmp & One), Tmp >>= 32;
  Tmp = Tmp + x * Val[2], Rt[2] = (Tmp & One), Tmp >>= 32;
  Tmp = Tmp + x * Val[3], Rt[3] = (Tmp & One);
  return Rt;
}
inline BI BI::operator*(const BI& x) const {
  BI Rt(0);
  Rt = (*this) * x[3], Rt = (Rt << 32);
  Rt += (*this) * x[2], Rt = (Rt << 32);
  Rt += (*this) * x[1], Rt = (Rt << 32);
  Rt += (*this) * x[0];
  return Rt;
}
BI BI::operator/(unsigned long long x) const {
  if (!x) return BI(0);
  // printf("Divide unsigned %u\n", x);
  BI Rt;
  unsigned long long Rem(0);
  Rt[3] = Val[3] / x, Rem = (Val[3] % x), Rem <<= 32;
  Rt[2] = (Val[2] + Rem) / x, Rem = ((Val[2] + Rem) % x), Rem <<= 32;
  Rt[1] = (Val[1] + Rem) / x, Rem = ((Val[1] + Rem) % x), Rem <<= 32;
  Rt[0] = (Val[0] + Rem) / x;
  return Rt;
}
inline BI BI::operator/(const BI& x) const {
  if (x <= One) return (*this) / x.Usign();
  BI TmpD(*this), Rt(0), Cur(x);
  unsigned Exp(0);
  while (Cur <= TmpD) Cur = (Cur << 1), ++Exp;
  --Exp, Cur = (x << Exp);
  while (~Exp) {
    if (Cur <= TmpD) Rt = Rt + Two(Exp), TmpD = TmpD - Cur;
    Cur = (Cur >> 1), --Exp;
  }
  return Rt;
}
unsigned BI::operator%(unsigned x) const {
  if (!x) return 0;
  // if (x != 10) printf("Mod unsigned %u\n", x);
  unsigned long long Rem(0);
  Rem = (Val[3] % x), Rem <<= 32;
  Rem = ((Val[2] + Rem) % x), Rem <<= 32;
  Rem = ((Val[1] + Rem) % x), Rem <<= 32;
  Rem = ((Val[0] + Rem) % x);
  // if (x != 10) printf("Eq %llu\n", Rem);
  return Rem;
}
BI BI::operator%(const BI& x) const {
  if (*this < x) return *this;
  if (x <= One) return BI((*this) % x.Usign());
  // if (Debug) Prt<BI>(*this), printf(" Mod "), Prt<BI>(x), putchar(0x0A);
  BI TmpD(*this), Cur(x);
  unsigned Exp(0);
  while (Cur <= TmpD) Cur = (Cur << 1), ++Exp;
  --Exp, Cur = (x << Exp);
  while (~Exp) {
    if (Cur <= TmpD) TmpD = TmpD - Cur;
    // if (Debug) printf("Exp %u ", Exp), Prt<BI>(Cur), putchar(0x0A);
    Cur = (Cur >> 1), --Exp;
  }
  // if (Debug) printf("Done Mod "), Prt<BI>(TmpD), putchar(0x0A);
  return TmpD;
}
template <typename TNum>
TNum Gcd(TNum x, TNum y) {
  // if (Debug)
  //   printf("Gcd "), Prt<TNum>(x), putchar(' '), Prt<TNum>(y), putchar(0x0A);
  TNum TmpG(x);
  while (y > 0) {
    TmpG = x, x = y, y = TmpG % y;
    // if (Debug) printf("Here Gcd\n");
  }
  // printf("DoneGcd "), Prt<TNum>(x), putchar(0x0A);
  return x;
}
template <typename TNum>
struct Div {
  TNum Up, Down;
  inline Div<TNum> operator+(Div<TNum> x) {
    Div<TNum> TmpP(*this);
    TNum G(Gcd<TNum>(Down, x.Down));
    // if (Debug) printf("gcd "), Prt<TNum>(G), putchar(0x0A);
    x.Down = x.Down / G, Down = Down / G;
    TmpP.Up = (x.Up * Down) + (Up * x.Down);
    Down *= G;
    TmpP.Down = x.Down * Down;
    G = Gcd<TNum>(TmpP.Up, TmpP.Down);
    TmpP.Up /= G, TmpP.Down /= G;
    return TmpP;
  }
  inline void Set(TNum x) { Down = 1, Up = x; }
  inline Div<TNum> Di(TNum x) {
    Div<TNum> TmpP(*this);
    TNum G(Gcd<TNum>(Up, x));
    TmpP.Up /= G, x /= G, TmpP.Down *= x;
    return TmpP;
  }
  inline Div<TNum> Di(unsigned long long x) { return Di(TNum(x)); }
};
void Prtd(Div<BI>& x) {
  Prt<BI>(x.Up), putchar(' '), Prt<BI>(x.Down), putchar(0x0A);
}
struct Node {
  vector<Node*> E;
  Div<BI> Val;
  unsigned Idg, Odg;
} N[100005], *Q[100005], *End[100005];
unsigned n, m;
unsigned Hd(0), Tl(0), CntEn(0);
unsigned A, B, C, D;
signed main() {
  // freopen("P7113_9.in", "r", stdin);
  // freopen("P7113.out", "w", stdout);
  n = RD(), m = RD();
  // n = (m >> 32), printf("%u\n", n);
  // return 0;
  for (unsigned i(1); i <= n; ++i) {
    N[i].Odg = RD(), N[i].Val.Set(0);
    if (!(N[i].Odg)) End[++CntEn] = N + i;
    for (unsigned j(1); j <= N[i].Odg; ++j) {
      B = RD();
      N[i].E.push_back(N + B);
      ++(N[B].Idg);
    }
  }
  for (unsigned i(1); i <= m; ++i) Q[++Tl] = N + i, N[i].Val.Set(1);
  for (unsigned i(m + 1); i <= n; ++i) N[i].Val.Set(0);
  while (Hd < Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i : Cur->E)
      if (!(--(i->Idg))) Q[++Tl] = i;
  }
  // printf("Here\n");
  for (unsigned i(1); i <= n; ++i) {
    if (!(Q[i]->Odg)) continue;
    Div<BI> No(Q[i]->Val.Di(Q[i]->Odg));
    // if ((i >= 60199)) printf("%u\n", i);
    for (auto j : Q[i]->E) {
      // if (i == 60199) printf("Son %u ", j - N), Prtd(j->Val), Debug = 1;
      j->Val = j->Val + No;
      // Debug = 0;
    }
  }
  for (unsigned i(1); i <= CntEn; ++i) Prtd(End[i]->Val);
  return 0;
}