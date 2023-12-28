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
struct Cond {
  unsigned Src;  // n + 1: F, n + 2: U
  char Type;     // Xor Type
} a[100005], b[100005], *Stk[100005], **STop(Stk);
vector<unsigned> Domi[100005];
unsigned m, n, A, B, D, t, Ans;
inline void Clr() {
  for (unsigned i(1); i <= n + 2; ++i) Domi[i].clear();
  n = RD(), m = RD(), Ans = 0;
}
void Find(unsigned x) {
  char Cur(0);
  while (a[x].Src != x) *(STop++) = a + x, x = a[x].Src;
  while (STop > Stk) {
    (*(--STop))->Src = x;
    (*STop)->Type = (Cur ^= (*STop)->Type);
  }
}
void Merge(unsigned x, unsigned y, char Xr) {
  // printf("Merge %u %u %u\n", x, y, Xr);
  Find(x), Find(y);
  // printf("Src (%u, %u) (%u, %u)\n", a[x].Src, a[x].Type, a[y].Src,
  // a[y].Type);
  if (a[x].Src == a[y].Src) {
    if ((a[x].Type ^ a[y].Type) == Xr) return;
    Find(n + 2);
    if (a[n + 2].Src != a[x].Src) Merge(x, n + 2, 0);
    return;
  }
  Xr ^= (a[x].Type ^ a[y].Type);
  // printf("Link %u -> %u\n", a[x].Src, a[y].Src);
  a[a[x].Src] = {a[y].Src, Xr};
}
signed main() {
  // freopen("P9869.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  RD(), t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n + 2; ++i) a[i].Src = i, a[i].Type = 0;
    for (unsigned i(1); i <= m; ++i) {
      char ITmp[5];
      scanf("%s", ITmp);
      if (ITmp[0] == '+' || ITmp[0] == '-') {
        A = RD(), B = RD();
        a[A] = a[B], a[A].Type ^= (ITmp[0] == '-');
      } else {
        A = RD();
        a[A].Src = n + ((ITmp[0] == 'U') ? 2 : 1);
        a[A].Type = (ITmp[0] == 'T' ? 1 : 0);
      }
    }
    for (unsigned i(1); i <= n + 2; ++i) Domi[a[i].Src].push_back(i);
    memcpy(b, a, sizeof(Cond) * (n + 3));
    for (unsigned i(1); i <= n + 2; ++i) a[i] = {i, 0};
    for (unsigned i(1); i <= n + 2; ++i)
      for (auto j : Domi[i]) Merge(j, i, b[j].Type);
    // printf("Done\n");
    Find(n + 2), Find(n + 1), D = a[n + 2].Src;
    for (unsigned i(1); i <= n; ++i) {
      Find(i);
      if (a[i].Src == D) ++Ans;
    }
    // for (unsigned i(1); i <= n + 2; ++i)
    //   printf("%u: %u %u\n", i, a[i].Src, a[i].Type);
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
A -> B
C -> A
B -> C

*/