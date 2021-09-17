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
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned m, n, Stack[55], Max[55], Hd, t, Now(0), Ans(0), Tmp(0), f[55][1270], g[55][27];
char Inch, a[55][55];
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P4148_1.in", "r", stdin);
//   freopen("P4148.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  n = RD(), m = RD(), t = RD();
  for (register unsigned i(1); i <= n; ++i) {
    while ((Inch ^ '0') && (Inch ^ '1')) Inch = getchar();
    for (register unsigned j(1); j <= m; ++j) {
      a[i][j] = Inch - '0', Inch = getchar();
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    register char flg(1);
    for (register unsigned j(1); j <= m; ++j) {
      if(a[i][j]) ++g[i][1];
    }
    if((g[i][1] << 1) < m) g[i][1] = m - g[i][1], flg = 0;
    a[i][0] = flg, Hd = 0;
    for (register unsigned j(1); j <= m; ++j) {
      if(a[i][j] ^ flg) {
        if(a[i][j - 1] ^ flg) {
          ++Stack[Hd];
        } else {
          Stack[++Hd] = 1;
        }
      }
    }
    sort(Stack + 1, Stack + Hd + 1);
    for (register unsigned j(Hd); j; --j) {
      g[i][2 + Hd - j] = g[i][1 + Hd - j] + Stack[i];
    }
    Max[i] = Hd + 1;
  }
  for (register unsigned i(1); i <= n; ++i) {
    Now += Max[i];
    for (register unsigned j(0); j <= Now; ++j) {
      f[i][j] = f[i - 1][j];
      for (register unsigned k(1); k <= min(Max[i], j); ++k) {
        f[i][j] = max(f[i][j], f[i - 1][j - k] + g[i][k]);
      }
    }
  }
  if(t >= Now) Ans = n * m;
  else Ans = f[n][t];
  printf("%u\n", Ans);
  //  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
//
