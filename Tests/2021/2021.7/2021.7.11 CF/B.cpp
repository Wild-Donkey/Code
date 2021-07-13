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
#define a(x, y) a[(((x) - 1) * m) + (y)]
#define b(x, y) b[(((x) - 1) * m) + (y)]
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
unsigned m, n, Cnt(0), A, B, C, D, t, Tmp(0), Cnta[155], Cntb[155];
char a[100005], b[100005], Ans[100005];
inline void Clr() {
  n = RD(), m = RD();
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      scanf("%s", a + ((i - 1) * m) + 1);
    }
    for (register unsigned i(1); i < n; ++i) {
      scanf("%s", b + ((i - 1) * m) + 1);
    }
//    for (register unsigned i(1); i <= n; ++i) {
//      for (register unsigned j(1); j <= m; ++j) putchar(a(i, j));
//      putchar('\n');
//    }
    for (register unsigned i(1); i <= m; ++i) {
      memset(Cnta, 0, sizeof(Cnta));
      memset(Cntb, 0, sizeof(Cntb));
      for (register unsigned j(1); j <= n; ++j) {
        ++Cnta[a(j, i)];
      }
      for (register unsigned j(1); j < n; ++j) {
        ++Cntb[b(j, i)];
      }
      for (register char j('a'); j <= 'z'; ++j) {
//        printf("%c : a %u b %u\n", j, Cnta[j], Cntb[j]);
        if(Cnta[j] > Cntb[j]) {
          Ans[i] = j;
          break;
        }
      }
      putchar(Ans[i]);
    }
    putchar('\n');
    fflush(stdout);
  }
  return Wild_Donkey;
}
/*
5 6
abcdef
uuuuuu
kekeke
ekekek
xyzklm

xbcklf
eueueu
ayzdem
ukukuk
*/
