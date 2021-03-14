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
unsigned int m, n, t, Tmpl[1005], Tmpr[1005], cnt(1);
int a[100005], Min[100005][2], Max[100005][2], Ans(-0x3f3f3f3f), Tmpm[1005];
char s[10005];
inline void Clr() {
  Ans = -0x3f3f3f3f;
  n = RD();
//  b[0] = RDsg();
  a[0] = 0;
  Min[0][0] = 0x3f3f3f3f;
  Max[0][0] = -0x3f3f3f3f;
  Min[n + 1][1] = -0x3f3f3f3f;
  Max[n + 1][1] = -0x3f3f3f3f;
//  memset(f, 0, sizeof(f));
}
//void Chk(const unsigned int &l, const unsigned int &r) {
//  Min[l - 1] = 0x3f3f3f3f;
//  Max[l - 1] = -0x3f3f3f3f;
//  L[l - 1] = l - 1;
//  R[l - 1] = l - 1;
//  for (register unsigned int i(l); i <= r; ++i) {
//    if (Min[i - 1] > a[i]) {
//      L[i][0] = i;
//      Min[i][0] = a[i];
//    }
//    else {
//      L[i][0] = L[i - 1][0];
//      Min[i][0] = Min[i - 1][0];
//    }
//    if (Max[i - 1][0] < a[i] - Min[i][0]) {
//      Max[i][0] = a[i] - Min[i][0];
//      R[i][0] = i;
//    }
//    else {
//      Max[i][0] = Max[i - 1][0];
//      R[i][0] = R[i - 1][0]; 
//    }
//  }
//  printf("%d\n", Max[n][0]);
//  return;
//}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned int T(1); T <= t; ++T) {
    Clr();
    for (register unsigned int i(1); i <= n; ++i) {
      a[i] = RDsg();
    }
    for (register unsigned int i(1); i <= n; ++i) {
      Min[i][0] = min(a[i], Min[i - 1][0]);
      Max[i][0] = max(a[i] - Min[i][0], Max[i - 1][0]);
    }
    for (register unsigned int i(n); i >= 1; --i) {
      Min[i][1] = max(a[i], Min[i + 1][1]);
      Max[i][1] = max(Min[i][1] - a[i], Max[i + 1][1]);
    }
//    printf("%d\n", Max[1][1]);
    for (register unsigned int i(1); i <= n; ++i) {
      Ans = max(Max[i][0] + Max[i][1], Ans);
    }
    printf("%d\n", Ans);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
*/
