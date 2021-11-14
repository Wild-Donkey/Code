#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
unsigned m, n, Cnt[30], Module[30];
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
char aP[100005], * a(aP), Flg(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 100002, stdin);
  while (a[1] < 'a') ++a;
  while (a[n + 1] >= 'a') a[n] -= 'a', ++n;
  a[n] -= 'a';
  for (unsigned i(1); i < n; ++i) {
    if (!(n % i)) {
      // printf("Check %u\n", i);
      m = n / i, memset(Module, 0, sizeof(Module)), Flg = 0;
      for (unsigned j(1); j <= i; ++j) ++Module[a[j]];
      for (unsigned j(2); j <= m; ++j) {
        memset(Cnt, 0, sizeof(Cnt));
        for (unsigned k(((j - 1)* i) + 1); k <= j * i; ++k) ++Cnt[a[k]];
        for (unsigned k(0); k < 26; ++k) if (Cnt[k] ^ Module[k]) { Flg = 1; break; }
        // for (unsigned k(0); k < 26; ++k) printf("%u Cnt    +%u Mod %u\n", k, Cnt[k], Module[k]);
        if (Flg) break;
      }
      if (!Flg) { for (unsigned j(1); j <= i; ++j) putchar(a[j] + 'a'); putchar('\n'); return 0; }
    }
  }
  printf("-1\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
*/