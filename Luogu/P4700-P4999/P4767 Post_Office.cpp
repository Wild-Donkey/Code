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
unsigned a[3005], Dec[3005][305], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), f[3005][305], g[3005][3005];
bool b[3005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P4767_3.in", "r", stdin);
//   freopen("P4767_NOClear.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
//  memset(g, 0x3f, sizeof(g));
//  g[0][0] = 0x3f3f3f3f;
//  Dec[0][1] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    g[1][i] = 0;
  }
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(i + 1); j <= n; ++j) {
      g[i][j] = g[i][j - 1] + a[j] - a[(i + j) >> 1]; // 预处理 
    }
  }
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
//    printf("Case %u ", i);
    Dec[i][min(i, m) + 1] = 0x3f3f3f3f; // 对于本轮DP, Dec[i][min(i, m) + 1] 是状态 (i, min(i, m)) 可行决策的右边界 
    for (register unsigned j(min(i, m)); j >= 1; --j) {
      unsigned Mxn(min(i - 1, Dec[i][j + 1]));  // 右边界 
//      printf("[%u %u]", Dec[i - 1][j], Mxn);
      for (register unsigned k(Dec[i - 1][j])/*左边界*/; k <= Mxn; ++k) {
        if(f[k][j - 1] + g[k + 1][i] < f[i][j]) {
//          f[i][j] = f[k][j - 1] + g[i - k][k + 1];
          f[i][j] = f[k][j - 1] + g[k + 1][i];
          Dec[i][j] = k;
        }
      }
//      printf("f[%u][%u]=%udes%u     ", i, j, f[i][j], Dec[i][j]);
//      printf("%3u", Dec[i][j]);
    }
    Dec[i][min(i, m) + 1] = 0;  // 对于下一轮, Dec[i][min(i, m) + 1] 是状态 (i + 1, min(i, m)) 的左边界 
//    putchar('\n');
  }
  printf("%u\n", f[n][m]);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



