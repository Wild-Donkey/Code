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
#define Lbt(x) ((x)&((~(x))+1))
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
unsigned Rka[100005], Rkb[100005], a[100005], b[100005], Ta[100005], Tb[100005], Numa[100005], Numb[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0), Topa, Topb;
bitset<100005> Ans;
inline void Clr() {
  Topa = Topb = n = RD();
  memset(Ta, 0, (n + 1) << 2);
  memset(Tb, 0, (n + 1) << 2);
  Ans = 0;
}
inline void Chg(unsigned* Arr) {
  while (A <= n) ++Arr[A], A += Lbt(A);
}
inline void Find(unsigned* Arr) {
  B = 0;
  while (A) B += Arr[A], A -= Lbt(A);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) Rka[i] = a[i] = RD();
    for (unsigned i(1); i <= n; ++i) Rkb[i] = b[i] = RD();
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (unsigned i(1); i <= n; ++i) {
      Rka[i] = lower_bound(a + 1, a + n + 1, Rka[i]) - a;
      Rkb[i] = lower_bound(b + 1, b + n + 1, Rkb[i]) - b;
      Numa[Rka[i]] = i;
      Numb[Rkb[i]] = i;
    }
    Ans[Numa[n]] = 1, A = Rkb[Numa[n]], Chg(Tb), --Topa;
    while (Topa || Topb) {
      if (Topa && (Ans[Numa[Topa]])) { --Topa; continue; }
      if (Topb && (Ans[Numb[Topb]])) { --Topb; continue; }
      if (Topa) {
        A = Topa, Find(Ta);
        if (B) {
          Ans[Numa[Topa]] = 1, A = Rkb[Numa[Topa]], Chg(Tb), --Topa;
          continue;
        }
      }
      if (Topb) {
        A = Topb, Find(Tb);
        if (B) {
          Ans[Numb[Topb]] = 1, A = Rka[Numb[Topb]], Chg(Ta), --Topb;
          continue;
        }
        else break;
      }
      else break;
    }
    for (unsigned i(1); i <= n; ++i) printf("%u", (unsigned)Ans[i]);
    putchar(0x0A);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
6
4
1 2 3 4
1 2 3 4
4
11 12 20 21
44 22 11 30
1
1000000000
1000000000
4
1 2 3 4
1 2 3 4
4
11 12 20 21
44 22 11 30
1
1000000000
1000000000
*/