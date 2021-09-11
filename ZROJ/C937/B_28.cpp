#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
int a[200005];
long long Sum(0);
unsigned Q[100000005], Tl, Hd, m, n, Cnt(0);
unsigned A, B, C, D, t, Ans(0), Tmp(0);
char InQue[200005];
inline void Clr() {
  n = RD(), Sum = 0, Tl = Hd = 0, Cnt = 0;
}
int main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  while (1) {
    Clr();
    if (!n) break;
    for (unsigned i(1); i <= n; ++i) Sum += (a[i] = RDsg());
    if (Sum <= 0) { printf("-1\n");continue; }
    for (register unsigned i(1); i <= n; ++i) if (a[i] < 0) Q[++Tl] = i, InQue[i] = 1;
    // printf("Sum %d\n", Sum);
    while (Tl ^ Hd) {
      unsigned Now(Q[++Hd]);
      ++Cnt, InQue[Now] = 0;
      // printf("Now %u Cnt %u [%u, %u] %d\n", Now, Cnt, Hd, Tl, a[Now]);
      if (Now == 1) { a[n] += a[Now]; if ((!InQue[n]) && (a[n] < 0)) Q[++Tl] = n, InQue[n] = 1; }
      else { a[Now - 1] += a[Now]; if ((!InQue[Now - 1]) && (a[Now - 1] < 0)) Q[++Tl] = Now - 1, InQue[Now - 1] = 1; }
      if (Now == n) { a[1] += a[Now]; if ((!InQue[1]) && (a[1] < 0)) Q[++Tl] = 1, InQue[1] = 1; }
      else { a[Now + 1] += a[Now]; if ((!InQue[Now + 1]) && (a[Now + 1] < 0)) Q[++Tl] = Now + 1, InQue[Now + 1] = 1; }
      a[Now] = -a[Now];
      // for (unsigned i(1); i <= n; ++i) printf("%d ", a[i]);
      // putchar('\n');
    }
    printf("%u\n", Cnt);
  }
  return Wild_Donkey;
}
/*
-1 2 -2 2: 3
-1 0 2 0: 1
1 -1 2 -1: 2
0 1 1 -1: 4
-1 1 0 1: 1
1 0 0 0


-1 2 -2 2: 1
1 1 -2 1: 3
1 -1 2 -1: 2
0 1 1 -1: 4
-1 1 0 1: 1
1 0 0 0

-1 -2 2 2
1 -3 2 1
-2 3 -1 1
-2 2 1 0
2 0 1 -2
0 0 -1 2
0 -1 1 1
-1 1 0 1
1 0 0 0

-1 -2 2 2
-3 2 0 2
3 -1 0 -1
2 1 -1 -1
1 1 -2 1
1 -1 2 -1
0 1 1 -1
-1 1 0 1
1 0 0 0
*/
