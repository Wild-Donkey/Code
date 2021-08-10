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
unsigned long long MOD(1000000007);
unsigned f[100005][15], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[100005], Mod[15] = "0chokudai0";
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(a + 1, 1, 100003, stdin);
  n = strlen(a + 1);
  f[0][0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    f[i][0] = 1;
    for (register unsigned j(1); j <= 8; ++j) {
      if(a[i] == Mod[j]) {
        f[i][j] += f[i - 1][j - 1];
        if(f[i][j] >= MOD) f[i][j] -= MOD;
      }
      f[i][j] += f[i - 1][j];
      if(f[i][j] >= MOD) f[i][j] -= MOD;
//      printf("f[%u][%u] = %u\n", i, j, f[i][j]);
    }
  }
  printf("%u\n", f[n][8]);
//  }
  return Wild_Donkey;
}

