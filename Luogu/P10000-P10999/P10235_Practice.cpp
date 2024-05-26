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
#define foreplay for
#define wild while
#define Lbt(x) (((~(x)) + 1) & (x))
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
unsigned a[100005], b[100005];
unsigned m, n, t, Ran, Tmp;
inline void Clr() {
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RDsg() + 1000000000;
  memcpy(b, a, (n + 1) << 2);
  sort(b + 1, b + n + 1);
  Ran = unique(b + 1, b + n + 1) - b - 1;
  for (unsigned i(1); i <= n; ++i)
    a[i] = lower_bound(b + 1, b + Ran + 1, a[i]) - b, a[i] = Ran - a[i] + 1;
  // for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
  // putchar(0x0A);
}
void Add(unsigned x) {
  while (x <= Ran) ++b[x], x += Lbt(x);
}
void Del(unsigned x) {
  while (x <= Ran) --b[x], x += Lbt(x);
}
unsigned Que(unsigned x) {
  unsigned Rt(0);
  while (x) Rt += b[x], x -= Lbt(x);
  return Rt;
}
unsigned Judge(unsigned long long x) {
  unsigned Seg(1), Begin(1);
  unsigned long long Sum(0);
  memset(b, 0, (n + 1) << 2);
  for (unsigned i(1); i <= n; ++i) {
    Tmp = ((a[i] - 1) ? Que(a[i] - 1) : 0);
    // printf("Cur %u Sum %llu Tmp %u\n", i, Sum, Tmp);
    if (Tmp + Sum > x) {
      ++Seg;
      for (unsigned j(Begin); j < i; ++j) Del(a[j]);
      Begin = i, Sum = 0;
    } else
      Sum += Tmp;
    Add(a[i]);
  }
  // printf("Judge %llu %u\n", x, Seg);
  return Seg;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    unsigned long long L(0), R(6000000000), Mid;
    while (L < R) {
      // printf("[%llu, %llu]\n", L, R);
      Mid = ((L + R) >> 1);
      if (Judge(Mid) <= m)
        R = Mid;
      else
        L = Mid + 1;
    }
    printf("%llu\n", L);
  }
  //  system("pause");
  return Wild_Donkey;
}