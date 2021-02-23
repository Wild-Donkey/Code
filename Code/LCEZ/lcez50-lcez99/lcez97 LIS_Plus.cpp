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
//#define int long long
#define Wild_Donkey 0
using namespace std;
inline unsigned int RD() {
  unsigned int intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned int m, n;
int a[100005], f[100005], g[100005], How[100005], Tmp, Prt[100005], Cnt(0);
char s[10005];
//inline void Clr() {
////  Ans = -0x3f3f3f3f;
//  n = RD();
//}
signed main() {
  // double Ti(clock()), Mti(0);
//   freopen("P1115_1.in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  for (register unsigned int i(n); i >= 1; --i) {
    a[i] = -RDsg();
  }
  f[0] = -0x3f3f3f3f;
  for (register unsigned int i(1); i <= n; ++i) {
//    printf("%d %d %d\n", f[Cnt], a[i], Cnt);
    if(f[Cnt] < a[i]) {
      f[++Cnt] = a[i];
      g[Cnt] = i;
      How[i] = g[Cnt - 1];
      How[0] = i;
      continue;
    }
    Tmp = lower_bound(f + 1, f + Cnt + 1, a[i]) - f;
    f[Tmp] = a[i];
    g[Tmp] = i;
    How[i] = g[Tmp - 1];
    if (Tmp == Cnt) {
      How[0] = i;
    }
  }
  printf("%d\n", Cnt);
  Tmp = 0;
  for (register unsigned int i(Cnt); i >= 1; --i) {
//    Prt[i] = a[How[Tmp]];
    printf("%d ", -a[How[Tmp]]);
    Tmp = How[Tmp];
  }
//  for (register unsigned int i(1); i <= Cnt; ++i) {
//    printf("%d ", -Prt[i]);
//  }
  putchar('\n');
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
8
3 18 7  14 10 55 12 23
6
1 4 5 2 3 6
1 2 3 6 W
1 4 5 6 A
6
4 5 6 1 2 3
4 5 6 A
1 2 3 W
*/
