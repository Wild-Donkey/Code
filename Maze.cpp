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
char a[35][35], f[35][35], Flg(0), Ans;
unsigned m, n;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(0); i < n; ++i) {
    for (unsigned j(0); j < m; ++j) scanf("%s", a[i] + j);
  }
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(1); j < m; ++j) {
      f[i][j] = ((a[i][j] == 'o') & (Flg ^ 1)) ||
                ((a[i][j] == 'x') & (f[i - 1][j] | f[i][j - 1]));
      if (a[i][j] == 'o') Flg = (1 ^ Flg), Ans = (f[i - 1][j] | f[i][j - 1]);
    }
  }
  // for (unsigned i(0); i < n; ++i) {
  //   for (unsigned j(0); j < m; ++j) printf("%u ", a[i][j]);
  //   putchar(0x0A);
  // }
  // for (unsigned i(0); i < n; ++i) {
  //   for (unsigned j(0); j < m; ++j) printf("%u ", f[i][j]);
  //   putchar(0x0A);
  // }
  printf(Ans ? "True\n" : "False\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
6 8
w w w w w w w w
w o w w x w x w
w x w x x w x w
w x x x x x x w
w x x w x w o w
w w w w w w w w
*/