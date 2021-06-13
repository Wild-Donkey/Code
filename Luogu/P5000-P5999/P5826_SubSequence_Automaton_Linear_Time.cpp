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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned a[100005], b[1100005], Pos[100005], Bucket[100005], Nxt[100005], m, n, t;
signed main() {
  RD(), n = RD(), t = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  for (register unsigned T(1), Len, Cnt(0); T <= t; ++T) {
    Pos[T] = ++Cnt, Len = Cnt + RD();
    while (Cnt < Len) b[Cnt++] = RD();
  }
  for (register unsigned i(1); i <= t; ++i)
    Nxt[i] = Bucket[b[Pos[i]]], Bucket[b[Pos[i]]] = i;
  for (register unsigned i(1), j, Tmp; i <= n; ++i) {
    Tmp = Bucket[a[i]], Bucket[a[i]] = 0;
    while (Tmp) j = Tmp, ++Pos[j], Tmp = Nxt[j], Nxt[j] = Bucket[b[Pos[j]]], Bucket[b[Pos[j]]] = j;
  }
  for (register unsigned i(1); i <= n; ++i)
    if(b[Pos[i]]) putchar('N'), putchar('o'), putchar('\n'); 
    else putchar('Y'), putchar('e'), putchar('s'), putchar('\n'); 
  return Wild_Donkey;
}
