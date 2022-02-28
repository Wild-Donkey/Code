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
unsigned m(0), n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[200005], b[200005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  scanf("%s", a + 1);
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] == 'A') b[++m] = 'B', b[++m] = 'B';
    else b[++m] = a[i];
  }
  for (unsigned i(1); i <= m; ++i) {
    if (b[i] == 'B' && b[i + 1] == 'B') ++i, putchar('A');
    else putchar(b[i]);
  }
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}