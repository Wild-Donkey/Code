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
int Mat[1005][1005], f[1005][5005], Tmp[5005];
unsigned m, n;
unsigned A, B, C, D, t;
void Merge(int *x, int *y, int Add) {  // x <- (y + Add)
  unsigned i(0), j(0);
  for (; (i + j < m) && ((x[i] ^ 0xafafafaf) || (y[j] ^ 0xafafafaf));) {
    if (x[i] <= y[j] + Add)
      Tmp[i + j] = y[j] + Add, ++j;
    else
      Tmp[i + j] = x[i], ++i;
  }
  memcpy(x, Tmp, (i + j) << 2);
}
inline void Clr() {
  n = RD(), m = RD();
  for (unsigned i(0); i <= n; ++i) memset(f[i], 0xaf, m << 2);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(i); j <= n; ++j) Mat[i][j] = RDsg();
    // printf("Done\n");
    f[0][0] = 0;
    for (unsigned i(1); i <= n; ++i) f[i][0] = Mat[1][i];
    for (unsigned i(1); i <= n; ++i) {
      for (unsigned j(0); j + 1 < i; ++j)  // Chose [j + 2, i]
        Merge(f[i], f[j], Mat[j + 2][i]);
      Merge(f[i], f[i - 1], 0);
      // printf("Done\n");
    }
    for (unsigned i(0); i < m; ++i) printf("%d ", f[n][i]);
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}