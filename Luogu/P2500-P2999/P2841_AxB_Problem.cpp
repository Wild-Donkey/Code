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
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
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
struct BI {
  unsigned Len;
  char a[205];
  inline BI() { Len = 1; a[0] = 0; }
  inline void Prt() {
    for (unsigned i(Len - 1); ~i; --i) putchar('0' + a[i]);
  }
  inline void Big() { Len = 200, a[199] = 1; }
  inline void operator = (unsigned x) {
    a[0] = 0;
    for (Len = 1; x; x /= 10, ++Len) a[Len - 1] = x % 10;
    if (Len > 1)--Len;
  }
  const inline char operator <(const BI& x) {
    if (Len ^ x.Len) return Len < x.Len;
    for (unsigned i(Len - 1); ~i; --i) if (a[i] ^ x.a[i]) return a[i] < x.a[i];
    return 0;
  }
  inline BI operator +(const BI& x) {
    BI Rt(x);
    char Up(0);
    for (unsigned i(max(Len, Rt.Len) + 1); i >= Rt.Len; --i) Rt.a[i] = 0;
    Rt.Len = max(Len, Rt.Len) + 1;
    for (unsigned i(0); i < Len; ++i) {
      Rt.a[i] += a[i] + Up, Up = 0;
      while (Rt.a[i] >= 10) Rt.a[i] -= 10, ++Up;
    }
    for (unsigned i(Len); i < Rt.Len && Up; ++i) {
      Rt.a[i] += Up, Up = 0;
      while (Rt.a[i] >= 10) Rt.a[i] -= 10, ++Up;
    }
    while (Up) {
      Rt.a[Rt.Len] = Up, Up = 0;
      while (a[Rt.Len] >= 10) Rt.a[Rt.Len] -= 10, ++Up;
      ++(Rt.Len);
    }
    while ((!(Rt.a[Rt.Len - 1])) && (Rt.Len > 1)) --(Rt.Len);
    return Rt;
  }
  inline BI operator *(const unsigned& x) {
    BI Rt(*this);
    unsigned MuT(0);
    for (unsigned i(Len); i <= 200; ++i) Rt.a[i] = 0;
    for (unsigned i(0); i < Len; ++i) MuT += a[i] * x, Rt.a[i] = MuT % 10, MuT /= 10;
    while (MuT) Rt.a[(Rt.Len)++] = MuT % 10, MuT /= 10;
    return Rt;
  }
}f[2][10005], Ten[205], Ans;
inline BI Suf(unsigned x, unsigned y) {
  BI Rt;
  Rt.Len = y + 1;
  for (unsigned i(0); i <= y; ++i) Rt.a[i] = 0;
  Rt.a[y] = x;
  return Rt;
}
const unsigned Fin[2][10] = { {0, 9, 8, 7, 6, 5, 4, 3, 2, 1},{1, 0, 9, 8, 7, 6, 5, 4, 3, 2} };
unsigned D, t, n;
unsigned Cnt(0), Len(0);
set<unsigned long long> Tai[10];
bitset <10005> OK;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), OK[0] = 1, Ans.Big();
  // BI A, B;
  // while (1) {
  //   A = RD(), D = RD(), A.Prt(), putchar('*'), printf("%u", D), putchar('='), (A * D).Prt(), putchar(0x0A);
  // }
  for (unsigned i(1); i <= n; ++i) OK[i] = (OK[i / 10] & ((i % 10) < 2));
  if (OK[n]) { printf("1 %u\n", n);return 0; }
  for (unsigned i(0); i <= 200; ++i) Ten[i].Len = i + 1, Ten[i].a[i] = 1;
  for (unsigned i(0); i < 10; ++i) Tai[(n * i) % 10].insert(i);
  for (unsigned i(0); i <= n; ++i) f[0][i].Big();
  for (auto i : Tai[0]) f[0][i * n / 10] = i;
  for (auto i : Tai[1]) f[0][i * n / 10] = i;
  // for (unsigned i(0); i <= n; ++i) f[0][i].Prt(), putchar(' '); putchar(0x0A);
  while (1) {
    for (unsigned i(1); i <= n; ++i) if (OK[i] & (f[Len & 1][i] < Ten[199])) if (f[Len & 1][i] < Ans) Ans = f[Len & 1][i];
    if (Ans < Ten[199]) break;
    ++Len;
    // printf("Len %u:\n", Len);
    for (unsigned i(0); i <= n; ++i) f[Len & 1][i].Big();
    for (unsigned i(0); i <= n; ++i) {
      for (auto j : Tai[Fin[0][i % 10]]) {
        unsigned Des((j * n + i) / 10);
        BI Tmp(f[(Len & 1) ^ 1][i] + Suf(j, Len));
        if (Tmp < f[Len & 1][Des]) f[Len & 1][Des] = Tmp;
      }
      for (auto j : Tai[Fin[1][i % 10]]) {
        unsigned Des((j * n + i) / 10);
        BI Tmp(f[(Len & 1) ^ 1][i] + Suf(j, Len));
        if (Tmp < f[Len & 1][Des]) f[Len & 1][Des] = Tmp;
      }
    }
    // for (unsigned i(0); i <= n; ++i) f[Len & 1][i].Prt(), putchar(' '); putchar(0x0A);
  }
  Ans.Prt(), putchar(' '), (Ans * n).Prt(), putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}