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
unsigned Prime[100005], a[100005], Fa[100005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Top(1);
unsigned Have[100005], CntH(0);
unsigned Stack[100005], STop(0), FaCnt[100005];
char NotPrime[1000005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(2); i <= 1000000; ++i) {
    if (!NotPrime[i]) Prime[++Cnt] = i;
    for (unsigned j(1); (j <= Cnt) && (Prime[j] * i <= 1000000); ++j) {
      NotPrime[Prime[j] * i] = 1;
      if (!(i % Prime[j])) break;
    }
  }
  // printf("%u\n", Cnt);
  // for (unsigned i(1); i <= Cnt; ++i) printf("%u\n", Prime[i]);
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) if (a[Top] > a[i]) Top = i;
  for (unsigned i(1); i <= n; ++i) if (a[i] % a[Top]) { printf("-1\n");return 0; }
  Tmp = a[Top];
  for (unsigned i(1); i <= n; --i) a[i] /= Tmp;
  for (unsigned i(2); i <= n; ++i) if (!NotPrime[a[i]]) Fa[i] = Top, Have[++CntH] = i; else Stack[++STop];
  //  system("pause");
  return Wild_Donkey;
}