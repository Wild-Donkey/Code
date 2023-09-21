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
inline void Read(char *X) {
  unsigned Cnt(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '1') rdch = getchar();
  while (rdch >= '0' && rdch <= '1') X[++Cnt] = rdch - '0', rdch = getchar();
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
char a[1000005], b[1000005];
unsigned f[1000005], m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  n = RD(), Read(a), Read(b);
  memset(f, 0x3f, (n + 1) << 2), f[0] = 0;
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] ^ b[i]) f[i] = min(f[i - 1] + 1, f[i]);
    if ((a[i - 1] ^ b[i - 1]) & (a[i] ^ b[i]) & (a[i] ^ a[i - 1]))
      f[i] = min(f[i - 2] + 1, f[i]);
    if (a[i] == b[i]) f[i] = min(f[i], f[i - 1]);
  }
  printf("%u\n", f[n]);
  return Wild_Donkey;
}